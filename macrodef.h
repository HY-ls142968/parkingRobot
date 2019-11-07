#ifndef MACRODEF_H
#define MACRODEF_H

//Hardware status definition
#define ERR_NO 0
#define ERR_CAN 101
#define ERR_SERPORT 102
#define ERR_GYRO 103
#define ERR_MOTOR 104
#define ERR_RADAR 105
#define ERR_READER 106
#define ERR_LASER 107

//robot mechnical parameters definition
#define LENGTH 0
#define WIDTH 0
#define HEIGHT 0
#define GEAR_RATIO_DRI 0
#define GEAR_RATIO_TURN 0
#define GEAR_RATIO_LIFT 0


#define TRUE            true
#define FALSE           false
typedef bool            BOOL;
typedef char            CHAR;
typedef unsigned char   UCHAR;
typedef unsigned char   BYTE;
typedef unsigned char   *PBYTE;
typedef unsigned short  WORD;
typedef unsigned short  USHORT;
typedef int             INT;
typedef unsigned int    UINT;
typedef unsigned int    DWORD;
typedef unsigned int    *LPDWORD;
typedef unsigned long        ULONG;
typedef unsigned long long   ULONG64;
typedef void            *PVOID;
typedef void            *LPVOID;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;





#endif // MACRODEF_H
