
#ifndef ARTIST_H
#define ARTIST_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "User.h"
#include "rated_object.h"


// i intemtionaly didnt initiate validate at first casue it would be too hard to use and actuall if admin can not be admin, then who would verify?

using namespace std;
//class DataBase;

class Album;
class Music;

//class Rated_object
class Artistt : public User , public Rated_object
{
public:

	
	Artistt();
	vector<Album*> get_albums();
	vector<Music*> get_musics();
	string get_name();
	bool get_validation(){return validated;}


	void addMusic(string music_name,string file_path);
	void addAlbum(string artist_name,string album_name);
	void addTo(string music_thing);
	void remove(string music_name);
	
	void get_validate();




	
private:
	vector<Music*> musics;
	vector<Album*> albums;
	bool validated;
	


};


#endif // ARTIST_H