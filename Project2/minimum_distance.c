#include <stdio.h>
#define MAX(N, M) (((N) > (M)) ? (N) : (M))

int main(void)
{	
	int matrix[8][8] =
	{
		{ 9, 6, 1, 5, 3, 7, 8, 5 },
		{ 3, 4, 2, 5, 7, 8, 7, 9 },
		{ 8, 7, 7, 6, 4, 3, 5, 7 },
		{ 3, 6, 8, 9, 5, 7, 7, 9 },
		{ 8, 7, 6, 2, 3, 5, 6, 8 },
		{ 1, 2, 3, 4, 5, 2, 3, 5 },
		{ 9, 8, 7, 6, 8, 3, 4, 5 },
		{ 6, 5, 4, 6, 3, 7, 9, 9 }
	};

	int sum_matrix[8][8] = { 0, };

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i && j))
			{
				sum_matrix[i][j] = MAX(sum_matrix[i - 1][j], sum_matrix[i][j - 1]) + matrix[i][j];
			}
			else
			{
				if (!i && j)
				{
					sum_matrix[i][j] = sum_matrix[i][j - 1] + matrix[i][j];
				}
				else if (!j && i)
				{
					sum_matrix[i][j] = sum_matrix[i - 1][j] + matrix[i][j];
				}
				else
				{
					sum_matrix[i][j] = matrix[i][j];
				}
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d ", sum_matrix[i][j]);
		}
		puts("");
	}

	return 0;
}