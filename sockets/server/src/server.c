/**
 *  Some info can get from:
 *  - https://pubs.opengroup.org/onlinepubs/009604499/functions/socket.htmla
 *  - http://www.chuidiang.org/clinux/sockets/sockets_simp.php
 */
#include "server.h"
#include <asm-generic/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#define MAX_PORT 65535
#define BUFFER_SIZE 5120 // 5 MiB of cache

void start_server(void) 
{
  printf("Setting-up server...\n");
  // Byte buffer
  char buffer[BUFFER_SIZE];
  // Socket info
  // server_fs : Server file decriptor, decriptor of the socket file.
  // new_socket: TODO: Add meaning
  // valread   : TODO: Add meaning
  int server_fd, new_socket, valread;

  // Create a new socket with options:
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  int opt = 1;
  // Creating a new socket file decriptor
  // AF_UNIX: For local communication. Could be Replaced with AF_INET/AF_INET6 for ipv4/6
  //          connection
  // SOCK_STREAM: Retrieve the data in a stream of bytes.
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
    perror("Socket reserve failed");
    exit(EXIT_FAILURE);
  }else
    printf("Decriptor obtained! <%d>\n", server_fd);

  // Configuring Socket
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0)
  {
    perror("Error while setting-up socket options");
    exit(EXIT_FAILURE);
  }else
    printf("Correctly applied options to socket!\n");

  // Configuring address
  address.sin_family = AF_INET; // Use ipv4 as protocol
  address.sin_addr.s_addr = INADDR_ANY; // TODO: Search what does it means
  address.sin_port = htons(port_number);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
  {
    perror("binding failed");
    exit(EXIT_FAILURE);
  }else
    printf("Binding correct <:%d>\n", address.sin_port);
  printf("Starting server at port %d\n", ntohs(address.sin_port));

  // Setting up listen
  if(listen(server_fd, 3) < 0)
  {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }else
    printf("listening...");

  // Accept new connections
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
  {
    perror("accept");
    exit(EXIT_FAILURE);
  }else
    printf("Accepted\n");
  printf("Starting server at port %d\n", address.sin_port);

  valread = read(new_socket, buffer, BUFFER_SIZE);
  printf("result of valread %d\n", valread);
  printf("[CLIENT]> %s\n", buffer);
  char *welcome_msg = "[SERVER] Successfully connected to server";
  send(new_socket, welcome_msg, strlen(welcome_msg), 0);

}


uint16_t search_available_port(int fd, int* opt)
{
  printf("Searching ports...");
  for(int i = 1; i < MAX_PORT; i++)// Looking for each available port
  {
    
  }

  return 0;
}
