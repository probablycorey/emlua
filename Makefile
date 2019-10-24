all: main.o

main.o: main.c lua
	emcc -Ilua-5.3.5/src main.c lua-5.3.5/src/liblua.a -s -O2 -o main.wasm
