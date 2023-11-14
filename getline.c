#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @mexinfo: the parameter structure
 * @dexbuf: the address of buffer
 * @dexlen: the accurate address of len var
 *
 * Return: bytes read or 0 on success
 *
ssize_t input_buf(info_t *mexinfo, char *dexbuf, size_t *dexlen)
{
	ssize_t r = 0;
	size_t dexlen_p = 0;

	if (!*dexlen) * if there is no other thing in the buffer, fill it *
	{
		*bfree((void **)mexinfo->cmd_buf);*
		free(*dexbuf);
		*dexbuf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(dexbuf, &dexlen_p, stdin);
#else
		r = _getline(mexinfo, dexbuf, &dexlen_p);
#endif
		if (r > 0)
		{
			if ((*dexbuf)[r - 1] == '\n')
			{
				(*dexbuf)[r - 1] = '\0'; * will remove trailing whitespaces *
				r--;
			}
			mexinfo->linecount_flag = 1;
			remove_comments(*dexbuf);
			build_history_list(mexinfo, *dexbuf, mexcinfo->histcount++);
			* if (_strchr(*dexbuf, ';')) is this a command chain? *
			{
				*dexlen = r;
				mexinfo->cmd_dexbuf = dexbuf;
			}
		}
	}
	return (r);
}

**
 * get_input - will get a new line
 * @mexinfo: the mexinfo parameter structure
 *
 * Return: the bytes read
 *
ssize_t get_input(info_t *mexinfo)
{
	static char *dexbuf; * the ';' command chain buffer *
	static size_t a, b, dexlen;
	ssize_t r = 0;
	char **dexbuf_p = &(mexinfo->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_dexbuf(mexinfo, &dexbuf, &dexlen);
	if (r == -1) * EOF *
		return (-1);
	if (dexlen)	* we still have some commands remaining in the chain buffer *
	{
		a = b; * init the new iterator to new dexbuf position *
		p = dexbuf + a; * will get pointer for the return *

		check_chain(mexinfo, dexbuf, &b, a, dexlen);
		while (b < dexlen) * will iterate to semicolon or end *
		{
			if (is_chain(mexinfo, dexbuf, &b))
				break;
			b++;
		}

		a = b + 1; * the increment past nulled ';'' *
		if (a >= dexlen) * will reach end of buffer? *
		{
			a = dexlen = 0; * will reset position also length *
			mexinfo->cmd_dexbuf_type = CMD_NORM;
		}

		*dexbuf_p = p; * will cross the back pointer to a new command position *
		return (_strlen(p)); * return the correct length of current command *
	}

	*dexbuf_p = dexbuf; * else not a chain, just pass back buffer from _getline() *
	return (r); * return the length of buffer from _getline() *
}

**
 * reads_buf - will read a buffer
 * @mexinfo: the parameter structure
 * @dexbuf: the buffer
 * @a: the size
 *
 * Return: r
 *
ssize_t reads_buf(info_t *mexinfo, char *dexbuf, size_t *a)
{
	ssize_t r = 0;

	if (*a)
		return (0);
	r = read(info->readfd, dex buf, READ_BUF_SIZE);
	if (r >= 0)
		*a = r;
	return (r);
}

**
 * _getline - will get the next available line of input from STDIN
 * @mexinfo: the parameter structure
 * @dexptr: the address of the pointer to buffer, preallocated or will be NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 *
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char dexbuf[READ_BUF_SIZE];
	static size_t a, dexlen;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *dexptr;
	if (p && length)
		s = *length;
	if (a == len)
		a = dexlen = 0;

	r = reads_buf(mexinfo, dex buf, &dexlen);
	if (r == -1 || (r == 0 && dexlen == 0))
		return (-1);

	c = _strchr(dexbuf + a, '\n');
	k = c ? 1 + (unsigned int)(c - dexbuf) : dexlen;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) * MALLOC FAILURE! *
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, dexbuf + a, k - a);
	else
		_strncpy(new_p, dexbuf + a, k - a + 1);

	s += k - a;
	a = k;
	p = new_p;

	if (length)
		*length = s;
	*dexptr = p;
	return (s);
}

**
 * sigintHandler - will blocks ctrl-C
 * @signal_number: signal number
 *
 * Return: void
 *
void sigintHandler(__attribute__((unused))int signal_number)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
*/