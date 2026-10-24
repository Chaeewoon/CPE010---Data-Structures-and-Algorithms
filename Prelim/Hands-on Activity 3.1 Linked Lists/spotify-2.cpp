#include "playlist.h"
#include <iostream>
#include <string>

int main(){
    Song *playlist = nullptr;

    std::cout << "===== CURRENT PLAYLIST =====" << std::endl;
    playlistInsertHead("Sparkle | Your Name AMV", &playlist);
    playlistInsertHead("I REALLY WANT TO STAY AT YOUR HOUSE", &playlist);
    playlistInsertHead("Color Your Night", &playlist);
    playlistTraverse(playlist);


    std::cout << "\n===== ADDING SONG =====" << std::endl;
    playlistInsertHead("Wakeshima Kanon - Tsukinami", &playlist);
    playlistTraverse(playlist);


    std::cout << "\n===== REMOVING A SONG =====" << std::endl;
    playlistDeleteNode("Color Your Night", &playlist);
    playlistTraverse(playlist);


    std::cout << "\n===== PLAYLIST =====" << std::endl;
    Song *current = playlist;
    std::cout << "Current Song: " << current->data << std::endl;
    current = current->next;
    std::cout << "Next Song: " << current->data << std::endl;
    current = current->prev;
    std::cout << "Previous Song: " << current->data << std::endl;

    return 0;
}