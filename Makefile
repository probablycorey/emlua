all: main.o

main.o: main.c lua
	emcc -Ilua-5.3.5/src main.c lua-5.3.5/src/liblua.a -O2 -o main.wasm -s EXPORTED_FUNCTIONS="['_run_lua']"

lua:
	cd lua-5.3.5/src && make clean && make generic CC='emcc -s WASM=1'
