#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @h: string to search
 * @n: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *h, const char *n)
{
	while (*n)
		if (*n++ != *h++)
			return (NULL);
	return ((char *)h);
}

/**
 * _strcat - concatenates two strings
 * @d: the destination buffer
 * @sr: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *d, char *sr)
{
	char *r = d;

	while (*d)
		d++;
	while (*sr)
		*d++ = *sr++;
	*d = *sr;
	return (r);
}
