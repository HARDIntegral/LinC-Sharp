#include <stdio.h>
#include <malloc.h>
#include "c_bridge.h"
#include "types.h"

#define DEFAULT_NUM_VARS    4

vars_t* bridge_init() {
    printf("Cross the bridge!\n");
    vars_t* vars_list = (vars_t*)malloc(sizeof(vars_t)); 
    vars_list->num_vars = 0;
    vars_list->vars = NULL;
    vars_list->types = NULL;
    return vars_list;
}

// TODO: finish writing the function so that I push vars to a stack
void receive_data(void* data, int type, vars_t* vars_list) {
    printf("%d\n", *(int*)data);

}
