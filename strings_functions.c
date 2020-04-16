#include "shell.h"
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

/**
 * _strcat - Concatenates two strings
 * @src: String 1
 * @dest: String 2
 * Return: A new string concatenated
 */
char *_strcat(char *src, char *dest)
{
	int i;
	int j;
	char *concatenated;

	concatenated = malloc(1 + _strlen(src) + _strlen(dest));

	for (i = 0; src[i] != '\0'; i++)
	{
		concatenated[i] = src[i];
	}

	for (j = 0; dest[j] != '\0'; j++)
	{
		concatenated[i + j] = dest[j];
	}
	concatenated[i + j] = '\0';

	return (concatenated);
}