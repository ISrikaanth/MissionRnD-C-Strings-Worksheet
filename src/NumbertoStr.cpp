/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal)
{
	int i = 0, a[20], temp, count = 0, j, k = 0, flag = 0;
	temp = number;
	if (number < 0)
	{
		number = -number;
		flag = 1;
	}
	while (number != temp)
	{
		count++;
		number = number * 10;
		temp = number;
	}
	while (temp != 0)
	{
		a[i] = temp % 10;
		i++;
		temp = temp / 10;
	}
	if (flag == 1)
	{
		str[k] = '-';
		k++;
	}
	for (j = i - 1; j >= count; j--)
	{
		str[k] = a[j] + '0';
		k++;
	}
	if (afterdecimal == 0)
	{
		str[k] = '\0';
		k++;
	}
	else
	{
		str[k] = '.';
		k++;
	}
	for (j = count - 1; j >= count - afterdecimal; j--)
	{
		str[k] = a[j] + '0';
		k++;
	}
}
