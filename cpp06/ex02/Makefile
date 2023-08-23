NAME = base

SRC = main.cpp Base.cpp
OBJS := $(SRC:%.cpp=%.o)

CPPFLAGS = -Wall -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all