#include "include.h"

int min_sum_diagonals_dop(int square, int** Matrix)
{
	int i, j, k;
	double sum = 0;
	int min = abs(Matrix[0][1]) + abs(Matrix[1][0]);
	int check = 0;

	for (i = square - 2; i > 0; i--)// �������� �� ���������
	{
		k = i;
		for (j = 0; j < square; j++)
		{
			sum = sum + abs(Matrix[k][j]);
			k = k - 1;
			if (k == -1)
			{
				break;
			}
		}
		if (sum < min)
		{
			min = sum;
		}
		sum = 0;
	}

	for (j = 1; j < square - 1; j++)
	{
		k = j;
		for (i = square - 1; i >= 0; i--)
		{
			sum = sum + abs(Matrix[i][k]);
			k = k + 1;
			if (k == square)
			{
				break;
			}
		}

		if (sum == min)
		{
			min = sum;
		}

		else
			if (sum < min)
			{
				min = sum;
			}
		sum = 0;
	}
	return min;
}