
#!/bin/bash
set -ex
rm -rf output 
mkdir -p output 
CLANG=${CLANG:=/usr/bin/clang}

$CLANG -std=c++20 -fmodules -fmodules-cache-path=output -fmodule-map-file=module.cppmap util.cc

