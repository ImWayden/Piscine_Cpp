# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wayden <wayden@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 12:51:46 by wayden            #+#    #+#              #
#    Updated: 2024/01/19 22:47:46 by wayden           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -Wno-unused

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = account

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

re : fclean all

clean:
	rm -f $(NAME)
	
fclean:
	rm -f $(OBJS) $(NAME)

# diff <(sed 's/^.\{17\}//' account.log) <(sed 's/^.\{17\}//' 19920104_091532.log) > diff.log