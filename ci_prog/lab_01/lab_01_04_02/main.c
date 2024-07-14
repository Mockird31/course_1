/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Converting time from seconds to hours and minutes
 * @date 2024-02-14
 * @param[in] seconds Int time in seconds
 * @param[out] hours Int converted time
 * @param[out] munutes Int converted time
 * @param[out] seconds Int converted time
 */
#include <stdio.h>
#define TIME 60

int main(void)
{
    int seconds;
    printf("Vvedite vremya v sekundah: ");
    if (scanf("%d", &seconds) != 1 || seconds < 0)
    {
        printf("Input error\n");
        return 1;
    }

    int hours = 0, minutes = 0;
    if (seconds >= TIME)
    {
        minutes = seconds / TIME;
        seconds %= TIME;
    }
    if (minutes >= TIME)
    {
        hours = minutes / TIME;
        minutes %= TIME;
    }

    printf("hours: %d\nminutes: %d\nseconds: %d\n", hours, minutes, seconds);
    return 0;
}
