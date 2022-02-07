#include <stdio.h>
#include "../ft_printf.h"
#include "tests.h"

char	**get_format_strings();

double	*get_double();
float	*get_float();
long double	*get_long_double();
char	*get_char();
char **get_string();
intmax_t *get_signed();
uintmax_t *get_unsigned();

int main()
{
	char	**double_strings = get_format_strings("lf");
	double *doubles = get_double();

	for (int i = 0; double_strings[i] != 0; i++)
	{
		for (int j = 0; doubles[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %lf: ", double_strings[i], doubles[j]);
			SOME_PRINTF("|");
			SOME_PRINTF(double_strings[i], doubles[j]);
			SOME_PRINTF("|\n");
		}
	}

	char	**float_strings = get_format_strings("f");
	float *floats = get_float();

	for (int i = 0; float_strings[i] != 0; i++)
	{
		for (int j = 0; floats[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %f: ", float_strings[i], floats[j]);
			SOME_PRINTF("|");
			SOME_PRINTF(float_strings[i], floats[j]);
			SOME_PRINTF("|\n");
		}
	}

	char	**long_double_strings = get_format_strings("Lf");
	long double *long_doubles = get_long_double();

	for (int i = 0; long_double_strings[i] != 0; i++)
	{
		for (int j = 0; long_doubles[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %Lf: ", long_double_strings[i], long_doubles[j]);
			SOME_PRINTF("|");
			SOME_PRINTF(long_double_strings[i], long_doubles[j]);
			SOME_PRINTF("|\n");
		}
	}

	char	**char_strings = get_format_strings("c");
	char *chars = get_char();

	for (int i = 0; char_strings[i] != 0; i++)
	{
		for (int j = 0; chars[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %c: ", char_strings[i], chars[j]);
			SOME_PRINTF("|");
			SOME_PRINTF(char_strings[i], chars[j]);
			SOME_PRINTF("|\n");
		}
	}

	char	**string_strings = get_format_strings("s");
	char **strings = get_string();

	for (int i = 0; string_strings[i] != 0; i++)
	{
		for (int j = 0; strings[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %s: ", string_strings[i], strings[j]);
			SOME_PRINTF("|");
			SOME_PRINTF(string_strings[i], strings[j]);
			SOME_PRINTF("|\n");
		}
	}

	char	**signed_strings = get_format_strings("d");
	intmax_t *signeds = get_signed();

	for (int i = 0; signed_strings[i] != 0; i++)
	{
		for (int j = 0; signeds[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %d: ", signed_strings[i], (int) signeds[j]);
			SOME_PRINTF("|");
			SOME_PRINTF(signed_strings[i], signeds[j]);
			SOME_PRINTF("|\n");
		}
	}

	char	**unsigned_strings = get_format_strings("u");
	uintmax_t *unsigneds = get_unsigned();

	for (int i = 0; unsigned_strings[i] != 0; i++)
	{
		for (int j = 0; unsigneds[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %u: ", unsigned_strings[i], (int) unsigneds[j]);
			SOME_PRINTF("|");
			SOME_PRINTF(unsigned_strings[i], unsigneds[j]);
			SOME_PRINTF("|\n");
		}
	}
}