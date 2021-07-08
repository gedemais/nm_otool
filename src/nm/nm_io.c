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

static char	*map_binary(char *path, t_binary *bin)
{
	struct stat	info;
	char		*content;
	int			fd;

	if ((fd = open(path, O_RDONLY)))
		return (NULL);

	if ()

	if ((content = mmap()) == MAP_FAILED)
		return (NULL);
}

char		**get_binarys_content(t_nm_env *env)
{
	if (!(contents = (char**)malloc(sizeof(char*) * (env->nb_binarys + 1))))
		return (NULL);
	for (unsigned int i = 0; i < env->nb_binarys; i++)
	{
		if (!(contents[i] = map_binary(env->binarys_paths[i], &env->binary_files[i])))
			return (NULL);
	}
}
