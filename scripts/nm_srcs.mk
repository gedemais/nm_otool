NM_SRC_PATH=src/nm/

NM_SRC_NAME=main.c\
			check_input_binary.c\
			error.c\
			nm_io.c\
			free.c

NM_SRC=$(addprefix $(NM_SRC_PATH), $(NM_SRC_NAME))
