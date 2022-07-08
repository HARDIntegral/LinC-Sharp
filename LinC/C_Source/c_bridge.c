#include <stdio.h>
#include <malloc.h>
#include "c_bridge.h"
#include "types.h"

#define DEFAULT_NUM_VARS    4

vars_t* bridge_init() {
    vars_t* vars_list = (vars_t*)malloc(sizeof(vars_t)); 
    vars_list->num_vars = 0;
    vars_list->vars = malloc(sizeof(void*)*DEFAULT_NUM_VARS);
    vars_list->types = (int*)malloc(sizeof(int*)*DEFAULT_NUM_VARS);
    vars_list->size = DEFAULT_NUM_VARS;
    return vars_list;
}

void receive_data(void* data, int type, vars_t* vars_list) {
    printf("Variable given to C from C#: %d\n", ++*(int*)data);
    if (vars_list->num_vars >= vars_list->size) {
        // TODO: double the list size somehow
    }
    vars_list->vars[vars_list->num_vars] = data;
    vars_list->types[vars_list->num_vars] = type;
    vars_list->num_vars++;
}
