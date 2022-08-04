#include "palindrome.h"

/**
 * is_palindrome - checks if a unsined long int is a palindrome
 * @n: number to be checked
 * Return: 1 if palindrome, otherwise 0
 */

int is_palindrome(unsigned long n)
{

    unsigned long reverse = 0;
    unsigned long num = n;
    unsigned long last = 0;

    while (n != 0)
        {
        last = n % 10;
        reverse = reverse * 10 + last;
        n /= 10;
        }

    if (reverse == num)
        return 1;
return 0;
}