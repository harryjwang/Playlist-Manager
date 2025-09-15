#include "playlist.h"
#include <iostream>

// implement classes' member functions here...

Playlist::Playlist(int playlistSize, int currentIndex){         // Constructor for the Playlist class
    maxPlaylistSize = playlistSize;                             
    playlistPointer = new std::string[maxPlaylistSize];         // create a dynamically allocated array that is of type string and holds
                                                                // a max size of maxPlaylistSize
    currentPlaylistIndex = currentIndex;                        
}

Playlist::~Playlist() {                                         // Destructor for the Playlist class
    delete[] playlistPointer;                                   // deletes the dynamically allocated array called playlistPointer
}


void Playlist::addSong(std::string songArtistName){             // addSong function that takes a songArtistName string (song;artist)

    // Find a way to parse "Artist;SongName" into two string variables artistName and songName

    int semiColonIndex = songArtistName.find(";");              // Parses the string with song;artist to identify location of semicolon
                                                                // (semicolon divides the two parts)

    std::string songName = songArtistName.substr(0,semiColonIndex);     // songName takes all the letters before the semicolon
    std::string artistName = songArtistName.substr(semiColonIndex + 1, songArtistName.size());  // artist name is the letters after the semisolon until the end of the originial string with song name and artist

    // std::cout << songName << std::endl;          -> Used for testing and debugging
    // std::cout << artistName << std::endl;        -> Used for testing and debugging

    if ((songName == "Baby" && artistName == "Justin Bieber") || (songName == "My Heart Will Go On")){ // Check the cases that are not allowed to be inputted into the playlist
        std::cout << "can not insert " << songName << ";" << artistName << std::endl;
        return;
    } else if (currentPlaylistIndex >= maxPlaylistSize){             // Check that the current index value is within the maxsize of the playlist
        std::cout << "can not insert " << songName << ";" << artistName << std::endl;
        return;
    }

    for (int i{0}; i < currentPlaylistIndex; i++){          // Check whether or not, for each string (song;artist) entry, it already exists in the playlist array
        if (songArtistName == playlistPointer[i]){
            std::cout << "can not insert " << songName << ";" << artistName << std::endl;
            return;
        }                       
    }
                                                                // all returns don't have a value for this function since it is of type void

    playlistPointer[currentPlaylistIndex] = songArtistName;     // add the string (song;artist) to the playlist array
    currentPlaylistIndex++;                                     // iterate the value of the currentIndex up by one to the next index
    std::cout << "success" << std::endl;

    //  debuging add function
    // for (int i{}; i < maxPlaylistSize; i++)
    // {
    //     std::cout << playlistPointer[i] << std::endl;
    // }

}

void Playlist::eraseSong(int indexToErase){                     // eraseSong function that takes an index and deletes the song;artist if possible

    // Take the index of the "indexToDelete" and shift all of the songs that are on the right of the index to the left by 1
    // If index doesn't exist or there's nothing in that index, return can't play n(index)

    if (indexToErase >= 0 && indexToErase < currentPlaylistIndex){      // checks whether inputted index to delete is an index with value
        int tempIndex{indexToErase};
        for (; tempIndex < maxPlaylistSize - 1; tempIndex++){               // for all values right of the index to delete, shift them over by one index spot
            playlistPointer[tempIndex] = playlistPointer[tempIndex + 1];
        }
        currentPlaylistIndex--;                                     // update the value of the currentIndex (right most index with a value) by one
        std::cout << "success" << std::endl;
    } else {                                                            // if index delete isn't valid (doesn't contain a value) return nothing
        std::cout << "can not erase " << indexToErase << std::endl;
        return;
    }
                                                                    // all returns don't have a value for this function since it is of type void

    //  debugging 
    // for (int i{}; i < maxPlaylistSize; i++){
    //     std::cout << playlistPointer[i] << std::endl;
    //}
}

void Playlist::playSong(int indexToPlay){                           // playSong function that selects the song at an index and "plays" it

    // Take the "indexToPlay" and select the song at that index and "play" the song
    // if there is not song or the playlist size doesn't cover that index, then return can't play n(index)

    if (indexToPlay >= 0 && indexToPlay < currentPlaylistIndex){           // checks that the index to play is a valid index (has a song;artist string)
        std::cout << "played " << indexToPlay << " " << playlistPointer[indexToPlay] << std::endl;
    } else {
        std::cout << "can not play " << indexToPlay << std::endl;
        return;
    }
                                                                        // return type is nothing because the function is of type void

    //debugging 
    // for (int i{}; i < maxPlaylistSize; i++){
    //     std::cout << playlistPointer[i] << std::endl;
    // }

    
}