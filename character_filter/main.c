#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LENGTH 64
#define BUFFER_SIZE 512

static int
filterupper(
    char *target,
    void *buffer,
    const size_t target_size,
    const size_t buffer_size
)
{
    size_t i, j;

    if(target_size > buffer_size) return 1;
    for(i = 0, j = 0; i < target_size; ++i) {
        if(isupper((unsigned char) *(target + i)) != 0) {
            *(((char *) buffer) + j) = *(target + i);
            j = j + 1;
        }
        if(*(target + i) == '\0') break;
    }

    strlcpy(target, (char *) buffer, target_size);
    return 0;
}

int
main(void) 
{
    char data[LENGTH];
    void *buffer;

    if((buffer = malloc(BUFFER_SIZE)) == NULL) {
        fprintf(stderr, "Cannot allocate memory!\n");
        exit(EXIT_FAILURE);
    }

    strlcpy(data, "Hello, WORLD!", LENGTH);
    filterupper(data, buffer, LENGTH, BUFFER_SIZE);
    printf("Res: %s\n", data);

    free(buffer);
    return 0;
}
