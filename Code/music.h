
#ifndef MUSIC_H
#define MUSIC_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
//#include "Artist.h"
#include "rated_object.h"



using namespace std;



class Album;
class Artistt;

class Music: public Rated_object
{
public:
	//Music(string m_name,string path,Artistt* creator);
	Music();
	void set_path(string path);
	void set_name(string _name);
	void set_author(Artistt* artist);
	void set_album(Album* album){belonged_album=album;}
	bool get_validation(){return validated;}


	string get_name();
	Album* get_album();
	string get_path(){return path_file;}
	Artistt* get_author();
	void get_validate();




	 
private:
	string path_file;
	bool validated;
	Artistt* author;
	Album* belonged_album;
	string name;



};









#endif // MUSIC_H