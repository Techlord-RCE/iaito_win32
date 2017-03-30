#ifndef R2HACKS_H
#define R2HACKS_H

//Prevents errors with Ws2tcpip.h
#define _WS2TCPIP_H_

//Prevent incompatible named variadic macro error
#include "types.h"

//Prevent incompatible named variadic macro error
#ifndef HAVE_EPRINTF
#define eprintf(x,...) fprintf(stderr,x,__VA_ARGS__)
#define eprint(x) fprintf(stderr,"%s\n",x)
#define HAVE_EPRINTF 1
#endif //HAVE_EPRINTF

//Implementation of 'sleep'
#include <windows.h>
static void sleep(unsigned int seconds) { Sleep(seconds * 1000); }

//Dummy implementation of 'fork'
static int fork() { __debugbreak(); return -1; }

//Prevent compile errors
#define snprintf _snprintf
#define __attribute__(x) __declspec(dllimport)

#endif //R2HACKS_H