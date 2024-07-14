#include "file.h"

int main(int argc, char **argv)
{
    int res = 0;
    size_t len = 0;
    if (*argv[1] == 'c' && argc == 4)
    {
        res = generate_file(argv[2], atoi(argv[3]));
    }
    else if (*argv[1] == 'p' && argc == 3)
    {
        get_size_bin(argv[2], &len);
        res = print_file(argv[2], len);
    }
    else if (*argv[1] == 'i' && argc == 3)
    {
        get_size_bin(argv[2], &len);
        res = main_func(argv[2], &len);
    }
    return res;
}
