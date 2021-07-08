#include "nm.h"

static int	ft_nm(t_nm_env *env, int argc, char **argv)
{
	if (!(env->binarys_paths = get_binarys_paths(argc, argv, (argc == 1))))
		return (1);

	env->nb_binarys = (unsigned)ft_tablen(env->binarys_paths);

	if (!(env->binary_files = get_binarys_files_content(env)))
	{
		nm_free(env);
		return (1);
	}

	for (int i = 0; env->binarys_paths[i]; i++)
	{
		
	}
	return (EXIT_SUCCESS);
}

int			main(int argc, char **argv)
{
	t_nm_env	env;
	int			code;

	code = ft_nm(&env, argc, argv);
	nm_free(&env);
	return (code);
}
