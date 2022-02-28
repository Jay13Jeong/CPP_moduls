NAME = megaphone
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp

all : $(NAME)

$(NAME) : $(SRCS)
	$(CXX) $(FLAGS) $(SRCS) -o $(NAME)

re: fclean all

clean:
	rm -f $(NAME)

fclean : clean

re : fclean all