#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
    if (argc < 3 || argc > 4) 
        fprintf(stderr, "Usage:\n <server address> <echo string> [port]");
    in_port_t server_port = (argc == 4 ? atoi(argv[3]) : 7);
    
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

