# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wayden <wayden@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 16:23:49 by wayden            #+#    #+#              #
#    Updated: 2025/02/08 04:16:48 by wayden           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp
OBJS = $(patsubst %.cpp,obj/%.o,$(SRCS))
NAME = Bureaucraty
all: obj $(NAME)

obj:
	mkdir -p obj

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)
