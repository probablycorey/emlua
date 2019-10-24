all: main.o

main.o: main.c lua
	emcc -Ilua-5.3.5/src main.c lua-5.3.5/src/liblua.a WASM=1 -s -O2 -o main.wasm

lua:
	cd lua-5.3.5/src && make generic CC='emcc -s WASM=1'
