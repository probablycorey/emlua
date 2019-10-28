#include <stdio.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

int hi() {
	printf("hi corey1\n");
	return 0;
}

int lua_main(const char* script) {
	lua_State* lua = luaL_newstate();
	luaL_openlibs(lua);
	int res = luaL_dostring(lua, script);
	size_t len = 0;
	const char* value = lua_tolstring(lua, lua_gettop(lua), &len);

	printf("%s %d\n", value, res);

	lua_close(lua);

	return 0;
}