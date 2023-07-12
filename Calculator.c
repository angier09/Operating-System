#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t lock;

double result=0;
double number=0;
double number2=0;

void* Addition(void* arg)
{
pthread_mutex_lock(&lock);
result=result+number;
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}

void* Subtraction(void* arg)
{
pthread_mutex_lock(&lock);
result=number-number2;
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}

void* Multiplication(void* arg)
{
pthread_mutex_lock(&lock);
result=number*number2;
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}

void* Division(void* arg)
{
pthread_mutex_lock(&lock);
result=number/number2;
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}

int main()
{

pthread_t thread1;
pthread_mutex_init(&lock,NULL);
printf("------------------------\n");
printf("       Calculator\n");
printf("------------------------\n");
printf("q -> quit\n");
printf("U -> Undo\n");
printf("+ -> Addition\n");
printf("- -> Subtraction\n");
printf("* -> Multiplication\n");
printf("/ -> Division\n");
char choice;
//first time two variables will be entered

printf("Enter Number = ");
scanf("%lf",&number);
printf("Enter Number = ");
scanf("%lf",&number2);
printf("Enter Operator: ");
scanf(" %c",&choice);
switch(choice)
{
case '+':
{
result=number+number2;
break;
}
case '-':
{
result=number-number2;
break;
}
case '/':
{
if(number == 0)
{
printf("ERROR! Division by zero\n");
break;
}
else
{
result=number/number2;
break;
}
}
case '*':
{
result=number*number2;
break;
}
default:
{
printf("ERROR! Invalid Operator\n");
break;
}
}
printf("\nRESULT = %lf\n",result);

//loop user can enter as many number
//loop will end when q pressed
while(choice != 'q' ||choice != 'q')
{
printf("Enter Operator: ");
scanf(" %c",&choice);
if(choice == 'q' || choice == 'Q')
{
printf("----- EXIT-----\n");
break;
}
printf("Enter Number = ");
scanf("%lf",&number);
switch(choice)
{
case '+':
{
pthread_create(&thread1, NULL, Addition, NULL);
pthread_join(thread1, NULL);
break;
}
case '-':
{
pthread_create(&thread1, NULL, Subtraction, NULL);
pthread_join(thread1, NULL);
break;
}
case '/':
{
if(number == 0)
{
printf("ERROR! Division by zero\n");
break;
}
else
{
pthread_create(&thread1, NULL, Division, NULL);
pthread_join(thread1, NULL);
break;
}
}
case '*':
{
pthread_create(&thread1, NULL,Multiplication, NULL);
pthread_join(thread1, NULL);
break;
}
case 'u':
{
printf("Undo! Input Again\n");
break;
}
default:
{
printf("ERROR! Invalid Operator\n");
break;
}
}
printf("\nRESULT = %lf\n",result);
}

//showing output
printf("\n\nRESULT = %lf\n\n",result);
pthread_mutex_destroy(&lock);
return 0;
}


