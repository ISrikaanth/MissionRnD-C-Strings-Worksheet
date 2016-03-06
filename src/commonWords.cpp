/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>
#define SIZE 31
int strcompare(char *str1, char *str2, int i, int j, int k, int l);
char ** commonWords(char *str1, char *str2)
{
	if ((str1 == NULL) || (str2 == NULL))
		return NULL;
	char *s[100];
	int i = 0, j = 0, a[50], b[50], k = 1, l = 1, m, e = 0, p = 0, x = 0, y = 0;
	a[0] = 0; b[0] = 0;
	while (str1[i] != 0)
	{
		if (str1[i] == ' ')
		{
			a[k] = i - 1;
			a[k + 1] = i + 1;
			k += 2;
		}
		i++;
	}
	a[k] = i - 1;
	k++;
	i = 0;
	while (str2[i] != 0)
	{
		if (str2[i] == ' ')
		{
			b[l] = i - 1;
			b[l + 1] = i + 1;
			l += 2;
		}
		i++;
	}
	b[l] = i - 1;
	l++;
	for (i = 0; i < k; i += 2)
	{
		for (j = 0; j < l; j += 2)
		{
			if ((strcompare(str1, str2, a[i], a[i + 1], b[j], b[j + 1]) == 1))
			{
				for (m = b[j]; m <= b[j + 1]; m++)
				{
					s[x][y] = str2[m];
					y++;
				}
				if (y>0)
				{
					s[x][y] = '\0';
					x++;
					y = 0;
					break;
				}
			}
		}
	}
	if ((x == 0) || (str1 == NULL) || (str2==NULL))
		return NULL;
	return s;
}
int strcompare(char *str1, char *str2, int i, int j, int k, int l)
{
	if ((j - i) != (l - k))
		return 0;
	while (i <= j)
	{
		if (str1[i] == str2[k])
		{
			i++;
			k++;
		}
		else
			break;
	}
	if (i > j)
		return 1;
	else
		return 0;
}
