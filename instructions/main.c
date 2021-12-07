#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
  int a[3];
  __asm__("mov $0x0, %eax\n\t");
  __asm__("cpuid\n\t");
  __asm__("mov %%eax, %0\n\t": "=r" (a[0]));
  printf("%s\n", (char*) a);
  printf("%x\n", (unsigned int*)a[0]);
}
