#ifndef COMMON_INCLUDE_H
#define  COMMON_INCLUDE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <netinet/in.h>
#include "colors.h"
#include <jansson.h>
#include "file_mime_type.h"
#include <libgen.h>
#include "typeDef.h"
#include "debugs.h"
#include <errno.h>
#include "basic_C_Funcitons.h"

typedef struct {
    CHAR MsgID[10];
    CHAR MsgFrom[30];
    CHAR Message[200];
    CHAR MsgTo[30];
} ClientMessageInfo_t;

typedef struct {
    INT8 MsgStatus;
    CHAR MsgID[10];
    CHAR MsgFrom[30];
    CHAR Message[200];
    CHAR MsgTo[30];
} ServerResponce_t;
#endif
