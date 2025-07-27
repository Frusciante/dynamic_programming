#include <stdio.h>
#define COIN_CNT 4
#define GOAL_VALUE 21

int main(void)
{
	int coins[COIN_CNT] = { 1, 4, 5, 9 };
	int arr[GOAL_VALUE + 1] = { 0, };

	for (int i = 1; i < GOAL_VALUE + 1; i++)
	{
		int min = 0x7FFFFFFF;
		for (int j = 0; j < COIN_CNT; j++)
		{
			int sum_value = 0;
			if (coins[j] > i)
			{
				break;
			}

			sum_value = arr[i - coins[j]] + 1;
			if (min > sum_value) { min = sum_value; }
		}
		arr[i] = min;
	}

	arr[0] = 1;
	for (int i = 0; i < GOAL_VALUE + 1; i++)
	{
		printf("%d : %d\n", i, arr[i]);
	}
		
	return 0;
}