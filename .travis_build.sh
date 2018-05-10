#!/bin/bash

set -u
set -e

rm -rf build
mkdir build
cd build
conan install ..
cmake -G Ninja ..
ninja -j6
ninja test
