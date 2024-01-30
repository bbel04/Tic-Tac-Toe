//
//  TTTfunctions.h
//  Tic Tac Toe Scratch
//
//  Created by Ben Belardo on 1/21/24.
//

#ifndef TTTfunctions_h
#define TTTfunctions_h


#endif /* TTTfunctions_h */
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <thread>
//using namespace std;

void display(void);
void chooseSquare(int);
bool win(void);
int protectData(std::string prompt);
void playAgain(void);

extern bool winF;

class tttFunctions
{
public:
    void display(void)
    {
        if (square[1] == 1)  //if not chosen
            std::cout << "\n\t       |       |\n\t   " << square[1] << "   |";
        else if (square[1] == 0)  //if Player O chooses
            std::cout << "\n\t       |       |\n\t   O   |";
        else           //if Player X chooses
            std::cout << "\n\t       |       |\n\t   X   |";
        
        if (square[2] == 2)
            std::cout << "   " << square[2] << "   |";
        else if (square[2] == 0)
            std::cout << "   O   |";
        else
            std::cout << "   X   |";
        
        if (square[3] == 3)
            std::cout << "   " << square[3] << "   ";
        else if (square[3] == 0)
            std::cout << "   O   ";
        else
            std::cout << "   X   ";
        
        if (square[4] == 4)
            std::cout << "\n\t_______|_______|_______\n\t       |       |\n\t   " << square[4] << "   |";
        else if (square[4] == 0)
            std::cout << "\n\t_______|_______|_______\n\t       |       |\n\t   O   |";
        else
            std::cout << "\n\t_______|_______|_______\n\t       |       |\n\t   X   |";
        
        if (square[5] == 5)
            std::cout << "   " << square[5] << "   |";
        else if (square[5] == 0)
            std::cout << "   O   |";
        else
            std::cout << "   X   |";
        
        if (square[6] == 6)
            std::cout << "   " << square[6];
        else if (square[6] == 0)
            std::cout << "   O";
        else
            std::cout << "   X";
        
        if (square[7] == 7)
            std::cout << "\n\t_______|_______|_______\n\t       |       |\n\t   " << square[7] << "   |";
        else if (square[7] == 0)
            std::cout << "\n\t_______|_______|_______\n\t       |       |\n\t   O   |";
        else
            std::cout << "\n\t_______|_______|_______\n\t       |       |\n\t   X   |";
        
        if (square[8] == 8)
            std::cout << "   " << square[8] << "   |";
        else if (square[8] == 0)
            std::cout << "   O   |";
        else
            std::cout << "   X   |";
        
        if (square[9] == 9)
            std::cout << "   " << square[9] << "\n\t       |       |";
        else if (square[9] == 0)
            std::cout << "   O   \n\t       |       |";
        else
            std::cout << "   X   \n\t       |       |";
        
        std::cout << "\n\n";
    }

    void chooseSquare(int turn)
    {
        int choice;
        bool x = 0;   //boolean variable initialized to false
        int i = 1;    //int i used for looping through TTT squares
        
        if (turn == 0)
        {
            while (1)     //infiinite loop until valid choice is made
            {
                choice = protectData("\nChoose a square 1-9: ");  //calls protect data, sends string prompt
                
                for (int i = 1; i <= 9; i++)   //from 1-9
                {
                    if (square[i] == i && choice == i)  //if square matches choice, turn
                    {
                        square[i] = turn;
                        x = 1;   //boolean is true, indicates valid choice has been made, breaks out of loop
                        break;
                    }
                }
                if (i == 10)   //if all squares chosen
                {
                    std::cout << "That square has already been chosen ";
                }
                if (x == 1)  //if valid choice made, break
                {
                    break;
                }
            }
        }
        //New Computer Player
        else if (turn == 1)
        {
            srand(static_cast<unsigned int>(time(nullptr)));  //srand seeds rand()
            do
            {
                std::cout << "\nComputer is choosing...";
                choice = rand() % 9 + 1;   //random move for computer
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));           //delays move
            } while (square[choice] != choice);  //generates a random number for a square that has not been chosen
            square[choice] = turn;         //turns the square
            x = 1;
        }
        else if (turn == -1)   // Similar to the first player's logic
        {
            bool x = 0;
            int i = 1;
            while (1)
            {
                choice = protectData("\nChoose a square 1-9: ");
                for (int i = 1; i <= 9; i++)
                {
                    if (square[i] == i && choice == i)
                    {
                        square[i] = turn;
                        x = 1;
                        break;
                    }
                }
                if (i == 10)
                {
                    std::cout << "That square has already been chosen ";
                }
                if (x == 1)
                {
                    break;
                }
            }
        }
    }
    
    bool win(void)
    {
        int Octr = 0;     //player win counters
        int Xctr = 0;
        
        ioFile.open("winTTT.txt", std::ios::app);   //opens file, keep track of total wins losses, may need to include path on macOS -- /Users/ /Documents/winTTT.txt
        
        
        if (!ioFile)   //if there is an error opening the file
        {
            std::cerr << "Error Opening File";
            exit(EXIT_FAILURE);
        }
        
        for (int i = 1; i <= 9; i += 3) //for all row wins
            if (square[i] == square[i + 1] && square[i+1] == square[i + 2])   //generalized row
            {
                winF = true;
                std::cout << "\n**WIN** row " << i/3 + 1 << "." << std::endl;
                ioFile << "\n**WIN** row " << i/3 + 1 << "." << std::endl;     //writes to file
                if (square[i] == 0)
                {
                    Octr++;
                    std::cout << "\n PLayer O has won the game.\n Player O has " << Octr << " win(s).";
                    ioFile << "\n Player O has won the game.\n Player O has " << Octr << " win(s).";
                    ioFile.close();      //closes file
                    
                    return true;
                }
                else    //if chosen by Player X
                {
                    Xctr++;
                    std::cout << "\n Player X has won the game.\n Player X has " << Xctr << " win(s).";
                    ioFile << "\n Player X has won the game.\nPlayer X has " << Xctr << " win(s).";
                    ioFile.close();
                    
                    return true;
                }
            }
        
        for (int i = 1; i <=3; i++)   //for all column wins
            if (square[i] == square[i + 3] && square[i + 3] == square[i + 6])
            {
                winF = true;
                std::cout << "\n**WIN** column " << i << "." << std::endl;
                ioFile << "\n**WIN** column " << i << "." << std::endl;
                if (square[i] == 0)  //check if chosen by Player O
                {
                    Octr++;
                    std::cout << "\n PLayer O has won the game.\n Player O has " << Octr << " win(s).";
                    ioFile << "\n Player O has won the game.\n Player O has " << Octr << " win(s).";
                    ioFile.close();
                    
                    return true;
                }
                else    //if chosen by Player X
                {
                    Xctr++;
                    std::cout << "\n Player X has won the game.\n Player X has " << Xctr << " win(s).";
                    ioFile << "\n Player X has won the game.\nPlayer X has " << Xctr << " win(s).";
                    ioFile.close();
                    
                    return true;
                }
            }
        //diagonals
        if ((square[1] == square[5] && square[5] == square[9]) || (square[3] == square[5] && square[5] == square[7]))
        {
            winF = true;
            std::cout << "\n**Win**  diagonal.\n";
            ioFile << "\n**Win**  diagonal.\n";
            if (square[1] == 0)
            {
                Octr++;
                std::cout << "\n PLayer O has won the game.\n Player O has " << Octr << " win(s).";
                ioFile << "\n Player O has won the game.\n Player O has " << Octr << " win(s).";
                ioFile.close();
                
                return true;
            }
            else
            {
                Xctr++;
                std::cout << "\n PLayer X has won the game.\n Player X has " << Xctr << " win(s).";
                ioFile << "\n Player X has won the game.\n Player X has " << Xctr << " win(s).";
                ioFile.close();
                
                return true;
            }
        }
        
        ioFile.close();
        
        return false;
    }
    
    int protectData(std::string prompt)
    {
        int input;
        std::cout << prompt;
        std::cin >> input;
        
        if (input < 1 || input > 9 || std::cin.fail())     //if out of numerical range or character is entered
        {
            if (std::cin.fail())
            {
                std::cin.clear();       //clears bad data
                std::cin.ignore();      //resets buffer
            }
            std::cout << "\nEnter a valid square 1-9: ";    //prompts for valid answer
            std::cin >> input;
        }
        return input;
    }
    
    void playAgain()
    {
        char play;
        
        std::cout << "Would you like to play again? Enter 'Y' or 'N': ";
        std::cin >> play;
        
        if (play == 'Y' || play == 'y')    //if user chooses yes
        {
            winF = false;           //sets winF = false, replaces squares
            for (int i = 1; i <= 9; i++)
            {
                square[i] = i;
            }
        }
        else if (play == 'N' || play == 'n')      //if user chooses no
        {
            std::string wins;
            std::cout << "Thank you for playing! Goodbye.\n";
            winF = true;
            
            ioFile.open("winTTT.txt", std::ios::in);   //open results file
            
            if (!ioFile)     //if there is an error opening file
            {
                std::cerr << "\n\nError displaying results";
                exit(EXIT_FAILURE);
            }
            
            std::cout << "\nHere are your game results\n";     //display win/loss/tie results
            
            while (ioFile >> wins)       //data is read from ioFile
            {
                std::cout << wins << "  ";    //data is displayed in output of program
                if (ioFile.eof())        //if it is the end of the file, break
                    break;
            }
            
            ioFile.close();
        }
        
        else
        {
            std::cout << "Invalid Input. The program will end.";
        }
    }
    
private:
    int square[10] = { 0,1,2,3,4,5,6,7,8,9 };
    std::fstream ioFile;
};
