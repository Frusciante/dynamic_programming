#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
	const char* str_a = "abbbdaaa";
	const char* str_b = "badabbdba";
	size_t str_a_len = strlen(str_a) + 1;
	size_t str_b_len = strlen(str_b) + 1;

	int** distance_matrix = (int**)malloc(str_a_len * sizeof(int*));
	if (!distance_matrix)
	{
		return 1;
	}

	for (int i = 0; i < str_a_len; i++)
	{
		distance_matrix[i] = (int*)malloc(str_b_len * sizeof(int));
		if (!distance_matrix[i])
		{
			return 1;
		}
		memset(distance_matrix[i], 0x7FFFFFFF, str_b_len * sizeof(int));
	}

	// ���̰� i�� ���ڿ��� ���̰� 0�� ���ڿ��� �Ÿ��� i
	for (int i = 0; i < str_a_len; i++)
	{
		distance_matrix[i][0] = i;
	}

	// ���������� ���̰� j�� ���ڿ��� ���̰� 0�� ���ڿ��� �Ÿ��� j
	for (int j = 0; j < str_b_len; j++)
	{
		distance_matrix[0][j] = j;
	}

	for (int i = 1; i < str_a_len; i++)
	{
		for (int j = 1; j < str_b_len; j++)
		{
			if (str_a[i - 1] == str_b[j - 1])
			{
				distance_matrix[i][j] = distance_matrix[i - 1][j - 1];
			}
			else
			{
				if (distance_matrix[i][j - 1] < distance_matrix[i - 1][j])
				{
					distance_matrix[i][j] = (distance_matrix[i - 1][j - 1] < distance_matrix[i][j - 1] ? distance_matrix[i - 1][j - 1] : distance_matrix[i][j - 1]) + 1;
				}
				else
				{
					distance_matrix[i][j] = (distance_matrix[i - 1][j - 1] < distance_matrix[i - 1][j] ? distance_matrix[i - 1][j - 1] : distance_matrix[i - 1][j]) + 1;
				}
			}
		}
	}

	for (int i = 0; i < str_a_len; i++)
	{
		for (int j = 0; j < str_b_len; j++)
		{
			printf("%d ", distance_matrix[i][j]);
		}
		puts("");
	}

	for (int i = 0; i < str_a_len; i++)
	{
		free(distance_matrix[i]);
	}
	free(distance_matrix);

	return 0;
}