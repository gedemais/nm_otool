#ifndef NM_H
# define NM_H

# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# define DEBUG_VERBOSE 0

typedef struct	s_binary
{
	char	*content; // Content of the mapped binary file
	off_t	size; // Size of the mapped binary file
}				t_binary;

typedef struct	s_nm_env
{
	char			**binarys_paths; // Array of binary files paths
	t_dynarray		binarys; // Array of binary files structures
	unsigned int	nb_binarys; // Number of binary files
	char			_pad[4];
}				t_nm_env;

void	nm_free(t_nm_env *env);

// IO
char		**get_binarys_paths(int argc, char **argv, bool none);
int			get_binarys_content(t_nm_env *env);


#endif
