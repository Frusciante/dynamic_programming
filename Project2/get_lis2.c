#include <stdio.h>
#define SEQUENCE_LEN 13

int main(void)
{
	int sequence[SEQUENCE_LEN] = { 60, 65, 50, 70, 63, 55, 45, 51, 45, 48, 54, 70, 61 };
	int lis[SEQUENCE_LEN] = { 0, };

	for (int i = 0; i < SEQUENCE_LEN; i++)
	{
		int max = 0;
		for (int j = i - 1; j > -1; j--)
		{
			if (sequence[j] > sequence[i] && lis[j] > max)
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