#include <stdio.h>
#include <string.h>
#define STR_LEN 30
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int main()
{
	char str1[STR_LEN + 1], str2[STR_LEN + 1];
	int lcs_matrix[STR_LEN][STR_LEN] = { 0, };

	fgets(str1, STR_LEN + 1, stdin);
	fgets(str2, STR_LEN + 1, stdin);

	str1[strlen(str1) - 1] = 0;
	str2[strlen(str2) - 1] = 0;

	int str1_len = strlen(str1);
	int str2_len = strlen(str2);

	if (str1_len < 1 || str2_len < 1)
	{
		return 1;
	}

	lcs_matrix[0][0] = (str1[0] == str2[0]) ? 1 : 0;

	for (int j = 1; j < str2_len; j++)
	{
		lcs_matrix[0][j] = (str1[0] == str2[j]) ? 1 : lcs_matrix[0][j - 1];
	}

	for (int i = 1; i < str1_len; i++)
	{
		lcs_matrix[i][0] = (str1[i] == str2[0]) ? 1 : lcs_matrix[i - 1][0];

		for (int j = 1; j < str2_len; j++)
		{
			if (str1[i] == str2[j])
			{
				lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1;
			}
			else
			{
				lcs_matrix[i][j] = MAX(lcs_matrix[i][j - 1], lcs_matrix[i - 1][j]);
			}
		}
	}

	for (int i = 0; i < str1_len; i++)
	{
		for (int j = 0; j < str2_len; j++)
		{
			printf("%d ", lcs_matrix[i][j]);
		}
		puts("");
	}

	printf("distance between strings : %d", str1_len + str2_len - lcs_matrix[str1_len - 1][str2_len - 1] * 2);

	return 0;
}