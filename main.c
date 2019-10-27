#include <stdio.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

int hi() {
	printf("hi corey\n");
	return 0;
}

int lua_main(const char* script) {
	lua_State* lua = luaL_newstate();
	luaL_openlibs(lua);
	int res = luaL_dostring(lua, script);

	size_t len = 0;
	const char* value = lua_tolstring(lua, lua_gettop(lua), &len);

	printf("%s\n", value);

	lua_close(lua);

	return 0;
}