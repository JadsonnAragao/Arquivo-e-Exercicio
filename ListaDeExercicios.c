#include<stdio.h>
#include <time.h>
#include <stdio.h>
#include <string.h>// Com base em Deitel e Paul um arquivo-lista de exercícios

struct Exercise{
    
	char lastName[15];
	char firstName[15];
	int series;
	int retry;
	int sum;
	int exer;
	char exerciseVariety[20];
	int seriesVar;
	int retryVar;
};

int List(void);
void textFiler(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void updateRead(FILE *fPtr);
void updateExer(FILE *fPtr);

int main(void)
{
	FILE *cfPtr;
	int choice;
	
	if((cfPtr = fopen("user.dat","rb+")) == NULL)
	{
		printf("Arquivo não pode ser aberto");
	}
	else
	{
		while((choice = List()) != 7)
		{
		
		  switch(choice)
		 {
		 	case 1:
		 	textFiler(cfPtr);
		 	break;
		     case 2:
		     updateRecord(cfPtr);
		     break;
		     case 3:
		     newRecord(cfPtr);
		     break;
		     case 4:
		     deleteRecord(cfPtr);
	         break;
	         case 5:
	         updateRead(cfPtr);
	         break;
	         case 6:
	         updateExer(cfPtr);
	         break;
	         default:
	         printf("Escolha incorreta");
	         break;
  }
}
	fclose(cfPtr);
}
return 0;
}
void textFiler(FILE *readPtr)
{
		 FILE *writePtr;	     
	struct Exercise activy = {"", "", 0, 0, 0, 0, "",0,0};	 
    char string1[15];
    char string2[15];
     
	if((writePtr = fopen("ListaExer.txt", "w")) == NULL)
	{
		printf("Arquivo não pode ser aberto\n");
	}
	else
	{				
		rewind(readPtr);		  		     		     	 	 
            
	  while(!feof(readPtr))
		{
			fread(&activy, sizeof(struct Exercise),1,readPtr);
		    
		 if(activy.sum != 0)
		 {     		 	
			      
     memcpy( string1,activy.lastName, 15);	
     memcpy( string2,activy.firstName, 15);		
		
			fprintf(writePtr,"\n*%s*\n",activy.exerciseVariety);
		 
		 	fprintf(writePtr,"\n%s: %d  %s: %d\n%s: %d  %s: %d\n%s: %d  %s: %d  %s:%d\n","Series",activy.series,":",activy.seriesVar,"Repetição",activy.retry,":",activy.retryVar,"Total",activy.sum,":", activy.seriesVar * activy.retryVar,"/Dias", activy.seriesVar / activy.series);
		       		   
		  }
	
		}		
	
		fprintf(writePtr,"\n%s: %s %s","Nome",string1, string2);
		fclose(writePtr);	
	}
	
}

void updateRecord(FILE *fPtr)
{
	  
	   int i;
	   int nov1;
	   int nov2;
	   char string1[15];
	   char string2[15];
   	struct Exercise activy = {"", "", 0, 0, 0, 0,"",0,0};
      
 
     printf("Digite o nome da conta: ");
   scanf("%s %s",string1,string2);
 
   fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) ) * sizeof(struct Exercise), SEEK_SET);
         
	fread(&activy, sizeof(struct Exercise),1,fPtr);	
      
if( (int)strlen(activy.lastName)  == 0)
		{
		 	printf("Não à alteração\n");
		}
		else
		{
		 	    fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) ) * sizeof(struct Exercise), SEEK_SET);
		 	   fread(&activy, sizeof(struct Exercise),1,fPtr);	
      
		 		printf("%s: %s %s\n","Nome",activy.lastName,activy.firstName);
		 	
		 	for(i = 0; i <= activy.exer; i++)
		 	{		 	
	   	  fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + i) * sizeof(struct Exercise), SEEK_SET);
         
	fread(&activy, sizeof(struct Exercise),1,fPtr);	
	   	  
	   	  printf("*%s*\n",activy.exerciseVariety);
	   	  
	   	  
	   	  
		 		printf("%5s: %d\n%5s: %d\n%5s: %d\n","Repetições",activy.retry, "Series",activy.series,"Total",activy.sum);
		 		
		 		printf("\n");
		 		
		 		printf("Adicione os novos valores: \n");
		 		printf("Repeticoes: ");
		 		scanf("%d",&nov1);
		 		printf("Series: ");
		 		scanf("%d",&nov2);
		 		activy.retry = nov1;
		 		activy.series = nov2;
		         activy.sum = activy.retry * activy.series;
	       	  activy.seriesVar += activy.series;
		 	     activy.retryVar += activy.retry;	
		 fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + i) * sizeof(struct Exercise), SEEK_SET);
		
		 	
		 	fwrite(&activy, sizeof(struct Exercise),1, fPtr);	
		 		printf("\n");
		 
		 	}
		for(i = 1; i <= activy.exer ; i++)
		{
		 		fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + i) * sizeof(struct Exercise), SEEK_SET);
		         			 												
			printf("\n%s: %d\n%s: %d\n%s: %d\n","Series",activy.series,"Repetições",activy.retry,"Soma",activy.sum);		

		 	
	 }
	
	}	
	
}
void updateExer(FILE *fPtr)
{
	   
	   int j;
	  int exe;
	   int i;	   
	   char string1[20];
	   char string2[15];
   	struct Exercise activy = {"", "", 0, 0, 0, 0,"",0,0};
      
 
     printf("Digite o nome da conta: ");
   scanf("%s %s",string1,string2);
 
   fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) ) * sizeof(struct Exercise), SEEK_SET);
         
	fread(&activy, sizeof(struct Exercise),1,fPtr);	
      
if( activy.sum == 0)
		{
		 	printf("Não à alteração\n");
		}
		else
		{
		 	 printf("Quantos exercicios:");
		 	 scanf("%d",&exe);
		 	   fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) ) * sizeof(struct Exercise), SEEK_SET);
         
	fread(&activy, sizeof(struct Exercise),1,fPtr);
		 	     
      
		 	printf("%s: %s %s\n","Nome",string1,activy.firstName);
		 	  
		 	  memcpy(activy.lastName, string1, 20);
	memcpy(activy.firstName, string2 , 15);	
		 	
		 	
		 	for(j = activy.exer;j <= activy.exer + exe; j++)
		 	{
	   	  fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + j) * sizeof(struct Exercise), SEEK_SET);
         
	fread(&activy, sizeof(struct Exercise),1,fPtr);	
	   		   memcpy(activy.lastName, string1, 20);
	memcpy(activy.firstName, string2 , 15);	 	 		
		 		printf("\n");	 		
		 		printf("Adicione o nome dos exercicios: ");
		 		scanf("%s",activy.exerciseVariety);
		 		printf("Repeticoes: ");
		 		scanf("%d",&activy.retry);
		 		printf("Series: ");
		 		scanf("%d",&activy.series);	 		
		         activy.sum = activy.retry * activy.series;
		 activy.seriesVar = activy.series;
		 	      activy.retryVar = activy.retry;
		 	      
		 fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + j) * sizeof(struct Exercise), SEEK_SET);
		
	 
	 
		 	
		 	fwrite(&activy, sizeof(struct Exercise),1, fPtr);	
		 		printf("\n");
		 
		 	}
		 	
		for(i = activy.exer; i < activy.exer + exe; i++)
		{
		 		fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + i) * sizeof(struct Exercise), SEEK_SET);
		         			 												
			printf("\n*%s*\n%s: %d\n%s: %d\n%s: %d\n",activy.exerciseVariety,"Series",activy.series,"Repetições",activy.retry,"Soma",activy.sum);		

		 	
	 }	 		
	
	   	
		 	fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) ) * sizeof(struct Exercise), SEEK_SET);
		 		fread(&activy, sizeof(struct Exercise),1,fPtr);
		 		
		 		activy.exer = activy.exer + exe;
		 			
		 			fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) ) * sizeof(struct Exercise), SEEK_SET);
		 fwrite(&activy, sizeof(struct Exercise),1, fPtr);
	  
	  
	}	
	
}
void updateRead(FILE *fPtr)
{
 	  int d;
	   int i;
	   char string1[15];
	   char string2[15];
   	struct Exercise activy = {"", "", 0, 0, 0, 0,"",0,0};
      
 
     printf("Digite o nome da conta: ");
   scanf("%s %s",string1,string2);
 memcpy( activy.lastName, string1, 15);		     		  memcpy( activy.firstName, string1, 15);		     		     		    		 
   fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) ) * sizeof(struct Exercise), SEEK_SET);
         
	fread(&activy, sizeof(struct Exercise),1,fPtr);	
      
if( (int)strlen(activy.lastName)  == 0)
		{
		 	printf("Não à alteração\n");
		}
		else
		{
		 	   memcpy( activy.lastName, string1, 15);
		 	   fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) ) * sizeof(struct Exercise), SEEK_SET);
		 	   fread(&activy, sizeof(struct Exercise),1,fPtr);	
      
		 		
		 	
		 	for(i = 0; i <= activy.exer; i++)
		 	{		 	
	   	  
	   	  memcpy( activy.lastName, string1, 15);
	   	  memcpy( activy.firstName, string2, 15);
	   	  fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + i) * sizeof(struct Exercise), SEEK_SET);
         
	fread(&activy, sizeof(struct Exercise),1,fPtr);	
	   	  
	   	  printf("*%s*\n",activy.exerciseVariety);
	   	  
		 				printf("\n%s: %s %s\n%s: %d\n%s: %d\n%s: %d\n","Nome",activy.lastName,activy.firstName,"Series",activy.series,"Repetições",activy.retry,"Soma",activy.sum);	
		 		
		 		printf("\n");
		 		
printf("Exercio cumprido?\n 1- sim e 2- nao\n");
		 		scanf("%d",&d);
		 	
		 		if(d == 1)
		 		{		 	      	 	      
		 	      activy.seriesVar += activy.series;
		 	      activy.retryVar += activy.retry;
		 	      
activy.sum = activy.retry * activy.series;
		 memcpy( activy.lastName, string1, 15);
		memcpy( activy.firstName, string2, 15);
		 
		   fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + i) * sizeof(struct Exercise), SEEK_SET);
		
		 	
		 	fwrite(&activy, sizeof(struct Exercise),1, fPtr);	
		 		printf("\n");
		 		}
		 	}
		for(i = 0; i <= activy.exer ; i++)
		{
		 		memcpy( activy.lastName, string1, 15);
	   	  memcpy( activy.firstName, string2, 15);
		 		fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + i) * sizeof(struct Exercise), SEEK_SET);		         	
	fread(&activy, sizeof(struct Exercise),1,fPtr);	   		 			
           
           									
           printf("*%s*\n",activy.exerciseVariety);																											
			printf("\n%s: %s %s\n%s: %d\n%s: %d\n%s: %d\n","Nome",activy.lastName,activy.firstName,"Series",activy.seriesVar ,"Repetições",activy.retryVar,"Soma",activy.sum + activy.sum);		

		 	
	 }	 		
		 	}
	
	
}
void deleteRecord(FILE *fPtr)
{
		 	char string1[15];
		 	
		 	struct Exercise activy;
		 	
		 	struct Exercise activyDelete = {"", "", 0, 0, 0, 0,"",0,0};
        
        printf("Insira o nome do usuario: ");
        scanf("%s %s",string1,activy.firstName);
        memcpy( activy.lastName, string1, 15);		     		     		  
        if((unsigned long)strlen(activy.lastName) == 0)
        {
        	printf("Arquivo não encontrado");
        }
        else
        {
        
     printf("\nArquivo deletado\n");

 fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName )) * sizeof(struct Exercise), SEEK_SET);
  
    fread(&activy, sizeof(struct Exercise),1,fPtr);
       
      
     for(int i = 0; i <= activy.exer + 1; i++)
     {     	
 	
fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + i) * sizeof(struct Exercise), SEEK_SET);
	 
	   fwrite(&activyDelete, sizeof(struct Exercise),1, fPtr); 
     }	
        }
}
void newRecord(FILE *fPtr)
{	
   
	char string1[15];
	int i;
	int num1;
	struct Exercise activy = {"", "", 0, 0, 0, 0,"",0, 0};     
	

	fread(&activy, sizeof(struct Exercise),1,fPtr);
		
		printf("\nInsira o Usuario: ");
	
		scanf("%s %s",string1,activy.firstName);	     
			    
			   memcpy( activy.lastName, string1, 15);		     		     		     	 	     	    		     					        		     
		 fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName )) * sizeof(struct Exercise), SEEK_SET);    		     		    fwrite(&activy, sizeof(struct Exercise),1, fPtr); 		     		     		   		     		
	 		  		     		     		     		     		  	 if(activy.sum != 0)
	 {
	 	printf("Já contém informação\n");
	 }
	 else
	 {
	 
	printf("Quantos exercicios? ");
    scanf("%d",&num1);    	
	 
	  activy.exer = num1;
	 
	 for(i = 0; i <= num1 - 1; i++)
	 {	 
	 
   printf("Digite o nome do exercicio: ");
   scanf("%s",activy.exerciseVariety);

   printf("Digite a repeticoes: ");
   scanf("%d",&activy.retry);
   printf("Digite a series:");
   scanf("%d",&activy.series);
   activy.sum = activy.retry * activy.series;
  activy.seriesVar = activy.series;
 activy.retryVar = activy.retry;	
  fseek(fPtr, ((unsigned long)strlen(activy.lastName) + strcspn( string1, activy.lastName ) + i) * sizeof(struct Exercise), SEEK_SET);    		     		     		   	 	     		     		    
   fwrite(&activy, sizeof(struct Exercise),1, fPtr); 
	 }

 
        }
}
int List(void)
{
	int menuChoice;
	
	printf("Digite sua escolha:\n"
	 "1- Armazena um arquivo de texto formatado\n"
	 "2- Atualiza uma conta\n"
	 "3- Inclue uma nova conta\n"
	 "4- Exclui uma conta\n"
	 "5- Cumpriu o dia\n"
	 "6- Adiciona o exercicio\n"
	 "7- termina o progama\n");

scanf("%d",&menuChoice);
return menuChoice;

}
