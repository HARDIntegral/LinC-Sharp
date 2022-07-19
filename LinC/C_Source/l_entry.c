#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

void lua_init(char* lua_file) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    lua_close(L);
}
