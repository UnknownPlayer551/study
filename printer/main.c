#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define LEN 6
static int
compare_func(const void *x, const void *y)
{
    const int32_t *p_x = (const int32_t *) x;
    const int32_t *p_y = (const int32_t *) y;

    if(*p_x < *p_y) return -1;
    if(*p_x > *p_y) return 1;
    return 0;
}

static void
print_array(const void *data, const size_t nmemb, const size_t size, void (*p)(const void *))
{
    size_t i;

    for(i = 0; i < nmemb; i++) {
        (*p)(data + (i*size));
    }
    puts("");
}

static void
formatter(const void *data)
{
    const int32_t *p_data = (const int32_t *) data;
    printf(" [%" PRId32 "] ", *p_data);
}

int
main(void)
{
    int32_t data[LEN] = {1, 3, 5, 2, 4, 6};
    printf("Res: %zu\n", sizeof data);

    print_array(data, LEN, sizeof(*data), formatter);
    qsort(data, LEN, sizeof(*data), compare_func);
    print_array(data, LEN, sizeof(*data), formatter);
    return 0;
}
