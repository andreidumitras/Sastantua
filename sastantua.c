#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c);

void    pune(char c, int cate)
{
    while (cate--)
        ft_putchar(c);
}

void    rand(int *spatii, int *x)
{
    pune(' ', *spatii);
    pune('/', 1);
    pune('*', *x);
    pune('\\', 1);
    pune('\n', 1 );
    (*spatii)--;
    (*x) += 2;
}

void    baza(int spatii, int size, int x, int usa)
{
    int     j;

    j = 2;
    if (size % 2 == 0)
        j++;
    while (j--)
        rand(&spatii, &x);
    j = usa;
    while (j--)
    {
        pune(' ', spatii);
        pune('/', 1);
        pune('*', (x - usa) / 2);
        if (usa >= 5 && j == usa / 2)
        {
            pune('|', usa - 2);
            pune('$', 1);
            pune('|', 1);
        }
        else
            pune('|', usa);
        pune('*', (x - usa) / 2);
        pune('\\', 1);
        pune('\n', 1);
        x += 2;
        spatii--;
    }
}

void    desenare(int spatii, int size, int usa)
{
    int     i;
    int     x;
    int     j;

    i = 1;
    x = 1;
    while (i < size)
    {
        j = i + 2;
        while (j--)
            rand(&spatii, &x);
        i++;
        spatii -= i / 2 + 1;
        x += (i / 2 + 1) * 2;
    }
    baza(spatii, size, x, usa);
}

void    sastantua(int size)
{
    int     spatii;
    int     linii   ;
    int     margine;
    int     size1;
    int     usa;

    size1 = size;
    margine = 0;
    linii = 0;
    usa = size;
    if (size % 2 == 0)
        usa--;
    while (size1)
    {
        linii += size1 + 2;
        if (size1 > 1)
            margine += size1 / 2 + 1;
        size1--;
    }
    spatii = linii + margine - 1;
    desenare(spatii, size, usa);
}
