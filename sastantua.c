/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:29:00 by adumitra          #+#    #+#             */
/*   Updated: 2023/09/12 19:57:23 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// link the function ft_putchar implemented in another file.
void ft_putchar(char c);

// it places a certain character c, for an amount of "cate"
void pune(char c, int cate)
{
    while (cate--)
        ft_putchar(c);
}

// it places a line with an amount of spaces ' ' and stars '*'
// it uses pointers to change the reference values provided as parameters
void rand(int *spatii, int *x)
{
    pune(' ', *spatii); `       // place spaces
    pune('/', 1);               // place '/'
    pune('*', *x);              // place stars
    pune('\\', 1);              // place '\'
    pune('\n', 1 );             // place a new line
    // after each line placed, the number of spaces decreases
    (*spatii)--;
    // after each line placed, the number of stars increases by 2
    (*x) += 2;
}

// it places the base of the pyramic
// the base a special block which has a dor, and the dor will have a doorknob after size 5.
void baza(int spatii, int size, int x, int usa)
{
    int j;

    // place the first lines which contains only stars
    j = 2;
    // initialiy the base has 2 lines containing stars.
    // if size is even, it will have 3 lines containing stars
    if (size % 2 == 0)
        j++;
    // place the lines containing stars
    while (j--)
        rand(&spatii, &x);

    // "usa" is the size of the door
    j = usa;
    // place the lines containing the door
    while (j--)
    {
        pune(' ', spatii);
        pune('/', 1);
        pune('*', (x - usa) / 2);
        // if the door has size grater than 5, it will have a doorknob in the middle of the door
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
        // increase the star number with 2
        x += 2;
        // decrease the spaces number with 1
        spatii--;
    }
}

// it controls the drawing of the pyramid
void desenare(int spatii, int size, int usa)
{
    int i;
    int x;
    int j;

    i = 1;
    x = 1;
    // looping through the pyramid's upper blocks, excluding the base
    while (i < size)
    {
        // compute the number of lines that construct the block
        j = i + 2;
        // place the amount of lines, modifying the number of spaces and stars
        while (j--)
            rand(&spatii, &x);
        i++;
        // update the number of spaces to correspond for the new block size.
        spatii -= i / 2 + 1;
        // update the number of stars to correspond for the new block size.
        x += (i / 2 + 1) * 2;
    }
    baza(spatii, size, x, usa);
}

// the main function that handles the drawing process
void sastantua(int size)
{
    int spatii;         // the amount of spaces for the peak
    int linii;          // the amount of lines of the pyramid
    int margine;        // the amount of stars corresponding to the first edge
    int size1;          // a copy for the initial size
    int usa;            // the size of the door

    // initialization
    size1 = size;
    margine = 0;
    linii = 0;
    usa = size;
    // if the size is even, the door is smaller with 1 line
    if (size % 2 == 0)
        usa--;

    // computing the number of lines and the number of spaces to be drawn
    while (size1)
    {
        linii += size1 + 2;
        if (size1 > 1)
            margine += size1 / 2 + 1;
        size1--;
    }
    // number of spaces is function of lines and total border size - 1
    spatii = linii + margine - 1;
    // draw the pyramid
    desenare(spatii, size, usa);
}
