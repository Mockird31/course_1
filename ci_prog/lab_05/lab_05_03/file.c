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
        int rand_num = rand() % RAND_VAR;
        put_number_by_pos(file, i, rand_num);
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int get_size_bin(FILE *file, size_t *len)
{
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

int print_file(char *path)
{
    FILE *file = fopen(path, "rb");
    if (!file)
    {
        return FILE_NOT_DEFINE;
    }
    int num;
    size_t len;
    int res = get_size_bin(file, &len);
    len /= sizeof(int);
    if (res != EXIT_SUCCESS)
    {
        fclose(file);
        return res;
    }
    for (size_t i = 0; i < len; i++)
    {
        get_number_by_pos(file, i, &num);
        printf("%d ", num);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

int sorted_file(char *path)
{
    FILE *file = fopen(path, "r+b");
    if (!file)
        return FILE_NOT_DEFINE;
    size_t len;
    int res = get_size_bin(file, &len);
    if (res != EXIT_SUCCESS)
    {
        fclose(file);
        return EXIT_FAILURE;
    }
    len /= sizeof(int);
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = len - 1; j > i; j--)
        {
            int num1, num2;
            get_number_by_pos(file, j - 1, &num1);
            get_number_by_pos(file, j, &num2);
            if (num1 > num2)
            {
                put_number_by_pos(file, j - 1, num2);
                put_number_by_pos(file, j, num1);
            }
        }
    }
    return EXIT_SUCCESS;
}

int from_bin_to_text(char *path_bin, char *path_txt)
{
    FILE *file_bin = fopen(path_bin, "rb");
    FILE *file_txt = fopen(path_txt, "w");
    if (!file_bin || !file_txt)
    {
        return FILE_NOT_DEFINE;
    }
    size_t len;
    int res = get_size_bin(file_bin, &len);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    len /= sizeof(int);
    for (size_t i = 0; i < len; i++)
    {
        int num;
        get_number_by_pos(file_bin, i, &num);
        fprintf(file_txt, "%d ", num);
    }
    fclose(file_bin);
    fclose(file_txt);
    return EXIT_SUCCESS;
}

int from_text_to_bin(char *path_txt, char *path_bin)
{
    FILE *file_txt = fopen(path_txt, "r");
    FILE *file_bin = fopen(path_bin, "wb");
    if (!file_bin || !file_txt)
    {
        return FILE_NOT_DEFINE;
    }
    size_t len;
    int num;
    int res = get_size_txt(file_txt, &len);
    rewind(file_txt);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    for (size_t i = 0; i < len; i++)
    {
        if (fscanf(file_txt, "%d", &num) == 1)
        {
            fwrite(&num, sizeof(int), 1, file_bin);
        }
    }
    fclose(file_txt);
    fclose(file_bin);
    return EXIT_SUCCESS;
}

int get_size_txt(FILE *file, size_t *len)
{
    rewind(file);
    *len = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1)
    {
        *len += 1;
    }
    if (*len == 0)
    {
        return ERROR_EMPTY;
    }
    return EXIT_SUCCESS;
}
