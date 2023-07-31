#include "mlx.h"
#include "math.h"

#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_vars
{
    void *mlx;
    void *win;
} t_vars;

typedef struct s_rectangle
{
    int x; // 좌측 상단 모서리 x 좌표
    int y; // 좌측 상단 모서리 y 좌표
    int width;
    int height;
    int color;
} t_rectangle;

// 각도를 라디안으로 변환하는 매크로
#define DEG2RAD(deg) ((deg)*M_PI / 180.0)

// 좌표 회전 함수
void rotate_point(double angle, int *x, int *y)
{
    double radian_angle = DEG2RAD(angle);
    int new_x = (*x - WIDTH / 2) * cos(radian_angle) - (*y - HEIGHT / 2) * sin(radian_angle) + WIDTH / 2;
    int new_y = (*x - WIDTH / 2) * sin(radian_angle) + (*y - HEIGHT / 2) * cos(radian_angle) + HEIGHT / 2;
    *x = new_x;
    *y = new_y;
}

void draw_rectangle(t_vars *vars, t_rectangle rect)
{
    int x;
    int y;

    // 좌측 상단 모서리에서 시작하여 사각형 그리기
    y = rect.y;
    while (y < rect.y + rect.height)
    {
        x = rect.x;
        while (x < rect.x + rect.width)
        {
            int rotated_x = x;
            int rotated_y = y;
            // 좌표 회전 적용
            rotate_point(30, &rotated_x, &rotated_y);
            mlx_pixel_put(vars->mlx, vars->win, rotated_x, rotated_y, rect.color);
            x += 10;
        }
        y += 10;
    }
}

int main(void)
{
    t_vars vars;
    t_rectangle rectangle;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Rectangle Drawing");

    rectangle.x = 960;
    rectangle.y = 540;
    rectangle.width = 500;
    rectangle.height = 250;
    rectangle.x = 960 - rectangle.width / 2;
    rectangle.y = 540 - rectangle.height / 2;
    rectangle.color = 0x00FF0000; // Red color in hexadecimal format (0xRRGGBBAA)

    // 사각형 그리기 함수 호출
    draw_rectangle(&vars, rectangle);

    mlx_loop(vars.mlx);
    return (0);
}
