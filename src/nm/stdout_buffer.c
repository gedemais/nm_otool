#include "nm.h"

int		stdout_buffer(t_binary *bin)
{
	uint32_t		nb_symbols;
	uint32_t		symbols_offset;
	uint32_t		strings_offset;

	struct nlist_64	*array;
	char			*stringtable;


	nb_symbols = bin->lc->nsyms;
	symbols_offset = bin->lc->symoff;
    strings_offset = bin->lc->stroff;

	array = bin->content + symbols_offset;
	stringtable = bin->content + strings_offset;
	
	if (!(bin->stdout_buffer = ft_strnew(nb_symbols * SYM_MAX_SIZE)))
		return (1);
	for (int32_t i = 0; i < nb_symbols; i++)
	{
		ft_strcat();
	}
	return (0);
}
