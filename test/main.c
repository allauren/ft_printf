
#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	char* str="alexis";
	write(1,"\0",1);
	printf("\n%c", 0);
//	printf("4567 |%.6d 12.5 f| plip\n", 42);
//	printf("4567 |%10d| plip\n", 102);
//	printf("|%.100s|\n", "je suis alexis");
//	printf("|%100x|\n",1024); 
	return 0;
}
