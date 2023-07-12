#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
struct Alaram
{
	int sleep_time;
	int ringing;
};

void gotosleep(struct Alaram alaram)
{
	sleep(alaram.sleep_time);
}
	
void *thread(void *arg)
{
	struct Alaram alaram=*(struct Alaram*)arg;
	alaram.ringing=1;
	printf("Alaram Will Rang After %d seconds\n\n",alaram.sleep_time);
	gotosleep(alaram);
	
	while(alaram.ringing!=0)
	{
		printf("........................................Alaram Ringing........................................\n");
		

        printf("Press 0 to stop\n");
		printf("Press 1 to snooze\n");
		printf("Enter Choice: ");
		scanf("%d",&alaram.ringing);
		
		if(alaram.ringing==0)
			continue;
		
		printf("Enter Snooze time: ");
		scanf("%d",&alaram.sleep_time);
		printf("Alaram Snoozing for %d seconds\n",alaram.sleep_time);
		gotosleep(alaram);
		printf("\nSnooze Time Completed\n");
	}

}
int main()
{
	pthread_t t;
	struct Alaram alaram;
	printf("Enter Alaram Time:");
	scanf("%d",&alaram.sleep_time);
	pthread_create(&t,NULL,thread,&alaram);	
	
	pthread_join(t,NULL);
	
	printf("\nAlaram Stopped");
}
