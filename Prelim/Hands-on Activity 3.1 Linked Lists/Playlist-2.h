#ifndef PLAYLIST_H
#define PLAYLIST_H

#include<iostream>
#include<string>

class Song{
    public:
    std::string data;
    Song* prev = nullptr;
    Song* next = nullptr;
};

// CREATE A SONG
Song* createSong(std::string newData){
    Song *newSong = new Song;
    newSong->data = newData;
    newSong->prev = newSong;
    newSong->next = newSong;
    return newSong;
}

// ADD A SONG
void playlistInsertHead(std::string newData, Song** currentHead){
    Song *newSong = createSong(newData);

    if(*currentHead == nullptr){
        *currentHead = newSong;
        return;
    }
    Song *tail = (*currentHead)->prev;

    newSong->next = *currentHead;
    newSong->prev = tail;
    (*currentHead)->prev = newSong;
    tail->next = newSong;
    *currentHead = newSong;
}

// DELETE A SONG
void playlistDeleteNode(std::string findData, Song** currentHead){

    if (*currentHead == nullptr) return;

    Song* currNode = *currentHead;

    do{
        if(currNode->data == findData){

            if(currNode->next == currNode){
                *currentHead = nullptr;
            }
            else{
                currNode->prev->next = currNode->next;
                currNode->next->prev = currNode->prev;

                if(currNode == *currentHead){
                    *currentHead = currNode->next;
                }
            }

            delete currNode;
            return;
        }
        currNode = currNode->next;
    } while(currNode != *currentHead);

    std::cout << "Song was not found in playlist" << std::endl;
}

// PRINT SONGS
void playlistTraverse(Song *currentHead){

    if(currentHead == nullptr){
        std::cout << "The playlist is empty, Please add a song" << std::endl;
        return;
    }
    Song *currentNode = currentHead;
    int track = 1;

    std::cout << "Now Playing: " << std::endl;

    do{
        std::cout << track << ". " << currentNode->data << std::endl;
        currentNode = currentNode->next;
        track++;
    } while(currentNode != currentHead);

    std::cout << std::endl;
}

#endif