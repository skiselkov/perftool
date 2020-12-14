#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include <acfutils/perf.h>

static void
do_alt2press(char **argv)
{
	double P;

	if (tolower(argv[1][0]) == 'a')
		P = INHG2PA(atof(&argv[1][1]));
	else if (tolower(argv[1][0]) == 'q')
		P = atof(&argv[1][1]) * 100;
	else
		P = atof(argv[1]);

	printf("P = %f Pa\n", alt2press(atof(argv[0]), P));
}

static void
do_ktas2mach(char **argv)
{
	printf("M = %f\n", ktas2mach(atof(argv[0]), atof(argv[1])));
}

static void
do_speed_sound(char **argv)
{
	printf("ss = %.2f m/s\n", speed_sound(atof(argv[0])));
}

static void
do_gas_density(char **argv)
{
	printf("dens = %.3f kg/m^3\n", gas_density(atof(argv[0]) * 1000,
	    atof(argv[1]), R_spec));
}

static void
print_usage(FILE *fp, const char *progname)
{
	fprintf(fp, "Usage: %s <command> <args>\n", progname);
}

int
main(int argc, char **argv)
{
	if (argc < 2) {
		print_usage(stderr, argv[0]);
		return (1);
	}

	if (strcmp(argv[1], "alt2press") == 0 && argc == 4) {
		do_alt2press(&argv[2]);
	} else if (strcmp(argv[1], "ktas2mach") == 0 && argc == 4) {
		do_ktas2mach(&argv[2]);
	} else if (strcmp(argv[1], "ss") == 0 && argc == 3) {
		do_speed_sound(&argv[2]);
	} else if (strcmp(argv[1], "dens") == 0 && argc == 4) {
		do_gas_density(&argv[2]);
	} else {
		print_usage(stderr, argv[0]);
		return (1);
	}

	return (0);
}
