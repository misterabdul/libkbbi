#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

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
  Results* (*init_result)() = dlsym(libkbbi_so, "init_result");
  void (*free_result)() = dlsym(libkbbi_so, "free_result");
  void (*search)(Results**, const char*, const int) =
    dlsym(libkbbi_so, "search");

  if (test) {
    printf("%s\n", test());

    Results* result = init_result();
    search(&result, "aba", 3);
    Results* tracer = result;

    printf("Search results for \"aba\": \n");
    while (tracer) {
      printf("%s, ", tracer->katakunci);
      tracer = tracer->next;
    }
    printf("\n");

    free_result(result);
    result = NULL;
  } else {
    printf("Can\'t load libkbbi.so\n");
  }

  dlclose(libkbbi_so);
  return 0;
}
