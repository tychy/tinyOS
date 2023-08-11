#include "user.h"

extern char __stack_top[];

__attribute__((noreturn)) void exit(void)
{
    for (;;)
        ;
}

__attribute__((section(".text.boot")))
__attribute__((naked)) void
start(void)
{
    __asm__ __volatile__(
        "mv sp, %[stack_top]\n"
        "call main\n"
        "call exit\n"
        :
        : [stack_top] "r"(__stack_top));
}