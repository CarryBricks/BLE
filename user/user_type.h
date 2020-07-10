#ifndef _USER_TYPE_H_
#define _USER_TYPE_H_



/*
 * 'signed' is redundant below, except for 'signed char' and if
 * the typedef is used to declare a bitfield.
 */

    /* 7.18.1.1 */

    /* exact-width signed integer types */
typedef   signed          char s8;
typedef   signed short     int s16;
typedef   signed           int s32;
typedef   signed       long long s64;

    /* exact-width unsigned integer types */
typedef unsigned          char u8;
typedef unsigned short     int u16;
typedef unsigned           int u32;
typedef unsigned       long long u64;





#endif



