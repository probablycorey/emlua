all: main.o

main.o: main.c
	emcc main.c -Os -o ./build/main.js -s EXPORTED_FUNCTIONS="['_lua_main']"

lua:
	cd lua-5.3.5/src && make generic CC='emcc -s WASM=1' AR='emar rcu' RANLIB='emranlib' 