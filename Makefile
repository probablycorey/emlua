all: main.o

main.o: main.c lua
	emcc -Ilua-5.3.5/src main.c lua-5.3.5/src/liblua.a -Os -o main.js -s EXPORTED_FUNCTIONS="['_lua_main', '_hi']"

lua:
	cd lua-5.3.5/src && make clean && make generic CC='emcc -s WASM=1' AR='emar rcu' RANLIB='emranlib'