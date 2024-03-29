all: main.o

main.o: main.c lua
	emcc -Ilua-5.3.5/src main.c lua-5.3.5/src/liblua.a -Os -o ./build/main.js -s EXPORTED_FUNCTIONS="['_lua_main']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall']"

lua:
	cd lua-5.3.5/src && make generic CC='emcc -s WASM=1' AR='emar rcu' RANLIB='emranlib' 