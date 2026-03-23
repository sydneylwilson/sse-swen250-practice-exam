#include <stdlib.h>
#include <string.h>
#include "cpractice.h"

#define BAD_PTR (int *)2

char *get_char_at_offset(char *str, int offset)
{
    if (str == NULL || offset < 0)
        return NULL;

    int len = strlen(str);

    if (offset >= len)
        return NULL;

    return str + offset;
}

int *compute_scaled_array(int *arr, int a, int c, int size)
{
    if (arr == NULL || size <= 0)
        return NULL;

    int *result = (int *)malloc(sizeof(int) * size);
    if (result == NULL)
        return NULL;

    int *src = arr;
    int *dst = result;
    int *end = arr + size;

    while (src < end)
    {
        *dst = a * (*src) + c;
        src++;
        dst++;
    }

    return result;
}

int sum_array_and_release(int *arr, int size)
{
    if (arr == NULL || arr == BAD_PTR || size <= 0)
        return 0;

    int sum = 0;
    int *ptr = arr;
    int *end = arr + size;

    while (ptr < end)
    {
        sum += *ptr;
        ptr++;
    }

    free(arr);

    return sum;
}

int pointer_equals(int *p1, int *p2)
{
    if (p1 == NULL || p2 == NULL)
        return 0;

    return (p1 == p2) ? 1 : 0;
}

int toggle_state()
{
    static int state = 1; // start so first return is 0

    state = !state;
    return state;
}

int repair_string(char *str)
{
    if (str == NULL || str[0] == '\0')
        return 0;

    str[0] = 'X';
    return 1;
}
