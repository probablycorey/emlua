all: main.o

main.o: main.c lua
	emcc -Ilua-5.3.5/src main.c lua-5.3.5/src/liblua.a -Os -o main.wasm -s EXPORTED_FUNCTIONS="['_run_lua']"

lua:
	cd lua-5.3.5/src && make clean && make generic CC='emcc -s WASM=1'


	emcc -Ilua-5.3.5/src main.c -Os -o main.wasm
