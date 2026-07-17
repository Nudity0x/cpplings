"""File-change watching for the auto-check loop.

Wraps ``watchdog`` to notify the TUI whenever an exercise ``.cpp`` file is
saved. The watcher is deliberately dumb: it reports *which* file changed and
lets the caller decide whether that file is the current exercise and whether to
recheck. Debouncing collapses the burst of events editors emit on save into a
single notification.
"""

from __future__ import annotations

import threading
import time
from pathlib import Path
from typing import Callable

from watchdog.events import FileSystemEvent, FileSystemEventHandler
from watchdog.observers import Observer


class _ExerciseChangeHandler(FileSystemEventHandler):
    """Forwards debounced ``.cpp`` change events to a callback."""

    def __init__(self, callback: Callable[[Path], None], debounce_s: float) -> None:
        self._callback = callback
        self._debounce_s = debounce_s
        self._lock = threading.Lock()
        # Per-path timestamp of the last event we acted on, for debouncing.
        self._last_seen: dict = {}

    def _handle(self, event: FileSystemEvent) -> None:
        if event.is_directory:
            return
        path = Path(str(event.src_path))
        if path.suffix != ".cpp":
            return

        now = time.monotonic()
        with self._lock:
            last = self._last_seen.get(path, 0.0)
            if now - last < self._debounce_s:
                return
            self._last_seen[path] = now

        self._callback(path)

    def on_modified(self, event: FileSystemEvent) -> None:
        self._handle(event)

    def on_created(self, event: FileSystemEvent) -> None:
        self._handle(event)


class ExerciseWatcher:
    """Watches the ``exercises/`` tree and invokes a callback on saves.

    Usage::

        watcher = ExerciseWatcher(exercises_dir, on_change)
        watcher.start()
        ...
        watcher.stop()

    The callback runs on watchdog's observer thread, so callers that touch UI
    state must marshal back to their own thread (the Textual app does this via
    ``call_from_thread``).
    """

    def __init__(
        self,
        exercises_dir: Path,
        callback: Callable[[Path], None],
        debounce_s: float = 0.2,
    ) -> None:
        self._exercises_dir = exercises_dir
        self._handler = _ExerciseChangeHandler(callback, debounce_s)
        self._observer = Observer()

    def start(self) -> None:
        self._observer.schedule(
            self._handler, str(self._exercises_dir), recursive=True
        )
        self._observer.start()

    def stop(self) -> None:
        self._observer.stop()
        self._observer.join()
