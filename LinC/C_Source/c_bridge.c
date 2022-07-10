#include <stdio.h>
#include <malloc.h>
#include "c_bridge.h"
#include "types.h"

#define DEFAULT_NUM_VARS    4

vars_t* bridge_init(char* lua_file) {
    // TODO: pass the file contents to the Lua interpreter instance

    vars_t* vars_list = (vars_t*)malloc(sizeof(vars_t)); 
    vars_list->num_vars = 0;
    vars_list->vars = malloc(sizeof(void*)*DEFAULT_NUM_VARS);
    vars_list->types = (int*)malloc(sizeof(int*)*DEFAULT_NUM_VARS);
    vars_list->size = DEFAULT_NUM_VARS;
    return vars_list;
}

void receive_data(void* data, int type, vars_t* vars_list) {
    if (vars_list->num_vars >= vars_list->size) {
        vars_list->size *= 2;
        vars_list->vars = realloc(vars_list->vars, vars_list->size);
        vars_list->types = realloc(vars_list->types, vars_list->size);
    }
    vars_list->vars[vars_list->num_vars] = data;
    vars_list->types[vars_list->num_vars] = type;
    vars_list->num_vars++;
}
