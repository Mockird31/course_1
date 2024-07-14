#include "file.h"

int main(int argc, char **argv)
{
    int res = EXIT_FAILURE;
    if (argc < 2)
        return 1;
    if (argc > 4)
        return 1;
    if (*argv[1] == 'c' && argc == 4)
        res = generate_file(argv[3], atoi(argv[2]));
    else if (*argv[2] == 'c' && argc == 4)
        res = generate_file(argv[3], atoi(argv[1]));
    else if (*argv[1] == 'p' && argc == 3)
        res = print_file(argv[2]);
    else if (*argv[1] == 's' && argc == 3)
        res = sorted_file(argv[2]);
    else if (strcmp(argv[1], "import") == 0)
        res = from_text_to_bin(argv[2], argv[3]);
    else if (strcmp(argv[1], "export") == 0)
        res = from_bin_to_text(argv[2], argv[3]);
    return res;
}
