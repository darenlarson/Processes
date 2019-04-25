// Write a program that opens the text.txt file (with the `fopen()` library call)
// located in this directory

// and then calls `fork()` to create a new process.

// Can both the child and parent access the file descriptor returned by `fopen()`?

// What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // fp is a file pointer tothe type "FILE".
    // text.txt is the name of the file to be opened.
    // w is the mode, which refers to the operation that will be performed: r, w, a r+, w+, or a+.
    FILE* fp;
    fp = fopen("text.txt", "w");

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0) {
        printf("Child Process\n");

        char *child_string = "The CHILD process wrote this string\n";

        fwrite(child_string, sizeof(char), strlen(child_string), fp);

    } else {
        printf("Parent Process\n");

        char *parent_string = "The PARENT process wrote this string \n";

        fwrite(parent_string, sizeof(char), strlen(parent_string), fp);
    }

    // fclose() closes the file that is being pointed by file pointer fp
    fclose(fp);
    
    return 0;
}
