#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>

#define BUFFER_SIZE 64

static void clean_line(char *str) {
    size_t i;

    for(i = 0; *(str+i) != '\0'; ++i)
        if(*(str+i) == '\n') {
            *(str+i) = '\0';
            break;
        }
}

int main(void) {
    long input;
    int32_t value;
    char buffer[BUFFER_SIZE];
    char *end_ptr;

    for(;;) {
        fprintf(stderr, "Input: ");
        if(fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error\n");
            exit(EXIT_FAILURE);
        }

        clean_line(buffer);

        input = strtol(buffer, &end_ptr, 10);
        if(errno == ERANGE) {
            fprintf(stderr, "OUT OF RANGE! TRY AGAIN!\n");
            errno = 0;
            continue;
        }
        if(*end_ptr != '\0') {
            fprintf(stderr, "Hey! don't include anything other than digits!\n");
            continue;
        }

        if(input < INT32_MIN) {
            fprintf(stderr, "Too low! try again!\n");
            continue;
        }
        
        if(input > INT32_MAX) {
            fprintf(stderr, "Too HIGH! try again!\n");
            continue;
        }

        value = (int32_t) input;
        printf("Res: %" PRId32 "\n", value);
        break;
    }
    return 0;
}
