FILES = megaphone.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_FILES = $(FILES:.cpp=.o)

megaphone: $(OBJ_FILES)
	c++ $(FLAGS) $(OBJ_FILES) -o megaphone

$(OBJ_FILES): $(FILES)
	c++ $(FLAGS) -c $(FILES)

clean:
	rm -f megaphone.o

fclean: clean
	rm -f megaphone

all: megaphone

re: fclean all