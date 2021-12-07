#include <stdio.h>
#include "bitview.h"

int main(void)
{
	int a = 100;
	printf("The value of variable a is %d, in the location %p\n", a, &a);
	printf("bit representation: \n%s\n", get_bits(a));
	char *inter = (char*) &a;
	printf("location before: %p\n", inter);
	inter++;
	printf("location after: %p\n", inter);
	int *p = (int*) inter;
	printf("Pointer transformed to int: %p, value: %d\n", p, *p);
	printf("Bit representation of shifted pointer: \n%s\n", get_bits(*p));
	*p += 0x8938289;
	printf("After added 2 (00000010): \n%s\n", get_bits(*p));
	printf("Result of the initial variable a: %d\n", a);
	printf("The result of adding with offset: \n%s\n", get_bits(a));

}
