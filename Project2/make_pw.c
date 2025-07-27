#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
	int n;
	scanf_s("%d", &n);
	
	int* arr = (int*)calloc(sizeof(int), (size_t)(n + 1));
	if (!arr)
	{
		return 1;
	}

	for (int i = 1; i < n + 1 && i <= 4; i++)
	{
		arr[i] = (int)pow(2, i - 1);
	}

	for (int i = 5; i < n + 1; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			arr[i] += arr[i - j];
		}
	}

	for (int i = 0; i < n + 1; i++)
	{
		printf("%d ", arr[i]);
	}

	free(arr);

	return 0;
}