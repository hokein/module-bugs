#!/bin/bash
set -ex
mkdir -p output
CLANG=${CLANG:=/usr/bin/clang}
$CLANG  -iquote . -fmodule-name=mock_resolver -Xclang=-fmodule-map-file-home-is-cwd  -xc++ -Xclang=-emit-module -Xclang=-fmodules-embed-all-files -Xclang=-fmodules-local-submodule-visibility -fmodules -std=gnu++20     -nostdinc++ -nostdlib++ -c module.cppmap -o output/mock_resolver.pic.pcm
$CLANG  -iquote . -fmodule-name=sql_internal -Xclang=-fmodule-map-file-home-is-cwd  -xc++ -Xclang=-emit-module -Xclang=-fmodules-embed-all-files -Xclang=-fmodules-local-submodule-visibility -fmodules -std=gnu++20     -nostdinc++ -nostdlib++ -c module.cppmap -o output/sql_internal.pic.pcm
$CLANG -iquote . -Xclang=-fmodule-file=output/mock_resolver.pic.pcm -Xclang=-fmodule-file=output/sql_internal.pic.pcm -std=gnu++20 -nostdinc++ -nostdlib++ -c main.cc -o output/main.o
