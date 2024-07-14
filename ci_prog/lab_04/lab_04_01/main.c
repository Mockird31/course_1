#include "tests.h"

int main(void)
{
    size_t fails = 0;
    fails += test_strpbrk();
    fails += test_strspn();
    fails += test_strcspn();
    fails += test_strchr();
    fails += test_strrchr();
    printf("%zu\n", fails);
    return SUCCESS;
}