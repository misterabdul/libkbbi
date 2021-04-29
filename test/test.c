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

  char* (*version)() = dlsym(libkbbi_so, "version");
  Results* (*init_result)() = dlsym(libkbbi_so, "init_result");
  void (*free_result)() = dlsym(libkbbi_so, "free_result");
  int (*search)(Results**, int*, const char*, const int) =
    dlsym(libkbbi_so, "search");
  int (*count)() = dlsym(libkbbi_so, "count");

  int total_test = 4;
  int failed_test = 0;

  if (version && init_result && free_result && search && count) {
    printf("Test 1 of %d : ", total_test);
    const char* check_version = "0.0.1";
    if (strncmp(version(), check_version, strlen(check_version)) == 0) {
      printf("success\n");
    } else {
      printf("failed\n");
      failed_test++;
    }

    printf("Test 2 of %d : ", total_test);
    if (count() == 35969) {
      printf("success\n");
    } else {
      printf("failed\n");
      failed_test++;
    }

    Results* result = init_result();
    int result_count;

    printf("Test 3 of %d : ", total_test);
    char* query = "abdullah";
    if (!search(&result, &result_count, query, strlen(query))) {
      printf("success\n");
    } else {
      printf("failed\n");
      failed_test++;
    }

    if (result) {
      free_result(result);
      result = NULL;
    }

    printf("Test 4 of %d : ", total_test);
    char* query2 = "abdu";
    if (search(&result, &result_count, query2, strlen(query2)) &&
        result_count == 4) {
      printf("success\n");
    } else {
      printf("failed\n");
      failed_test++;
    }

    if (result) {
      free_result(result);
      result = NULL;
    }

    if(failed_test) {
      printf("Failed %d of %d tests.\n", failed_test, total_test);
    } else {
      printf("All test run successfully.\n");
    }
  } else {
    printf("Can\'t load libkbbi.so\n");
  }

  dlclose(libkbbi_so);
  return 0;
}
