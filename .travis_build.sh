#!/bin/bash

set -u
set -e

rm -rf build
mkdir build
cd build
conan install ..
cmake ..
make -j6
make test
