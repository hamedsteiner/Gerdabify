


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
#include "Gerdabify_logic.h"
#include "api.hpp"

using namespace std;



    GerdabifyAPI::GerdabifyAPI()
    {
    	logic=new Gerdabify_logic;
    }
    void GerdabifyAPI::enterBrowserMode()
    {

    	logic->enterBrowserMode();
    }
    
    void GerdabifyAPI::goToHome()
    {
    	logic->goToHome();

    }
    void GerdabifyAPI::goToPlayLists()
    {
    	logic->goToPlayLists();
    }
    void GerdabifyAPI::goToLibrary()
    {
		logic->goToLibrary();
 
    }
    void GerdabifyAPI::goToAlbum()
    {
		logic->goToAlbum();
    }
    void GerdabifyAPI::goToArtist()
    {
		logic->goToArtist();
    }

    List GerdabifyAPI::search(string name)
    {
		logic->search( name);
    }
    void GerdabifyAPI::select(string name)
    {
		logic->select( name);
    }
    
    List GerdabifyAPI::list()
    {
		logic->list();
    }
    List GerdabifyAPI::listMusics()
    {
		logic->listMusics();
    }
    List GerdabifyAPI::listAlbums()
    {
		logic->listAlbums();
    }
    List GerdabifyAPI::listPlaylists()
    {
		logic->listPlaylists();
    }
    List GerdabifyAPI::listArtists()
    {
		logic->listArtists();
    }


    void GerdabifyAPI::play()
    {
		logic->play();
    }

    void GerdabifyAPI::addTo(string name)
    {
		logic->addTo( name);
    }
    void GerdabifyAPI::goTo(string name)
    {
		logic->goTo( name);
    }
    void GerdabifyAPI::createPlaylist(string name)
    {
		logic->createPlaylist( name);
    }
    void GerdabifyAPI::clearPlaylist(string name)
    {
		logic->clearPlaylist( name);
    }

    void GerdabifyAPI::remove(string name)
    {
    	logic->remove( name);
    }

    void GerdabifyAPI::orderItem(string name, int order)
    {
    	logic->orderItem(name, order);
    }
    void GerdabifyAPI::rate(int score)
    {
    	logic->rate( score);
    }

    string GerdabifyAPI::getArtist()
    {
    	logic->getArtist();
    }
    string GerdabifyAPI::getAlbum()
    {
    	logic->getAlbum();
    }

    string GerdabifyAPI::getName()
    {
    	logic->getName();
    }
    string GerdabifyAPI::getCompleteName()
    {
    	logic->getCompleteName();
    }
    int GerdabifyAPI::getRate()
    {
    	logic->getRate();
    }
    int GerdabifyAPI::getUserRate()
    {
    	logic->getUserRate();
    }
    int GerdabifyAPI::getCriticRate()
    {
    	logic->getCriticRate();
    }





//user

    void GerdabifyAPI::enterPlayMode()
    {
    	logic->enterPlayMode();
    }

    void GerdabifyAPI::next()
    {
    	logic->next();
    }
    void GerdabifyAPI::previous()
    {
    	logic->previous();
    }
    void GerdabifyAPI::pause()
    {
    	logic->pause();
    }

    void GerdabifyAPI::shuffle()
    {
    	logic->shuffle();
    }
    void GerdabifyAPI::repeatOne()
    {
    	logic->repeatOne();
    }
    void GerdabifyAPI::repeat()
    {
    	logic->repeat();
    }
//

    void GerdabifyAPI::signup(UserData user, string name)
    {
    	logic->signup( user,  name);
    }
    void GerdabifyAPI::login(string user, string name)
    {
    	logic->login(user,  name);
    }
    void GerdabifyAPI::addMusic(string name, string  path)
    {
    	logic->addMusic( name, path);
    }
    void GerdabifyAPI::addAlbum(string name, string path)
    {
    	logic->addAlbum( name,  path);
    }
    void GerdabifyAPI::validate()
    {
    	logic->validate();
    }
    UserData GerdabifyAPI::getUserDetails(string user)
    {
    	logic->getUserDetails(user);
    }