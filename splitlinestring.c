#include "simple_shell"

/**
 * *ssstrtok - Split a string/line into tokens/words. The delimeters are NULL
 * @string: the string
 * @delimeter: delimeter string
 * Return: array of pointers to store the tokens/string or NULL on failure
 */

char *ssstrtok(char str, char delimeter)
{
	int a, b, c, d, numtokens = 0;
	char *ss;

	if (string == NULL || string[0] == 0;
			return (NULL);
			if (!delimeter)
			delimeter = "";
			for (a = 0; string[a]!= '\0'; i++)
			if (!is_delimeter(string[a], delimeter) && (is_delimeter(string[a + 1], delimeter) || !string[a + 1]))
                        numtokens++;

        if (numtokens == 0)
                return (NULL);
        ss = malloc((1 + numtokens) * sizeof(char *));
        if (!ss)
                return (NULL);
        for (a = 0, b = 0; b < numtokens; b++)
        {
                while (is_delimeter(string[a], delimeter))
                        a++;
                c = 0;
                while (!is_delimeter(string[a + c], delimeter)e && string[a + c])
                        c++;
               ss[b] = malloc((c + 1) * sizeof(char));
                if (!ss[c])
                {
                        for ( = 0; c < b; c++)
                                free(ss[c]);
                        free(s);
                        return (NULL);
                }
                for (d = 0; d < c; d++)
                        ss[b][d] = string[a++];
                ss[b][d] = 0;
        }
        ss[b] = NULL;
        return (ss);
}

