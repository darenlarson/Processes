// Write a program that calls `fork()`.

// Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100).

// What value is the variable in the child process?

// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    printf("pid: %d\n", (int) getpid());

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0) {
        printf("Child pid: %d\n", (int) getpid());
        printf("Child: x: %d\n", x);

        x++;

        printf("Child incremented x: %d\n", x);

    } else {
        printf("Parent of child: %d\n", rc);
        printf("Parent pid: %d\n", (int) getpid());
        printf("Parent: x: %d\n", x);

        x = x*2;

        printf("Parent doubled x: %d\n", x);
    }

    // printf("x: %d\n", x);

    return 0;
}
