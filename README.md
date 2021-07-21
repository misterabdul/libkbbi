# LibKBBI

[![CircleCI](https://circleci.com/gh/misterabdul/libkbbi/tree/master.svg?style=svg)](https://circleci.com/gh/misterabdul/libkbbi/tree/master)

KBBI library in C.

Data source taken from [efenfauzi/django_kbbi](https://github.com/efenfauzi/django_kbbi).

## Todo

- [x] Create tests script
- [ ] Unit testing with CMake

## Building from git

```sh
# Update all submodules
$ git submodule update --init --recursive

# Run script to create & copy generated source code
$ ./cpdeps.sh

# Create build directory
$ mkdir -p build
$ cd build

# Run cmake to generate build files
# You may set the install prefix flag
# default: -DCMAKE_INSTALL_PREFIX=/usr/local
$ cmake ..

# Run make to start building
$ make

# Optional: run install script to install the lib
$ sudo make install

# Optional: run uninstall script to uninstall the lib
$ sudo make uninstall

```

## Building from released source

Currently not possible because GitHub didn't support the inclusion of submodule directories yet. Clone the source code with git, then checkout to the released tag.
