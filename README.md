# Learning CMake and C++

## VSCode Extensions
It would be great to work with the official CMake extension in VSCode `CMake Tools` provided by `Microsoft`.

For C++, one can install `C/C++ Extension Pack`, also from `Microsoft`.

## CMake Guide
CMake works with a file in the project folder called `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

add_executable(HelloWorld hello_world.cxx)
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
