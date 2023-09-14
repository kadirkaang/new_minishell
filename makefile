# NAME #
NAME = minishell

# FLAGS #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

# READLINE #
# LREADLINE_FLAGS = -lreadline -L /home/linuxbrew/.linuxbrew/opt/readline/lib/
# READLINE = -I /home/linuxbrew/.linuxbrew/opt/readline/include/
# LINUX_READLINE = -lreadline -L/usr/lib/x86_64-linux-gnu/

LREADLINE_FLAGS = -lreadline -L /opt/homebrew/Cellar/readline/8.2.1/lib
READLINE = -I /opt/homebrew/Cellar/readline/8.2.1/include

# INCLUDES #
INCDIR = includes/
INCLUDES = -I $(INCDIR)

# OBJS #
OBJDIR := objs/
SRCDIR := src/

# SRCS #
MAIN = main init_shell get_env signal
LEXER = lexer lexer_utils
FREE = free_1 free_2
EXPANDER = expander expander_utils expander_utils2 expander_utils3 expander_utils4
#BUILTINS = builtings cd echo env exit export ft_env_strdup pwd unset
#PIPES = pipes utils_pipe_fd utils_pipes error init_pipes
#REDIR = redir_input redir_output redir_index
#CMD = cmd exec init_cmd utils_cmd

PLAIN_SRCS =	$(addsuffix .c, $(addprefix main/, $(MAIN)))			\
				$(addsuffix .c, $(addprefix free/, $(FREE)))				\
				$(addsuffix .c, $(addprefix lexer/, $(LEXER)))			\
				$(addsuffix .c, $(addprefix expander/, $(EXPANDER)))			\
				# $(addsuffix .c, $(addprefix builtings/, $(BUILTINS)))	\
				#$(addsuffix .c, $(addprefix pipes/, $(PIPES)))			\
				#$(addsuffix .c, $(addprefix redir/, $(REDIR)))			\
				#$(addsuffix .c, $(addprefix cmd/, $(CMD)))

SRCS := $(addprefix $(SRCDIR), $(PLAIN_SRCS))
OBJS := $(addprefix $(OBJDIR), $(PLAIN_SRCS:.c=.o))

.SILENT:

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(READLINE) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft all
	echo "Libft created"
#	$(CC) $(CFLAGS) $(LREADLINE_FLAGS) $(READLINE) libft/libft.a $^ -o $(NAME)
	$(CC) $(CFLAGS) $^ $(LREADLINE_FLAGS) $(LINUX_READLINE) libft/libft.a -o $(NAME)
	echo "MINISHELL"

clean:
	make -C libft clean
	rm -rf $(OBJDIR)
	$(RM) $(OBJS)
	echo "Objs deleted"

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)
	echo "Executable deleted"

re: fclean all

.PHONY: all clean fclean re