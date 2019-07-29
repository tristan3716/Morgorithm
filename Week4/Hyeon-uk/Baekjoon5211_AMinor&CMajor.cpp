#include <stdio.h>
#include <string.h>

int main() {
	char in[101];
	scanf("%s", in);

	int ccount = 0;
	int acount = 0;

	for (unsigned int i = 0; i < strlen(in); ++i) {
		if (i == 0 || in[i - 1] == '|') {
			if (in[i] == 'A' || in[i] == 'D' || in[i] == 'E')
				acount++;

			if (in[i] == 'C' || in[i] == 'F' || in[i] == 'G')
				ccount++;
		}
	}
	if (ccount == acount) {
		char last = in[strlen(in) - 1];
		if (last == 'A' || last == 'D' || last == 'E')
			acount++;
		if (last == 'C' || last == 'F' || last == 'G')
			ccount++;
	}

	if (acount > ccount)
		printf("A-minor\n");
	else
		printf("C-major\n");

	return 0;
}