#!/bin/bash

proj_root_dir=$(pwd)

rm -rf ./gst/lib
mkdir ./gst/lib
cd ./gst/lib

proj_name=gs

flags=(
	-std=gnu99 -Wl,--no-as-needed -ldl -lGL -lX11 -pthread -lXi -D_POSIX_C_SOURCE=199309L
)

# Include directories
inc=(
  -I ${proj_root_dir}/gst/third_party/include/
)

# Source files
src=(
  ${proj_root_dir}/impl.c
)

# Build Library
gcc -c -O3 -g ${flags[*]} ${inc[*]} ${src[*]} ${libs[*]}
ar -rvs lib${proj_name}.a *o 
ranlib lib${proj_name}.a
rm *.o
cd ..
