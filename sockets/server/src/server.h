#include <stdbool.h>
#ifndef _SERVER_H
#define _SERVER_H
extern bool use_udp;
extern unsigned short port_number;

void start_server(void);

unsigned short search_available_port(int fd, int *opt);

#endif
