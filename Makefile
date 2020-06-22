CC = gcc


PUSH_SWAP = push_swap
CHECKER = checker
MAKE = make
LIB = ./includes/libft/libft.a
LIBA = ./includes/libft
FLAGS = -Wall -Wextra -Werror
INC = ./includes

SRC_PUSH_SWAP = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c \
				./src/px.c ./src/rrx.c ./src/sx.c ./src/is_sorted.c \
			    ./src/sort_stacks.c ./src/sorting_algorythm.c ./src/rx.c \
			    ./src/ft_push_swap.c ./src/rotations.c ./src/extra_functions.c \
			    ./src/cleaner.c

SRC_CHECKER = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c ./src/px.c \
			          ./src/rrx.c ./src/rx.c ./src/sx.c ./src/is_sorted.c \
			          ./src/ft_checker.c ./src/cleaner.c

HEADER = ./includes/ft_push_swap.h

OBJ_PS = $(SRC_PUSH_SWAP:.c=.o)

OBJ_CK = $(SRC_CHECKER:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

%.o: %.c
	    $(CC) $(FLAGS) -c -o $@ $< -g

$(PUSH_SWAP): $(LIB) $(OBJ_PS)
	    $(CC) $(FLAGS) -I $(INC) -o $(PUSH_SWAP) $(SRC_PUSH_SWAP) -g -L $(LIBA) -lft 
		#-fsanitize=address -fno-omit-frame-pointer

$(CHECKER): $(LIB) $(OBJ_CK)
	    $(CC) $(FLAGS) -I $(INC) -o $(CHECKER) $(SRC_CHECKER) -g -L $(LIBA) -lft 
		#-fsanitize=address -fno-omit-frame-pointer

$(LIB):
	    $(MAKE) -C ./includes/libft/ 

clean:
	    $(MAKE) clean -C ./includes/libft
		rm -f $(OBJ_PS)
		rm -f $(OBJ_CK)

fclean: clean
	    $(MAKE) fclean -C ./includes/libft
		rm -f $(PUSH_SWAP)
		rm -f $(CHECKER)

re: fclean all
