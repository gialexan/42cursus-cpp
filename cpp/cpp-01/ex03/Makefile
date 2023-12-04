# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 19:06:44 by gialexan          #+#    #+#              #
#    Updated: 2023/12/03 13:34:32 by gialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                                EX03                                        ##
################################################################################

RESET := \033[0m
CYAN  := \033[1;36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

NAME := 			ex03


################################################################################
##                                DIRECTORIES                                 ##
################################################################################

OBJ_DIR		:= obj

SRC_FILES	:= 	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS 		:= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all:		$(NAME)

################################################################################
##                                 COMPILATION                                ##
################################################################################

CFLAGS  := -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	@$(LOG) "Building $@"
	@c++ $^ -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(LOG) "Compiling $(notdir $<)"
	@c++ $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(LOG) "Creating objects directory"
	@mkdir $@

clean:
	@$(RM) -r $(OBJS)
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing objects directory"
	@$(RM) -r $(NAME)
	@$(LOG) "Removing $(NAME)"

fclean: clean

re:					fclean all

.PHONY:				all clean fclean re libft