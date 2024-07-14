#include <stdio.h>

#define MAX_SIZE 10
#define ERROR_INPUT 1
#define SINGLE_MATRIX 2
#define NOT_SQUARE 3
#define NO_NECHET 4
#define SUCCESS 0

int enter_matrix(int a[MAX_SIZE][MAX_SIZE], size_t *row, size_t *col);
int find_elements(int a[MAX_SIZE][MAX_SIZE], size_t row, int *sr_ar);

int main(void)
{
    int a[MAX_SIZE][MAX_SIZE];
    size_t row, col;
    int sr_ar;
    int res_ent, res;
    res_ent = enter_matrix(a, &row, &col);
    if (res_ent != SUCCESS)
    {
        return res_ent;
    }
    res = find_elements(a, row, &sr_ar);
    if (res == 0)
    {
        printf("Average equals %d\n", sr_ar);
    }
    else 
    {
        return NO_NECHET;
    }
    return SUCCESS;
}

int enter_matrix(int a[MAX_SIZE][MAX_SIZE], size_t *row, size_t *col)
{
    printf("Enter rows: ");
    if (scanf("%zu", row) != 1 || *row == 0 || *row > MAX_SIZE)
    {
        printf("Error input\n");
        return ERROR_INPUT;
    }

    printf("Enter cols: ");
    if (scanf("%zu", col) != 1 || *col == 0 || *col > MAX_SIZE)
    {
        printf("Error input\n");
        return ERROR_INPUT;
    }

    if (*row == 1 && *col == 1)
    {
        printf("This is a single matrix\n");
        return SINGLE_MATRIX;
    }

    if (*row != *col)
    {
        printf("Not a square matrix\n");
        return NOT_SQUARE;
    }

    printf("Enter elements:\n");
    for (size_t i = 0; i < *row; i++)
    {
        for(size_t j = 0; j < *col; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
            {
                printf("Wrong element\n");
                return ERROR_INPUT;
            }
        }
    }
    return SUCCESS;
}

int find_elements(int a[MAX_SIZE][MAX_SIZE], size_t row, int *sr_ar)
{
    *sr_ar = 0;
    int count = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = i + 1; j < row; j++)
        {
            if (a[i][j] % 2 != 0)
            {
                *sr_ar += a[i][j];
                count++;
            }
        }
    }
    if (count == 0)
    {
        printf("Odd elements are missing\n");
        return NO_NECHET;
    }
    *sr_ar /= count;
    return SUCCESS;
}