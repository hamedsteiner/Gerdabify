
#ifndef USER_H
#define USER_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "exception.h"
#include "static_declare.h"
#include "playlist.h"
#include "place.h"


#include "queue.h"





using namespace std;

enum Mode {Browse, Player};

//class Playlist;
class Queue;
class Artist_place;
class Album_place;
class Library;
class Album_place;
class SinglePlaylist;
class QueuePlace;
class Database;
class Music;

class User
{
public:

// user funcs ***
 //User(UserData _this_person,string _password);
User();


virtual void set_person(UserData _this_person){this_person=_this_person;}
virtual void set_password(string _password){password=_password;}
virtual void set_database(Database* db){database=db;}

virtual  UserData getUserDetails();
virtual  string get_password();
virtual vector<Playlist*> get_playlists(){return playlists;}
virtual void enterBrowserMode();
virtual void enterPlayMode();

virtual Mode get_mode(){return current_mode;}




//over ride
virtual void validate();

virtual void addMusic(string music_name,string file_path);
virtual void addAlbum(string artist_name,string album_name);






virtual void goToHome();
virtual void goToPlayLists();
virtual void goToLibrary();
virtual void goToAlbum();
virtual void goToArtist();

virtual List list();
virtual List listMusics();
virtual List listAlbums();
virtual List listPlaylists();
virtual List listArtists();

virtual void ratee(int rate);
virtual string getArtist();
virtual string getAlbum();
virtual string getName();
virtual string getCompleteName();
virtual int getRatee();
virtual int getUserRatee();
virtual int getCriticRatee();

virtual void goTo(string _playlist_name); // playlist * bere 
virtual List search(string all_music_things); /// bere to user
virtual void select(string music_thing); /// music, album ,artist , playlist
virtual void createPlaylist(string new_playlist);
virtual void clearPlaylist(string _playlist_name);
virtual void addTo(string music_thing);
virtual void remove(string music_name);
virtual void orderItem(string music_name, int order);

virtual void play();






virtual void next();
virtual void previous();
virtual void pause();
virtual void shuffle();
virtual void repeatOne();
virtual void repeat();


	 
protected:
	Place* current_place;
	std::vector<Playlist*> playlists;
	Playlist* current_playlist;
	Queue* queue;
	Mode current_mode;
	Database* database;
	string password;
	UserData this_person;

	
};









#endif // USER_H