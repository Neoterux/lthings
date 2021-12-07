#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char* argv[])
{

  if (argc > 1){
    float avg = 0;
    for (int i = 1; i < argc; i++)
      avg += atof(argv[i]);
    avg /= (argc-1);
    avg /= 1000;

    printf("%.2f\n", avg);

  }else 
    fprintf(stderr, "No input provided\n");

  return 0;
}
