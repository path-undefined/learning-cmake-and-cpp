# Learning CMake and C++

## VSCode Extensions
It would be great to work with the official CMake extension in VSCode `CMake Tools` provided by `Microsoft`.

For C++, one can install `C/C++ Extension Pack`, also from `Microsoft`.

## Build a Simple Project with CMake
CMake works with a file in the project folder called `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.29)

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
cmake_minimum_required(VERSION 3.29)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCE "./app/*.cpp")

add_executable(HelloWorld ${SOURCE})
target_include_directories(HelloWorld PRIVATE ".")
```

Here, we are using the [Cannonical Project Structure](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html) (kinda). The header files and the source files will be put together.

# Including External Libraries
In my case, I would use SDL2 as a 3rd party dependency. Note that, a lot of documentation is talking about using `find_package` command in CMake. This is only a trick provided by CMake or maybe OS package management applications too. In my case, I want to have the full control.

Bascially, what I have to do is just providing the include path, and also the path to the library. But we should firstly build SDL2:

```shell
$ cd /${SDL2_SOURCE_CODE_PATH}/SDL2-2.30.5
$ mkdir build
$ cd build
$ cmake -DCMAKE_INSTALL_PREFIX:PATH=${PROJECT_VENDOR_PATH}/SDL2-2.30.5 ..
$ cmake --build .
$ cmake --install .
```

And then configure the project in this way:

```cmake
cmake_minimum_required(VERSION 3.29)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCE "./app/*.cpp")

add_executable(HelloWorld ${SOURCE})

target_include_directories(HelloWorld PRIVATE ".")

target_include_directories(HelloWorld PRIVATE "./vendor/SDL2-2.30.5/include")
target_link_directories(HelloWorld PRIVATE "./vendor/SDL2-2.30.5/lib64")
target_link_libraries(HelloWorld PRIVATE "SDL2")
```

This will link the built executable to link to the `libSDL2.so`. Use following command to check:

```shell
$ ldd HelloWorld
```
