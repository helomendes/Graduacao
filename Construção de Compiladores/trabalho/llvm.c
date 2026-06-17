#include "llvm.h"
#include <string.h>
#include <stdio.h>

struct LLVMData create_llvmdata(char* value, Type pascal_type) {
    struct LLVMData new_data;
    new_data.value= value ? strdup(value) : NULL;
    new_data.pascal_type = pascal_type;

    return new_data;
}

char* new_temp(int* temp_count) {
    char buffer[32];
    sprintf(buffer, "%%t%d", *temp_count);
    (*temp_count)++;
    return strdup(buffer);
}
