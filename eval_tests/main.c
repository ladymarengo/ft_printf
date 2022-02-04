#include <stdio.h>
#include "../ft_printf.h"
#include "tests.h"

char	**get_double_strings();
double	*get_double();
char	**get_float_strings();
float	*get_float();
char	**get_long_double_strings();
long double	*get_long_double();

int main()
{
	char	**double_strings = get_double_strings();
	double *doubles = get_double();
	char	*temp;

	for (int i = 0; double_strings[i] != 0; i++)
	{
		for (int j = 0; doubles[j] != 0; j++)
		{
			temp = strdup(double_strings[i]);
			temp[strlen(temp) - 1] = '\0';
			SOME_PRINTF("format string is %s: ", temp);
			SOME_PRINTF(double_strings[i], doubles[j]);
		}
	}

	char	**float_strings = get_float_strings();
	float *floats = get_float();

	for (int i = 0; float_strings[i] != 0; i++)
	{
		for (int j = 0; floats[j] != 0; j++)
		{
			temp = strdup(float_strings[i]);
			temp[strlen(temp) - 1] = '\0';
			SOME_PRINTF("format string is %s: ", temp);
			SOME_PRINTF(float_strings[i], floats[j]);
		}
	}

	char	**long_double_strings = get_long_double_strings();
	long double *long_doubles = get_long_double();

	for (int i = 0; long_double_strings[i] != 0; i++)
	{
		for (int j = 0; long_doubles[j] != 0; j++)
		{
			temp = strdup(long_double_strings[i]);
			temp[strlen(temp) - 1] = '\0';
			SOME_PRINTF("format string is %s, value is %Lf: ", temp, long_doubles[j]);
			SOME_PRINTF(long_double_strings[i], long_doubles[j]);
		}
	}
}