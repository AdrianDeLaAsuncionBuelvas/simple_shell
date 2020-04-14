/**
 * _strcmp - Compares two strings
 * @s1: The string to test
 * @s2: The string to test
 * Return: An interer, the difference between strings
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strlen - Return the lenght of a string
 * @s: The string to test
 *
 * Return: Integer: The lenght of a string
 */
int _strlen(char *s)
{
	int contador = 0;
	int indice = 0;
	while (s[indice] != '\0')
	{
		contador++;
		indice++;
	}
	return (contador);
}