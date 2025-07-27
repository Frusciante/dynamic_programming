#include <stdio.h>
#include <string.h>
#define JEWEL_CNT 10
#define MAX_WEIGHT 20
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

typedef struct jewel
{
	int weight;
	int value;
}JEWEL;

int main(void)
{
	JEWEL jewels[] = { {2, 3}, {6, 5}, {2, 4}, {3, 2}, {4, 3}, {5, 3}, {4, 2}, {6, 6}, {7, 9}, {10, 8} };
	int dp_matrix[JEWEL_CNT][MAX_WEIGHT + 1];
	memset(dp_matrix, -1, JEWEL_CNT * MAX_WEIGHT * sizeof(int));

	dp_matrix[0][jewels[0].weight] = jewels[0].value;
	dp_matrix[0][0] = 0;

	for (int i = 1; i < JEWEL_CNT; i++)
	{
		dp_matrix[i][0] = 0;
		for (int j = 0; j < MAX_WEIGHT + 1; j++)
		{
			int weight_remainder = j - jewels[i].weight;
			if (weight_remainder >= 0 && dp_matrix[i - 1][weight_remainder] != -1)
			{
				int test_value = dp_matrix[i - 1][weight_remainder] + jewels[i].value;
				dp_matrix[i][j] = MAX(test_value, dp_matrix[i - 1][j]);
			}
			else
			{
				dp_matrix[i][j] = dp_matrix[i - 1][j];
			}
		}
	}

	for (int i = 0; i < JEWEL_CNT; i++)
	{
		for (int j = 0; j < MAX_WEIGHT + 1; j++)
		{
			printf("%2d ", dp_matrix[i][j]);
		}
		puts("");
	}

	return 0;
}