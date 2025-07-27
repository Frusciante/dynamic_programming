#include <stdio.h>
#define SEQUENCE_LEN 10

int main(void)
{
	int sequence[SEQUENCE_LEN] = { 20, 80, 10, 50, 55, 20, 60, 70, 5, 90 };
	int lis[SEQUENCE_LEN] = { 0, };

	for (int i = 0; i < SEQUENCE_LEN; i++)
	{
		int max = 0;
		for (int j = i - 1; j > -1; j--)
		{
			if (sequence[j] < sequence[i] && lis[j] > max)
			{
				max = lis[j];
			}
		}
		lis[i] = max + 1;
	}

	for (int i = 0; i < SEQUENCE_LEN; i++)
	{
		printf("%d ", lis[i]);
	}

	return 0;
}