# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wayden <wayden@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 16:23:49 by wayden            #+#    #+#              #
#    Updated: 2025/06/26 20:48:17 by wayden           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -g3 -std=c++98 #-DDEBUG_BUILD=0

SRCS = main.cpp DEBUG.cpp ErrorManager.cpp MergeInsert.cpp
OBJS = $(patsubst %.cpp,obj/%.o,$(SRCS))
NAME = PmergeMe
DEBUG_NAME = PmergeMe_debug

all: obj $(NAME)

debug: obj $(DEBUG_NAME)

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
	rm -f $(NAME) $(DEBUG_NAME)
