
#ifndef GERDABIFY_LOGIC_H
#define GERDABIFY_LOGIC_H

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

#include "Artist.h"
#include "admin.h"
#include "Database.h"
#include "editor.h"
using namespace std;

//class User;





class Gerdabify_logic
{
public:
    Gerdabify_logic();
    bool Is_iterative(UserData _new_user);
    void signup(UserData new_user, string password);
    void login(string user_name, string password);
    void addMusic(string, string);
    void addAlbum(string, string);
    UserData getUserDetails(string username);

    void enterBrowserMode();
    void enterPlayMode();  

    
    void validate();



    void goToHome();
    void goToPlayLists();
    void goToLibrary();
    void goToAlbum();
    void goToArtist();

    List search(string name);

    void select(string thing);
    


    List list();
    List listMusics();
    List listAlbums();
    List listPlaylists();
    List listArtists();
    void createPlaylist(string name);

    void play();


    void addTo(string name);
    void goTo(string place);
    void clearPlaylist(string name);
    void remove(string music_name);
    void orderItem(string music_name, int order);

    

    void rate(int);
    string getArtist();
    string getAlbum();
    string getName();
    string getCompleteName();
    int getRate();
    int getUserRate();
    int getCriticRate();

    
    void next();
    void previous();
    void pause();
    void shuffle();
    void repeatOne();
    void repeat();



    
    //void verifyUser(string);	
	 
private:
	std::vector<User*> users;
	User* active_user;
	Database main_database;



};









#endif // GERDABIFY_LOGIC_H