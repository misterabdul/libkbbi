#include "libkbbi.h"

Results*
init_result()
{
  return kbbi_data_init_result();
}

void
free_result(Results* results)
{
  return kbbi_data_free_result(results);
}

int
search(Results** results,
       int* result_size,
       const char* query,
       const int query_size)
{
  return kbbi_data_search(results, result_size, query, query_size);
}

int
count()
{
  return kbbi_data_count();
}

char*
test()
{
  return "Hello from libkbbi.so";
}
