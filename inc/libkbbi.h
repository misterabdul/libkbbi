#ifndef _LIB_KBBI_H
#define _LIB_KBBI_H

/**
 * The results object data type.
 **/
typedef struct _kbbi_results
{
  char* katakunci;
  char* artikata;
  struct _kbbi_results* next;
} * KBBI_Results;

/**
 * Initialize the results object.
 *
 * @return KBBI_Results
 **/
extern KBBI_Results
KBBI_resultInit();

/**
 * Free the memory of results object.
 *
 * @param  KBBI_Results results
 * @return void
 **/
extern void
KBBI_resultFree(KBBI_Results results);

/**
 * Do searching in KBBI data for given search query.
 *
 * @param  KBBI_Results* results
 * @param  int* result_size
 * @param  char* query
 * @param  int query_size
 * @return int
 **/
extern int
KBBI_search(KBBI_Results* results,
            int* result_size,
            const char* query,
            const int query_size);

/**
 * Count the total words in the KBBI data.
 *
 * @return int
 **/
extern int
KBBI_count();

/**
 * Get the current library version.
 *
 * @return char*
 **/
extern char*
KBBI_version();

#endif
