#include<iostream>
#include<ctime>

char getplayerchoice()
{
  char x;
  do{
  std::cout<<"Make your choice : \n";
  std::cout<<"Enter 'r' for Rock \nEnter 'p' for Paper \nEnter 's' for Scissors \n";
  std::cin>>x;
  } while(x!='r'&& x!='s'&& x!='p');
  std::cout<<"Your choice is ";
  switch(x)
  {
      case 'r':
      {
          std::cout<<"ROCK";
          break;
      }
      case 'p':
     {
         std::cout<<"PAPER";
         break;
     }
     case 's':
     {
        std::cout<<"SCISSORS";
        break;
     }
  }
  return x;
 }
 
 
 
 char getcomputerchoice()
 {
     srand(time(0));
     int n =rand() % 3 + 1;
     switch(n) 
     {
         case 1:{ return 'r';
                  break;
                }
         case 2:{return 'p';
                  break;
                }
        case 3: { return 's';
                 break;
                }
     }
 }


void winnerselector(int x,int y)
{
   switch(x)
   {
      case 'r':
      {
        if(y=='r')
        {
            std::cout<<"\nIt's a TIE! try again";
        }
        if(y=='s')
        {
          std::cout<<"\nYou WIN against computer!!Preparing to leak your personal data...." ;
        }
        if(y=='p')
        {
            std::cout<<"\nYou Lose against computer!!Terminator incoming....";
        }
      }
      break;
      case 's':
      {
          if(y=='s')
          {
             std::cout<<"\nIt's a TIE! try again";  
          }
          if(y=='r')
          {
             std::cout<<"\nYou Lose against computer!!Terminator incoming...."; 
          }
          if(y=='p')
          {
            std::cout<<"\nYou WIN against computer!!Preparing to leak your personal data...." ; 
          }
      }
      break;
      case 'p':
      {
          if(y=='p')
          {
              std::cout<<"\nIt's a TIE! try again";    
          }
          if(y=='s')
          {
              std::cout<<"\nYou Lose against computer!!Terminator incoming....";   
          }
          if(y=='r')
          {
            std::cout<<"\nYou WIN against computer!!Preparing to leak your personal data...." ;   
          }
          break;
      }
   }
}

 

int main()
{
  char player_choice,computer_choice;
  std::cout<<"\t\t\t\t\tROCK PAPER SCISSORS!!! HERE WE GO!!! \n";
  std::cout<<"\t\t\t\t\t************************************ \n";
  player_choice = getplayerchoice();
  computer_choice = getcomputerchoice();
  std::cout<<"\nComputer choice is ";
    switch(computer_choice)
  {
      case 'r':
      {
          std::cout<<"ROCK";
          break;
      }
      case 'p':
     {
         std::cout<<"PAPER";
         break;
     }
     case 's':
     {
        std::cout<<"SCISSORS";
        break;
     }
  }
  
  winnerselector(player_choice,computer_choice);
  
 }
