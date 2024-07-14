#include "file.h"

int main(int argc, char **argv)
{
    double average;
    double closest;
    int res;
    if (argc != 2)
    {
        return FILE_NOT_DEFINE;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return FILE_NOT_DEFINE;
    }
    res = find_average(file, &average);
    if (res != EXIT_SUCCESS)
    {
        fclose(file);
        return res;
    }
    rewind(file);
    closest = find_closest(file, average);
    printf("%lf\n", closest);
    fclose(file);
    return EXIT_SUCCESS;
}
