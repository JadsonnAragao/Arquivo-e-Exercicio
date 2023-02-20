#include <stdio.h>

struct clientData{
	
	char lastName[15];
	char firstName[10];
    int retry;
    int series;
   int sum;
};
int main(void)
{
	int i;
	
	struct clientData client = {"","",0, 0, 0, 0, "",0,0};
	
	FILE *cfPtr;
	
	if((cfPtr = fopen("user.dat", "wb") )  == NULL)
	{
	printf("Arquivo nã pode ser aberto");
	}
	else
	{
		for(i = 1; i <= 100; i++)
		{
			fwrite(&client, sizeof(struct clientData),1,cfPtr);
		}
	fclose(cfPtr);
	}
 return 0;
	}