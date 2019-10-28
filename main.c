#include <stdio.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

int lua_main(const char* script) {
	script = "print('head')";
	lua_State* lua = luaL_newstate();
	luaL_openlibs(lua);
	int res = luaL_dostring(lua, script);
	size_t len = 0;
	const char* value = lua_tolstring(lua, lua_gettop(lua), &len);

	if (res == 0) {
		printf("🚀 %s %s\n", value, script);
	} else {
		printf("🛑 %s\n", value);
	}

	lua_close(lua);

	return res;
}

int main(int argc, char *argv[]) {
	return lua_main("return 4");
}