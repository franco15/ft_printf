NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

PSRC = ft_printf.c format.c is.c set.c sint.c uint.c oct.c hex.c str.c p.c \
		char.c extra.c wstr.c utils.c \

MLSRC = ./minilibft/conv.c ./minilibft/lst.c ./minilibft/mem.c \
		./minilibft/put.c ./minilibft/strings.c ./minilibft/strings2.c \
		./minilibft/strings3.c ./minilibft/xtra.c ./minilibft/ft_isletter.c \
		./minilibft/wstr.c ./minilibft/uni.c \

POBJ = $(PSRC:.c=.o)

MLOBJ = $(MLSRC:.c=.o)

INC = -I./minilibft

all: $(NAME)

$(NAME): $(MLOBJ)
	@$(CC) -c $(CFLAGS) $(PSRC) $(INC)
	@ar rcs $(NAME) $(POBJ) $(MLOBJ)
	@echo "lib kewl"

./minilibft/%.o:./minilibft/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@/bin/rm -f $(POBJ) $(MLOBJ)
	@echo "objs ded"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "lib ded"

re: fclean all
