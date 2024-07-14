#include "file.h"

int main(void)
{
    size_t pos;
    int res = process(stdin, &pos);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    printf("pos = %zu\n", pos);
    return EXIT_SUCCESS;
}
