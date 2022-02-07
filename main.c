#include "ft_printf.h"
#include <stdio.h>

int main()
{
	unsigned int i = 42;
	// ft_printf("Hello world%%\n");
	// printf("%.25Lf\n", (0.2l - 0.15l) ^ (0.15l - 0.1l));
	// printf("%.25Lf %.25Lf\n", (long double) 0.85 - (long double) 0.8, (long double) 0.9 - (long double) 0.85);
	// printf("%.15Lf %.15Lf\n", (long double) 0.15 + (long double) 0.05, (long double) 0.15 - (long double) 0.05);
	// ft_printf("%.2f\n", 7.23496);
	// printf("%.2f\n", 7.23496);
	// if ( 0.15 - 0.1 >= 0.2 - 0.15)
	// 	printf("1");
	// if ( 0.15 - 0.1 < 0.2 - 0.15)
	// 	printf("2");
	ft_printf("ft|%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f|\n", 0.15, 0.25, 0.35, 0.45, 0.55, 0.65, 0.75, 0.85, 0.95);
	printf("  |%.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f|\n\n", 0.15, 0.25, 0.35, 0.45, 0.55, 0.65, 0.75, 0.85, 0.95);

	ft_printf("ft|%.1Lf %.1Lf %.1Lf %.1Lf %.1Lf %.1Lf %.1Lf %.1Lf %.1Lf|\n", 0.15l, 0.25l, 0.35l, 0.45l, 0.55l, 0.65l, 0.75l, 0.85l, 0.95l);
	printf("  |%.1Lf %.1Lf %.1Lf %.1Lf %.1Lf %.1Lf %.1Lf %.1Lf %.1Lf|\n\n", 0.15l, 0.25l, 0.35l, 0.45l, 0.55l, 0.65l, 0.75l, 0.85l, 0.95l);

	// __float128 res = 0.1l;
	// ft_printf("%Lf\n", (long double) res);
	// printf("%Lf\n\n", (long double) res);

	// ft_printf("%wer\n");
	printf("|%d|\n", ft_printf("%"));
	printf("|%d|\n\n", printf("%"));

	ft_printf("{% 03d}\n", 0);
	printf("{% 03d}\n\n", 0);

	ft_printf("%2.9p\n", 1234);
	printf("%2.9p\n\n", 1234);


	ft_printf("|%.p, %.0p|", 0, 0);
	printf("|%.p, %.0p|", 0, 0);

	// ft_printf("{%.19f}{%.19lf}{%.19Lf}\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	// printf("{%.19f}{%.19lf}{%.19Lf}\n\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);

	// ft_printf("{%.0f}{%.0lf}{%.0Lf}\n", 1.5, 1.5, 1.5l);
	// printf("{%.0f}{%.0lf}{%.0Lf}\n\n", 1.5, 1.5, 1.5l);

	// ft_printf("{%f}{%lf}{%Lf}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
	// printf("{%f}{%lf}{%Lf}\n\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);

	// ft_printf("%#.3o\n", 1);
	// printf("%#.3o\n\n", 1);

	// ft_printf("|%#05.0f|\n", (float) 1);
	// printf("|%#05.0f|\n", (float) 1);

	// ft_printf("|%c %s %p %d %i %u %o %x %X\n", 'b', "hello", &i, 5, -11, 356, 786, 34, -9);
	// printf("|%c %s %p %d %i %u %o %x %X\n\n", 'b', "hello", &i, 5, -11, 356, 786, 34, -9);

	// ft_printf("|%.1f|\n", 6.39384674839);
	// printf("|%.1f|\n\n", 6.39384674839);


	return (0);
}