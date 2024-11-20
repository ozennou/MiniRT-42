NAME = miniRT

OBJS = $(shell find . -name "*.c" | sed 's/\.c$$/.o/' | tr '\n' ' ')

CC = cc #-Wall -Werror -Wextra

RM = rm -f

%.o : %.c header.h
	@$(CC) -Imlx -c -O3 $< -o $@
	@echo "Compiling $<"

$(NAME) : $(OBJS)
	@$(CC) $(OBJS) -lm -lmlx -framework OpenGL -framework AppKit -O3 -o $(NAME)
	@echo "Linking $(NAME)"

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@echo "Cleaning ..."

fclean : clean
	@$(RM) $(NAME)
	@echo "Full cleaning ..."

re : fclean all

a : all clean

.PHONY : clean