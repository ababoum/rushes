SRC = srcs/main.cpp srcs/Dico.cpp srcs/WordFind.cpp srcs/Screen.cpp
NAME = wordle
CXXFLAGS = -Werror -Wall -Wextra
CXX = c++
OBJ = $(SRC:.cpp=.o)
HEAD = includes/Dico.hpp includes/WordFind.hpp includes/Screen.hpp

all : $(NAME)

$(NAME) : $(OBJ) $(HEAD)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

.cpp.o: $(HEAD)
	$(CXX) -c $(CXXFLAGS) $< -o $(<:.cpp=.o)
	
clean : 
		@rm -rf ${OBJ} 2> /dev/null

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
