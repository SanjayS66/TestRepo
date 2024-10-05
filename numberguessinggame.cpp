#include <iostream>
#include<ctime>

int main() {
    // Write C++ code here
    std::cout << "***************** Welcome to number guessing game ****************\n \n";
    int num,guess,tries,i,range;
    
    std::cout<<"Enter range of number from which random number is to be generated : ";
    std::cin>>range;
    
    srand(time(0));
    num = (rand()%range)+1;
   
    tries =5;
    std::cout<<"Random number in range of "<<range<<" generated successfully \nYou get 5 tries to guess the number... USE THEM WISELY \n\n";
    
    
    for(i=0;i<tries;i++)
    { 
        std::cout<<"Enter your guess ("<<(tries-i)<<" tries left) : ";
        std::cin>>guess;
        if(guess==num)
        {
            std::cout<<"YOU GUESSED IT CORRECTLY!!!!   ";
            break;
        }
        else
        {
            std::cout<<"WRONG GUESS !!!\n";
        }
    }
    std::cout<<"The Random Number is "<<num;

    return 0;
}
