//read write score to file
//fix 2 by 2 ARRAYS


/* 
 * File:   main.cpp
 * Author: Christopher Kooyman
 * Created on May 29, 2014, 7:52 PM
 */
//system libraries 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;
//Global Constants
const int COL=4;
const int ROW=4;
//Function Prototypes
int rannum();
//Returns random number
void brdDsn(int [ROW][COL],int);
//creates board design 
void ini(int [ROW][COL]);
//initiate function to zero then set two points
void newnum(int[ROW][COL]);
void game(int [ROW][COL]);
//Main game function 

//execution Begins Here!
int main(int argc, char** argv) {
    //Main Program
    //Initiate random seed
    srand(time(NULL));
    //declare variables
    int newnum=rannum();
    //2 by 2 function 
    int grid[ROW][COL];
    string name;
    int scorbrd=0;
    //call functions
    cout<<"Welcome to 2048 a number game"<<endl;
    cout<<"the goal is to get to the number 2048 by combining like numbers ie 2 and 2"<<endl;
    cout<<"the controls are"<<endl;
    cout<<"W for up "<<endl;
    cout<<"A for left"<<endl;
    cout<<"S for down"<<endl;
    cout<<"and D for right"<<endl;
    cout<<"To Quit press Q"<<endl;
    cout<<"Enter in your first name: ";
    cin>>name;
    ini(grid);
    game(grid);
    //exit stage right
    return 0;
    //end of main
    
}
void game(int grid[][COL]){
    int scorbrd=0;
    brdDsn(grid,scorbrd);
    bool usrinp=true;
    while(usrinp==true){
        char keyprs;
        cin>>keyprs;
        while(!(keyprs=='w'||keyprs=='W'||keyprs=='s'||keyprs=='S'||keyprs=='a'||keyprs=='A'||keyprs=='d'||keyprs=='D'||keyprs=='q'||keyprs=='Q')){
            cout<<"try again. W,A,S,D"<<endl;
            cin>>keyprs;
        }
        if(keyprs=='q'||keyprs=='Q'){
            usrinp=false;
        }
        else if(keyprs=='w'||keyprs=='W'){
            //colum 1 2 3 4 up logic 
            for(int row=0;row<4;row++){
                if(grid[row][0]==grid[row][1]&&grid[row][0]!=0){
                    grid[row][0]+=grid[row][1];
                    scorbrd+=grid[row][0];
                    grid[row][1]=0;   
                    if(grid[row][2]==grid[row][3]&&grid[row][2]!=0){
                        grid[row][2]+=grid[row][3];
                        grid[row][1]=grid[row][2];
                        scorbrd+=grid[row][2];
                        grid[row][2]=0;
                        grid[row][3]=0;
                    }
                    else{
                        grid[row][1]=grid[row][2];
                        grid[row][2]=grid[row][3];
                        grid[row][3]=0;
                    }
                }
                 if(grid[row][1]==grid[row][2]&&grid[row][1]!=0){
                    grid[row][1]+=grid[row][2];
                    scorbrd+=grid[row][1];
                    grid[row][2]=0;
                    if(grid[row][3]!=0){
                        grid[row][2]=grid[row][3];
                        grid[row][3]=0;
                    }
                }
                 if(grid[row][2]==grid[row][3]&&grid[row][2]!=0){
                    grid[row][2]+=grid[row][3];
                    scorbrd+=grid[row][2];
                    grid[row][3]=0;
                }
                 if(grid[row][0]==grid[row][2]&&grid[row][0]!=0&&grid[row][1]==0){
                    grid[row][0]+=grid[row][2];
                    scorbrd+=grid[row][0];
                    grid[row][2]=0;
                    grid[row][1]=grid[row][3];
                    grid[row][3]=0;
                }
                 if(grid[row][0]==grid[row][3]&&grid[row][0]!=0&&grid[row][1]==0&&grid[row][2]==0){
                    grid[row][0]+=grid[row][3];
                    scorbrd+=grid[row][0];
                    grid[row][3]=0;
                }
                 if(grid[row][1]==grid[row][3]&&grid[row][1]!=0&grid[row][2]==0){
                    grid[row][1]+=grid[row][3];
                    scorbrd+=grid[row][1];
                    grid[row][3]=0;
                    if(grid[row][0]==0){
                        grid[row][0]=grid[row][1];
                        grid[row][1]=0;
                    }
                }
                 if(grid[row][0]==0){
                    if(grid[row][1]!=0){
                        grid[row][0]=grid[row][1];
                        grid[row][1]=0;
                        if(grid[row][2]!=0){
                            grid[row][1]=grid[row][2];
                            grid[row][2]=0;
                            if(grid[row][3]!=0){
                                grid[row][2]=grid[row][3];
                                grid[row][3]=0;
                            }
                        }
                        else if(grid[row][3]!=0){
                            grid[row][1]=grid[row][3];
                            grid[row][3]=0;
                        }
                    }
                    else if(grid[row][2]!=0){
                        grid[row][0]=grid[row][2];
                        grid[row][2]=0;
                        if(grid[row][3]!=0){
                            grid[row][1]=grid[row][3];
                            grid[row][3]=0;
                        }
                    }
                    else if(grid[row][3]!=0){
                        grid[row][0]=grid[row][3];
                        grid[row][3]=0;
                    }
                }
                 if(grid[row][1]==0){
                    if(grid[row][2]!=0){
                        grid[row][1]=grid[row][2];
                        grid[row][2]=0;
                        if(grid[row][3]!=0){
                            grid[row][2]=grid[row][3];
                            grid[row][3]=0;
                        }
                    }
                    else if(grid[row][3]!=0){
                        grid[row][1]=grid[row][3];
                        grid[row][3]=0;
                    }
                }
                    else if(grid[row][2]==0){
                        if(grid[row][3]!=0){
                            grid[row][2]=grid[row][3];
                            grid[row][3]=0;
                        }
                   }
             }
        }
                else if(keyprs=='a'||keyprs=='A'){
                    for(int cols=0;cols<4;cols++){
                    if(grid[0][cols]==grid[1][cols]&&grid[0][cols]!=0){
                        grid[0][cols]+=grid[1][cols];
                        scorbrd+=grid[0][cols];
                        grid[1][cols]=0;   
                        if(grid[2][cols]==grid[3][cols]&&grid[2][cols]!=0){
                            grid[2][cols]+=grid[3][cols];
                            scorbrd+=grid[2][cols];
                            grid[1][cols]=grid[2][cols];
                            grid[2][cols]=0;
                            grid[3][cols]=0;
                        }
                        else{
                            grid[1][cols]=grid[2][cols];
                            grid[2][cols]=grid[3][cols];
                            grid[3][cols]=0;
                        }
                    }
                     if(grid[1][cols]==grid[2][cols]&&grid[1][cols]!=0){
                        grid[1][cols]+=grid[2][cols];
                        scorbrd+=grid[1][cols];
                        grid[2][cols]=0;
                        if(grid[3][cols]!=0){
                            grid[2][cols]=grid[3][cols];
                            grid[3][cols]=0;
                        }
                    }
                     if(grid[2][cols]==grid[3][cols]&&grid[2][cols]!=0){
                        grid[2][cols]+=grid[3][cols];
                        scorbrd+=grid[2][cols];
                        grid[3][cols]=0;
                    }
                     if(grid[0][cols]==grid[2][cols]&&grid[0][cols]!=0&&grid[1][cols]==0){
                        grid[0][cols]+=grid[2][cols];
                        scorbrd+=grid[0][cols];
                        grid[2][cols]=0;
                        grid[1][cols]=grid[3][cols];
                        grid[3][cols]=0;
                    }
                     if(grid[0][cols]==grid[3][cols]&&grid[0][cols]!=0&&grid[1][cols]==0&&grid[2][cols]==0){
                        grid[0][cols]+=grid[3][cols];
                        scorbrd+=grid[0][cols];
                        grid[3][cols]=0;
                    }
                     if(grid[1][cols]==grid[3][cols]&&grid[1][cols]!=0&grid[2][cols]==0){
                        grid[1][cols]+=grid[3][cols];
                        scorbrd+=grid[1][cols];
                        grid[3][cols]=0;
                        if(grid[0][cols]==0){
                            grid[0][cols]=grid[1][cols];
                            grid[1][cols]=0;
                        }
                    }
                     if(grid[0][cols]==0){
                        if(grid[1][cols]!=0){
                            grid[0][cols]=grid[1][cols];
                            grid[1][cols]=0;
                            if(grid[2][cols]!=0){
                                grid[1][cols]=grid[2][cols];
                                grid[2][cols]=0;
                                if(grid[3][cols]!=0){
                                    grid[2][cols]=grid[3][cols];
                                    grid[3][cols]=0;
                                }
                            }
                            else if(grid[3][cols]!=0){
                                grid[1][cols]=grid[3][cols];
                                grid[3][cols]=0;
                            }
                        }
                        else if(grid[2][cols]!=0){
                            grid[0][cols]=grid[2][cols];
                            grid[2][cols]=0;
                            if(grid[3][cols]!=0){
                                grid[1][cols]=grid[3][cols];
                                grid[3][cols]=0;
                            }
                        }
                        else if(grid[3][cols]!=0){
                            grid[0][cols]=grid[3][cols];
                            grid[3][cols]=0;
                        }
                    }
                     if(grid[1][cols]==0){
                        if(grid[2][cols]!=0){
                            grid[1][cols]=grid[2][cols];
                            grid[3][cols]=0;
                            if(grid[3][cols]!=0){
                                grid[2][cols]=grid[3][cols];
                                grid[3][cols]=0;
                            }
                        }
                        else if(grid[3][cols]!=0){
                            grid[1][cols]=grid[3][cols];
                            grid[3][cols]=0;
                        }
                    }
                        else if(grid[2][cols]==0){
                            if(grid[3][cols]!=0){
                                grid[2][cols]=grid[3][cols];
                                grid[3][cols]=0;
                            }
                        }
                    }
                }
        else if(keyprs=='s'||keyprs=='S'){
            for(int row=0;row<4;row++){
            //row 1 colum 4321 down logic 
            if(grid[row][3]==grid[row][2]&&grid[row][3]!=0){
                grid[row][3]+=grid[row][2];
                scorbrd+=grid[row][3];
                grid[row][2]=0;   
                if(grid[row][1]==grid[row][0]&&grid[row][1]!=0){
                    grid[row][1]+=grid[row][0];
                    scorbrd+=grid[row][1];
                    grid[row][2]=grid[row][1];
                    grid[row][1]=0;
                    grid[row][0]=0;
                }
                else{
                    grid[row][2]=grid[row][1];
                    grid[row][1]=grid[row][0];
                    grid[row][0]=0;
                }
            }
             if(grid[row][2]==grid[row][1]&&grid[row][2]!=0){
                grid[row][2]+=grid[row][1];
                scorbrd+=grid[row][2];
                grid[row][1]=0;
                if(grid[row][0]!=0){
                    grid[row][1]=grid[row][0];
                    grid[row][0]=0;
                }
            }
             if(grid[row][1]==grid[row][0]&&grid[row][1]!=0){
                grid[row][1]+=grid[row][0];
                scorbrd+=grid[row][1];
                grid[row][0]=0;
            }
             if(grid[row][3]==grid[row][1]&&grid[row][3]!=0&&grid[row][2]==0){
                grid[row][3]+=grid[row][1];
                scorbrd+=grid[row][3];
                grid[row][1]=0;
                grid[row][2]=grid[row][0];
                grid[row][0]=0;
            }
             if(grid[row][3]==grid[row][0]&&grid[row][3]!=0&&grid[row][2]==0&&grid[row][1]==0){
                grid[row][3]+=grid[row][0];
                grid[row][0]=0;
            }
             if(grid[row][2]==grid[row][0]&&grid[row][2]!=0&grid[row][1]==0){
                grid[row][2]+=grid[row][0];
                scorbrd+=grid[row][2];
                grid[row][0]=0;
                if(grid[row][3]==0){
                    grid[row][3]=grid[row][2];
                    grid[row][2]=0;
                }
            }
             if(grid[row][3]==0){
                if(grid[row][2]!=0){
                    grid[row][3]=grid[row][2];
                    grid[row][2]=0;
                    if(grid[row][1]!=0){
                        grid[row][2]=grid[row][1];
                        grid[row][2]=0;
                        if(grid[row][0]!=0){
                            grid[row][1]=grid[row][0];
                            grid[row][0]=0;
                        }
                    }
                    else if(grid[row][0]!=0){
                        grid[row][2]=grid[row][0];
                        grid[row][0]=0;
                    }
                }
                else if(grid[row][1]!=0){
                    grid[row][3]=grid[row][1];
                    grid[row][1]=0;
                    if(grid[row][0]!=0){
                        grid[row][2]=grid[row][0];
                        grid[row][0]=0;
                    }
                }
                else if(grid[row][0]!=0){
                    grid[row][3]=grid[row][0];
                    grid[row][0]=0;
                }
            }
             if(grid[row][2]==0){
                if(grid[row][1]!=0){
                    grid[row][2]=grid[row][1];
                    grid[row][1]=0;
                    if(grid[row][0]!=0){
                        grid[row][1]=grid[row][0];
                        grid[row][0]=0;
                    }
                }
                else if(grid[row][0]!=0){
                    grid[row][2]=grid[row][0];
                    grid[row][0]=0;
                }
            }
                else if(grid[row][1]==0){
                    if(grid[row][0]!=0){
                        grid[row][1]=grid[row][0];
                        grid[row][0]=0;
                    }
                }
        }
    }
        else if(keyprs=='d'||keyprs=='D'){
            for(int cols=0;cols<4;cols++){
            //D right logic
            if(grid[3][cols]==grid[2][cols]&&grid[3][cols]!=0){
                grid[3][cols]+=grid[2][cols];
                scorbrd+=grid[3][cols];
                grid[2][cols]=0;   
                if(grid[1][cols]==grid[0][cols]&&grid[1][cols]!=0){
                    grid[1][cols]+=grid[0][cols];
                    scorbrd+=grid[1][cols];
                    grid[2][cols]=grid[1][cols];
                    grid[1][cols]=0;
                    grid[0][cols]=0;
                }
                else{
                    grid[2][cols]=grid[1][cols];
                    grid[1][cols]=grid[0][cols];
                    grid[0][cols]=0;
                }
            }
             if(grid[2][cols]==grid[1][cols]&&grid[2][cols]!=0){
                grid[2][cols]+=grid[1][cols];
                scorbrd+=grid[2][cols];
                grid[1][cols]=0;
                if(grid[0][cols]!=0){
                    grid[1][cols]=grid[0][cols];
                    grid[0][cols]=0;
                }
            }
             if(grid[1][cols]==grid[0][cols]&&grid[1][cols]!=0){
                grid[1][cols]+=grid[0][cols];
                scorbrd+=grid[1][cols];
                grid[0][cols]=0;
            }
             if(grid[3][cols]==grid[1][cols]&&grid[3][cols]!=0&&grid[2][cols]==0){
                grid[3][cols]+=grid[1][cols];
                scorbrd+=grid[3][cols];
                grid[1][cols]=0;
                grid[2][cols]=grid[0][cols];
                grid[0][cols]=0;
            }
             if(grid[3][cols]==grid[0][cols]&&grid[3][cols]!=0&&grid[2][cols]==0&&grid[1][cols]==0){
                grid[3][cols]+=grid[0][cols];
                scorbrd+=grid[3][cols];
                grid[0][cols]=0;
            }
             if(grid[2][cols]==grid[0][cols]&&grid[2][cols]!=0&grid[1][cols]==0){
                grid[2][cols]+=grid[0][cols];
                scorbrd+=grid[2][cols];
                grid[0][cols]=0;
                if(grid[3][cols]==0){
                    grid[3][cols]=grid[2][cols];
                    grid[2][cols]=0;
                }
            }
             if(grid[3][cols]==0){
                if(grid[2][cols]!=0){
                    grid[3][cols]=grid[2][cols];
                    grid[2][cols]=0;
                    if(grid[1][cols]!=0){
                        grid[2][cols]=grid[1][cols];
                        grid[1][cols]=0;
                        if(grid[0][cols]!=0){
                            grid[1][cols]=grid[0][cols];
                            grid[0][cols]=0;
                        }
                    }
                    else if(grid[0][cols]!=0){
                        grid[2][cols]=grid[0][cols];
                        grid[0][cols]=0;
                    }
                }
                else if(grid[1][cols]!=0){
                    grid[3][cols]=grid[1][cols];
                    grid[1][cols]=0;
                    if(grid[0][cols]!=0){
                        grid[2][cols]=grid[0][cols];
                        grid[0][cols]=0;
                    }
                }
                else if(grid[0][cols]!=0){
                    grid[3][cols]=grid[0][cols];
                    grid[0][cols]=0;
                }
            }
             if(grid[2][cols]==0){
                if(grid[1][cols]!=0){
                    grid[2][cols]=grid[1][cols];
                    grid[0][cols]=0;
                    if(grid[0][cols]!=0){
                        grid[1][cols]=grid[0][cols];
                        grid[0][cols]=0;
                    }
                }
                else if(grid[0][cols]!=0){
                    grid[2][cols]=grid[0][cols];
                    grid[0][cols]=0;
                }
            }
                else if(grid[1][cols]==0){
                    if(grid[0][cols]!=0){
                        grid[1][cols]=grid[0][cols];
                        grid[0][cols]=0;
                    }
                }
        }
    }
        newnum(grid);
        for(int format=0;format<30;format++){
             cout<<endl;
         }
        brdDsn(grid,scorbrd);
    }
}

    void newnum(int grid[][COL]){
        int breakdo=0;
        do{
        short row=rand()%4+1;
        short cols=rand()%4+1;
        if(grid[row][cols]==0){
            grid[row][cols]=rannum();
            breakdo++;
        }
    }
    while(breakdo<1);
    }
//Initiate Game board start
void ini(int grid[][COL]){
    int breakdo=0;
    short ranval=rand()%16+1;
    for(int c=0;c<4;c++){
        for(int r=0;r<4;r++){
            grid[r][c]=0;
        }
    }
    do{
        short row=rand()%4+1;
        short cols=rand()%4+1;
        if(grid[row][cols]==0){
            grid[row][cols]=rannum();
            breakdo++;
        }
    }
    while(breakdo<2);
    
}
//Random num 
int rannum(){
    int n=0;
    short ranval=rand()%20+1;
        if(ranval<15){
            n=2;
        }
        else{
            n=4;
        }
    return n;
}
//Board Design 
void brdDsn(int grid[][COL],int score){
    cout<<"Current Score : "<<score<<endl;
    cout<<"+----+----+----+----+"<<endl;
    for(int c=0;c<4;c++){
        for(int r=0;r<4;r++){
            if(grid[r][c]<10){
                cout<<"|   "<<grid[r][c];
            }
            else if(grid[r][c]<100){
                cout<<"|  "<<grid[r][c];
            }
            else if(grid[r][c]<1000){
                cout<<"| "<<grid[r][c];
            }
            else{
                cout<<"|"<<grid[r][c];
            }
            if(r==3){
                cout<<"|"<<endl;
                cout<<"+----+----+----+----+"<<endl;
            }
        }
    }
}