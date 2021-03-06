#include "hello.h"
#include <msp430.h>
#include <stdio.h>

// Trusted functions
DECLARE_SM(hello, 0x1234);

/* ======== HELLO WORLD SM ======== */
void SM_ENTRY(hello) hello_greet(void)
{
    puts("Greetings from hello Module");
}

/* ======== UNTRUSTED CONTEXT ======== */

void untrusted_hello(void){
    puts("Hello from untrusted library");

    sancus_enable_wrapped(&hello, SM_GET_WRAP_NONCE(hello), SM_GET_WRAP_TAG(hello));

    puts("Sancus module enabled.");
}
