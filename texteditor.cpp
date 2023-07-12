#include<iostream>
#include<chrono>
#include<unistd.h>
#include<stdlib.h>
#include<string>
#include<termios.h>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<stdio.h>
using namespace std;
using namespace std::chrono;
int s=30;
bool flag=false;
string textfile;;
string text="";
fstream myfile;
void *read(void *arg)
{
    auto start = high_resolution_clock::now();
     while(!flag)
        {
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);

            if(duration.count()==s)
            {
                s=s+30;
                myfile.open(textfile,ios::out); 
                myfile<<text;
            }
        }
        myfile.close();

        return NULL;
}

int main()
{
    char ch;
    int s=2;
    cout<<"Press '/' Symbol to Exit\n";
    cout<<"Enter File Name: ";
    cin>>textfile;
    pthread_t t1;
    pthread_create(&t1,NULL,read,NULL);
    static struct termios oldTermios, newTermios;

    tcgetattr(STDIN_FILENO, &oldTermios);
        newTermios = oldTermios;
        cfmakeraw(&newTermios);
        tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);

    while(ch!='/')
    {
        
        ch=getchar();
        
        if(ch=='/')
        {
            flag=true;
            myfile.open(textfile,ios::out); 
            myfile<<text;
        }
        if(ch==127)
        {
            cout<<'\a';
            cout<<'\b';
            cout<<" ";
            cout<<'\b';
            if(!text.empty())
                text.pop_back();
            continue;
        }
        text=text+ch;
        cout<<ch;
    }
   
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
    pthread_join(t1,NULL);
    return 0;

}