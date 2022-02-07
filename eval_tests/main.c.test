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
char	**get_lengths();
char	**get_di();
char	**get_oux();

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
			SOME_PRINTF("%d ", SOME_PRINTF(double_strings[i], doubles[j]));
			SOME_PRINTF("|\n");
		}
		SOME_PRINTF("format string is %s, value is %lf: ", double_strings[i], 0);
		SOME_PRINTF("|");
		SOME_PRINTF("%d ", SOME_PRINTF(double_strings[i], 0));
		SOME_PRINTF("|\n");
	}

	char	**float_strings = get_format_strings("f");
	float *floats = get_float();

	for (int i = 0; float_strings[i] != 0; i++)
	{
		for (int j = 0; floats[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %f: ", float_strings[i], floats[j]);
			SOME_PRINTF("|");
			SOME_PRINTF("%d ", SOME_PRINTF(float_strings[i], floats[j]));
			SOME_PRINTF("|\n");
		}
		SOME_PRINTF("format string is %s, value is %f: ", float_strings[i], 0);
		SOME_PRINTF("|");
		SOME_PRINTF("%d ", SOME_PRINTF(float_strings[i], 0));
		SOME_PRINTF("|\n");
	}

	char	**long_double_strings = get_format_strings("Lf");
	long double *long_doubles = get_long_double();

	for (int i = 0; long_double_strings[i] != 0; i++)
	{
		for (int j = 0; long_doubles[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %Lf: ", long_double_strings[i], long_doubles[j]);
			SOME_PRINTF("|");
			SOME_PRINTF("%d ", SOME_PRINTF(long_double_strings[i], long_doubles[j]));
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
			SOME_PRINTF("%d ", SOME_PRINTF(char_strings[i], chars[j]));
			SOME_PRINTF("|\n");
		}
		SOME_PRINTF("format string is %s, value is %c: ", char_strings[i], NULL);
		SOME_PRINTF("|");
		SOME_PRINTF("%d ", SOME_PRINTF(char_strings[i], NULL));
		SOME_PRINTF("|\n");
	}

	char	**string_strings = get_format_strings("s");
	char **strings = get_string();

	for (int i = 0; string_strings[i] != 0; i++)
	{
		for (int j = 0; strings[j] != 0; j++)
		{
			SOME_PRINTF("format string is %s, value is %s: ", string_strings[i], strings[j]);
			SOME_PRINTF("|");
			SOME_PRINTF("%d ", SOME_PRINTF(string_strings[i], strings[j]));
			SOME_PRINTF("|\n");
		}
		SOME_PRINTF("format string is %s, value is %s: ", string_strings[i], NULL);
		SOME_PRINTF("|");
		SOME_PRINTF("%d ", SOME_PRINTF(string_strings[i], NULL));
		SOME_PRINTF("|\n");
	}

	char	**pointer_strings = get_format_strings("p");
	char	c = 'h';
	int		i = 5;

	for (int i = 0; pointer_strings[i] != 0; i++)
	{
			// SOME_PRINTF("format string is %s, value is %p: ", pointer_strings[i], &strlen);
			// SOME_PRINTF("|");
			// SOME_PRINTF(pointer_strings[i], &strlen);
			// SOME_PRINTF("|\n");
			SOME_PRINTF("format string is %s, value is %p: ", pointer_strings[i], NULL);
			SOME_PRINTF("|");
			SOME_PRINTF("%d ", SOME_PRINTF(pointer_strings[i], NULL));
			SOME_PRINTF("|\n");
	}

	intmax_t *signeds = get_signed();
	char	**lengths = get_lengths();
	char	*temp;
	char	**signed_strings;
	char	**di = get_di();

	for (int d = 0; di[d] != 0; d++)
	{
		for (int l = 0; lengths[l] != 0; l++)
		{
			temp = ft_strjoin(lengths[l], di[d]);
			signed_strings = get_format_strings(temp);
			
			for (int i = 0; signed_strings[i] != 0; i++)
			{
				for (int j = 0; signeds[j] != 0; j++)
				{
					SOME_PRINTF("format string is %s, value is %d: ", signed_strings[i], signeds[j]);
					SOME_PRINTF("|");
					SOME_PRINTF("%d ", SOME_PRINTF(signed_strings[i], signeds[j]));
					SOME_PRINTF("|\n");
				}
				SOME_PRINTF("format string is %s, value is %d: ", signed_strings[i], 0);
				SOME_PRINTF("|");
				SOME_PRINTF("%d ", SOME_PRINTF(signed_strings[i], 0));
				SOME_PRINTF("|\n");
			}
			free(temp);
			free(signed_strings);
		}
	}

	char	**unsigned_strings = get_format_strings("u");
	uintmax_t *unsigneds = get_unsigned();
	char	**oux = get_oux();

	for (int d = 0; oux[d] != 0; d++)
	{
		for (int l = 0; lengths[l] != 0; l++)
		{
			temp = ft_strjoin(lengths[l], oux[d]);
			unsigned_strings = get_format_strings(temp);
			
			for (int i = 0; unsigned_strings[i] != 0; i++)
			{
				for (int j = 0; unsigneds[j] != 0; j++)
				{
					SOME_PRINTF("format string is %s, value is %u: ", unsigned_strings[i], unsigneds[j]);
					SOME_PRINTF("|");
					SOME_PRINTF("%d ", SOME_PRINTF(unsigned_strings[i], unsigneds[j]));
					SOME_PRINTF("|\n");
				}
				SOME_PRINTF("format string is %s, value is %u: ", unsigned_strings[i], 0);
				SOME_PRINTF("|");
				SOME_PRINTF("%d ", SOME_PRINTF(unsigned_strings[i], 0));
				SOME_PRINTF("|\n");
			}
			free(temp);
			free(unsigned_strings);
		}
	}
}