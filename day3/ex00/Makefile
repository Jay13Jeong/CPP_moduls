NAME			= claptrap
SRCS			= main.cpp \
				ClapTrap.cpp
OBJS			= $(SRCS:.cpp=.o)
CXX				= c++
RM				= rm -f
FLAGS		=	-Wall -Wextra -Werror -std=c++98

%.o :			%.cpp
				$(CXX) $(FLAGS) -c -o $@ $<

all:			$(NAME)

$(NAME):		$(OBJS) ClapTrap.hpp
				$(CXX) $(FLAGS) -o $(NAME) $(OBJS) -I ClapTrap.hpp

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
