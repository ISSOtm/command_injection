
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char * lineptr = NULL;
    size_t size = 0;
    ssize_t readLen = getline(&lineptr, &size, stdin);

    if (readLen == -1) {
        perror("getline");
        exit(1);
    }

    char buf[size + strlen("ping ") + 1];
    sprintf(buf, "ping -c 4 %s", lineptr);
	system(buf);

    free(lineptr);
	return 0;
}
