#include <stdio.h>
#include <ctype.h>
#include <inttypes.h>
#if defined (__RDSEED__) && defined(__RDRND__)
#define __RDRAND__
#include <immintrin.h>
int rnd() {
   int a = 0;
 //  printf("rdrand used\n");
   _rdrand32_step(&a);
   return a;
}
#else
int random();
#endif

#ifndef ITERATIONS
   #define ITERATIONS 0x100000
#endif
//#include <stdlib.h>

int main(void)
{
   #ifdef __AVX__
   printf("AVX found!!!\n");
   #else
   printf("No avx defined.\n");
   #endif
   #ifdef __RDRAND__
      printf("RDRAND found!!!\n");
   #else
      printf("No rdrand found. :(\n");
   #endif 
   printf("Executing %lu iterations\n", ITERATIONS);

   for (uint64_t i = 0; i< ITERATIONS; i++) {
   #ifdef __RDRAND__
      rnd();
//      printf(">%d", rnd());
   #else
      random();
//      printf(">%d\n", random());
   #endif
   }

   return 0;
}
