
#include "lprintf.h"

int main(void)
{
    char *hidden;
    int i;
    char *str = ft_strdup("test");

    hidden = NULL;
    i = 0;
    while (i < 5)
    {
        ft_putchar_str(&hidden, 31);
        i++;
    }
    printf("%4.s", hidden);
}