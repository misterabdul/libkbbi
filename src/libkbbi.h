#ifndef _LIB_KBBI_H
#define _LIB_KBBI_H

#include "kbbi_data.h"

extern char*
test();

extern Results*
init_result();

extern void
free_result(Results* result);

extern int
search(Results** result,
       int* result_size,
       const char* query,
       const int query_size);

extern int
count();

#endif
