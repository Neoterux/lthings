#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <getopt.h>

uint16_t port = 0;
char *ip = "127.0.0.1";

void parse_args(int, char**);

int main(int argc, char** argv)
{
  parse_args(argc, argv);
  if (port == 0){
    perror("No port inserted");
    exit(EXIT_FAILURE);
  }
  int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return 0;
}


void parse_args(int argc, char **argv)
{
  int opt;
  while((opt = getopt(argc, argv, "hp:i:")) != -1)
  {
    switch(opt)
    {
      case 'h':
        break;
      case 'p':
        port = atoi(optarg);
        break;
      case 'i':
        ip = malloc(strlen(optarg)+ 1);
        strcpy(ip, optarg);
        break;
      case '?':
      default:
        perror("a");
        exit(EXIT_FAILURE);
    }
  }
}
