#include <libkbbi/libkbbi.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
  int total_test = 4;
  int failed_test = 0;

  printf("Test 1 of %d : ", total_test);
  const char* check_version = "0.0.1";
  if (strncmp(KBBI_version(), check_version, strlen(check_version)) == 0) {
    printf("success\n");
  } else {
    printf("failed\n");
    failed_test++;
  }

  printf("Test 2 of %d : ", total_test);
  if (KBBI_count() == 35969) {
    printf("success\n");
  } else {
    printf("failed\n");
    failed_test++;
  }

  KBBI_Results results = KBBI_resultInit();
  int result_count;

  printf("Test 3 of %d : ", total_test);
  char* query = "abdullah";
  if (!KBBI_search(&results, &result_count, query, strlen(query))) {
    printf("success\n");
  } else {
    printf("failed\n");
    failed_test++;
  }

  if (results) {
    KBBI_resultFree(results);
    results = NULL;
  }

  printf("Test 4 of %d : ", total_test);
  char* query2 = "abdu";
  if (KBBI_search(&results, &result_count, query2, strlen(query2)) &&
      result_count == 4) {
    printf("success\n");
  } else {
    printf("failed\n");
    failed_test++;
  }

  if (results) {
    KBBI_resultFree(results);
    results = NULL;
  }

  if(failed_test) {
    printf("Failed %d of %d tests.\n", failed_test, total_test);
  } else {
    printf("All test run successfully.\n");
  }

  return 0;
}
