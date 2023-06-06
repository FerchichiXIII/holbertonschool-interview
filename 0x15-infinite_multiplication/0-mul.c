#include "holberton.h"

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
    char *num1, *num2;

    if (argc != 3)
    {
        _putchar('E');
        _putchar('r');
        _putchar('r');
        _putchar('o');
        _putchar('r');
        _putchar('\n');
        return (98);
    }

    num1 = argv[1];
    num2 = argv[2];

    multiply(num1, num2);

    return (0);
}

/**
 * multiply - Multiply two positive numbers
 * @num1: First number
 * @num2: Second number
 */
void multiply(char *num1, char *num2)
{
    int len1, len2, len, i, j, k;
    char *result; /* Change data type to char* */
    int carry, n1, n2, sum;

    len1 = _strlen(num1);
    len2 = _strlen(num2);
    len = len1 + len2;
    result = malloc(sizeof(char) * (len + 1)); /* Allocate space for null terminator */
    if (result == NULL)
        exit(98);

    for (i = 0; i < len; i++)
        result[i] = '0'; /* Initialize result array with '0' */

    result[len] = '\0'; /* Add null terminator at the end */

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = num1[i] - '0';

        for (j = len2 - 1, k = len - len1 + i; j >= 0; j--, k--)
        {
            n2 = num2[j] - '0';
            sum = (n1 * n2) + (result[k] - '0') + carry;
            carry = sum / 10;
            result[k] = (sum % 10) + '0';
        }

        if (carry > 0)
            result[k] += carry;
    }

    _print_number(result);
    free(result);
}

void _print_number(char *number)
{
    int i, start;

    start = 0;

    for (i = 0; number[i] == '0' && number[i + 1]; i++)
        ;

    for (; i < _strlen(number); i++)
    {
        _putchar(number[i]);
        start = 1;
    }

    if (start == 0)
        _putchar('0');

    _putchar('\n');
}
/**
 * _strlen - Calculate the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;

    return (i);
}