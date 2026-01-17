CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS_DIR = srcs
OBJS_DIR = objects

SRCS_FILES =	main.cpp \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.cpp=.o))

NAME =   Mutated_abomination

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
#	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re

# static_cast: コンパイル時に型変換可能かチェックするぞ。実行時に型変換するぞ。
# dynamic_cast: 実行時に型変換可能かチェックするぞ。実行時に型変換するぞ。
# const_cast: 実行時const修飾子の変更（型変換チェックなんてしない）
# reinterpret_cast: 実行時バイナリレベルでの再解釈（型変換チェックなんてしない）