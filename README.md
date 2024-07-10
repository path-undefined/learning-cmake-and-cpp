# Learning CMake and C++

## VSCode Extensions
It would be great to work with the official CMake extension in VSCode `CMake Tools` provided by `Microsoft`.

For C++, one can install `C/C++ Extension Pack`, also from `Microsoft`.

## Build a Simple Project with CMake
CMake works with a file in the project folder called `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(HelloWorld "./app/hello_world.cpp")
```

The CMake mechanism contains 2 steps. First, CMake will build the native building environment by generating either IDE projects, makefiles, etc. And then CMake will use the generated building environment to build the target.

So according to the understanding, for the 2 steps separately, we have to run the following command to generate the building environment:

```console
$ mkdir build
$ cd build
$ cmake ..
```

And then we should use the following command to build the project:

```console
$ cmake --build .
$ ./HelloWorld
Hello world!
```

## Multiple Files
Usually by "project", we are not talking about a single CXX file, but a bunch of them.

For this reason, we have to use a glob-matching to collect all the CXX files in the project:

```cmake
cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCE "./app/*.cpp")

add_executable(HelloWorld ${SOURCE})
target_include_directories(HelloWorld PRIVATE ".")
```

Here, we are using the [Cannonical Project Structure](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html) (kinda). The header files and the source files will be put together.
