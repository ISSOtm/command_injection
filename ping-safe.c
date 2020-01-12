
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char * lineptr = NULL;
    size_t size = 0;
    ssize_t readLen = getline(&lineptr, &size, stdin);

    if (readLen == -1) {
        perror("getline");
        exit(1);
    }

    // How many bytes without the optional terminating newline
    size_t len = strcspn(lineptr, "\n");
    char buf[len + 1];
    memcpy(buf, lineptr, len);
    buf[len] = '\0';
    free(lineptr);

    char * const args[] = {
        "ping",
        "-c",
        "4",
        buf,
        NULL
    };

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        execvp("ping", args);
    } else {
        waitpid(pid, NULL, 0);
    }
}
