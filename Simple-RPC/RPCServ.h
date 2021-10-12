#ifndef RPCServ
#define RPCServ

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BACKLOG_SIZE    10

int addInts(int a, int b);

int multiplyInts(int a, int b);

float divideFloats(float a, float b);

int sleep(int x);

unit64_t factorial(int x);

#endif