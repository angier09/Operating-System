#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<stdbool.h>

void hangman()
{
 FILE * fp;
  char * line = NULL;
  size_t len = 0;
  int read;
  int random;
  int count=0;
  int total_tries=6;
  int tries=0;
  char guess;
  int flag=0;;
  bool check=false;
  int j=0;
    
  srand(time(NULL));
  random = (rand() % 5) + 1;
//  printf("random number= %d\n",random);


  fp = fopen("words.txt", "r");
  if (fp == NULL)
    	exit(EXIT_FAILURE);

  while((read = getline(&line, &len, fp)) != -1)
  {    
   	count++;
   	if(count==random)
   	{
      	break;
   	}
  }
 
  fclose(fp);
 
  char* arr;
  arr = (char*)malloc ( read * sizeof (char));

//  printf("word= %s\n",line);

  for(int i=0;i<read-1;i++)
  {
 	arr[i]='_';
  }

  printf("word is %d lengths long...",read-1);

  while(tries<total_tries){
 	printf("Enter guess: ");
 	scanf(" %c",&guess);
 	printf("\n");

	printf("character entered = ");
	printf("%c",guess);
	printf("\n");

 	for(int i=0;i<read-1;i++)
 	{
     	if(guess==line[i])
     	{
       	flag=1;
       	arr[i]=line[i];
     	}
 	}

 	if(flag==0)
 	{
    	tries++;
    	printf("guessed letter doesn't exist...you have %d tries left\n",total_tries-tries);
 	}

 	flag=0;
	 
 	printf("guessed soo far: ");
 	for(int i=0;i<read-1;i++)
 	{
     	printf("%c",arr[i]);
 	}
 	printf("\n");
 	for(int i=0;i<read-1;i++)
 	{
    	if(arr[i]!='_')
    	{
      	j++;
    	}
 	}

 	if(j==read-1)
 	{
    	printf("\n\nYOU WON!!\n");
    	return;
 	}
 	j=0;
  }

	printf("\n\nYou Lost!! The word was %s",line);

}
int main(void)
{
   hangman();

   return 0;
}





