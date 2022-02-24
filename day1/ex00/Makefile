NAME =	zombie
SRCS =	./main.cpp \
		./Zombie.cpp \
		./newZombie.cpp \
		./randomChump.cpp
CXX	=	c++
FLANG = -Wall -Wextra -Werror -std=c++98
OBJS =	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re