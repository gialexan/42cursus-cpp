# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 20:12:53 by gialexan          #+#    #+#              #
#    Updated: 2023/12/10 09:54:15 by gialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                                EX05                                        ##
################################################################################

RESET := \033[0m
CYAN  := \033[1;36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

NAME := 			harlFilter


################################################################################
##                                DIRECTORIES                                 ##
################################################################################

OBJ_DIR		:= obj

SRC_FILES	:= 	main.cpp Harl.cpp 

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
	@c++ -c $< -o $@

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