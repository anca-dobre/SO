/**
  * SO, 2016
  * Lab #5
  *
  * Task #4, lin
  *
  * Use of gdb to solve "Segmentation fault" problems
  */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

char *read_message()
{
	char *buf;

	buf = malloc(BUFSIZ * sizeof(*buf));
	DIE(buf == NULL, "malloc");

	printf("Give input string: ");
	fgets(buf, 1024, stdin);

	/*
	 * cand se returneaza un pointer la o variabila locala,
	 * compilatorul se prinde ca zona aia se va suprascrie la urmatorul
	 * apel de functie, asa ca returneaza el NULL.
	 */
	return buf;
}

void upper_string(char *msg)
{
	int i = 0;

	while (msg[i] != '\0') {
		if (msg[i] >= 'a' && msg[i] <= 'z')
			msg[i] -= 32;
		i++;
	}
}

int main(void)
{
	char *message;

	message = read_message();

	upper_string(message);

	printf("\n\nString is %s\n", message);

	free(message);

	return 0;
}
