#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include "server.h"

//: Switches {{{
bool cport_file = false; // Create an output file with the port that is in use
uint16_t port_number = 0; // The port number in use
bool use_udp = false;
//: }}}

void parse_opts(int, char**);
void help_string(char *);

int main(int argc, char** argv)
{
  parse_opts(argc, argv);
   if((optind - argc) <= -1)
  {
    fprintf(stderr, "Invalid quantity of arguments.\n");
    fprintf(stderr, "aborting...\n");
    return -1;
  }
  if (cport_file)
  {
    FILE *portfile = fopen("port_number", "w");
    printf("Creating port file...\n");
    fprintf(portfile, "%d", port_number);
    fclose(portfile);
    printf("File successfully created\n");
  }
  start_server();
}


//: Parse args function {{{
void parse_opts(int argc, char** argv)
{
  int opt;
  while((opt = getopt(argc, argv, "hufp:")) != -1)
  {
    switch(opt)
    {
      case 'f':
        cport_file = true;
        break;
      case 'u':
        use_udp = true;
        break;
      case 'p':
        port_number = atoi(optarg);
        if (port_number == 0)
        {
          fprintf(stderr, "Invalid port input\n");
          exit(1);
        }
        break;
      case 'h':
        help_string(argv[0]);
        exit(0);
        break;
      case '?':
      default:
        help_string(argv[0]);
        exit(-1);
    }
  }
}

void help_string(char* exe)
{
  printf("USAGE:\n");
  printf("%s [option]\n", exe);
  printf("OPTIONS\n");
  printf("-h            Show this help string.\n");
  printf("-u            Use UDP instead of TCP/IP.\n");
  printf("-f            Create a file where the port would be saved.\n");
  printf("-p [1-65535]  The port in wich the server would listen.\n");
}
//: }}}
