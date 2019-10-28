all: main.o

main.o: main.c
	emcc main.c -o ./build/main.js -s EXPORTED_FUNCTIONS="['_hi']" EXTRA_EXPORTED_RUNTIME_METHODS="['ccall']"

lua:
	cd lua-5.3.5/src && make generic CC='emcc -s WASM=1' AR='emar rcu' RANLIB='emranlib' 