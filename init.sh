#!/usr/bin/sh
cd gst
echo "Initializing GST..."
mkdir ./src/
mkdir ./bin/
mv ./template/impl.c ../
mv ./template/main.c ../src
rm -rf ./template

echo "Building static library..."
./build_lib.sh
