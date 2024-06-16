#!/bin/sh

mkdir -p build_z

cd build_z

cmake ../src

make -j8
