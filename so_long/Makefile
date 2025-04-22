NAME = so_long

SRC = test.c

OBJ = $(SRC:%.c=%.o)

$(info SRC=$(SRC))
$(info OBJ=$(OBJ))
$(info NAME=$(NAME))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

config:
	make -C ./mlx_linux

