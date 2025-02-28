
#!/bin/bash
set -ex
rm -rf output 
mkdir -p output 
CLANG=${CLANG:=/usr/bin/clang}

$CLANG -std=c++20 -Wundefined-func-template -fmodules -fmodules-cache-path=output -fbuiltin-module-map -I "$PWD/include" test.cpp
