##
## EPITECH PROJECT, 2020
## PSU_2019_malloc
## File description:
## Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
LINE_RETURN	=	$(ECHO) ""

SRC	=  	src/malloc.c	\
		src/realloc.c	\
		src/calloc.c    \
		src/reallocarray.c  \
		src/utils.c

NAME	=	libmy_malloc.so

NAME_TEST 	= 	unit_tests

CFLAGS	=	-Wall \
    -Wextra \
    -Werror \
    -fPIC

LDFLAGS = -shared

SRCS	=	$(SRC)

OBJ	=	$(SRC:.c=.o)

OBJ_TESTS = 	$(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run: $(OBJ_TESTS) message
	@$(CC) -o $(NAME_TEST) $(SRCS) --coverage -lcriterion
	@$(LINE_RETURN)
	@./unit_tests
	@$(LINE_RETURN)
	@gcovr --exclude tests --print-summary
	@$(LINE_RETURN)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)" _   _       _ _     _____         _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)"| | | |_ __ (_) |_  |_   _|__  ___| |_ ___"$(DEFAULT)
	@$(ECHO) $(BOLD_T)"| | | | '_ \| | __|   | |/ _ \/ __| __/ __|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)'| |_| | | | | | |_    | |  __/\__ \ |_\__ \\'$(DEFAULT)
	@$(ECHO) $(BOLD_T)" \___/|_| |_|_|\__|   |_|\___||___/\__|___/\n"$(DEFAULT)
	@$(LINE_RETURN)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_TESTS)
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf tests/*.gcda
	@rm -rf tests/*.gcno

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_TEST)

re:	fclean all 

.PHONY: all tests_run clean fclean re message
