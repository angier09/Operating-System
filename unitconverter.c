#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
void menu()
{
    printf("Select From Below Reading\n\n");
    printf("1. Meters(m)\n\n");
    printf("2. Kilometers(km)\n\n");
    printf("3. Miles(mi)\n\n");    
}
int main()
{
    double input;
    double reading;
    int type;
    int conv;
    char m[2];
    char n[2];

    printf("Units: Meters(m), Kilometers(km), Miles(mi)\n\n");
    printf("Enter Reading: ");
    scanf("%le",&input);
    reading=input;
    menu();
    scanf("%d",&type);
    
    if(type==1)
        m[0]='m';
    else if(type==2)
    {
        m[0]='k';
        m[1]='m';
    }
    else
    {
        m[0]='m';
        m[1]='i';
    }

    printf("1.Convert To Meters\n\n");
    printf("2.Convert  To Kilometers\n\n");
    printf("3.Convert To Miles\n\n");
    printf("Select The Desired Option: ");
    scanf("%d",&conv);

    if(conv==1)
        n[0]='m';
    else if(conv==2)
    {
        n[0]='k';
        n[1]='m';
    }
    else
    {
        n[0]='m';
        n[1]='i';
    }

    if(conv==type)
    {
        printf("Cannot Convert Because It Is Already In Selected Reading");
        return 0;
    }
    else if(type==1)
        switch (conv)
        {
        case 2:
            reading=reading*1000;
            break;
        case 3:
            reading=reading*0.000621371;
            break;
        
        default:
            printf("Wrong Input");
            break;
        }
    else if(type==2)
        switch (conv)
        {
        case 1:
            reading=reading*1000;
            break;
        case 3:
            reading=reading*0.621371;
            break;
        default:
            printf("Wrong Input");
            break;
        }
    else
        switch (conv)
        {
        case 1:
            reading=reading*1609.34;
            break;
        case 2:
            reading=reading*1.60934;
            break;
        default:
            printf("Wrong Input");
            break;
        }

        printf("After Converting %f %s into %s we get %f %s",input,m,n,reading,n);
}