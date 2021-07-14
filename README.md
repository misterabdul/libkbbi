# LibKBBI

KBBI library in C.

Data source taken from [efenfauzi/django_kbbi](https://github.com/efenfauzi/django_kbbi).

## Todo

- [ ] Create tests script

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
