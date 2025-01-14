# Errors C++

Errors C++ is a [C++](https://isocpp.org/) package that provides utilities for error handling.
This package mainly consists of the `errors::Error` class, representing an object that may contain an error.

This package serves as an alternative to error handling using [try-catch exceptions](https://en.cppreference.com/w/cpp/language/try_catch), commonly found in C++ code.
It facilitates error handling by returning values, following the style of [Go's error handling](https://go.dev/blog/error-handling-and-go).

## Key Features

This package provides the following key features:

- Error handling in the style of Go  by returning an `errors::Error`.
- Support for creating errors in the style of [fmtlib](https://github.com/fmtlib/fmt) using `errors::format`.
- Direct printing of `errors::Error` using C++ streams and fmtlib.

## Integration

To integrate this package into your C++ project, you can build and install it locally using [CMake](https://cmake.org/):

```sh
cmake -B build .
cmake --build build --config Release
cmake --install build
```

Once installed, you can use it in your CMake project as the `Errors` package:

```cmake
find_package(Errors 1.0.0 REQUIRED CONFIG)

add_executable(foo foo.cpp)
target_link_libraries(foo PRIVATE errors::errors)
```

Alternatively, you can also integrate this package using [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake):

```cmake
cpmaddpackage(gh:threeal/errors-cpp@1.0.0)

add_executable(foo foo.cpp)
target_link_libraries(foo PRIVATE errors)
```

## Usage

This package contains an `errors::Error` class, which represents an error object.
Functions that may produce errors should return this object so that the error can be handled properly.

```cpp
errors::Error read_file(const char* filepath);

int main() {
  const auto err = read_file(filepath);
  if (err) {
    // Handle the error.
  }

  // Continue processing if no error.
}
```

For functions returning `errors::Error`, use `errors::nil` function to signify no error or return an error object created from the `errors::make` function.

```cpp
errors::Error read_file(const char* filepath) {
  std::ifstream file(filepath);
  if (!file.is_open()) {
    return errors::make("failed to open file");
  }

  // Process with no error.

  return errors::nil();
}
```

Alternatively, an error object can also be created with a formatted message in the style of fmtlib using `errors::format` function.

```cpp
if (!file.is_open()) {
  return errors::format("failed to open '{}'", filepath);
}
```

For more details and examples, refer to the [examples](./examples) directory.

## License

This project is licensed under the terms of the [MIT License](./LICENSE).

Copyright © 2023-2025 [Alfi Maulana](https://github.com/threeal)
