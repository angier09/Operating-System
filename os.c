#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include <string.h>
#include <sys/types.h>
#include<pthread.h>

typedef struct {
	char name[256];
	pid_t pid; 
        float execution_time;
} Process;

typedef struct Node {
	Process process;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
	int size;
} Queue;

void init(Queue* q) {
	q->front = q->rear = NULL;
	q->size = 0;
}

int is_empty(Queue* q) {
	return q->size == 0;
}

void enqueue(Queue* q, Process process) {
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->process = process;
	new_node->next = NULL;

	if (is_empty(q)) {
    	q->front = q->rear = new_node;
	} else {
    	q->rear->next = new_node;
    	q->rear = new_node;
	}

	q->size++;
}

Process dequeue(Queue* q) {
	if (is_empty(q)) {
    	printf("Error: Queue is empty\n");
    	exit(EXIT_FAILURE);
	}

	Node* temp = q->front;
	Process process = temp->process;
	q->front = q->front->next;
	free(temp);
	q->size--;

	if (q->front == NULL) {
    	q->rear = NULL;
	}

	return process;
}

void display(Queue* q) {
	if (is_empty(q)) {
    	printf("Queue is empty\n");
    	return;
	}
	printf("\nReady queue: \n");

	Node* temp = q->front;
	while (temp != NULL) {
    	printf("%s \n", temp->process.name);
    	temp = temp->next;
	}
	printf("\n");
}

void dequeue_by_name(Queue* q, char* name) {
	if (is_empty(q)) {
    	printf("Error: Queue is empty\n");
    	return;
	}

	Node* current = q->front;
	Node* prev = NULL;
	int count = 0;

	while (current != NULL) {
    	if (strcmp(current->process.name, name) == 0) {
        	if (current == q->front) {
            	q->front = current->next;
        	} else if (current == q->rear) {
            	prev->next = NULL;
            	q->rear = prev;
        	} else {
            	prev->next = current->next;
        	}

        	Node* temp = current;
        	current = current->next;
        	free(temp);
        	q->size--;
        	count++;
    	} else {
        	prev = current;
        	current = current->next;
    	}
	}

	if (count == 0) {
    	printf("Error: Process not found\n");
	} else {
    	printf("Dequeued %d processes with name '%s' from ready queue\n\n", count, name);
	}
}

FILE*f;




void* loop(void*arg)
{
    Queue* q=(Queue*)arg;
    Node* current=q->front;

        while(current!=NULL)
        {
            current->process.execution_time=current->process.execution_time+0.02;
            fprintf(f,"%s    %f\n",current->process.name,current->process.execution_time);
            current=current->next;
            
        }


}


int main(int argc,char *argv[])
{

	Queue ready_queue;
	init(&ready_queue);
        pthread_t execution,menu;
        f=fopen("executionTime.txt","w");
        if(f==NULL)
        { printf("ERROR opening execution file\n");}
	int ram_in_usage=1500;
	int ram_unitconverter=300;
	int ram_texteditor=1000;
	int ram_alarm=150;
	int ram_login=100;
	int ram_calculator=400;
	int ram_candycrush=700;
	int ram_calander=200;
	int ram_tictactoe=500;
	int ram_guessgame=400;
	int ram_hangman=450;
	int ram_bmi=300;
	int ram_msgapp=1000;
	int ram_stopwatch=250;
	int ram_minesweeper=800;
	int ram_pacman=1200;
	int ram=atoi(argv[1]);
	int storage=atoi(argv[2]);
	int cores=atoi(argv[3]);
	int reserve_memory=1500;  //mb
	int in;
	int choice=0;
	pid_t pid;
	int is_running_alarm=0;
	int is_running_texteditor=0;
	int is_running_login=0;
	int is_running_unitconverter=0;
	int is_running_calculator=0;
	int is_running_candycrush=0;
	int is_running_calender=0;
	int is_running_tictactoe=0;
	int is_running_guessgame=0;
	int is_running_hangman=0;
	int is_running_bmi=0;
	int is_running_msgapp=0;
	int is_running_stopwatch=0;
	int is_running_minesweeper=0;
	int is_running_pacman=0;
	int is_running_askpassword=0;
    
	ram=ram*1000; 	//changing gb to mb
	if(ram<reserve_memory)
	{
       	printf("Not enough memory to start the os!!\n");
       	return 0;
	}
	printf("WIN MAC\n\n");
	fflush(stdout);
	printf("Loading...........\n\n");
	fflush(stdout);
	printf("....................Welcome To WIN MAC...............\n\n");
    
	sleep(2);

    
    
	system("gcc -o alaram alaram.c -lpthread");
	system("g++ -o texteditor texteditor.cpp -lpthread");
	system("gcc -o login login.c");
	system("gcc -o unitconverter unitconverter.c");
	system("gcc -o Calculator Calculator.c -lpthread");
	system("g++ -o candyCrush candyCrush.cpp");
	system("g++ -o Calendar Calendar.cpp");
	system("g++ -o TicTacToe TicTacToe.cpp");
	system("gcc -o guess_game guess_game.c");
	system("gcc -o hangman hangman.c");
	system("gcc -o bmi_calculator bmi_calculator.c");
	system("gcc -o msg_app msg_app.c");
	system("g++ -o stopWatch stopWatch.cpp");
	system("g++ -o MineSweeper MineSweeper.cpp");
	system("g++ -o pacman pacman.cpp");
	system("gcc -o askpassword askpassword.c");
    
	system("./askpassword");



	while(1)
	{
    	printf("0. Kernel mode\n\n");
    	printf("1. Unit Convertor\n\n");
    	printf("2. Text Editor\n\n");
    	printf("3. Set Alaram\n\n");
    	printf("4. Remove/Set Password\n\n");
    	printf("5. Calculator\n\n");
    	printf("6. Candy Crush\n\n");
    	printf("7. Calendar\n\n");
    	printf("8. Tic Tac Toe\n\n");
    	printf("9. Guess Game\n\n");
    	printf("10. Hangman\n\n");
    	printf("11. BMI Calculator\n\n");
    	printf("12. Msg  App\n\n");
    	printf("13. Stop Watch\n\n");
    	printf("14. Packman\n\n");
    	printf("15. MineSweeper\n\n");
    	printf("16. display ready queue\n\n");
    	printf("17. Shutdown\n\n");
    	printf("Select Option: ");
    	scanf("%d",&in);
   	 
    	 
    	if(in==0)
    	{
      	while(choice!=16) {
    		 printf("1. End Unit Convertor\n\n");
       		 printf("2. End Text Editor\n\n");
       		 printf("3. End Set Alaram\n\n");
      		 printf("4. End Remove/Set Password\n\n");
     		 printf("5. End Calculator\n\n");
       		 printf("6. End Candy Crush\n\n");
       		 printf("7. End Calendar\n\n");
       		 printf("8. End Tic Tac Toe\n\n");
      		 printf("9. End Guess Game\n\n");
       		 printf("10. End Hangman\n\n");
       		 printf("11. End BMI Calculator\n\n");
       		 printf("12. End Msg  App\n\n");
       		 printf("13. End Stop Watch\n\n");
       		 printf("14. End Packman\n\n");
       		 printf("15. End MineSweeper\n\n");
       		 printf("16. go back to user mode\n\n");
       		 printf("enter Option: ");
       		 scanf("%d",&choice); 
                 
                 pthread_create(&execution,NULL,loop,(void*)&ready_queue);
                 pthread_join(execution,NULL);
           	 
            	switch(choice){

               	case 1:
                   	if(is_running_unitconverter){
                      	printf("unit converter is not running\n");
                   	}
                   	else
                   	{
                      	is_running_unitconverter=0;
                      	system("pkill unitconverter");
                      	ram_in_usage=ram_in_usage-ram_unitconverter;
                      	dequeue_by_name(&ready_queue,"unit converter");
                   	}
                  	break;
               	case 2:
                   	if(is_running_texteditor){
                      	printf("text editor is not running\n");
                   	}
                   	else
                   	{
                      	is_running_texteditor=0;
                      	system("pkill texteditor");
                      	ram_in_usage=ram_in_usage-ram_texteditor;
                      	dequeue_by_name(&ready_queue,"text editor");
                   	}
                  	break;
               	case 3:
                   	if(is_running_alarm){
                      	printf("alarm is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill alaram");

                      	ram_in_usage=ram_in_usage-ram_alarm;
                   	}
                  	break;
               	case 4:
                   	if(is_running_login){
                      	printf("login is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill login");
                      	ram_in_usage=ram_in_usage-ram_login;
                   	}
                  	break;
               	case 5:
                   	if(is_running_calculator){
                      	printf("calculator is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill Calculator");
                      	ram_in_usage=ram_in_usage-ram_calculator;
                   	}
                  	break;
               	case 6:
                   	if(is_running_candycrush){
                      	printf("candy crush is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill  candyCrush");
                      	ram_in_usage=ram_in_usage-ram_candycrush;
                   	}
                  	break;
               	case 7:
                   	if(is_running_calender){
                      	printf("Calender is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill Calendar");
                      	ram_in_usage=ram_in_usage-ram_calander;
                   	}
                  	break;
               	case 8:
                   	if(is_running_tictactoe){
                      	printf("Tic Tac Toe is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill TicTacToe");
                      	ram_in_usage=ram_in_usage-ram_tictactoe;
                   	}
                  	break;
               	case 9:
                   	if(is_running_guessgame){
                      	printf("guess game is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill guess_game");
                      	ram_in_usage=ram_in_usage-ram_guessgame;
                   	}
                  	break;
               	case 10:
                   	if(is_running_hangman){
                      	printf("hangman is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill hangman");
                      	ram_in_usage=ram_in_usage-ram_hangman;
                   	}
                  	break;
               	case 11:
                   	if(is_running_bmi){
                      	printf("BMI calculator is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill bmi_calculator");
                      	ram_in_usage=ram_in_usage-ram_calculator;
                   	}
                  	break;
               	case 12:
                   	if(is_running_msgapp){
                      	printf("msg app is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill msg_app");
                      	ram_in_usage=ram_in_usage-ram_msgapp;
                   	}
                  	break;
               	case 13:
                   	if(is_running_stopwatch){
                      	printf("stop watch is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill stopWatch");
                      	ram_in_usage=ram_in_usage-ram_stopwatch;
                   	}
                  	break;
               	case 14:
                   	if(is_running_minesweeper){
                      	printf("Mine Sweeper is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill MineSweeper");
                      	ram_in_usage=ram_in_usage-ram_minesweeper;
                   	}
                  	break;
               	case 15:
                   	if(is_running_pacman){
                      	printf("Pacman is not running\n");
                   	}
                   	else
                   	{
                      	system("pkill pacman");
                      	ram_in_usage=ram_in_usage-ram_pacman;
                   	}
                  	break;
                	case 16:
                  	break;
               	default:
                   	printf("Wrong input enter again...\n");


            	}
       	}
        	choice=0;
    	}
        pthread_create(&execution,NULL,loop,(void*)&ready_queue);
        pthread_join(execution,NULL);
    	switch(in){
      	case 1:
         	printf("requesting ram...\n");
         	if((ram_in_usage+ram_unitconverter)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_unitconverter;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "unit converter");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 2:
         	if((ram_in_usage+ram_texteditor)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_texteditor;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "text editor");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	} 	 
         	break;
      	case 3:
         	if((ram_in_usage+ram_alarm)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_alarm;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "Alarm");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 4:
         	if((ram_in_usage+ram_login)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_login;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "login");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 5:
         	if((ram_in_usage+ram_calculator)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_calculator;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "calculator");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 6:
         	if((ram_in_usage+ram_candycrush)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_candycrush;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "candy crush");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 7:
         	if((ram_in_usage+ram_calander)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_calander;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "calander");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 8:
         	if((ram_in_usage+ram_tictactoe)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_tictactoe;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "tic tac toe");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 9:
         	if((ram_in_usage+ram_guessgame)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_guessgame;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "guess game");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 10:
         	if((ram_in_usage+ram_hangman)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_hangman;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "hangman");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 11:
         	if((ram_in_usage+ram_bmi)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_bmi;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "bmi calculator");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 12:
         	if((ram_in_usage+ram_msgapp)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_msgapp;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "msg app");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 13:
         	if((ram_in_usage+ram_stopwatch)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_stopwatch;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();

             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "stopwatch");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 14:
         	if((ram_in_usage+ram_minesweeper)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_minesweeper;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "minesweeper");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;
      	case 15:
         	if((ram_in_usage+ram_pacman)<ram)
         	{
              	ram_in_usage=ram_in_usage+ram_pacman;
              	printf("ram in usage= %d\n",ram_in_usage);             	 
              	pid=fork();
             	 
              	Process* process = (Process*) malloc(sizeof(Process));
              	sprintf(process->name, "pacman");
              	process->pid = getpid();

              	enqueue(&ready_queue, *process);
         	}
         	else
         	{
              	printf("Not enough ram available to run the process...\n");
         	}
         	break;

    	}

    	if(pid==0 && in == 1) { is_running_unitconverter=1;
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./unitconverter", NULL);
         	}
    	if(pid==0 && in == 2){
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./texteditor", NULL);
        	is_running_texteditor=1; }
    	if(pid==0 && in == 3){
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./alaram", NULL);
        	is_running_alarm=1;  }
    	if(pid==0 && in == 4) {
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./login", NULL);
        	is_running_login=1;  }
    	if(pid==0 && in == 5) {
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./Calculator", NULL);
        	is_running_calculator=1;  }
    	if(pid==0 && in == 6) {
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./candyCrush", NULL);
        	is_running_candycrush=1;  }
    	if(pid==0 && in == 7){
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./Calendar", NULL);
        	is_running_calender=1;   }
    	if(pid==0 && in == 8){
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./TicTacToe", NULL);
        	is_running_tictactoe=1;   }
    	if(pid==0 && in == 9){
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./guess_game", NULL);
        	is_running_guessgame=1;   }
    	if(pid==0 && in == 10) {
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./hangman", NULL);
        	is_running_hangman=1;   }
    	if(pid==0 && in == 11) {
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./bmi_calculator", NULL);
        	is_running_bmi=1;   }
    	if(pid==0 && in == 12)  {
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./msg_app", NULL);
        	is_running_msgapp=1;   }
    	if(pid==0 && in == 13) {
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./stopWatch", NULL);
        	is_running_stopwatch=1;   }
    	if(pid==0 && in == 14) {
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./MineSweeper", NULL);
        	is_running_minesweeper=1;   }
    	if(pid==0 && in == 15)  {
        	execl("/usr/bin/gnome-terminal", "gnome-terminal", "--working-directory=/home/f219304/Desktop/os1/", "--", "./pacman", NULL);
        	is_running_pacman=1;   }  

    	if(in==16)
    	{
      	display(&ready_queue);
    	}
	if(in==17)
	{ break; }
         pthread_create(&execution,NULL,loop,(void*)&ready_queue);
         pthread_join(execution,NULL);
	}
    
}


