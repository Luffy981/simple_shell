#include "file.h"
void free_struct(vars_t *vars)
{
	int i = 0;
	while(vars->arrays[i])
	{
		free(vars->arrays[i]);
		i++;
	}
	free(vars->arrays);
}