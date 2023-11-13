#include <stdio.h>
#include <stdlib.h>

/**
 * add_numbers - Add numbers and also return th result.
 * @nma: The first num to add.
 * @mpa: The second num to add.
 *
 * Return: Sum of nma and mpa or 0 on success.
 */
int add_numbers(int nma, int mpa)
{
	return (nma + mpa);
}

/**
 * main - main point.
 *
 * Return: 0 on success.
 */
int main(void)
{
	int result = add_numbers(10, 13);

	printf("Result: %d\n", result);

	return (0);
}
