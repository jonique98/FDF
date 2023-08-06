// #include <stdio.h>  // printf()
// #include <stdlib.h> // exit()
// #include "fdf.h"

// #define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자인 
// #define X_EVENT_KEY_RELEASE 3   // x_event에 들어가는 값

// #define KEY_W 13    // MacOS의 키보드 코드들이다.          
// #define KEY_A 0     //
// #define KEY_S 1     // 위에서 부터 차례대로
// #define KEY_D 2     //
// #define KEY_ESC 53  // 'W' 'A' 'S' 'D' 'ESC'들의 키보드 코드이다.



// #define MOUSE_LEFT_BUTTON 1
// #define MOUSE_RIGHT_BUTTON 2
// #define MOUSE_SCROLL_BUTTON 3
// #define MOUSE_SCROLL_UP 4
// #define MOUSE_SCROLL_DOWN 5 

// typedef	struct s_param // 키 값을 입력 받고 정해진 동작을 수행했는지
// {                      // 여부를 판단하기 위해 선언하였다.
// 	int x;               // x값
// 	int y;               // y값
// 	int z;				 // y값
    
//     void	*mlx_ptr;
//     void	*win_ptr;
// } t_param;

// void param_init(t_param *param) // 구조체 param 초기화 함수
// {
// 	param->x = 0;
// 	param->y = 0;
// 	param->z = 0;
    
// 	param->mlx_ptr = 0;
// 	param->win_ptr = 0;
// }

// int key_press(int keycode, t_param *param) // 어떤 키가 눌렸는지 판단하고,
// {                                                // 정의된 행동을 수행하는 함수
// 	if (keycode == KEY_W)        // W 키를 누르면 param.x값이 1 증가한다.
// 		param->x++;
// 	else if (keycode == KEY_S)   // S 키를 누르면 param.x값이 1 감소한다.
// 		param->x--;
// 	else if (keycode == KEY_A)   // A 키를 누르면 param.y값이 1 증가한다.
// 		param->y++;
// 	else if (keycode == KEY_D)   // D 키를 누르면 param.y값이 1 감소한다.
// 		param->y--;
// 	else if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
// 		exit(0);
// 	printf("(x, y): (%d, %d)\n", param->x, param->y); // param의 값 확인
// 	return (0);
// }

// int mouse_event(int keycode, int x, int y, t_param *param) // 어떤 키가 눌렸는지 판단하고,
// {                                                // 정의된 행동을 수행하는 함수
//     if (keycode == MOUSE_LEFT_BUTTON) 
//         printf("MOUSE_LEFT_BUTTON\n");
//     else if (keycode == MOUSE_RIGHT_BUTTON)
//         printf("MOUSE_RIGHT_BUTTON\n");
//     else if (keycode == MOUSE_SCROLL_BUTTON)
//         printf("MOUSE_SCROLL_BUTTON\n");
//     else if (keycode == MOUSE_SCROLL_UP)
// 	{
//         printf("MOUSE_SCROLL_UP\n");
// 		param->z++;
// 	}
//     else if (keycode == MOUSE_SCROLL_DOWN)
// 	{
//         printf("MOUSE_SCROLL_DOWN\n");
// 		param->z--;
// 	}
// 	printf("%d %d %d\n", x, y, param->z);
//     return (0);
// }
// int main(void)
// {
// 	t_param *param;
	
// 	param = (t_param *)malloc(sizeof(t_param));
// 	param_init(param);
// 	param->mlx_ptr = mlx_init();
// 	param->win_ptr = mlx_new_window(param->mlx_ptr , 300, 300, "Hello, World!");
// 	printf("======\n");
// 	mlx_key_hook(param->win_ptr, &key_press, param);
// 	mlx_mouse_hook(param->win_ptr, &mouse_event, param);
// 	printf("======\n");
// 	mlx_loop(param->mlx_ptr);
// 	int a = mlx_clear_window(param->mlx_ptr, param->win_ptr);
// 	printf("%d",a);
// 	return (0);
// }


// //음 이러면 되려나??
 


// #include <stdio.h>  // printf()
// #include <stdlib.h> // exit()

// #define NOT_USE 0     // 안씀
// #define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자인 
// #define X_EVENT_KEY_RELEASE 3   // x_event에 들어가는 값

// #define KEY_W 13    // MacOS의 키보드 코드들이다.          
// #define KEY_A 0     //
// #define KEY_S 1     // 위에서 부터 차례대로
// #define KEY_D 2     //
// #define KEY_ESC 53  // 'W' 'A' 'S' 'D' 'ESC'들의 키보드 코드이다.



// #define MOUSE_LEFT_BUTTON 1
// #define MOUSE_RIGHT_BUTTON 2
// #define MOUSE_SCROLL_BUTTON 3
// #define MOUSE_SCROLL_UP 4
// #define MOUSE_SCROLL_DOWN 5 

// typedef struct s_mouse
// {
// 	int	mouse_keycode;

// 	int x;				// x값
// 	int y;				// y값

// 	int draw_x;			// x값
// 	int draw_y;			// y값
// }	t_mouse;

// typedef	struct s_param // 키 값을 입력 받고 정해진 동작을 수행했는지
// {                      // 여부를 판단하기 위해 선언하였다.
// 	int x;               // x값
// 	int y;               // y값
// 	int z;				 // y값
    
// 	t_mouse	mouse;

//     void	*mlx_ptr;
//     void	*win_ptr;
// } t_param;

// int key_press(int keycode, t_param *param) // 어떤 키가 눌렸는지 판단하고,
// {                                                // 정의된 행동을 수행하는 함수
// 	if (keycode == KEY_W)        // W 키를 누르면 param.x값이 1 증가한다.
// 		param->x++;
// 	else if (keycode == KEY_S)   // S 키를 누르면 param.x값이 1 감소한다.
// 		param->x--;
// 	else if (keycode == KEY_A)   // A 키를 누르면 param.y값이 1 증가한다.
// 		param->y++;
// 	else if (keycode == KEY_D)   // D 키를 누르면 param.y값이 1 감소한다.
// 		param->y--;
// 	else if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
// 		exit(0);
// 	printf("(x, y): (%d, %d)\n", param->x, param->y); // param의 값 확인
// 	return (0);
// }

// int mouse_event_down(int keycode, int x, int y, t_param *param)
// {             
// 	printf("DOWN_");
//     if (keycode == MOUSE_LEFT_BUTTON) 
//         printf("MOUSE_LEFT_BUTTON\n");
//     else if (keycode == MOUSE_RIGHT_BUTTON)
//         printf("MOUSE_RIGHT_BUTTON\n");
//     else if (keycode == MOUSE_SCROLL_BUTTON)
//         printf("MOUSE_SCROLL_BUTTON\n");
//     else if (keycode == MOUSE_SCROLL_UP)
// 	{
//         printf("MOUSE_SCROLL_UP\n");
// 		param->z++;
// 	}
//     else if (keycode == MOUSE_SCROLL_DOWN)
// 	{
//         printf("MOUSE_SCROLL_DOWN\n");
// 		param->z--;
// 	}
// 	printf("%d %d %d\n", x, y, param->z);
//     return (0);
// }

// int mouse_event_up(int keycode, int x, int y, t_param *param)
// {             
// 	printf("UP_");
//     if (keycode == MOUSE_LEFT_BUTTON) 
//         printf("MOUSE_LEFT_BUTTON\n");
//     else if (keycode == MOUSE_RIGHT_BUTTON)
//         printf("MOUSE_RIGHT_BUTTON\n");
//     else if (keycode == MOUSE_SCROLL_BUTTON)
//         printf("MOUSE_SCROLL_BUTTON\n");
//     else if (keycode == MOUSE_SCROLL_UP) // 아마 이건 작동 안할듯??
//         printf("MOUSE_SCROLL_UP\n");
//     else if (keycode == MOUSE_SCROLL_DOWN) // 아마 이건 작동안할듯??
//         printf("MOUSE_SCROLL_DOWN\n");
// 	printf("%d %d %d\n", x, y, param->z);
//     return (0);
// }

// int mouse_event_draw(int x, int y, t_param *param)
// {             
// 	printf("DRAW_");
// 	printf("key_code : \n");
// 	printf("%d %d %p\n", x, y, param);
//     return (0);
// }

// void	*ft_memset(void *b, int c, long unsigned int len)
// {
// 	unsigned char	*ptr;

// 	ptr = (unsigned char *)b;
// 	while (len-- > 0)
// 		*ptr++ = c;
// 	return (b);
// }

// int main(void)
// {
// 	t_param *param;
	
// 	param = (t_param *)malloc(sizeof(t_param));
// 	ft_memset(param, 0, sizeof(t_param));
// 	param->mlx_ptr = mlx_init();
// 	param->win_ptr = mlx_new_window(param->mlx_ptr , 300, 300, "Hello, World!");
// 	printf("======\n");
// 	mlx_key_hook(param->win_ptr, &key_press, param);
// 	mlx_mouse_hook(param->win_ptr, &mouse_event_down, param);
// 	mlx_hook(param->win_ptr, 5, NOT_USE, &mouse_event_up, param);
// 	mlx_hook(param->win_ptr, 6, NOT_USE, &mouse_event_draw, param);
// 	printf("======\n");
// 	mlx_loop(param->mlx_ptr);
// 	int a = mlx_clear_window(param->mlx_ptr, param->win_ptr);
// 	printf("%d",a);
// 	return (0);
// }
