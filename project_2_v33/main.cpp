    /* 
 * File:   main.cpp
 * Author: Huey Nguyen
 * Created on February 2, 2023, 12:43 PM
 * Purpose:  3rd version of project 2
 *           add sorts
     *       
 *  
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototype
void slots (int &,int &,int &,int &,int & ,int &,int &,int & ,int &);   //void function to display slots
int Times (int[]);                                                      // function to calculate wether a value appears 3 times but does not match
bool winT(int);                                                         // bool function to determine when to add a multiplier
void Sel (int[]);                                                       //function to display selection sort
void swap(int *a, int *b);                                              //swap function for both sorting functions
void printsel (int[]);                                                  //Print function to display the results of selection sorts
void bubble(int []);                                                    //Bubble sort
void printbub(int []);                                                  //Print for bubble function
//Execution begins here at main 
int main(int argc, char** argv) {
    //Set random number seed
    srand(time(0));
    //Declare Variables
   
    int mny;     //value for money       
    unsigned int win=0;            //Value for the winnings of that spin
    int loss=0;           //Value for how much money was paid/ lost
    float Twin=0;         //Total winnings 
    float net;            //How much money was earned
    int Games=0;          //how many games were played
    int Wgame=0;          //How many games were won
    char Y;               //Input value for when to play again
    string Wins="You have won $",         //strings to display amount won, amount paid, total earnings
            Losses="You have payed $",
            Earn="Net pay is $";
    int Nmtch;                        //value for No matches but 3 slots
    char slot;                        //input for determining between animals or numbers
    //Initialize Variables
  
     cout<<"We will be playing slots!"<<endl;
     cout<<"Would you like the slots to have animals or numbers?"<<endl<<"Input"<<" A "<<"for animals"<<
           " and"<<" N "<<"for numbers"<<endl;  
     cin>>slot;
     

      do{   
      Games++;            //Number of games played increments every time time you spin again
    int A=rand()%9+1;     // sets each slot to equal a number from 1-9
     int B=rand()%9+1;  
      int C=rand()%9+1;  
       int D=rand()%9+1;  
        int E=rand()%9+1;  
         int F=rand()%9+1;  
          int G=rand()%9+1;  
           int H=rand()%9+1; 
            int I=rand()%9+1; 
            int Val[]={A,B,C,D,E,F,G,H,I};
            string Anmls[]={"Ant", "Dog", "Cat", "Bat", "Emu", "Koi", "Owl","Yak","Fox"};
            bool match;          // bool for when a match occurs
                 match=((A==B&&B==C||D==E&&E==F||G==H&&H==I)||(A==D&&D==G||B==E&&E==H||C==F&&F==I)||(A==E&&E==I||(C==E&&E==G))) ?
                 true:false;   
            bool prfct;         //bool for when all slots equal each other
                 prfct=(A==B&&B==C&&C==D&&D==E&&E==F&&F==G&&G==H&&H==I)?
                     true:false; 
            bool corn;          //bool for matching corners
                 corn= (A==C&&C==G&&G==I)?
                     true:false;
            bool dmnd;         //bool for matching edges
                 dmnd= (B==D&&D==F&&F==H)?
                     true:false;
            bool cent;         //bool for center is greatest value
                 cent= (E>A&&E>B&&E>D&&E>C&&E>F&E>>G&&E>H&&E>I)?
                     true:false;
        Nmtch= Times(Val); 
    //Map/Process the Inputs -> Outputs
    cout<<"Input how much money you would like to insert"<<endl;  
    //Display Inputs/Outputs
        cin>>mny;
        if (mny<=0){     //Validating user input, ends if number is 0 or lower
            cout<<"Invalid input"<<endl
                <<"enter a number bigger than 0";
            exit(0);
        }
        else{
            if(slot=='A'||slot=='a'){          //nested if statement for the two displays
   slots(A, B, C, D, E, F, G, H, I);
            }
            else if(slot=='N'||slot=='n'){
                if(Games%2==0){                //If game is even then selection sort will be used
                    printsel (Val);
                    cout<<endl;
                }
                else{                         //Else if odd bubble will be used
                     printbub(Val);
                     cout<<endl;
                }
            }
    loss+=mny;
    //multiplier for each case
    if (match==true){
        if (A==B&&B==C){
            mny*=1.5;
        }
        if (D==E&&E==F){
            mny*=1.5;
        }
        if (G==H&&H==G){
            mny*=1.5;
        }
        // Multipliers for Horizontal matches
        if (A==D&&D==G){
            mny*=1.5;
        }    
        if (B==E&&E==H){
            mny*=1.5;
        }
        if (C==F&&F==I){
            mny*=1.5;
        }
        // Multipliers for verticals
        if (A==E&&E==I){
            mny*=1.5;
        }
        if (C==E&&E==G){
            mny*=1.5;
        }
        //Multipliers for diagonal
        if (corn==true){
            mny*=2;
        }
        //Multiplier for when corners match & 3 in a row match
        if (dmnd==true){
            mny*=2;
        }
        //Multiplier for when a diamond pattern matches & 3 in a row match
        if (cent==true){
            mny*=2;
        }
        //Multiplier for when center is the greatest & 3 in a row match
         win=mny;
      //Set the value of money earned to the winnings
    }
    else if(corn==true){  //multiplier for when corners match and no 3 in row
            mny*=2;
            win=mny;
    }
    else if (dmnd==true){  //multiplier for when a diamond pattern matches and no 3 in row
            mny*=2;
        }
    else if(cent==true){    //Multiplier for when the center is the biggest number
        mny*=2;
        win=mny;
    }
    else if (winT(Nmtch==true)||(match==false)){         //multiplier for when three appear but no matches
        mny*=(1.2*Nmtch);
        win=mny;
    }
    
    else if((match==false)&&(corn==false)&&(dmnd==false)&&(cent==false)&&(winT(Nmtch)==false)) {
        win=0;   //if nothing is true winnings is set to 0
    }
    (prfct==true)? win=pow(mny,4):win=win;        //if all slots are the same money is set to the 4th power
   
    Twin+=win;                                 //Total wins will equal each winning amount
    net=Twin-loss;                             //Calculates what the total winnings or losses will be
    if (match==true||corn==true||dmnd==true||cent==true||winT(Nmtch)==true){  //If a scenario where money was won occurred games won will increment
        Wgame++;
    }
    //End of calculations 
                 cout<<"You have won $"<<fixed<<setprecision(2)<<showpoint<<win<<endl;   //outputs money won from that spin
         
    cout<<"Play again?"<<endl
        <<"If so type Y"<<endl;    
    cin>>Y;  
        }
    }
    while (Y=='y'||Y=='Y');    //ends loop
    cout<<"You have played"<<endl;
    
    for (int i=1;i<Games;i++){      //For loop to show how many games have been played
        cout<<i<<" ";
    }
    if (Games>1){
        cout<<endl;
    }
        cout<<Games<<" ";          //shows the how many games were played   
   (Games==1)? cout<<"time":cout<<"times";    //Ternary operator for when only 1 game was played
    cout<<endl;
    cout<<"of those games you won "<<Wgame<<endl;
    cout<<Losses<<fixed<<setprecision(2)<<showpoint<<loss<<endl           //Shows how much money was paid
        <<Wins<<fixed<<setprecision(2)<<showpoint<<Twin<<endl             //Shows how much was won
        <<Earn<<fixed<<setprecision(2)<<showpoint<<net;                   //Shows how much money you have left after considering how much was payed and won
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

// Slots utilize switch cases to create each slot in a void function
void slots(int &A, int &B, int &C, int &D, int &E, int &F, int &G, int &H,int &I){
    cout<<"####### ####### #######"<<endl;
   switch (A){
        case 1:
            cout<<"# Ant # "; break;
        case 2:
            cout<<"# Dog # "; break;
        case 3:
            cout<<"# Cat # "; break;
        case 4:
            cout<<"# Bat # "; break;
        case 5:
            cout<<"# Emu # "; break;
        case 6:
            cout<<"# Koi # "; break;
        case 7:
            cout<<"# Owl # "; break;
        case 8:
            cout<<"# Yak # "; break;
        case 9:
            cout<<"# Fox # ";
    }
  
          switch (B){
        case 1:
            cout<<"# Ant # "; break;
        case 2:
            cout<<"# Dog # "; break;
        case 3:
            cout<<"# Cat # "; break;
        case 4:
            cout<<"# Bat # "; break;
        case 5:
            cout<<"# Emu # "; break;
        case 6:
            cout<<"# Koi # "; break;
        case 7:
            cout<<"# Owl # "; break;
        case 8:
            cout<<"# Yak # "; break;
        case 9:
            cout<<"# Fox # ";
    }

         switch (C){
        case 1:
            cout<<"# Ant # "; break;
        case 2:
            cout<<"# Dog # "; break;
        case 3:
            cout<<"# Cat # "; break;
        case 4:
            cout<<"# Bat # "; break;
        case 5:
            cout<<"# Emu # "; break;
        case 6:
            cout<<"# Koi # "; break;
        case 7:
            cout<<"# Owl # "; break;
        case 8:
            cout<<"# Yak # "; break;
        case 9:
            cout<<"# Fox # ";
    }
    cout<<endl;
    cout<<"####### ####### #######"<<endl;
    cout<<"####### ####### #######"<<endl;
 
             switch (D){
        case 1:
            cout<<"# Ant # "; break;
        case 2:
            cout<<"# Dog # "; break;
        case 3:
            cout<<"# Cat # "; break;
        case 4:
            cout<<"# Bat # "; break;
        case 5:
            cout<<"# Emu # "; break;
        case 6:
            cout<<"# Koi # "; break;
        case 7:
            cout<<"# Owl # "; break;
        case 8:
            cout<<"# Yak # "; break;
        case 9:
            cout<<"# Fox # ";
    }

              switch (E){
        case 1:
            cout<<"# Ant # "; break;
        case 2:
            cout<<"# Dog # "; break;
        case 3:
            cout<<"# Cat # "; break;
        case 4:
            cout<<"# Bat # "; break;
        case 5:
            cout<<"# Emu # "; break;
        case 6:
            cout<<"# Koi # "; break;
        case 7:
            cout<<"# Owl # "; break;
        case 8:
            cout<<"# Yak # "; break;
        case 9:
            cout<<"# Fox # ";
    }

            switch (F){
        case 1:
            cout<<"# Ant #"; break;
        case 2:
            cout<<"# Dog #"; break;
        case 3:
            cout<<"# Cat #"; break;
        case 4:
            cout<<"# Bat #"; break;
        case 5:
            cout<<"# Emu #"; break;
        case 6:
            cout<<"# Koi #"; break;
        case 7:
            cout<<"# Owl #"; break;
        case 8:
            cout<<"# Yak #"; break;
        case 9:
            cout<<"# Fox #";
    }
    cout<<endl;
    cout<<"####### ####### #######"<<endl;    
    cout<<"####### ####### #######"<<endl;

             switch (G){
        case 1:
            cout<<"# Ant # "; break;
        case 2:
            cout<<"# Dog # "; break;
        case 3:
            cout<<"# Cat # "; break;
        case 4:
            cout<<"# Bat # "; break;
        case 5:
            cout<<"# Emu # "; break;
        case 6:
            cout<<"# Koi # "; break;
        case 7:
            cout<<"# Owl # "; break;
        case 8:
            cout<<"# Yak # "; break;
        case 9:
            cout<<"# Fox # ";
    }

             switch (H){
        case 1:
            cout<<"# Ant # "; break;
        case 2:
            cout<<"# Dog # "; break;
        case 3:
            cout<<"# Cat # "; break;
        case 4:
            cout<<"# Bat # "; break;
        case 5:
            cout<<"# Emu # "; break;
        case 6:
            cout<<"# Koi # "; break;
        case 7:
            cout<<"# Owl # "; break;
        case 8:
            cout<<"# Yak # "; break;
        case 9:
            cout<<"# Fox # ";
    }

            switch (I){
        case 1:
            cout<<"# Ant #"; break;
        case 2:
            cout<<"# Dog #"; break;
        case 3:
            cout<<"# Cat #"; break;
        case 4:
            cout<<"# Bat #"; break;
        case 5:
            cout<<"# Emu #"; break;
        case 6:
            cout<<"# Koi #"; break;
        case 7:
            cout<<"# Owl #"; break;
        case 8:
            cout<<"# Yak #"; break;
        case 9:
            cout<<"# Fox #";
    }
    cout<<endl;
    cout<<"####### ####### #######"<<endl;
}
int Times(int Val[]){                         //function to calculate wether a value appears 3 times but does not match
    int j=0;
    int Z=0;
    int Y=0,X=0,W=0,V=0,U=0,T=0,S=0,R=0,Q=0;
    for (int i=0;i<9;i++){
        if (Val[i]==1){
            Y++;
        }
        if (Val[i]==2){
            X++;  
        }
        if (Val[i]==3){
            W++;
        }
        if (Val[i]==4){
            V++;
        }
        if (Val[i]==5){
            U++;
        }
        if (Val[i]==6){
            T++;
        }
        if (Val[i]==7){
            S++;
        }
        if (Val[i]==8){
            R++;
        }
        if (Val[i]==9){
            Q++;
        }
        }
    if (Y>=3){
        Z++;
    }
    if (X>=3){
        Z++;
    }
    if (W>=3){
        Z++;
    }
    if (V>=3){
        Z++;
    }
    if (U>=3){
        Z++;
    }
    if (T>=3){
        Z++;
    }
    if (S>=3){
        Z++;
    }
    if (R>=3){
        Z++;
    }
    if (Q>=3){
        Z++;
    }
    return Z;
}
bool winT(int Nmtch){                    // bool function to determine when to add a multiplier
    if(Nmtch>0){
      return true;
    }
    return false;
}
void printsel(int Val[]){                 //Print function to display the results of selection sort
    int i;
    for (i=0;i<3;i++){
      cout<<Val[i] << " ";
    }
    cout<<endl;
    for (i=3;i<6;i++){
    cout<<Val[i]<<" ";
    }
    cout<<endl;
    for (i=6;i<9;i++){
    cout<<Val[i]<<" ";
}
}
void swap(int *a, int *b) {                  //swap function for both sorting functions
  int temp = *a;
  *a = *b;
  *b = temp;
}
void Sel(int Val[]){                          //Print function to display the results of selection sorts
    for (int i=0;i<8;i++){
        int min=i;
        for (int j=i+1;j<9;j++){
            if (Val[j]<Val[min]){
                min=j;
            }
        }
       if (min!=i)
        swap(&Val[min],&Val[9]);
    }
}
void bubble(int Val[]){                     ////Bubble sort
    for (int i=0;i<8;i++){
        for(int j=0;j<8-i;j++){
            if (Val[j]>Val[j+1]){
                swap(Val[j],Val[j+1]);
            }
        }
    }
}
void printbub(int Val[]){              //Print for bubble function
    int i;
    for (i=0;i<3;i++){
      cout<<Val[i] << " ";
    }
    cout<<endl;
    for (i=3;i<6;i++){
    cout<<Val[i]<<" ";
    }
    cout<<endl;
    for (i=6;i<9;i++){
    cout<<Val[i]<<" ";
}
}