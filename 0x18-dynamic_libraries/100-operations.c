int add(int n, int m);
int sub(int n, int m);
int mul(int n, int m);
int div(int n, int m);
int mod(int n, int m);

/**
* add - adds two integers
* @n: first integer to add
* @m: second integer to add
* Return: the sum
*/

int add(int n, int m)
{
	return (n + m);
}

/**
* sub - subtracts two integers
* @n: first integer to add
* @m: second integer to add
* Return: the subtract
*/

int sub(int n, int m)
{
	return (n - m);
}

/**
* mul - multiplies two integers
* @n: first integer to add
* @m: second integer to add
* Return: the multiple
*/

int mul(int n, int m)
{
	return (n * m);
}

/**
* div - divideds two integers
* @n: first integer to add
* @m: second integer to add
* Return: the dividend integer
*/

int div(int n, int m)
{
	return (n / m);
}

/**
  mod - finds the modulus of two integers
  @n: first integer to add
  @m: second integer to add
  Return: the modulus
*/

int mod(int n, int m)
{
	return (n % m);
}
