#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int ac, char **av)
{
	if (ac != 5)
	{
		printf("gen = ./gen taille[x] taille[y] mursdifferents[w] density[z]");
		return (0);
		}
	srand(time(NULL));
	int x = atoi(av[1]);
	int y = atoi(av[2]);
	int w = atoi(av[3]);
	int z = atoi(av[4]);
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			int q = rand() % 100;
			if ((i == 0 || j == 0) || (i == y - 1 || j == x - 1))
				printf("%d ", 1);
			else if (q < z)
				printf("%d ", q % w);
			else
				printf ("0 ");
		}
		printf("\n");
	}
	return (0);
}
