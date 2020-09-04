
#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "gerdabPlayer.hpp"
#include "User.h"
using namespace std;
class GerdabPlayer;

class Music;
class Album;
class Artistt;


class Queue
{
public:
	Queue();
	vector<Music*> get_musics();
	void add_music(Music* new_music);
	void add_album(Album* new_album);
	void add_artist(User* new_Artist);
	void add_playlist(Playlist* new_playlist);
	vector<string>get_albums();
	void clear();


	void play();
	void pause();
    //void resume();
    void next();
    void previous();
    void shuffle();
    void repeat();
    void repeatOne();








	 
private:
	std::vector<Music*> musics;
	//string name;
	GerdabPlayer player;
	vector<string> album_names;
	bool already_started;
	bool repeatition;
	bool one_music_repeat;
	char status;
	bool shuffler;


	


};









#endif // PLAYLIST_H