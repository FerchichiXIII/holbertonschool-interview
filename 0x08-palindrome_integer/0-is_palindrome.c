#include "palindrome.h"

/**
 * is_palindrome - checks whether or not
 * @n: long
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0, remainder, original = n;

    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    return (original == reversed ? 1 : 0);
}
