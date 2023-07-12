#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int main()
{
    FILE * fp;
    FILE *fb;
    int c;

    char new[100];
    char confirm[100];
    bool fg=false;
    fb=fopen("check.txt","r");
    fscanf(fb,"%d",&c);

    printf("1.Change/Add Password\n\n");
    printf("2.Remove Password\n\n");
    printf("Select Option: ");

    int in;

    scanf("%d",&in);

    if(in == 1)
    {
    	while(!fg)
    	{
            printf("New Password: ");
            fgets(new,100,stdin);
            fgets(new,100,stdin);
            printf("Confirm Password: ");
            fgets(confirm,100,stdin);
    
            if(strcmp(new,confirm)==0)
            {
                printf("Password Created Sucessfully");
                fp=fopen("pass.txt","w");
                fb=fopen("check.txt","w");
                fprintf(fb,"1");
                fputs(new,fp);
                fg=true;
            }
            else
                printf("Passwords Does Not Match\n");
        }
    }
    else
    {
        fb=fopen("check.txt","w");
        fprintf(fb,"0");
    }
}
