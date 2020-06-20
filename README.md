# Ensemble Windows Registry

This is a simple wrapper for the [Win32 Registry](https://docs.microsoft.com/en-us/windows/win32/sysinfo/structure-of-the-registry).

## Usage

First, we create an instance of `Registry` with a key of our program:

```c++
auto r = new Registry("SOME_KEY");
```

Next, we shall add an integer into the registry:

```c++
r->RegSetInt(true, "sample-integer", 101);
```

Then, we shall retrieve the integer:

```c++
r->RegGetInt(true, "sample-integer");
```

## Install

Make this repository a submodule by executing the following command after you `cd` to your program folder in the terminal:

```shell script
git submodule add https://github.com/yvan-burrie/ensemble-win-reg
```

Then, include the `CMakeLists.txt` from your root CMake script using:

```cmake
include("${CMAKE_SOURCE_DIR}/ensemble-win-reg/CMakeLists.txt")
```
