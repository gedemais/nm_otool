#ifndef NM_H
# define NM_H

# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>

# define DEBUG_VERBOSE 1

typedef struct	s_binary
{
	char		*content; // Content of the mapped binary file
	size_t		size; // Size of the mapped binary file
}				t_binary;

typedef struct	s_nm_env
{
	char			**binarys_paths; // Array of binary files paths
	t_binary		**binary_files; // Array of binary files structures
	unsigned int	nb_binarys; // Number of binarys
}				t_nm_env;

void	nm_free(t_nm_env *env);

// IO
char	**get_binarys_paths(int argc, char **argv, bool none);
char	**get_binarys_content(t_nm_env *env);


#endif
