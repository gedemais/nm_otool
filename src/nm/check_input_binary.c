#include "nm.h"

static int	check_magic(t_binary *bin)
{
	t_mach_header *header;

	header = bin->content;
	if (header->magic != MH_MAGIC_64)
		return (1);
	return (0);
}

int		binary_checkup(t_binary *bin, char *bin_path)
{
	if (check_magic(bin))
	{
		nm_error_print("ft_nm: ", bin_path, " The file was not recognized as a valid object file", "\n");
		return (1);
	}
	return (0);
}
