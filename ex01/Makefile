# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ageels <ageels@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/09 12:15:13 by ageels        #+#    #+#                  #
#    Updated: 2023/05/11 10:30:41 by ageels        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = Form_up_maggots

FLAGS = -I. -Wall -Werror -Wextra -std=c++98

HDR = Bureaucrat.hpp\
	Form.hpp

SRC = main.cpp\
	Bureaucrat.cpp\
	Form.cpp

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME) : $(OBJ) $(HDR)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR) : 
	mkdir -pv $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re