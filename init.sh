#!/usr/bin/sh
cd gst
echo "Generating GS..."
git submodule update --recursive --init

echo "Initializing GST..."
mkdir ../src/
mkdir ../bin/
cp ./template/impl.c ../
cp ./template/main.c ../src
cd ..

echo "Building static library..."
./gst/build_lib.sh
