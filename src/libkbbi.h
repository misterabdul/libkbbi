#ifndef _LIB_KBBI_H
#define _LIB_KBBI_H

/**
 * The results object data type.
 **/
typedef struct results
{
  char* katakunci;
  char* artikata;
  struct results* next;
} Results;

/**
 * Initialize the results object.
 *
 * @return Results*
 **/
extern Results*
init_result();

/**
 * Free the memory of results object.
 *
 * @param  Results* result
 * @return void
 **/
extern void
free_result(Results* result);

/**
 * Do searching in KBBI data for given search query.
 *
 * @param  Results** result
 * @param  int* result_size
 * @param  char* query
 * @param  int query_size
 * @return int
 **/
extern int
search(Results** result,
       int* result_size,
       const char* query,
       const int query_size);

/**
 * Count the total words in the KBBI data.
 *
 * @return int
 **/
extern int
count();

/**
 * Get the current library version.
 *
 * @return char*
 **/
extern char*
version();

#endif
