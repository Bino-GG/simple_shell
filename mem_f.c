#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        s[i] = b;
    return (s);
}

/**
 * ffree - frees a string of strings
 * @p: string of strings
 */
void ffree(char **p)
{
    char **a = p;

    if (!p)
        return;
    while (*p)
        free(*p++);
    free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @pp: pointer to previous malloc'ated block
 * @os: byte size of previous block
 * @ns: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *pp, unsigned int os, unsigned int ns)
{
    char *p;

    if (!pp)
        return (malloc(ns));
    if (!ns)
        return (free(pp), NULL);
    if (ns == os)
        return (pp);

    p = malloc(ns);
    if (!p)
        return (NULL);

    os = os < ns ? os : ns;
    while (os--)
        p[os] = ((char *)pp)[os];
    free(pp);
    return (p);
}
