#include "file.h"

int get_number_by_pos(FILE *f, size_t pos, int *find_num)
{
    *find_num = 0;
    fseek(f, sizeof(int) * pos, SEEK_SET);
    fread(find_num, sizeof(int), 1, f);
    return EXIT_SUCCESS;
}

int put_number_by_pos(FILE *f, size_t pos, int num)
{
    fseek(f, sizeof(int) * pos, SEEK_SET);
    fwrite(&num, sizeof(int), 1, f);
    return EXIT_SUCCESS;
}

int generate_file(char *path, size_t len)
{
    if (len == 0)
    {
        return ERROR_EMPTY;
    }
    srand(time(NULL));
    FILE *file = fopen(path, "wb");
    if (!file)
    {
        return FILE_NOT_DEFINE;
    }
    for (size_t i = 0; i < len; i++)
    {
        int rand_num = rand() % 1000;
        put_number_by_pos(file, i, rand_num);
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int get_size_bin(char *path, size_t *len)
{
    FILE *file = fopen(path, "rb");
    if (!file)
        return FILE_NOT_DEFINE;
    if (fseek(file, 0L, SEEK_END))
    {
        return ERROR_SIZE;
    }
    *len = ftell(file);
    if (*len == 0)
    {
        return ERROR_EMPTY;
    }
    if (*len % sizeof(int) != 0)
    {
        return ERROR_SIZE;
    }
    return EXIT_SUCCESS;
}

int print_file(char *path, size_t len)
{
    len /= 4;
    FILE *file = fopen(path, "rb");
    if (!file)
    {
        return FILE_NOT_DEFINE;
    }
    int num;
    for (size_t i = 0; i < len; i++)
    {
        get_number_by_pos(file, i, &num);
        printf("%d ", num);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

int count_odd(FILE *file, size_t bin_len, int *counter_odd)
{
    *counter_odd = 0;
    int num = 0;
    for (size_t i = 0; i < bin_len; i++)
    {
        get_number_by_pos(file, i, &num);
        if (num % 2 != 0)
        {
            *counter_odd += 1;
        }
    }
    return EXIT_SUCCESS;
}

void shift_right(FILE *file, size_t start_pos, size_t size, size_t shift_by)
{
    int num;
    for (size_t i = size; i > start_pos; --i)
    {
        get_number_by_pos(file, i - 1, &num);
        put_number_by_pos(file, i - 1 + shift_by, num);
    }
}

int put_in_file(FILE *file, size_t *size, int odd_count)
{
    int num = 0;
    size_t i = 0;

    while (i < *size)
    {
        get_number_by_pos(file, i, &num);
        if (num % 2 == 0)
        {
            shift_right(file, i + 1, *size, 1);
            put_number_by_pos(file, i + 1, odd_count);
            (*size)++;
            i += 2;
        }
        else
        {
            i++;
        }
    }
    return EXIT_SUCCESS;
}

int main_func(char *path, size_t *len)
{
    (*len) /= 4;
    int counter_odd;
    FILE *file = fopen(path, "rb+");
    if (!file)
        return FILE_NOT_DEFINE;
    int res = count_odd(file, *len, &counter_odd);
    if (res != EXIT_SUCCESS)
        return res;
    fseek(file, 0, SEEK_SET);
    res = put_in_file(file, len, counter_odd);
    fclose(file);
    return EXIT_SUCCESS;
}
