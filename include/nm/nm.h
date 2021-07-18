#ifndef NM_H
# define NM_H

# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach/machine.h>

# define DEBUG_VERBOSE 1

# define SYM_MAX_SIZE 128

typedef struct	s_aligned_mach_header_64
{
	uint32_t	magic;		/* mach magic number identifier */
	cpu_type_t	cputype;	/* cpu specifier */
	cpu_subtype_t	cpusubtype;	/* machine specifier */
	uint32_t	filetype;	/* type of file */
	uint32_t	ncmds;		/* number of load commands */
	uint32_t	sizeofcmds;	/* the size of all the load commands */
	uint32_t	flags;		/* flags */
	uint32_t	reserved;	/* reserved */
}				t_mach_header;

typedef struct	s_binary
{
	void					*content; // Content of the mapped binary file
	struct symtab_command	*symtable; // Address of the symtable section
	char					*stdout_buffer;
	off_t					size; // Size of the mapped binary file
	uint32_t				arch; // 32 / 64 bits
	uint32_t				pad;
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

int			binary_checkup(t_binary *bin, char *bin_path);

void		nm_error_print(char *a, char *b, char *c, char *d);
#endif
