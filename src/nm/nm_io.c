#include "nm.h"

char	**get_binarys_paths(int argc, char **argv, bool none)
{
	char			**bins;
	unsigned int	size;

	size = none ? 1 : (unsigned)argc - 1;
	size += 1; // NULL ptr delimiter

	if (!(bins = (char**)malloc(sizeof(char*) * size)))
		return (NULL);

	if (none)
	{
		if (!(bins[0] = ft_strdup("./a.out")))
			return (NULL);
		bins[1] = NULL;
	}
	else
		for (int i = 1; i < argc; i++)
		{
			if (!(bins[i - 1] = ft_strdup(argv[i])))
				return (NULL);
			if (i + 1 == argc)
				bins[i] = NULL;
		}

	if (DEBUG_VERBOSE > 0)
	{
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("BINARYS PATHS :\n");
		ft_pctab(bins);
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	}

	return (bins);
}

static int	map_binary(char *path, t_binary *bin)
{
	struct stat	info;
	int			fd;

	if ((fd = open(path, O_RDONLY)) == -1 || fstat(fd, &info) == -1)
		return (1);

	bin->size = info.st_size;
	if ((bin->content = mmap(0, (size_t)bin->size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (1);

	return (0);
}

int		get_binarys_content(t_nm_env *env)
{
	t_binary	new;

	if (init_dynarray(&env->binarys, sizeof(t_binary), 8))
		return (1);

	for (unsigned int i = 0; i < env->nb_binarys; i++)
	{
		if (DEBUG_VERBOSE > 0)
			printf("Mapping %s in memory...\n", env->binarys_paths[i]);

		if (map_binary(env->binarys_paths[i], &new))
		{
			ft_putstr_fd("ft_nm : ", 2);
			ft_putstr_fd(env->binarys_paths[i], 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(strerror(errno), 2);
			return (1);
		}

		if (push_dynarray(&env->binarys, &new, true))
			return (1);

		if (DEBUG_VERBOSE > 0)
			printf("%s mapped in memory\n", env->binarys_paths[i]);
	}
	return (0);
}
