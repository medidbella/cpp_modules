FILES = main.cpp PhoneBook_utils.cpp Contact_utils.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_FILES = $(FILES:.cpp=.o)

phone_book: $(OBJ_FILES)
	c++ $(FLAGS) $(OBJ_FILES) -o phone_book

$(OBJ_FILES): $(FILES)
	c++ $(FLAGS) -c $(FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f phone_book

all: phone_book

re: fclean all