#if DEBUGGING

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "gba/gba.h"
#include "string_util.h"
#include "text.h"

#define REG_DEBUG_ENABLE ((vu16 *)0x4FFF780)
#define REG_DEBUG_FLAGS ((vu16 *)0x4FFF700)
#define REG_DEBUG_STRING ((char *)0x4FFF600)

#define MGBA_LOG_FATAL 0
#define MGBA_LOG_ERROR 1
#define MGBA_LOG_WARN 2
#define MGBA_LOG_INFO 3
#define MGBA_LOG_DEBUG 4

static bool32 mgba_open(void)
{
    *REG_DEBUG_ENABLE = 0xC0DE;
    return *REG_DEBUG_ENABLE == 0x1DEA;
}

static const char sDigits[10] = "0123456789";

static int PrintInt(char *dest, int num)
{
    char buffer[10];
    int i, j, m, n, negative;

    if (num < 0)
    {
        negative = TRUE;
        num = -num;
    }
    else
    {
        negative = FALSE;
    }

    for (n = 0; num > 0; ++n)
    {
        buffer[n] = sDigits[num % 10];
        num /= 10;
    }

    if (n == 0)
    {
        buffer[0] = '0';
        n = 1;
    }

    if (negative)
    {
        *dest++ = '-';
        j = 1;
    }
    else
    {
        j = 0;
    }

    for (i = 0; i < n; ++i)
        dest[i] = buffer[n-i-1];
    return i+j;
}

void Printf(const char *fmt, ...)
{
    char *dest;
    va_list args;

    if (!mgba_open())
        return;

    va_start(args, fmt);
    dest = REG_DEBUG_STRING;

    while (*fmt != '\0')
    {
        if (*fmt == '%')
        {
            fmt++;

            switch (*fmt)
            {
            case '%':
                *dest++ = '%';
                fmt++;
                break;

            case 'd':
                dest += PrintInt(dest, va_arg(args, int));
                fmt++;
                break;

            default:
                fmt++;
                break;
            }
        }
        else
        {
            *dest++ = *fmt++;
        }
    }

    *dest = '\0';
    *REG_DEBUG_FLAGS = MGBA_LOG_INFO | 0x100;
    va_end(args);
}

#endif
