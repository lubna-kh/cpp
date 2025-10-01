NAME =

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =
OBJDIR = objs

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

#| $(OBJDIR) ensures the obj/ folder exists before placing the .o files inside it, without causing pointless recompiles every time you run make.

$(OBJDIR)/%.o : %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
