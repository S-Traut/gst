#!/usr/bin/sh

echo "Initializing GST..."
mkdir ../src/
mkdir ../bin/
mv ./template/impl.c ../
mv ./tempalte/main.c ../src
rm -rf ./template

echo "Building static library..."
./build_lib.sh
