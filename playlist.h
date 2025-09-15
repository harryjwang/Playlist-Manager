// define your classes here...

#include <string>

class Playlist{

    public:
        Playlist(int playlistSize, int currentIndex);               // constructor of the class -> sets values
        ~Playlist();                                                // destructor of the class -> avoid memory related issues

        void addSong(std::string songArtistName);                   // addSong function declaration
        void eraseSong(int indexToerase);                           // eraseSong function declaration
        void playSong(int indexToPlay);                             // playSong function declaration

    private:
        std::string *playlistPointer;                               // intialize the dynamic array that will store the song;artist string

        int maxPlaylistArrayIndex{};                                // initialize max index of the playlist array (maxPlaylistSize - 1)
        int maxPlaylistSize{};                                      // max value of the playlist array
        int currentPlaylistIndex;                                   // initializes the current playlist index value in

};