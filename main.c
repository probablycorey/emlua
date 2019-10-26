#include <stdio.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

int main(int argc, char *argv[]) {
	lua_State* lua = luaL_newstate();
	luaL_openlibs(lua);
	const char* script = "HELLO";
	int res = luaL_dostring(lua, script);

	size_t len = 0;
	const char* value = lua_tolstring(lua, lua_gettop(lua), &len);

	printf("%s\n", value);

	lua_close(lua);

	return 0;
}