#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main()
{
    FILE *fp;
    FILE *fb;

    fp=fopen("pass.txt","r");
    bool fg=false;
    char new[100],confirm[100];

    fb=fopen("check.txt","r");
    int c;
    fscanf(fb,"%d",&c);
    if(c==0)
        return 0;
    while(!fg)
    {
        printf("Password: ");
        scanf("%s",new);
        fscanf(fp,"%s",confirm);       
        if(!strcmp(new,confirm))
        {
            fg=true;
        }
        else
        printf("Invalid Password\n");
    }
}