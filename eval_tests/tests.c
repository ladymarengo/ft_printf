#include <stdlib.h>

char	**get_double_strings()
{
	char	**double_strings;

	double_strings = malloc(sizeof (char *) * 30);
	double_strings[0] = "|%lf|\n";
	double_strings[1] = "|%.1lf|\n";
	double_strings[2] = "|%10lf|\n";
	double_strings[3] = "|%-10lf|\n";
	double_strings[4] = "|%010lf|\n";
	double_strings[5] = "|%-010lf|\n";
	double_strings[6] = "|%#lf|\n";
	double_strings[7] = "|%#.0lf|\n";
	double_strings[8] = "|%.0lf|\n";
	double_strings[9] = "|% 10lf|\n";
	double_strings[10] = "|%+lf|\n";
	double_strings[11] = "|%.19lf|\n";
	double_strings[12] = "|%010.0lf|\n";
	double_strings[13] = 0;

	return (double_strings);
}

double *get_double()
{
	double *doubles;

	doubles = malloc(sizeof (double) * 100);
	doubles[0] = 0.15;
	doubles[1] = -6.39384674839;
	doubles[2] = 1444565444646.6465424242242;
	doubles[3] = -1444565444646.6465424242242454654;
	doubles[4] = 0.15;
	doubles[5] = 0.25;
	doubles[6] = 0.35;
	doubles[7] = 0.45;
	doubles[8] = 0.55;
	doubles[9] = 0.65;
	doubles[10] = 0.75;
	doubles[11] = 0.85;
	doubles[12] = 0.95;
	doubles[12] = 1;
	doubles[12] = -1.5;
	doubles[13] = 0;

	return (doubles);
}

char	**get_float_strings()
{
	char	**float_strings;

	float_strings = malloc(sizeof (char *) * 30);
	float_strings[0] = "|%f|\n";
	float_strings[1] = "|%.1f|\n";
	float_strings[2] = "|%10f|\n";
	float_strings[3] = "|%-10f|\n";
	float_strings[4] = "|%010f|\n";
	float_strings[5] = "|%-010f|\n";
	float_strings[6] = "|%#f|\n";
	float_strings[7] = "|%#.0f|\n";
	float_strings[8] = "|%.0f|\n";
	float_strings[9] = "|% 10f|\n";
	float_strings[10] = "|%+f|\n";
	float_strings[11] = "|%.19f|\n";
	float_strings[12] = "|%010.0f|\n";
	float_strings[13] = 0;

	return (float_strings);
}

float *get_float()
{
	float *floats;

	floats = malloc(sizeof (float) * 100);
	floats[0] = 0.15;
	floats[1] = -6.39384674839;
	floats[2] = 1444565444646.6465424242242;
	floats[3] = -1444565444646.6465424242242454654;
	floats[4] = 0.15;
	floats[5] = 0.25;
	floats[6] = 0.35;
	floats[7] = 0.45;
	floats[8] = 0.55;
	floats[9] = 0.65;
	floats[10] = 0.75;
	floats[11] = 0.85;
	floats[12] = 0.95;
	floats[12] = 1;
	floats[12] = -1.5;
	floats[13] = 0;

	return (floats);
}

char	**get_long_double_strings()
{
	char	**long_double_strings;

	long_double_strings = malloc(sizeof (char *) * 30);
	long_double_strings[0] = "|%Lf|\n";
	long_double_strings[1] = "|%.1Lf|\n";
	long_double_strings[2] = "|%10Lf|\n";
	long_double_strings[3] = "|%-10Lf|\n";
	long_double_strings[4] = "|%010Lf|\n";
	long_double_strings[5] = "|%-010Lf|\n";
	long_double_strings[6] = "|%#Lf|\n";
	long_double_strings[7] = "|%#.0Lf|\n";
	long_double_strings[8] = "|%.0Lf|\n";
	long_double_strings[9] = "|% 10Lf|\n";
	long_double_strings[10] = "|%+Lf|\n";
	long_double_strings[11] = "|%.19Lf|\n";
	long_double_strings[12] = "|%010.0Lf|\n";
	long_double_strings[13] = 0;

	return (long_double_strings);
}

long double *get_long_double()
{
	long double *long_doubles;

	long_doubles = malloc(sizeof (long double) * 100);
	long_doubles[0] = 0.15l;
	long_doubles[1] = -6.39384674839l;
	long_doubles[2] = 1444565444646.6465424242242l;
	long_doubles[3] = -1444565444646.6465424242242454654l;
	long_doubles[4] = 0.15l;
	long_doubles[5] = 0.25l;
	long_doubles[6] = 0.35l;
	long_doubles[7] = 0.45l;
	long_doubles[8] = 0.55l;
	long_doubles[9] = 0.65l;
	long_doubles[10] = 0.75l;
	long_doubles[11] = 0.85l;
	long_doubles[12] = 0.95l;
	long_doubles[12] = 1l;
	long_doubles[12] = -1.5l;
	long_doubles[13] = 0;

	return (long_doubles);
}