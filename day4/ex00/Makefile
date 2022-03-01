NAME = poly
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =	srcs/main.cpp \
		srcs/Cat.cpp \
		srcs/Dog.cpp \
		srcs/Animal.cpp \
		srcs/WrongCat.cpp \
		srcs/WrongAnimal.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
RM = rm -rf

%.o :	%.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) -I includes $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re