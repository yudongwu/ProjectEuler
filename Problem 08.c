#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char *buffer;
	int i = 0, j = 0;

	fp = fopen("E://file.txt", "r");

	char c;

	while ((c = fgetc(fp))) {
		if (c == EOF)
			break;
		else if (c != '\n')
			i++;
	}
	buffer = (char *)malloc(i * sizeof(char));
	rewind(fp);
	while ((c = fgetc(fp))) {
		if (c == EOF)
			break;
		else if (c != '\n') {
			*(buffer + j) = c;
			j++;
		}
	}
	findmax(buffer, i);
}

int findmax(char *buffer, int i)
{
	int j = 0, max = 0;

	for (j = 0; j < i - 4; j++) {
		if (max < ((buffer[j] - '0') * (buffer[j + 1] - '0') * (buffer[j + 2] - '0') * (buffer[j + 3] - '0') * (buffer[j + 4] - '0')))
			max = ((buffer[j] - '0') * (buffer[j + 1] - '0') * (buffer[j + 2] - '0') * (buffer[j + 3] - '0') * (buffer[j + 4] - '0'));

	}
	printf("\n%d", max);
	return 0;

}

//Answer:40824
