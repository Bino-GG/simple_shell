#include "shell.h"

/**
 * _strcpy - copies a string
 * @d: the destination
 * @sr: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *d, char *sr)
{
    int i = 0;

    if (d == sr || sr == 0)
        return (d);
    while (sr[i])
    {
        d[i] = sr[i];
        i++;
    }
    d[i] = 0;
    return (d);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
    int l = 0;
    char *r;

    if (str == NULL)
        return (NULL);
    while (*str++)
        l++;
    r = malloc(sizeof(char) * (l + 1));
    if (!r)
        return (NULL);
    for (l++; l--;)
        r[l] = *--str;
    return (r);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }
}

/**
 * _putchar - writes the character c to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char ch)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(1, buf, i);
        i = 0;
    }
    if (ch != BUF_FLUSH)
        buf[i++] = ch;
    return (1);
}
