#include "libkbbi.h"

#include "kbbi_data.h"

#define VERSION "0.0.1"

#define KBBI_ATTRIB_VISIBLE __attribute__((visibility("default")))

KBBI_ATTRIB_VISIBLE KBBI_Results
KBBI_resultInit()
{
  return (KBBI_Results)kbbi_data_init_result();
}

KBBI_ATTRIB_VISIBLE void
KBBI_resultFree(KBBI_Results results)
{
  return kbbi_data_free_result((_Results*)results);
}

KBBI_ATTRIB_VISIBLE int
KBBI_search(KBBI_Results* results,
            int* result_size,
            const char* query,
            const int query_size)
{
  return kbbi_data_search((_Results**)results, result_size, query, query_size);
}

KBBI_ATTRIB_VISIBLE int
KBBI_count()
{
  return kbbi_data_count();
}

KBBI_ATTRIB_VISIBLE char*
KBBI_version()
{
  return VERSION;
}
