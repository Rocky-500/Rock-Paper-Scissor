#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

char getComputerMove(){
    srand(time(0));
    int move = rand()%3;

    if(move==0) 
    return 'r';
    else if(move==1)
    return 'p';
    else
    return 's';
}

int getResults(char playerMove, char computerMove){
    if(playerMove==computerMove)
    return 0;

    if(playerMove=='r' && computerMove=='s') { 
        return 1; 
    } 
    if(playerMove=='r' && computerMove=='p') { 
        return -1; 
    } 
    if(playerMove=='s' && computerMove=='p') { 
        return 1; 
    } 
    if(playerMove=='s' && computerMove=='r') { 
        return -1; 
    } 
    if(playerMove=='p' && computerMove=='r') { 
        return 1; 
    } 
    if(playerMove=='p' && computerMove=='s') { 
        return -1; 
    } 

    return 0;
}

int main(){
    char playerMove, computerMove;
    int player=0, computer=0;

    cout<<"\n\n\n\t\t Welcome to Rock Paper Scissor Game\n";
    cout<<"\n\nEnter   'r' - Rock\n\t's' - Scissor\n\t'p' - Paper\n\n";

    for(int i=5;i>0;i--){
        cout<<"You have "<<i<<" chance remaining."<<endl;

        while(1){
            cin>>playerMove;
            if(playerMove=='r'||playerMove=='s'||playerMove=='p'){
                break;
            }
            else{
                cout<<"\n\t\tInvalid Player move. \n\t\tPlease Try Again.";
            }
        }
        computerMove = getComputerMove();
        int result = getResults(playerMove,computerMove);

        if(result == 1){ 
            player++;
        } 
        else if(result == -1){ 
            
            computer++;
        } 
        
        cout<<"\t\t\t\tYour Move: "<<playerMove; 
        cout<<"\t\tComputer's Move: "<<computerMove <<endl; 
        cout<<"\t\tPoints : ";
        cout<<"\tYou: "<<player; 
        cout<<"\t\t\tComputer: "<<computer <<endl; 

    }

    if(player>computer){
        cout<<"\n\t\t\t\tCongratulations! You won the game!\n";
    }
    else if(player<computer){
        cout<<"\n\t\t\t\tOh! Computer won the game!\n";
    }
    else{
        cout << "\n\t\t\t\tGame Draw!\n";
    }
  
    return 0;
}