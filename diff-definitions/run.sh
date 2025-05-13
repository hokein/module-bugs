
CLANG=${CLANG:=/usr/bin/clang}
EXTRA_CFLAGS="-Xclang -fallow-pcm-with-compiler-errors"

rm -rf output
mkdir -p output

$CLANG -iquote .  -fmodule-name=piecewise_linear_boundary -fmodule-map-file=piecewise_linear_boundary.cppmap -Xclang=-fno-cxx-modules -Xclang=-fmodule-map-file-home-is-cwd  -xc++ -Xclang=-emit-module  -fmodules -fno-implicit-modules -fno-implicit-module-maps -std=gnu++20 -nostdinc++ -nostdlib++ -c piecewise_linear_boundary.cppmap -o output/piecewise_linear_boundary.pic.pcm $EXTRA_CFLAGS

$CLANG -iquote . -fmodule-name=roadgraph_libs -fmodule-map-file=roadgraph_libs.cppmap -Xclang=-fno-cxx-modules -Xclang=-fmodule-map-file-home-is-cwd  -xc++ -Xclang=-emit-module   -fmodules  -fno-implicit-modules -fno-implicit-module-maps        -Xclang=-fmodule-file=output/piecewise_linear_boundary.pic.pcm    -std=gnu++20 -nostdinc++ -nostdlib++ -c roadgraph_libs.cppmap -o output/roadgraph_libs.pic.pcm $EXTRA_CFLAGS

