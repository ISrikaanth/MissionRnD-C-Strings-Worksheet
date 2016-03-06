/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void str_words_in_rev(char *input, int len)
{

	int i, j, k = 0, count = 0, l;
	for (i = len; i<100; i++)
		input[i] = '\0';
	for (i = len - 1; i >= 0; i--)
		input[i + len] = input[i];
	len = len + len;
	i = len - 1;
	while (i >= (len / 2))
	{
		while ((input[i] != ' ') && (i >= len / 2))
			i--;
		for (j = i + 1; (input[j] != ' ') && (input[j] != '\0'); j++)
		{
			input[k] = input[j];
			k++;
		}
		j = i;
		if (input[j] == ' ')
		{
			while (input[j] == ' ')
			{
				count++;
				j--;
			}
		}
		for (l = 0; l < count; l++)
		{
			input[k] = ' ';
			k++;
		}
		i = i - count;
		count = 0;
	}
	input[len / 2] = '\0';
}
