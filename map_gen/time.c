#include <time.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	time_t t;
	time_t t1;

	time(&t);
	sleep(1);
	time(&t1);
	double frametime;
	printf("%f\n", frametime = (t1 - t) / 1000);
	printf("%f\n", 1 / frametime);
}
