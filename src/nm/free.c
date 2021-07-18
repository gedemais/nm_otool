#include "nm.h"

static void unmap_binarys(t_nm_env *env)
{
	t_binary	*bin;

	for (int i = 0; i < env->binarys.nb_cells; i++)
	{
		bin = dyacc(&env->binarys, i);
		if (munmap(bin->content, (size_t)bin->size) == -1)
			ft_putendl_fd(strerror(errno), 2);
		if (bin->stdout_buffer)
			free(bin->stdout_buffer);
	}
	free_dynarray(&env->binarys);
}

void	nm_free(t_nm_env *env)
{
	ft_free_ctab(env->binarys_paths);
	unmap_binarys(env);
}
