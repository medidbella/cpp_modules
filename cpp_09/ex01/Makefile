FILES = $(shell ls | grep .cpp)
PROG = RPN
FLAGS = -fsanitize=address -g3 -Wall -Wextra -Werror -std=c++98
OBJ_FILES = $(FILES:.cpp=.o)

$(PROG): $(OBJ_FILES)
	c++ $(FLAGS) $(OBJ_FILES) -o $(PROG)

$(OBJ_FILES): $(FILES)
	c++ $(FLAGS) -c $(FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(PROG)

all: $(PROG)

re: fclean all
