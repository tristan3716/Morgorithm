#include <stdio.h>
#include <string.h>

int main()
{
	char music[150] = { 0, };
	int A_count = 0, C_count = 0;
	int count = 0;
	scanf("%s", music);

	for (int i = 0; i < strlen(music); i++)
	{
		
		if (music[i] == '|' )
		{
			if(music[count] == 'A' || music[count] == 'D' || music[count] == 'E')
				A_count++;
			else if (music[count] == 'C' || music[count] == 'F' || music[count] == 'G')
			{
				C_count++;
			}
		}
		else
		{
			if (i != (strlen(music) - 1))
			{
				continue;
			}
			if (music[count] == 'A' || music[count] == 'D' || music[count] == 'E')
				A_count++;
			else if (music[count] == 'C' || music[count] == 'F' || music[count] == 'G')
			{
				C_count++;
			}	
		}	
		if (i != (strlen(music) - 1))
		{
			count = i + 1;
		}
	}
	if (A_count > C_count)
		printf("A-minor");
	else if (A_count == C_count)
	{
		if (music[strlen(music)-1] == 'A' || music[strlen(music) - 1] == 'D' || music[strlen(music) - 1] == 'E')
			printf("A-minor");
		else if (music[strlen(music) - 1] == 'C' || music[strlen(music) - 1] == 'F' || music[strlen(music) - 1] == 'G')
		{
			printf("C-major");
		}
	}
	else
		printf("C-major");

	return 0;
}