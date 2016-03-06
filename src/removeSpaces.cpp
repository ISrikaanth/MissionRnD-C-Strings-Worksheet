/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stddef.h>
char removeSpaces(char *str)
{
	if (str == NULL)
		return NULL;
	int i = 0, j, k, len;
	while (str[i] != '\0')
		i++;
	len = i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			break;
		i++;
	}
	if ((str[i] == '\0'))
		return '\0';
	for (j = 0; j < len; j++)
	{
		if (str[j] == ' ')
		{
			for (k = j; k < len - 1; k++)
				str[k] = str[k + 1];
			str[k] = '\0';
			if (str[j] == ' ')
				j--;
			i--;
		}
	}
	return '\0';
}