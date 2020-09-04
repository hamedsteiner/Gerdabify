
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "music.h"


using namespace std;

//class Music;
class Album;


class Playlist
{
public:

	 //Playlist(string _name);
	 void set_name(string _name);
	 void set_owner(string _owner);
	 string get_owner();
	 string get_name();

	 vector<Music*> get_musics();
	 void set_music(Music* new_music);
	 void set_album(Album* new_album);
	 vector<string>get_albums();
	 void clear();
	 void remove(string music_name);
	 void orderItem(string music_name, int order);


	 
private:
	std::vector<Music*> musics;
	string name;
	vector<string>album_names;
	string owner;

	


};









#endif // PLAYLIST_H