#include "libkbbi.h"

#include "kbbi_data.h"

#define VERSION "0.0.1"

Results*
init_result()
{
  return (Results*)kbbi_data_init_result();
}

void
free_result(Results* results)
{
  return kbbi_data_free_result((_Results*)results);
}

int
search(Results** results,
       int* result_size,
       const char* query,
       const int query_size)
{
  return kbbi_data_search((_Results**)results, result_size, query, query_size);
}

int
count()
{
  return kbbi_data_count();
}

char*
version()
{
  return VERSION;
}
