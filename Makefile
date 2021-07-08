NM_NAME=ft_nm
OTOOL_NAME=ft_otool

CC=gcc
FLAGS=-Wall -Werror -Wextra -Weverything

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    FLAGS += -g3 -fsanitize=address
endif

OPTI ?= 0
ifeq ($(OPTI), 1)
    FLAGS += -Ofast -march=native
endif

SCRIPT_PATH=scripts/

include $(SCRIPT_PATH)/nm_srcs.mk
include $(SCRIPT_PATH)/nm_includes.mk

include $(SCRIPT_PATH)/otool_srcs.mk
include $(SCRIPT_PATH)/otool_includes.mk

NM_OBJ=$(NM_SRC:.c=.o)
OTOOL_OBJ=$(OTOOL_SRC:.c=.o)

LIB_PATH=libft/
LIB=$(LIB_PATH)/libft.a

all: $(LIB) $(NM_NAME) $(OTOOL_NAME)

$(LIB): $(LIB_PATH)
	make -C $(LIB_PATH)

$(NM_NAME): $(NM_OBJ)
	$(CC) $(FLAGS) $(NM_OBJ) -o $(NM_NAME) $(LIB)

$(OTOOL_NAME): $(OTOOL_OBJ)
	$(CC) $(FLAGS) $(OTOOL_OBJ) -o $(OTOOL_NAME) $(LIB)

$(NM_SRC_PATH)%.o: $(NM_SRC_PATH)%.c $(NM_INC)
	$(CC) $(FLAGS) -I$(NM_INC_PATH) -I$(LIB_PATH) -o $@ -c $<

$(OTOOL_SRC_PATH)%.o: $(OTOOL_SRC_PATH)%.c $(OTOOL_INC)
	$(CC) $(FLAGS) -I$(OTOOL_INC_PATH) -I$(LIB_PATH) -o $@ -c $<

clean:
	rm -rf $(NM_OBJ)
	rm -rf $(OTOOL_OBJ)
	make -C $(LIB_PATH) clean

fclean: clean
	rm -rf $(NM_NAME)
	rm -rf $(OTOOL_NAME)
	make -C $(LIB_PATH) fclean

re: fclean all
