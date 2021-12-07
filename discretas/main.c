#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

extern int optind;
extern char *optarg;

int graph_enabled = 0;
int verbose = 0;

int isdigitstr(char* str);

int main (int argc, char **argv){
   char opt;

   while((opt = getopt(argc, argv, "vg") != -1)){
      switch(opt){
         case 'v':
            verbose = 1;
            break;
         case 'g':
            graph_enabled = 1;
            break;
         case '?':
         default:
            fprintf(stderr, "unrecognized option \"%s\"", argv[optind]);
            exit(-2);
      }
   }

   for (int i = 0; i< argc; i++){
      printf("[%d] > %s\n", i, argv[i]);
   }
   if (argc == 1){
      fprintf(stderr, "Insuficient number of arguments\n");
      return 1;
   }else if (argc > 2){
      fprintf(stderr, "Only give 1 argument at the time\n");
      return -1;
   }
   size_t len = strlen(argv[1]);
   if (isdigitstr(argv[1]) != len){
      fprintf(stderr, "Inserted value isn't a valid number\n");
      exit(3);
   }
   if (argv[1][0] == '-'){
      printf("Cannot proccess negative numbers\n");
      exit(4);
   }
   unsigned long long value = atoll(argv[1]);
   printf("Initial value: %llu\n", value);
   
   size_t i = 0;
   while ((value = value/2)){
      printf("\t>> %llu\n", value);
      i++;
   }
   printf("===========[ Times executed: %lu | expected O(n/2)  ]===========\n", i);
}


int isdigitstr(char* str)
{
   ssize_t len = strlen(str);
   int dquantity = 0;
   for(int i = 0; i< len; i++){
      if (isdigit(str[i]))
         dquantity++;
   }
   return dquantity;
}
