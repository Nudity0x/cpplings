# Input & Output

C++ does stream I/O through the `<iostream>` header. `std::cout` is the standard
output stream and `std::cin` the standard input stream. You push data out with
the insertion operator `<<` and pull it in with the extraction operator `>>`.

`std::endl` writes a newline *and* flushes the buffer; a plain `'\n'` just writes
the newline, which is usually what you want. When reading, `>>` skips leading
whitespace and stops at the next whitespace, so reading a full line of text needs
`std::getline` instead. Mixing `>>` and `getline` is a classic source of
"why did it skip my input?" bugs.

## Further information

- [`std::cout` and the standard streams](https://en.cppreference.com/w/cpp/io/cout)
- [`std::getline`](https://en.cppreference.com/w/cpp/string/basic_string/getline)
- [Input with `std::cin`](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/)
