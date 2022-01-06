NAME = megaphone
CC = clang++
CFLAGS = -Wall -Wextra -Werror
SRCS = megaphone.cpp

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

re: fclean all

clean:
	rm -f $(NAME)

fclean : clean

re : fclean all