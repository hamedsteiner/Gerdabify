
#ifndef ALBUM_H
#define ALBUM_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
//#include "music.h"
//#include "User.h"
#include "rated_object.h"

 

using namespace std;

class Artistt;
class Music;

class Album: public Rated_object
{
public:

	Album();
	 //Album(Artistt* creator,string _name); // nmishe baraye in new kard !!!!!!!!!
	 void set_name(string _name);
	 void set_author(Artistt* artist);

	 void add_music(Music* new_music);
	 void add_album(Album* new_album);

	 void remove(string music_name);
	 bool get_validation(){return validated;}



	 string get_name();
	 void get_validate();
	 Artistt* get_author();
	 vector<Music*> get_musics();


	 
private:
	bool validated;
	Artistt* author;
	std::vector<Music*> musics;
	string name;

	


};









#endif // ALBUM_H