#include "pthread.h"
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include "ctime"
#include "cstdlib"
using namespace std;

char arr[3][3] = {'1','2','3','4','5','6','7','8','9'};
char curr_marker='x';
int curr_player=1,winner;
void play_game();
void marker(int mark);
void board();
int win();
void machine_marker(int mark);
void swap();

void board()
{
    cout<<endl;
    for(int i=0;i<3;i++)
    {
      
        for (int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" | ";
        }
       
        cout<<endl<<"-----------"<<endl;
    }
}


void play_game()
{
     float n = 1;
    int  player_won,coin; 
    int m,slot,toss=1;
    bool mark=false,choose=false;
     board();
    


    
    cout<<"\nWELCOME TO TIC TAC TOE! \n Please choose from which module of the game you want to play :\n 1) Player Vs Player. \n 2) Player Vs Machine. ";
    cin>>m;
    if(m==1 || m==2)
    {
        choose=true;
    }
    else {
        while(choose!=true)
        {
            cout<<"\n The entered value for the module isn't available, please enter either 1 or 2 = ";
            cin>>m;
            if(m==1 || m==2)
    {
        choose=true;
    }
    else{ choose=false;}
        }
    }
    switch (m){
  
        case 1 : cout<< "\nYou've chosen the player to player module.The player 1 has marker X while player 2 has marker O"; 
        cout<<"\n\nStarting the game with a toss \n If the toss value is 1 then player 1 goes first.\n if toss value is 2 then player 2 goes first.\n";
        
    coin= rand()%2 +1 ;
    cout<<"\nThe toss value is = "<<coin;
    if(coin == 1)
    {
        toss=1;


    }
    else if(coin==2){
        toss=2;
    }
         if(toss==1)
         {
          curr_player=1;
          curr_marker='x';
         }
         else if (toss==2)
         {
             curr_player=2;
             curr_marker='o';
         }
         for(int i=0;i<9;i++)
         {
         cout<<"\nIt's player "<<curr_player<<"'s turn. \nEnter your slot :";
         cin>>slot;
         if(slot<=9 && slot>=1)
         {
           marker(slot);
           mark=true;
         }
         else {
           while(mark != true)
           {
             cout<<"\nThe slot entered does not exist please enter another slot = ";
             cin>>slot;
          if(slot<=9 && slot>=1)
         {
           marker(slot);
           mark=true;
         }
            else
            {
              mark=false;
            }
             
           }
         }
         player_won=win(); 
         if(player_won==1)
        {
            cout<<"\nPlayer 1 won. CONGRATULATIONS! \n";  
             board();
            break;  
        }
        if(player_won==2)
        {
            cout<<"\nPlayer 2 won. CONGRATULATIONS! \n";  
            board();
          
            break;   
        }
         
         swap();
         board();
         }
         if(player_won==0)
         {
             cout<<"\nThe game ended in a tie.";
              board();
         }                       
         
    
                                                  
        break;
        case 2: 
        cout<< "You've chosen the player to machine module.The player 1 is you and have the marker X while player 2 is the computer has marker O\n"; 
        
    coin= (rand()%2)+1;
    cout<<"\nThe toss value is = "<<coin;
    if(coin == 1)
    {
        toss=1;


    }
    else {
        toss=2;
    }
         if(toss==1)
         {
          curr_player=1;
          curr_marker='x';
         }
         else if (toss==2)
         {
             curr_player=2;
             curr_marker='o';
         }
         for(int i=0;i<9;i++)
         {
           if(curr_player==1)
           { 
         cout<<"\nIt's player 1's turn. Enter your slot :";
         cin>>slot;
         }
         else {
           cout<<"\nIt's computer's turn.";
           slot=rand()%9+1;
         }
         if(slot<=9 && slot>=1)
         {
           machine_marker(slot);
           mark=true;
         }
         else {
           while(mark != true)
           {
             cout<<"\nThe slot entered does not exist please enter another slot = ";
             cin>>slot;
          if(slot<=9 && slot>=1)
         {
           machine_marker(slot);
           mark=true;
         }
            else
            {
              mark=false;
            }
             
           }
         }
         player_won=win(); 
         if(player_won==1)
        {
            cout<<"\nPlayer 1 won. CONGRATULATIONS! \n";  
             board();
            break;  
        }
        if(player_won==2)
        {
            cout<<"\nThe computer won, BEST OF LUCK NEXT TIME.\n";  
            board();
          
            break;   
        }
         
         swap();
         board();
         }
         if(player_won==0)
         {
             cout<<"\nThe game ended in a tie.\n";
              board();
         }                       
         
    
                                                  
        break;
}
    }
void machine_marker(int mark)
{
  int row=mark/3,col;
   bool space=false,marker=false;
   
   if(curr_player==1)
   {


   
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else{
       while(space !=true)
      {
             
      cout<<"\n The place is occupied. Enter another slot = ";
      cin>>mark;
      if(mark>=1 && mark<=9)
      {
        row=mark/3;
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else
    {
      space=false;
    }
      }
      else{
        while(marker !=true)
        {
          cout<<"\n The slot entered does not exist please enter again = ";
         cin>>mark;
         if(mark>=1 && mark<=9)
      {
        marker=true;
        row=mark/3;
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else
    {
      marker=false;
      space=false;
    }
        }
        
      }
    }
      }
     row=mark/3;
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else
    {
      space=false;
    }


      }
   } 
   else if (curr_player==2){


    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else{
       while(space !=true)
      {  
       mark=rand()%9+1;
      if(mark>=1 && mark<=9)
      {
        row=mark/3;
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else
    {
      space=false;
    }
      }
      else{
        while(marker !=true)
        {
          mark=rand()%9+1;
         if(mark>=1 && mark<=9)
      {
        marker=true;
        row=mark/3;
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else
    {
      marker=false;
      space=false;
    }
        }
        
      }
    }
      }
     row=mark/3;
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else
    {
      space=false;
    }


      }
   }
    
}


void marker(int mark)
{


    int row=mark/3,col;
   bool space=false,marker=false;
   
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else{
       while(space !=true)
      {
             
      cout<<"\n The place is occupied. Enter another slot = ";
      cin>>mark;
      if(mark>=1 && mark<=9)
      {
        row=mark/3;
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else
    {
      space=false;
    }
      }
      else{
        while(marker !=true)
        {
          cout<<"\n The slot entered does not exist please enter again = ";
         cin>>mark;
         if(mark>=1 && mark<=9)
      {
        marker=true;
        row=mark/3;
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else  {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else
    {
      marker=false;
      space=false;
    }
        }
        
      }
    }
      }
     row=mark/3;
    if(mark %3 == 0)
    {
        row=row-1;
        col=2;
    }
    else {
        col=(mark%3)-1;   
    }
    if(arr[row][col] !='x' && arr[row][col] !='o')
    {
      arr[row][col]=curr_marker;
      space=true;
    }
    else
    {
      space=false;
    }


      }
   } 
    
int win()
{
    for(int i=0;i<3;i++)
    {
        if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2])
        {
            return curr_player;
        }
       if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i])
       {
           return curr_player;
       }
       if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])
       {
           return curr_player;
       }
       if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])
       {
           return curr_player;
       }
    }
    return 0;
}
void swap()
{
    if(curr_marker=='x')
{
    curr_marker='o';   
}
else{
    curr_marker='x';
}
if(curr_player==1)
{
    curr_player=2;
}
else
{
    curr_player=1;
}
}


int main()
{
play_game();
return 0;
}
