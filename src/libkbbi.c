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

void
search(Results** results, const char* query, const int query_size)
{
  return kbbi_data_search(results, query, query_size);
}

char*
test()
{
  return "Hello from libkbbi.so";
}
