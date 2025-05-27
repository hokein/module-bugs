experiment_context_test/experiment_context_test.pic.o: experiment_context/experiment_context.pic.pcm
	mkdir -p experiment_context_test
	rm -rf $@
	$(CLANG) -iquote . -Wuninitialized-const-reference -fmodules  -Xclang=-fmodule-file=experiment_context/experiment_context.pic.pcm -std=gnu++20  -c experiment_context_test.cc -o experiment_context_test/experiment_context_test.pic.o $(EXTRA_CFLAGS)
bar/bar.pic.pcm:
	mkdir -p bar
	rm -rf $@
	$(CLANG) -iquote . -fmodule-name=bar -fmodule-map-file=bar.cppmap -xc++ -Xclang=-emit-module -fmodules -std=gnu++20 -c bar.cppmap -o bar/bar.pic.pcm $(EXTRA_CFLAGS)
foo/foo.pic.pcm:
	mkdir -p foo
	rm -rf $@
	$(CLANG) -iquote . -fmodule-name=foo -fmodule-map-file=foo.cppmap -xc++ -Xclang=-emit-module -fmodules -std=gnu++20 -c foo.cppmap -o foo/foo.pic.pcm $(EXTRA_CFLAGS)
experiment_context/experiment_context.pic.pcm: bar/bar.pic.pcm foo/foo.pic.pcm
	mkdir -p experiment_context
	rm -rf $@
	$(CLANG) -iquote . -Wuninitialized-const-reference -fmodule-name=experiment_context -fmodule-map-file=experiment_context.cppmap -xc++ -Xclang=-emit-module -fmodules  -Xclang=-fmodule-file=bar/bar.pic.pcm -Xclang=-fmodule-file=foo/foo.pic.pcm -std=gnu++20 -c experiment_context.cppmap -o experiment_context/experiment_context.pic.pcm $(EXTRA_CFLAGS)
.PHONY: clean
clean:
	find . \( -name '*.pcm' -o -name '*.o' \) -delete
