# Nom de l'exécutable
NAME = push_swap

# Compilateur et options
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Répertoires des projets
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf

# Bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Fichiers sources et objets
SRCS = main.c push_swap.c parsing.c instructions.c indexation.c instructions_print.c instructions_print2.c \
sort_large_stack.c sort_large_utils.c sort_b_utils.c
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(LIBFT) $(PRINTF) $(NAME)

# Compilation de push_swap
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^
	
# Générer les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Générer libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Générer printf
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Nettoyage des objets
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

# Récompilation complète
re: fclean all

.PHONY: all clean fclean re