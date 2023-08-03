42 :
	arch -x86_64 gcc *.c ./get_next_line/*.c -L ../mlx -I. -Lmlx -lmlx -framework OpenGL -framework Appkit
	./a.out ./test_maps/42.fdf

pyra :
	arch -x86_64 gcc *.c ./get_next_line/*.c -L ../mlx -I. -Lmlx -lmlx -framework OpenGL -framework Appkit
	./a.out ./test_maps/pyra.fdf

elem :
	arch -x86_64 gcc *.c ./get_next_line/*.c -L ../mlx -I. -Lmlx -lmlx -framework OpenGL -framework Appkit
	./a.out ./test_maps/elem2.fdf

