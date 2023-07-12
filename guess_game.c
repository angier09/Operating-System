#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void guess_game()
{
 	int random;
    
    srand(time(NULL));
    
    random = (rand() % 100) + 1;
    
    printf("Enter a guess for the number between 1 and 100\n");
    
    int num, tries = 0,total_tries=10;
    
    do{
       
   	scanf("%d", &num);
   	if(tries==10)
       	{
           	printf("You lost...you used up all your tries\n");
           	break;
       	}
   	if(num > random){
       	total_tries--;
       	printf("The number you entered is greater...You have %d tries left\n",total_tries);
       	tries++;
      	 
   	}
   	else if(num < random){
       	total_tries--;
       	printf("The number you entered is smaller...You have %d tries left\n",total_tries);
       	tries++;
      	 
   	}
   	else{
      	 
       	printf("\n\nCorrect Guess, You Won in %d tries!\n", tries);
      	 
   	}
   	 
    }
    while(num != random);

}

int main(void) {
    
    guess_game();
    return 0;
}






