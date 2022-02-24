NAME			= replace
SRCS			= main.cpp
OBJS			= $(SRCS:.cpp=.o)
CXX				= c++
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(FLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) *.replace

re:				fclean $(NAME)

.PHONY:			all clean fclean re
