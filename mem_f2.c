#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @pf: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **pf)
{
    if (pf && *pf)
    {
        free(*pf);
        *ptr = NULL;
        return (1);
    }
    return (0);
}
