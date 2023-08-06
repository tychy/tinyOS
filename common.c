#include "common.h"

void putchar(char ch);

void printf(const char *fmt, ...)
{
    va_list vargs;
    va_start(vargs, fmt);

    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
            switch (*fmt)
            {
            case '\0':
            case '%':
                putchar('%');
                break;
            case 's':
            {
                const char *s = va_arg(vargs, const char *);
                while (*s)
                {
                    putchar(*s);
                    s++;
                }
                break;
            }
            case 'd':
            {
                int val = va_arg(vargs, int);
                if (val < 0)
                {
                    putchar('-');
                    val = -val;
                }
                while (val)
                {
                    putchar('0' + val % 10);
                    val /= 10;
                }
                break;
            }
            case 'x':
            {
                int val = va_arg(vargs, int);
                for (int i = 7; i >= 0; i--)
                {
                    int nibble = (val >> (i * 4)) & 0xf;
                    putchar("0123456789abcdef"[nibble]);
                }
                break;
            }
            }
        }
        else
        {
            putchar(*fmt);
        }
        fmt++;
    }
    va_end(vargs);
}