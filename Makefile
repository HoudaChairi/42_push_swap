NAME = push_swap
NAME_B = checker
SRC = push_swap.c \
	create.c \
	utils.c \
	list_utils.c \
	err_and_tab.c \
	sort.c \
	sort_hundred.c \
	back_to_a.c \
	pa_pb.c \
	sa_sb_ss.c \
	ra_rb_rr.c \
	reverse_ra_rb_rr.c \
	get_next_line_utils.c \
	ft_free.c \
	depart.c

SRC_B = list_utils.c \
		err_and_tab.c \
		create.c \
		sort.c \
		sort_hundred.c \
		sa_sb_ss.c \
		pa_pb.c \
		ra_rb_rr.c \
		reverse_ra_rb_rr.c \
		back_to_a.c \
		checker.c \
		utils.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_free.c \
		depart.c 
		
CC = cc
CFLAGS = -Wall -Wextra -Werror 
FT_P = ./ft_printf/libftprintf.a

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(FT_P) -o $@

bonus : $(NAME_B)

$(NAME_B) : $(OBJ_B)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ_B) $(FT_P) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	make clean -C ./ft_printf
	rm -f $(OBJ) $(OBJ_B)
fclean : clean
	make fclean -C ./ft_printf
	rm -f $(NAME) $(NAME_B)

re : fclean all

.PHONY : all clean fclean re bonus