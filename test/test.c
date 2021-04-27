#include <dlfcn.h>
#include <stdio.h>

int
main(void)
{
  void* libkbbi_so = dlopen("./libkbbi.so", RTLD_LOCAL | RTLD_NOW);
  char* (*test)() = dlsym(libkbbi_so, "test");

  if (test)
    printf("%s\n", test());
  else
    printf("Can\'t load libkbbi.so\n");

  return 0;
}
