#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define LEN 128

static void
show_file(FILE* file)
{
    char data[LEN];

    while(fgets(data, LEN-1, file) != NULL)
        printf("%s", data);
}

int
main(void)
{
    FILE *file;

    file = fdopen(666, "a+");
    if(file == NULL) {
        fprintf(stderr, "Dude! it's on 666!\n");
        exit(EXIT_FAILURE);
    }
    show_file(file);
    fprintf(file, "I LOVE YOU!!!!!!\n");

    rewind(file);
    show_file(file);

    if(fclose(file) == EOF) {
        fprintf(stderr, "I fucking knew it!\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
