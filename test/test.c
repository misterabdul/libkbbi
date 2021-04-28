#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct results
{
  char* katakunci;
  char* artikata;
  struct results* next;
} Results;

int
main(void)
{
  void* libkbbi_so = dlopen("./libkbbi.so", RTLD_LOCAL | RTLD_NOW);
  char* (*test)() = dlsym(libkbbi_so, "test");
  int (*count)() = dlsym(libkbbi_so, "count");
  Results* (*init_result)() = dlsym(libkbbi_so, "init_result");
  void (*free_result)() = dlsym(libkbbi_so, "free_result");
  int (*search)(Results**, int*, const char*, const int) =
    dlsym(libkbbi_so, "search");

  if (test) {
    printf("%s\n", test());

    printf("Data count : %d\n", count());

    Results* result = init_result();
    int result_count;
    char* query = "abdullah";

    if (search(&result, &result_count, query, strlen(query))) {
      Results* tracer = result;

      printf("Search results for \"%s\": \n", query);
      while (tracer) {
        printf("%s, ", tracer->katakunci);
        tracer = tracer->next;
      }
      printf("\n%d word(s)\n", result_count);
    } else {
      printf("Not result found for \"%s\".\n", query);
    }

    if (result) {
      free_result(result);
      result = NULL;
    }
  } else {
    printf("Can\'t load libkbbi.so\n");
  }

  dlclose(libkbbi_so);
  return 0;
}
