// NoteTaker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "NoteTaker.h"

int main()
{
    std::cout << "Welcome To Note Taker!\n";
    MainLoop();
}


// Contains the main menu and opertations loop
void MainLoop()
{
    // Main inf Loop
    while(true)
    {
        std::cout << "What would you like to do? (Exit Application = exit, open a file = open, create a file = new): \n";
        // Holds Input
        std::string input;

        // Get user requests
        std::cin >> input;


        //      Determine user request

        // Exit application
        if (input == "exit" || input == "Exit")
        {
            break;
        }
        // Open existing file
        else if (input == "open" || input == "Open")
        {
            OpenFile();
        }
        // Create new file and open it
        else if (input == "new" || input == "New")
        {
            NewFile();
        }
    }
}

// Open existing file
void OpenFile()
{
    // Used to store user input
    std::string input;
    while (true)
    {
        std::cout << "Please input the required file Name: ";

        // Get User Input
        std::cin >> input;

        // Check if input is null
        if (input != "")
        {
            break;
        }
        else
        {
            // Clears Screen
            system("CLS");

            // Ask user to reinput data
            std::cout << "Something was wrong with that input";
        }
    }

    
    // Clears Screen
    system("CLS");

    // Give user basic commands
    std::cout << "Exit with save == :EXIT:, Exit without save == :EXITNS: \n";
    
    // Used to store file in string form
    std::vector<std::string> fileStr;

    // Open file
    std::ofstream file;
    file.open(input + ".txt");
    
    while (true)
    {
        // Get input
        std::cin >> input;

        if (input == ":EXIT:")
        {
            for (size_t i = 0; i < fileStr.size(); i++)
            {
                file << (fileStr[i] + "\n");
            }
            break;
        }

        else if (input == ":EXITNS:")
        {
            break;
        }

        else
        {
            
            fileStr.push_back(input);
        }
        

    }
}

// Create new file
void NewFile()
{
    // Used to store user input
    std::string input;
    while (true)
    {
        std::cout << "Please input the required file Name: ";
        
        // Get User Input
        std::cin >> input;

        // Check if input is null
        if (input != "")
        {
            break;
        }
        else
        {
            // Ask user to reinput data
            std::cout << "Something was wrong with that input";
        }
    }

    // Create new ofStream
    std::ofstream newFile;
    newFile.open((input + ".txt"));
    newFile.close();
}


