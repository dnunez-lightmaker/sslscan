// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#pragma comment(lib, "Ws2_32.lib")

#include "targetver.h"

#ifdef _WIN32
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <tchar.h>
#include <stdint.h>
#include <Winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>

#define VERSION "V1.0"
#endif

/*
The strstr function locates the first occurrence of the null-terminated string \c little in the null-terminated string \c big.
The strcasestr function is similar to strstr , but ignores the case of both strings.
The strnstr function locates the first occurrence of the null-terminated string \c little in the string \c big, where not more than \c len characters are searched. Characters that appear after a \0 character are not searched. Since the strnstr function is a FreeBSD specific API, it should only be used when portability is not a concern.
While the strcasestr function uses the current locale, the strcasestr_l function may be passed a locale directly. See xlocale for more information.
*/
char* winStrnStr(char *str, const char *substr, size_t n);

/*
The functions gettimeofday() and settimeofday() can get and set the
time as well as a timezone.  The tv argument is a struct timeval (as
specified in <sys/time.h>):

struct timeval {
time_t      tv_sec;     // seconds
suseconds_t tv_usec;    // microseconds
};

and gives the number of seconds and microseconds since the Epoch(see
time(2)).The tz argument is a struct timezone :

struct timezone {
int tz_minuteswest;     // minutes west of Greenwich
int tz_dsttime;         // type of DST correction
};

If either tv or tz is NULL, the corresponding structure is not set or
returned.  (However, compilation warnings will result if tv is NULL.)

The use of the timezone structure is obsolete; the tz argument should
normally be specified as NULL.  (See NOTES below.)

Under Linux, there are some peculiar "warp clock" semantics
associated with the settimeofday() system call if on the very first
call(after booting) that has a non - NULL tz argument, the tv argument
is NULL and the tz_minuteswest field is nonzero.  (The tz_dsttime
field should be zero for this case.)  In such a case it is assumed
that the CMOS clock is on local time, and that it has to be
incremented by this amount to get UTC system time.No doubt it is a
bad idea to use this feature.
*/

int winGetTimeOfDay(struct timeval *tp, struct timezone *tzp);

/*
The macros are provided to operate on timeval structures, defined in <sys/time.h> as:

struct timeval {
time_t      tv_sec;     // seconds
suseconds_t tv_usec;    // microseconds
};
timeradd() adds the time values in a and b, and places the sum in the timeval pointed to by res.The result is normalized such that res->tv_usec has a value in the range 0 to 999, 999.
timersub() subtracts the time value in b from the time value in a, and places the result in the timeval pointed to by res.The result is normalized such that res->tv_usec has a value in the range 0 to 999, 999.

timerclear() zeros out the timeval structure pointed to by tvp, so that it represents the Epoch : 1970 - 01 - 01 00 : 00 : 00 + 0000 (UTC).

timerisset() returns true (nonzero) if either field of the timeval structure pointed to by tvp contains a nonzero value.

timercmp() compares the timer values in a and b using the comparison operator CMP, and returns true (nonzero)or false (0) depending on the result of the comparison.Some systems(but not Linux / glibc), have a broken timercmp() implementation, in which CMP of >= , <= , and == do not work; portable applications can instead use

!timercmp(..., <) !timercmp(..., >) !timercmp(..., != )
*/
void winTimerSub(struct timeval *a, struct timeval *b, struct timeval *res);
