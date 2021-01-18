NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

INCLUDE = -I Includes

SRCS = ft_printf.c ft_print_result.c

OBJS = $(SRCS:.c=.o)

OBJS_LIBFT = libft/ft_strlen.o libft/ft_atoi.o libft/ft_isalpha.o libft/ft_isdigit.o libft/ft_isalnum.o \
libft/ft_isascii.o libft/ft_isprint.o libft/ft_toupper.o libft/ft_tolower.o libft/ft_memset.o \
libft/ft_bzero.o libft/ft_memcpy.o libft/ft_memccpy.o libft/ft_memmove.o libft/ft_memchr.o \
libft/ft_memcmp.o libft/ft_strchr.o libft/ft_strrchr.o libft/ft_strncmp.o \
libft/ft_strlcpy.o libft/ft_strlcat.o libft/ft_strnstr.o libft/ft_calloc.o libft/ft_strdup.o \
libft/ft_substr.o libft/ft_strjoin.o libft/ft_strtrim.o libft/ft_split.o libft/ft_itoa.o \
libft/ft_strmapi.o libft/ft_putchar_fd.o libft/ft_putstr_fd.o libft/ft_putendl_fd.o \
libft/ft_putnbr_fd.o



all : ${NAME}

$(NAME):	
	make -C ./libft
	gcc $(FLAG) $(INCLUDE) -c $(SRCS) 
	ar rc $(NAME) ${OBJS} $(OBJS_LIBFT) 
	ranlib ${NAME}
	gcc main.c libftprintf.a

clean : 
	/bin/rm -f ${OBJS}
	make clean -C libft

fclean :	clean
	rm -rf ${NAME}
	make fclean -C libft

re : fclean all
