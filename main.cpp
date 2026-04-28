#include<iostream>
#include<random>
#include<limits>
#include <cstdlib> 
int main(){
      std::cout<<"★★★★★★★★★★★★★★★★★★★★★★★★★★"<<std::endl;
      std::cout<<"★        NUMBER GUESSING GAME        ★"<<std::endl;
      std::cout<<"★★★★★★★★★★★★★★★★★★★★★★★★★★"<<std::endl;      
    int maxRange,chances,score,random_number,choice;  
    std::random_device rd;
    std::mt19937 gen(rd());
    char play_again;     
   do{   
     std::cout<<"Select mode \n 1.Easy\n 2.Medium\n 3.Hard"<<std::endl;          
     std::cout<<"enter choice:";
     std::cin>>choice;                               
    switch(choice){
         case 1:                                    
               maxRange=50; 
               chances=5;               
                 break;
         case 2:
             maxRange=100;
            chances=10;              
              break;
         case 3:
             maxRange=1000;
             chances=15;                                   
             break;
         default:
             std::cout<<"Invalid input!Exiting...\n"; 
            return 0;                                              
      }       
    std::uniform_int_distribution<int>range(1,maxRange);  
    random_number=range(gen);  
     int guess_number;
       bool won=false;        
      while(chances > 0 && !won){
       std::cout << "\n-----------------------------------------\n";        
        std::cout << "(Range: 1-" << maxRange <<")\n";                  
        std::cout<<"Enter your guess:";
        std::cin>>guess_number; 
        if(std::cin.fail())
        {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Invalid input please try again \n"; 
         continue;                      
        }
      if(guess_number < 1 || guess_number > maxRange){
            std::cout<<"Enter number between 1 and "<<maxRange<<"\n";
            continue;
      }
      if(guess_number == random_number)
      {
     std::cout<<"\n🎉Congrats!You guessed the number\n";
        won=true;

       }
               
      else if(guess_number < random_number) 
     {
        std::cout<<"Too low\n";
       if(std::abs(guess_number - random_number) <= 5)
       {
         std::cout << "🔥 Very close!\n"; 
        }            
       chances--;
       if(chances > 0)
       std::cout << "Attempts left: " << chances << "\n";
       else
       std::cout << "No chances left\n";
                                 
    } 
     else if(guess_number > random_number) 
    {  
      std::cout<<"Too high\n";
        if(std::abs(guess_number - random_number) <= 5)
        {
         std::cout << "🔥 Very close!\n"; 
        }    
       chances--;
      if(chances > 0)
      std::cout << "Attempts left: " << chances << "\n";
      else
      std::cout << "No chances left\n";                            
     } 
}
   std::cout<<"-----------------------------------------\n";
   if(!won) std::cout<<"Game Over!The number is:"<<random_number<<"\n";
   
    score = won ? chances * 10 : 0;
    std::cout<<"Your score:"<<score<<"\n";       
    std::cout<<"-----------------------------------------\n"; 
   std::cout<<"play again (y/n)?:"; 
   std::cin>>play_again;
 } while (play_again == 'y' || play_again == 'Y');       
                                       
    return 0;    
  }
