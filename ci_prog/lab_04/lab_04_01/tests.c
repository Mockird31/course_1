#include "tests.h"

int test_strpbrk()
{
    size_t fails = 0;
    char s1[MAX_STR] = "Hello, world!";
    char s2[MAX_STR] = "lheo";
    if (my_strpbrk(s1, s2) != strpbrk(s1, s2))
    {
        fails++;
    }
    strcpy(s1, "Hello, world");
    strcpy(s2, "1234");
    if (my_strpbrk(s1, s2) != strpbrk(s1, s2))
    {
        fails++;
    }
    return fails;
}

int test_strspn()
{
    size_t fails = 0;
    char s1[MAX_STR] = "j1241-й2год";
    char s2[MAX_STR] = "12345j67890";
    if (my_strspn(s1, s2) != strspn(s1, s2))
    {
        fails++;
    }
    strcpy(s1, "Hello, world");
    strcpy(s2, "1234");
    if (my_strspn(s1, s2) != strspn(s1, s2))
    {
        fails++;
    }
    return fails;
}

int test_strcspn()
{
    size_t fails = 0;
    char s1[MAX_STR] = "blabla_l";
    char s2[MAX_STR] = "123456789";
    if (my_strcspn(s1, s2) != strcspn(s1, s2))
    {
        fails++;
    }
    strcpy(s1, "Hello, world");
    strcpy(s2, "1234");
    if (my_strcspn(s1, s2) != strcspn(s1, s2))
    {
        fails++;
    }
    return fails;
}

int test_strchr()
{
    size_t fails = 0;
    char s1[MAX_STR] = "lasflalsf1laflsa1fa";
    if (strchr(s1, '1') != my_strchr(s1, '1'))
    {
        fails++;
    }
    if (strchr(s1, '3') != my_strchr(s1, '3'))
    {
        fails++;
    }
    return fails;
}

int test_strrchr()
{
    size_t fails = 0;
    char s1[MAX_STR] = "lasflalsf1laflsa1fa";
    if (strrchr(s1, '1') != my_strrchr(s1, '1'))
    {
        fails++;
    }
    if (strrchr(s1, '5') != my_strrchr(s1, '5'))
    {
        fails++;
    }
    return fails;
}
