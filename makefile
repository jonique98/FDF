CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L./minilibx -lmlx -framework OpenGL -framework AppKit

NAME = fdf
SRCDIR = ./src
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SRCS:.c=.o)
INC = -I$(SRCDIR)

BNSNAME = fdf_bonus
BNSSRCDIR = ./bonus
BNSSRCS = $(wildcard $(BNSSRCDIR)/*.c)
BNSOBJECTS = $(BNSSRCS:.c=.o)
BNSINC = -I$(BNSSRCDIR)

RMF = rm -f

all : $(NAME)

bonus : $(BNSNAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)

$(BNSNAME) : $(BNSOBJECTS)
	$(CC) $(CFLAGS) $(BNSOBJECTS) $(LIBS) -o $(BNSNAME)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(BNSSRCDIR)/%.o : $(BNSSRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(BNSINC)

clean :
	$(RMF) $(OBJECTS) $(BNSOBJECTS)

fclean : clean
	$(RMF) $(NAME) $(BNSNAME)

re : fclean all

.PHONY : clean fclean all re bonus





42 :
	arch -x86_64 cc ./*.c -L ./mlx -I. -Lmlx -lmlx -framework OpenGL -framework Appkit
	./a.out ./test_maps/42.fdf

pyra :
	arch -x86_64 gcc ./*.c  -L ../mlx -I. -Lmlx -lmlx -framework OpenGL -framework Appkit
	./a.out ./test_maps/pyra.fdf

# elem :
# 	arch -x86_64 gcc *.c ./get_next_line/*.c -L ../mlx -I. -Lmlx -lmlx -framework OpenGL -framework Appkit
# 	./a.out ./test_maps/elem2.fdf

# frac :
# 	arch -x86_64 gcc *.c ./get_next_line/*.c -L ../mlx -I. -Lmlx -lmlx -framework OpenGL -framework Appkit
# 	./a.out ./test_maps/elem-fract.fdf
