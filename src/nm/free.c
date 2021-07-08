#include "nm.h"

void	nm_free(t_nm_env *env)
{
	ft_free_ctab(env->binarys_paths);

	for (unsigned int i = 0; i < env->nb_binarys; i++)
	{
		munmap()
	}
}
