NAME			= scavtrap
SRCS			= main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp
OBJS			= $(SRCS:.cpp=.o)
CXX				= c++
RM				= rm -f
FLAGS		=	-Wall -Wextra -Werror -std=c++98

%.o :			%.cpp
				$(CXX) $(FLAGS) -c -o $@ $<

all:			$(NAME)

$(NAME):		$(OBJS) ClapTrap.hpp ScavTrap.hpp
				$(CXX) $(FLAGS) -o $(NAME) $(OBJS) -I ClapTrap.hpp -I ScavTrap.hpp

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
