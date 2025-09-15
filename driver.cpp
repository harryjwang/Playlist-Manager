// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "playlist.h"

using namespace std;


int main(int argc, char *argv[]){
    
    // your code goes here...

    // Input number of songs you want to put into the array (playlist)
    // Set the number of songs to myplaylist.maxSongs{}

    // while the myplaylist.maxSongs is a valid number
        // 1. Add song if: "i" pressed and _________;______________ entered
        // 2. Select song to play if: "p" pressed and position n given
        // 3. Delete/Erase song at position if: "e" pressed and position n given

        // if "done" is entered then you break out of the code and end the code


    std::string lineInput{};        // Entire input line that is inputed by the user -> ie. m 10 OR i 1;1 OR e 2 OR p 5
    std::string commandInput{};     // Portion of the input line that represents the letter (setting array size, play, add, or delete)
    std::string inputString{};      // Portion of the input line that represents the index or size to create array
    
    int sizeEntry{};                
    int startIndex{0};              

    std::cin.ignore();              //ignore the "m " that is used when initializing the size of the playlist array
    std::cin >> sizeEntry;        
    Playlist myPlaylist(sizeEntry, startIndex);     // create object of class Playlist type with sizeEntry and startIndex as arguments
                                                    // to initliaze the value of the object
    std::cout << "success" << std::endl;            

    while(sizeEntry >= 0){                          
        std::getline(std::cin, lineInput);          // gets the line of the entire line that represents the command and index

        int spaceIndex = lineInput.find(" ");       // Find the index value of the "space" -> used to separate command from input value

        commandInput = lineInput.substr(0,spaceIndex);  // command input takes the values before the space (letter)
        inputString = lineInput.substr(spaceIndex + 1, lineInput.size());   // inputString takes the argument of command (int -> index)

        if (commandInput == "i"){                   
            myPlaylist.addSong(inputString);        
        } else if (commandInput == "p"){            
            int playIndex = std::stoi(inputString); // store the input string as an integer (string -> integer conversion)
            myPlaylist.playSong(playIndex);         
        } else if (commandInput == "e"){            
            int eraseIndex = std::stoi(inputString);    // store the inputString as an integer (string -> integer)
            myPlaylist.eraseSong(eraseIndex);           
        } else if (commandInput == "done"){        
            break;                                  // if the command is "done" the playlist is complete and we break out of the while loop
        }   
    }
}