#ifndef TYPE_DEF_H
#define TYPE_DEF_H

typedef short                   INT16;
typedef unsigned short          UINT16;
typedef short *                 INT16PTR;
typedef unsigned short*         UINT16PTR;

typedef int                     INT32;
typedef unsigned int            UINT32;
typedef int *                   INT32PTR;
typedef unsigned int*           UINT32PTR;

typedef long int                INT64;
typedef unsigned long int       UINT64;
typedef long int*               INT64PTR;
typedef unsigned long int*      UINT64PTR;

typedef char                    CHAR;
typedef char *                  CHARPTR;

typedef char                    INT8;
typedef unsigned char           UINT8;
typedef char*                   INT8PTR;
typedef unsigned char*          UINT8PTR;

typedef void                    VOID;
typedef void *                  VOIDPTR;

typedef enum
{
    NO = 0,
    YES = 1,

    FALSE = 0,
    TRUE = 1,

    FAIL = 0,
    SUCCESS = 1,

    NOT_PRESENT=-1,
    NEGITIVE_STATUS=-1,

    SUCCESS_RESPONCE_CODE=0,
    FAIL_RESPONCE_CODE=1
}BOOL;

#endif
