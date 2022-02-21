# Build example

#!bin/sh

proj_root_dir=$(pwd)

rm -rf bin
mkdir bin
cd bin


flags=(
	-std=gnu99 -Wl,--no-as-needed -ldl -lGL -lX11 -pthread -lXi -D_POSIX_C_SOURCE=199309L
)

# Include directories
inc=(
  -I ../gst/third_party/include/
)

# Source files
src=(
    ../src/main.c
)

lib_dirs=(
    -L ../gst/lib/
)

libs=(
    -lgs
)

# Build
gcc -O3 ${lib_dirs[*]} ${libs[*]} ${inc[*]} ${src[*]} ${flags[*]} -lm -o App

cd ..
./bin/App
