#include "file.h"

int main(int argc, char **argv)
{
    int res = ERROR_ARGS;
    if (argc > 4)
        return ERROR_ARGS;
    if (argc < 3)
        return ERROR_ARGS;
    if (strcmp(argv[1], "st") == 0)
        res = sorting(argv[2], argv[3]);
    else if (strcmp(argv[1], "ft") == 0)
        res = print_endstr(argv[2], argv[3]);
    else if (strcmp(argv[1], "at") == 0)
        res = insert_in_file(argv[2]);
    return res;
}
