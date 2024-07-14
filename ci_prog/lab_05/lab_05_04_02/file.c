#include "file.h"

int get_len(FILE *file, size_t *len)
{
    rewind(file);
    *len = 0;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, file) != NULL)
    {
        *len += 1;
    }
    if (*len == 0)
    {
        fclose(file);
        return ERROR_EMPTY;
    }
    *len /= NUM_OF_FIELDS;
    return EXIT_SUCCESS;
}

size_t read_products(char *path, product_t products[], size_t *len)
{
    FILE *file = fopen(path, "r");
    if (!file)
        return FILE_NOT_DEFINED;
    int res = get_len(file, len);
    if (res != EXIT_SUCCESS)
        return res;
    rewind(file);
    for (size_t i = 0; i < *len; i++)
    {
        if (fgets(products[i].name, MAX_NAME + 1, file) != NULL)
            products[i].name[strcspn(products[i].name, "\n")] = 0;

        if (fgets(products[i].maker, MAX_MAKER + 1, file) != NULL)
            products[i].maker[strcspn(products[i].maker, "\n")] = 0;

        if (fscanf(file, "%u\n", &products[i].price) != EXIT_FAILURE)
            return EXIT_FAILURE;
        if (fscanf(file, "%u\n", &products[i].quantity) != EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int write_products(char *path, product_t products[], size_t len)
{
    FILE *file = fopen(path, "w");
    if (!file)
        return FILE_NOT_DEFINED;
    for (size_t i = 0; i < len; i++)
    {
        product_t prod = products[i];
        fprintf(file, "%s\n%s\n%u\n%u\n", prod.name, prod.maker, prod.price, prod.quantity);
    }
    fclose(file);
    return EXIT_SUCCESS;
}

void compare_by_price(product_t products[], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = len - 1; j > i; j--)
        {
            product_t p1 = products[j - 1];
            product_t p2 = products[j];
            if ((p1.price < p2.price) || (p1.price == p2.price && p1.quantity < p2.quantity))
            {
                product_t temp = products[j - 1];
                products[j - 1] = products[j];
                products[j] = temp;
            }
        }
    }
}

int sorting(char *path_src, char *path_dst)
{
    size_t len;
    int res1, res2;
    product_t products[MAX_PRODUCTS];
    res1 = read_products(path_src, products, &len);
    if (res1 != EXIT_SUCCESS)
    {
        return res1;
    }
    compare_by_price(products, len);
    res2 = write_products(path_dst, products, len);
    if (res2 != EXIT_SUCCESS)
    {
        return res2;
    }
    return EXIT_SUCCESS;
}

int print_prep_data(char *path, char *substr, product_t products[], size_t len)
{
    if (strlen(substr) == 0)
        return ERROR_ARGS;
    FILE *file = fopen(path, "r");
    if (!file)
        return FILE_NOT_DEFINED;
    size_t offset;
    size_t count = 0;
    char *endstr;
    for (size_t i = 0; i < len; i++)
    {
        product_t prod = products[i];
        offset = strlen(prod.name) - strlen(substr);
        endstr = prod.name + offset;
        if (strcmp(endstr, substr) == 0)
        {
            printf("%s\n%s\n%u\n%u\n", prod.name, prod.maker, prod.price, prod.quantity);
            count++;
        }
    }
    if (count == 0)
    {
        fclose(file);
        return ERROR_EMPTY;
    }
    return EXIT_SUCCESS;
}

int print_endstr(char *path, char *substr)
{
    product_t products[MAX_PRODUCTS];
    size_t len;
    int res1, res2;
    res1 = read_products(path, products, &len);
    if (res1 != EXIT_SUCCESS)
    {
        return res1;
    }
    res2 = print_prep_data(path, substr, products, len);
    if (res2 != EXIT_SUCCESS)
    {
        return res2;
    }
    return EXIT_SUCCESS;
}

int get_info_about_prod(product_t *prod)
{
    if (fgets(prod->name, MAX_NAME + 1, stdin) != NULL)
        prod->name[strcspn(prod->name, "\n")] = 0;
    else
        return ERROR_INPUT;
    if (fgets(prod->maker, MAX_MAKER + 1, stdin) != NULL)
        prod->maker[strcspn(prod->maker, "\n")] = 0;
    else
        return ERROR_INPUT;
    if (fscanf(stdin, "%u", &prod->price) == EOF)
        return EXIT_FAILURE;
    if (fscanf(stdin, "%u", &prod->quantity) == EOF)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int insert_in_file(char *path)
{
    product_t products[MAX_PRODUCTS];
    product_t input_prod;
    size_t len;
    int res = read_products(path, products, &len);
    if (res != EXIT_SUCCESS)
        return res;
    res = get_info_about_prod(&input_prod);
    if (res != EXIT_SUCCESS)
        return res;
    size_t index = len;
    for (size_t i = 0; i <= len - 1; i++)
    {
        product_t temp = products[i];
        if ((temp.price < input_prod.price) || (temp.price == input_prod.price && temp.quantity < input_prod.quantity))
        {
            index = i;
            break;
        }
    }
    for (size_t i = len; i > index; i--)
        products[i] = products[i - 1];
    products[index] = input_prod;
    res = write_products(path, products, len + 1);
    if (res != EXIT_SUCCESS)
        return ERROR_DATA;
    return EXIT_SUCCESS;
}
