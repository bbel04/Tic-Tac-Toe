//
//  main.cpp
//  Tic Tac Toe
//

#include <iostream>
#include <string>
#include <fstream>      //interprets fstream objects
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "TTTfunctions.h"

void display(void);         //to display board
void chooseSquare(int);     //to choose position on board
bool win(void);             //to determine if a player has won
int protectData(std::string prompt);   //protect against an invalid input
void playAgain(void);           //prompt the user to play again

int Tctr = 0;         //Tie counter
bool winF = false;    //tie flag, no winner

std::fstream ioFile;
std::string results;
std::string wins;

int main ()
{
    char gameChoice;   //variable to choose game mode
    const int maxMoves = 4;
    
    tttfunctions game;     //create class object
    
    std::cout << "Welcome to Tic-Tac-Toe";
    
    do 
    {
        std::cout << "\n\nPlease select a game mode: (T)wo player mode  |  (S)ingle player mode: ";  //two game modes
        std::cin >> gameChoice;
        std::cout << std::endl;
        
        int i;
        
        for (i = 0; i < maxMoves; i++)
        {
            game.display();
            game.chooseSquare(0);   // 0 to indicate player turn
            if (game.win())  //if win returns true, program ends
                break;  
            
            game.display();
            if (gameChoice == 'T' || gameChoice == 't')  //checks if user selected two player mode
                game.chooseSquare(-1);   //-1 to indicate player 2 turn
            else game.chooseSquare(1);   //1 to indicate computer turn if user chooses single player game mode
            if (game.win())
                break;
        }
        
        game.display();
        
        if (i == maxMoves)
        {
            game.display();
            game.chooseSquare(0);
            game.win();
        }
        
        if (!winF)
        {
            std::fstream ioFile;
            
            ioFile.open("winTTT.txt", std::ios::app);    // may need to include path on macOS -- /Users/ /Documents/winTTT.txt
            
            std::cout << "\nIt's a tie, no winner.\n";
            ioFile << "\nIt's a tie, no winner.\n";
            Tctr++;
            std::cout << "There have been " << Tctr << " tie(s). ";
            ioFile << "There have been " << Tctr << " tie(s). ";
            
            ioFile.close();
        }
        
        game.playAgain();
        
    } while (winF == false);    //execute once, terminate loop if winF is true
    
    ioFile.close();
    
    return 0;
}
