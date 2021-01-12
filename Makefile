NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRCS = ./srcs/ft_printf.c

OBJS = ./ft_printf.o


all :	${NAME}

$(NAME):	${OBJS}
	ar rc $(NAME) ${OBJS}
	ranlib ${NAME} libft/libft.a
	gcc main.c ${NAME} -I Includes

$(OBJS):
	make -C libft
	gcc ${FLAG} -I Includes -c ${SRCS} 

clean : 
	/bin/rm -f ${OBJS}
	make clean -C libft

fclean :	clean
	rm -rf ${NAME}
	make fclean -C libft

re : fclean all
