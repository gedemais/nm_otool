#include "nm.h"

static int	check_magic(t_mach_header *header, t_binary *bin)
{

	if ((bin->arch = header->magic) != MH_MAGIC_64)
		return (1);
	
	return (0);
}

static int	get_symbol_table(t_mach_header *header, t_binary *bin)
{
	struct load_command *lc;

	lc = (void*)((size_t)bin->content + (size_t)sizeof(t_mach_header));

	for (unsigned int i = 0; i < header->ncmds; i++)
	{
		if (lc->cmd == LC_SYMTAB) // Ending section
		{
			bin->symtable = (void*)lc;
			return (0);
		}
		lc = (void*)((size_t)lc + (size_t)lc->cmdsize);
	}

	return (1);
}

int		binary_checkup(t_binary *bin, char *bin_path)
{
	t_mach_header *header;

	header = bin->content;

	if (check_magic(header, bin) || get_symbol_table(header, bin))
	{
		nm_error_print("ft_nm: ", bin_path,
			" The file was not recognized as a valid object file", "\n");
		return (1);
	}
	
	return (0);
}
