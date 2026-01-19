NAME =  easyfind
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic  -Wsign-compare  -MMD -MP

SRCS_FILES = main.cpp

SRCS_DIR = srcs
OBJS_DIR = objects

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.cpp=.o))
DEPS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.cpp=.d))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)
	@rmdir $(OBJS_DIR) 2>/dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	@echo "Running tests..."
	./$(NAME)
	$(MAKE) fclean

.PHONY: all clean fclean re test

