#include "file.h"
char help_func(vars_t *vars)
{
	char *str = NULL;
	char (*f)(vars_t *h);
	if (vars->arrays[1])
	{
		f = help_match(vars);
		f(vars);
	}
	else
	{
		str = file_read("Help");

		write(1, str, strlen(str));
		free(str);
	}
	return(0);
}
char (*help_match(vars_t *vars))(vars_t *vars)
{
	unsigned int i;
	help_v h[] = {
		{"exit", print_exit},
		{"cd", print_cd},
		{"help", print_help},
		{"history", help_print_history},
		{NULL, NULL}
	};
	for (i = 0; h[i].p !=NULL; i++)
	{
		if (strcmp(vars->arrays[1], h[i].name) == 0)
		{
			break;
		}
	}
	return (h[i].p);
}

char print_exit(vars_t *vars)
{
	char *str = NULL;
	str = file_read("Exit");

	write(1, str, strlen(str));
	free(str);
	return (0);
}
char print_cd(vars_t *vars)
{
	char *str = NULL;
	str = file_read("Cd");
	write(1, str, strlen(str));
	free(str);
	return(0);
}
char print_help(vars_t *vars)
{
	char *str = NULL;
	str = file_read("Help_to_help");
	write(1, str, strlen(str));
	free(str);
	return(0);
}
char help_print_history(vars_t *vars)
{
	char *str = NULL;
	str = file_read("Help_history");
	write(1, str, strlen(str));
	free(str);
	return(0);
}
