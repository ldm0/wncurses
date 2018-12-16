#include<Windows.h>
#include<wncurses.h>
#include<math.h>
#include<time.h>


struct vec2 {
	float x, y;
};

struct vec3 {
	float x, y, z;
};

struct Ray {
	struct vec3 o, d;
};

float length(struct vec3 a)
{
	return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

struct vec3 cross(struct vec3 a, struct vec3 b)
{
	struct vec3 r;
	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return r;
}

//Gray val
float ball(struct vec2 coord, float time)
{
	struct vec2 uv;
	uv.x = coord.x;
	uv.y = coord.y;

	struct Ray r = {
		{0.f, 0.f, -10.f},
		{uv.x, uv.y, 0.f}
	};
	struct vec3 p = {cosf(time/20.f), 0.f, 50.f + 25.f * sinf(time/20.f)};
	struct vec3 tmp1;
	tmp1.x = r.d.x - r.o.x;
	tmp1.y = r.d.y - r.o.y;
	tmp1.z = r.d.z - r.o.z;
	struct vec3 tmp2;
	tmp2.x = p.x - r.o.x;
	tmp2.y = p.y - r.o.y;
	tmp2.z = p.z - r.o.z;
	return length(cross(tmp1, tmp2)) / length(tmp1);
}

void test_ball(void)
{
	initscr();
	curs_set(0);
	struct vec2 uv;
	clock_t time;
	for(;;) {
		time = clock();
		for(int y = 0; y < LINES; ++y) {
			move(y, 0);
			for (int x = 0; x < COLS; ++x) {
				//ray casting
				uv.x = ((float)x - COLS / 2) / (float)COLS;
				uv.y = ((float)y - LINES / 2) / (float)LINES / 2.f;
				addch('a' + (ball(uv,time / 50.f) * 10));
			}
		}
		refresh();
		Sleep(100);
	}
	getch();
	endwin();
}

