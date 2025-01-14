Errors C++
=============

Errors C++ is a `C++`_ package that provides utilities for error handling.
This package mainly consists of the :cpp:class:`errors::Error` class, representing an object that may contain an error.

This package serves as an alternative to error handling using `try-catch exceptions`_, commonly found in C++ code.
It facilitates error handling by returning values, following the style of `Go's error handling`_.

.. _C++: https://isocpp.org
.. _try-catch exceptions: https://en.cppreference.com/w/cpp/language/try_catch
.. _Go's error handling: https://go.dev/blog/error-handling-and-go

Key Features
------------

This package provides the following key features:

- Error handling in the style of Go  by returning an :cpp:class:`errors::Error`.
- Support for creating errors in the style of `fmtlib`_ using :cpp:func:`errors::format`.
- Direct printing of :cpp:class:`errors::Error` using C++ streams and fmtlib.

.. _fmtlib: https://github.com/fmtlib/fmt

Integration
-----------

To integrate this package into your C++ project, you can build and install it locally using `CMake`_:

.. code-block:: sh

   cmake -B build .
   cmake --build build --config Release
   cmake --install build

Once installed, you can use it in your CMake project as the `Errors` package:

.. code-block:: cmake

   find_package(Errors 1.0.0 REQUIRED CONFIG)

   add_executable(foo foo.cpp)
   target_link_libraries(foo PRIVATE errors::errors)

Alternatively, you can also integrate this package using `CPM.cmake`_:

.. code-block:: cmake

   cpmaddpackage(gh:threeal/errors-cpp@1.0.0)

   add_executable(foo foo.cpp)
   target_link_libraries(foo PRIVATE errors)

.. _CMake: https://cmake.org/
.. _CPM.cmake: https://github.com/cpm-cmake/CPM.cmake


Usage
-----

This package contains an :cpp:class:`errors::Error` class, which represents an error object.
Functions that may produce errors should return this object so that the error can be handled properly.

.. code-block:: cpp

   errors::Error read_file(const char* filepath);

   int main() {
     const auto err = read_file(filepath);
     if (err) {
       // Handle the error.
     }

     // Continue processing if no error.
   }

For functions returning :cpp:class:`errors::Error`, use :cpp:func:`errors::nil` function to signify no error or return an error object created from the :cpp:func:`errors::make` function.

.. code-block:: cpp

   errors::Error read_file(const char* filepath) {
     std::ifstream file(filepath);
     if (!file.is_open()) {
       return errors::make("failed to open file");
     }

     // Process with no error.

     return errors::nil();
   }

Alternatively, an error object can also be created with a formatted message in the style of fmtlib using :cpp:func:`errors::format` function.

.. code-block:: cpp

   if (!file.is_open()) {
     return errors::format("failed to open '{}'", filepath);
   }

For more details and examples, refer to the `examples`_ directory.

.. _examples: https://github.com/threeal/errors-cpp/tree/main/examples

API Docs
--------

.. doxygenclass:: errors::Error
   :project: errors
   :members: message, operator bool, operator<<

.. doxygenfunction:: errors::make
   :project: errors

.. doxygenfunction:: errors::nil
   :project: errors

Format Component
^^^^^^^^^^^^^^^^

.. doxygenfunction:: errors::format
   :project: errors_format

License
-------

.. image:: https://opensource.org/wp-content/uploads/2022/10/osi-badge-dark.svg
   :class: only-light
   :width: 150
   :align: right
   :target: https://opensource.org/licenses

.. image:: https://opensource.org/wp-content/uploads/2022/10/osi-badge-light.svg
   :class: only-dark
   :width: 150
   :align: right
   :target: https://opensource.org/licenses

This project is licensed under the terms of the `MIT License`_.

Copyright © 2023-2025 `Alfi Maulana`_

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

.. _Alfi Maulana: https://github.com/threeal
.. _MIT License: https://opensource.org/licenses/MIT
