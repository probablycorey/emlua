#include <stdio.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

int hi() {
	printf("hi corey1\n");
	return 0;
}

int lua_main(const char* script) {
	printf("A1");
	lua_State* lua = luaL_newstate();
	printf("B");
	luaL_openlibs(lua);
	printf("C");
	int res = luaL_dostring(lua, script);
	printf("D");
	size_t len = 0;
	printf("E");
	const char* value = lua_tolstring(lua, lua_gettop(lua), &len);

	printf("%s\n", value);

	lua_close(lua);

	return 0;
}