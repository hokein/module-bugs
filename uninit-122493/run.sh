#!/bin/bash
set -ex
mkdir -p output
CLANG=${CLANG:=/usr/bin/clang}
$CLANG  -iquote . -O1 -fmodule-name=strings2 -Xclang=-fmodule-map-file-home-is-cwd  -xc++ -Xclang=-emit-module -Xclang=-fmodules-embed-all-files -Xclang=-fmodules-local-submodule-visibility -fmodules -std=gnu++20     -nostdinc++ -nostdlib++ -c module.cppmap -o output/strings2.pic.pcm
$CLANG  -iquote . -O1 -fmodule-name=mock_resolver -Xclang=-fmodule-map-file-home-is-cwd  -xc++ -Xclang=-emit-module -Xclang=-fmodules-embed-all-files -Xclang=-fmodules-local-submodule-visibility -fmodules -std=gnu++20     -nostdinc++ -nostdlib++ -c module.cppmap -o output/mock_resolver.pic.pcm
$CLANG  -iquote . -O1 -fmodule-name=sql_internal -Xclang=-fmodule-map-file-home-is-cwd  -xc++ -Xclang=-emit-module -Xclang=-fmodules-embed-all-files -Xclang=-fmodules-local-submodule-visibility -fmodules -std=gnu++20     -nostdinc++ -nostdlib++ -c module.cppmap -o output/sql_internal.pic.pcm
$CLANG -iquote . -O1 -fmodule-map-file=module.cppmap -Xclang=-fmodule-file=output/mock_resolver.pic.pcm -Xclang=-fmodule-file=output/sql_internal.pic.pcm -std=gnu++20 -nostdinc++ -nostdlib++ -c main.cc -o output/main.o
