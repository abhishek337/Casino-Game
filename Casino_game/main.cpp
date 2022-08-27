#include <iostream>
#include <string.h>
#include <time.h>
using  namespace std;

void play_Game(string name, int amount){
    char choice;
    int batingamount;
    int dice;
    int guess_Num;

    srand(time(0));

    do
    {
        cout<<"Welcome, "<<name<<endl;
        cout<<"You have total balance : "<<amount<<endl;

        do
        {
            cout<<"Enter your bating amount : "<<endl;
            cin>>batingamount;

            if(batingamount > amount){
                cout<<"Your bating amount is greater than current balance."<<endl;
            }

        } while (batingamount > amount);
        
        
        dice = rand() % 10 + 1;

        do
        {
            cout<<"Enter Number between 1 to 10."<<endl;
            cin>>guess_Num;

            if(guess_Num < 0 || guess_Num > 10){
                cout<<"Enter Valid Number ."<<endl;
            }

        } while (guess_Num < 0 || guess_Num > 10);

        if(guess_Num == dice){

            cout<<"Congratulations..! You Won."<<endl;
            amount = amount + (batingamount * 10);
            cout<<"You price amount is "<<batingamount * 10<<endl;
            cout<<"Your Total balance is "<<amount<<endl;
        }
        else{
            cout<<"Sorry..! You guessed wrong number."<<endl;
            cout<<"Correct number is "<<dice<<endl;
            amount = amount - batingamount;
            cout<<"Your Total balance is "<<amount<<endl;
        }
        

        if(amount <= 0)
        break;

        cout<<"Do you want to play again ? (Y/N) "<<endl;
        cin>>choice;

    } while (choice == 'Y' || choice == 'y');
    
    cout<<"Thanks for playing !"<<endl;

}

void drawLine(int num, char sym){
    for(int i=0; i<num; i++){
        cout<<sym;
    }
    cout<<endl;
}

void rules(){

    drawLine(50, '_');
    cout<<"Rules : "<<endl;
    cout<<"1. Choose number between 1 to 10 ."<<endl;
    cout<<"2. If you won game you will recive 10X amount of your bating amount."<<endl;
    cout<<"3. If you lost your game batting amount is 0 Now."<<endl;
    drawLine(50,'_');
}

int main(){
    int amount;
    string name;

    cout<<"Welcome To My Casino ....!"<<endl;
    cout<<endl;

    cout<<"Enter your name : "<<endl;
    cin>>name;
    cout<<"Enter deposite amount for start bating : "<<endl;
    cin>>amount;

    rules();
    play_Game(name, amount);

    return 0;
}
