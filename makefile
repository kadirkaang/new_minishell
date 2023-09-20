# NAME #
NAME = minishell

# FLAGS #
CC = gcc -g
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
FREE = free_1 free_2 free_3
EXPANDER = expander expander_utils expander_utils2 expander_utils3 expander_utils4
CHECK = check_utils check
PARSER = parser parser_utils parser_utils_other welcome_to_parse
CREATE_FILES = create_files create_files_utils
EXEC = exec dub2_fd run_execve run_execve1 single_or_multi_commands
REDIR = heredoc heredoc_utils
BUILTIN = builtin run_builtin run_builtin1 run_builtin2 run_builtin3
#REDIR = redir_input redir_output redir_index
#CMD = cmd exec init_cmd utils_cmd

PLAIN_SRCS =	$(addsuffix .c, $(addprefix main/, $(MAIN)))					\
				$(addsuffix .c, $(addprefix free/, $(FREE)))					\
				$(addsuffix .c, $(addprefix lexer/, $(LEXER)))					\
				$(addsuffix .c, $(addprefix expander/, $(EXPANDER)))			\
				$(addsuffix .c, $(addprefix check/, $(CHECK)))					\
				$(addsuffix .c, $(addprefix parser/, $(PARSER)))				\
				$(addsuffix .c, $(addprefix create_files/, $(CREATE_FILES)))	\
				$(addsuffix .c, $(addprefix exec/, $(EXEC)))                    \
				$(addsuffix .c, $(addprefix redir/, $(REDIR)))                	\
				$(addsuffix .c, $(addprefix builtin/, $(BUILTIN)))                         	



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