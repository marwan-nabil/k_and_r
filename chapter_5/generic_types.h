// change this line when using other types
#define T char *

typedef struct {
	int x;
	int y;
} point;

int compare_strings(char *, char *);
int compare_ints(int, int);
int compare_points(point, point);
