#ifndef LLVM_H
#define LLVM_H

#include "symbol_table.h"

typedef struct LLVMData {
    char* value;
    Type pascal_type;
} LLVMData;

struct LLVMData create_llvmdata(char* value, Type pascal_type);
char* new_temp(int* temp_count);

#endif
