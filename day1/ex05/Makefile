NAME			= karen
SRCS			= main.cpp \
				  Karen.cpp
OBJS			= $(SRCS:.cpp=.o)
CXX				= c++
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -std=c++98

%.o :			%.cpp
				$(CXX) $(FLAGS) -c -o $@ $<

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(FLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
