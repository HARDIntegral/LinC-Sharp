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
    return vars_list;
}

void receive_data(void* data, int type) {
    printf("%d\n", *(int*)data);
}
