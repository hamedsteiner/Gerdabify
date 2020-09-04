
#ifndef SINGLEPLAYLIST_H
#define SINGLEPLAYLIST_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include "place.h"

class Artist;
class Playlist;
class Music;

using namespace std;

//typedef vector<string> List;


class SinglePlaylist: public Place
{
public:
	SinglePlaylist();

	void set_playlist(Playlist* pointed_playlist);
	Playlist* get_playlist(){return pointed_playlist;}

	List list();
	List listMusics();
	List listAlbums();


	void remove(string music_name);
	void orderItem(string music_name, int order);



	//void addTo(string music_thing);
	//void remove(string music_name);


	string getName();
	string getCompleteName();



private:
	Playlist* pointed_playlist;

};


#endif // SINGLEPLAYLIST_H