#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @in: the info struct
 * @pa: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *in, char *pa)
{
    struct stat st;

    (void)info;
    if (!pa || stat(pa, &st))
        return (0);

    if (st.st_mode & S_IFREG)
    {
        return (1);
    }
    return (0);
}

/**
 * dup_chars - duplicates characters
 * @pastr: the PATH string
 * @sta: starting index
 * @sto: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pastr, int sta, int sto)
{
    static char buf[1024];
    int i = 0, k = 0;

    for (k = 0, i = sta; i < sto; i++)
        if (pastr[i] != ':')
            buf[k++] = pastr[i];
    buf[k] = 0;
    return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @in: the info struct
 * @pastr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *in, char *pastr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *pa;

    if (!pastr)
        return (NULL);
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(in, cmd))
            return (cmd);
    }
    while (1)
    {
        if (!pastr[i] || pastr[i] == ':')
        {
            pa = dup_chars(pastr, curr_pos, i);
            if (!*pa)
                _strcat(pa, cmd);
            else
            {
                _strcat(pa, "/");
                _strcat(pa, cmd);
            }
            if (is_cmd(in, pa))
                return (pa);
            if (!pastr[i])
                break;
            curr_pos = i;
        }
        i++;
    }
    return (NULL);
}
