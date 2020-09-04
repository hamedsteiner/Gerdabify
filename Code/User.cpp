
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
#include "Artist.h"

#include "Album_place.h"
#include "Home.h"
#include "Artist_place.h"
#include "Playlist_place.h"
#include "place.h"
#include "Library.h"
#include "Music_place.h"
#include "playlist.h"
#include "Database.h"

#include "single_playlist.h"
#include "queue_place.h"
#include "queue.h"



using namespace std;


 ///////////////////// initial place to home , friend vclasss place

class Artistt;

/*
User::User(UserData _this_person,string _password) /// virtual constructor
{
	this_person=_this_person;
	password=_password;
	//current_place=new Home;
}*/



User::User()
{
    
    current_place=new Home;
    queue=new Queue;

}

 UserData User::getUserDetails()
{
	return this_person;
}
 string User::get_password()
{
	return password;
}

 void User::addMusic(string music_name,string file_path)
{
    throw NotAuthorized();
}
 void User::addAlbum(string artist_name,string album_name)
{
    throw NotAuthorized();
}
 void User::enterBrowserMode()
{
    current_mode=Browse;  
}
 void User::enterPlayMode()
{
    current_mode=Player;
}


 void User::validate()
{
	throw MethodNotAvailable();
}


void User::goToHome() // sets to home page
{
    Place* temp;

    //cout<<"RAFT HOME \n";
    temp=current_place->goToHome();
    //cout<<"RAFT HOME \n";
    delete current_place;
    current_place=temp;
    cout<<"you are at "<<current_place->get_type()<<endl;
}

void User::goToPlayLists()
{
    Place* temp;
    
    temp=current_place->goToPlayLists();
    delete current_place;
    dynamic_cast<Playlistplace*>(temp)->set_playlists(playlists);
    current_place=temp;
    cout<<"you are at "<<current_place->get_type()<<endl;
}



void User::goToLibrary()
{
    Place* temp;
    temp=current_place->goToLibrary();
    delete current_place;
    current_place=temp;
    dynamic_cast<Library*>(current_place)->set_db(database);
    cout<<"you are at "<<current_place->get_type()<<endl;

}
void User::goToAlbum()
{
    Place* temp;
    temp=current_place->goToAlbum();
    delete current_place;
    current_place=temp;
    cout<<"you are at "<<current_place->get_type()<<endl;
    //cout<<dynamic_cast<Albumplace*>(current_place)->get_album()->get_name();
}

 void User::goToArtist()
{
    Place* temp;
    temp=current_place->goToArtist();
    delete current_place;
    current_place=temp;
    cout<<"you are at "<<current_place->get_type()<<endl;
    User* alaki=dynamic_cast<Artistplace*>(current_place)->get_artist();
    cout<<dynamic_cast<Artistt*>(alaki)->get_name();
}




List User::search(string thing) // gives all complete names
{
    List output;
    
    output=(database->search_all(thing));
    //cout<<"ridn \n";
    for(int i=0;i<playlists.size();i++)
    {
        if(playlists[i]->get_name()==thing)
            output.push_back(" < "+ this_person.username + " > " +" - "+ thing);
    }
    return output;
}



void User::select(string thing)//we assume we can only choose one with the same name
{
    bool available=false;
    for(int i=0;i<playlists.size();i++) 
    {
        if(playlists[i]->get_name()==thing) // select a playlist
        {
            available=true;
            delete current_place;
            current_place=new SinglePlaylist;
            dynamic_cast<SinglePlaylist*>(current_place)->set_playlist(playlists[i]);
            cout<<"you have selected a playlist \n";
            break;
        }
    }


    if(available==false)
    {
        vector<User*> temp_artists=database->get_artists();
        for(int i=0;i<temp_artists.size();i++)
            if(dynamic_cast<Artistt*> (temp_artists[i])->get_name()==thing) //select an artist
            {
                available=true;
                delete current_place;
                current_place = new Artistplace;
                dynamic_cast<Artistplace*>(current_place)->set_artist(database->get_artists()[i]);
                dynamic_cast<Artistplace*>(current_place)->set_user(this_person);
                cout<<"you have selected a Artist \n";
                User* alaki=dynamic_cast<Artistplace*>(current_place)->get_artist();
                //cout<<dynamic_cast<Artistt*>(alaki)->get_name();
                break;
            }
    }


    if(available==false)
    {
        for(int i=0;i<database->get_musics().size();i++)
            if(database->get_musics()[i]->get_name()==thing) // select a music
            {
                available=true;
                delete current_place;
                current_place=new Musicplace();
                dynamic_cast<Musicplace*>(current_place)->set_music(database->get_musics()[i]);
                dynamic_cast<Musicplace*>(current_place)->set_user(this_person);
                cout<<"you have selected a music \n";
                break;

            }
    }

    if(available==false)
    {
        for(int i=0;i<database->get_albums().size();i++)
            if(database->get_albums()[i]->get_name()==thing)
            {
                available=true;
                delete current_place;
                current_place=new Albumplace;
                dynamic_cast<Albumplace*>(current_place)->set_album(database->get_albums()[i]);
                dynamic_cast<Albumplace*>(current_place)->set_user(this_person);
                   cout<<"you have selected a album   \n" ;
                break;// i intemtionaly didnt initiate validate at first casue it would be too hard to use and actuall if admin can not be admin, then who would verify?

            }
    }
}



void User::createPlaylist(string new_playlist) // to data base asli hm eafe she
{
    for (int i = 0; i < playlists.size(); i++)
    {
        if(playlists[i]->get_name()==new_playlist)
            throw AlreadyExists();
    }
    Playlist* n_playlist=new Playlist();
    n_playlist->set_name(new_playlist);
    n_playlist->set_owner(this_person.username);
    playlists.push_back(n_playlist) ;
    //cout<< playlists[0]->get_name();

}


void User::clearPlaylist(string _playlist_name)  // remove VS erase
{
    for (int i = 0; i < playlists.size(); i++)
    {
        if(playlists[i]->get_name()==_playlist_name)
        {
            //cout<<playlists[i]->get_name()<<endl;
            playlists[i]->clear();
            break;
        }
    }
}

void User::goTo(string _playlist_name) // should queue and playlist be one kind? and what should our current  playlist* if we use queue
{
    bool is_queue=false;
    bool is_playlist=false;
    for (int i=0 ; i<playlists.size();i++)
    {   
        if(playlists[i]->get_name()==_playlist_name)
        {
            current_playlist=playlists[i];
            is_playlist=true;
            break;
        }
        else if(_playlist_name=="queue")
        {
            is_queue=true;
            break;
        }    
    }
    if (is_queue==false && is_playlist==false)
        throw ItemDoesNotExists();

    else if(is_queue==true)
    {
        delete current_place;
        current_place=new QueuePlace;
        dynamic_cast<QueuePlace*>(current_place)->set_queue(queue);
        cout<<"you are at "<<dynamic_cast<QueuePlace*>(current_place)->getCompleteName()<<endl;
    }
    else if(is_playlist==true)
    {
        delete current_place;
        current_place=new SinglePlaylist();
        dynamic_cast<SinglePlaylist*>(current_place)->set_playlist(current_playlist);
        cout<<"you are at playlist "<<dynamic_cast<SinglePlaylist*>(current_place)->get_playlist()->get_name()<<endl;

    }

}

void User::addTo(string name)
{
    bool PlaylistFound=false;
    Playlist* temp_playlist;
    if(current_place->get_type()!="music" && current_place->get_type()!="album")
        throw MethodNotAvailable();

    else
    {
        for(int i =0;i<database->get_albums().size();i++)
            if(database->get_albums()[i]->get_name()==name)
                throw NotAuthorized();
    
        //if(AlbumFound==false) // will search among playlists only if the album is not found
        for(int i =0;i<playlists.size();i++)
            if(playlists[i]->get_name()==name)
            {
                PlaylistFound=true;
                temp_playlist=playlists[i];
                break;
            }
    }
    if(PlaylistFound==false && name!="queue")
        throw ItemDoesNotExists();

    else if(PlaylistFound=true)
    {
        if(current_place->get_type()=="music")
                temp_playlist->set_music(dynamic_cast<Musicplace*>(current_place)->get_music());
            else
                temp_playlist->set_album(dynamic_cast<Albumplace*>(current_place)->get_album());
    }
    else if(name=="queue")
    {
        if(current_place->get_type()=="music")
                queue->add_music(dynamic_cast<Musicplace*>(current_place)->get_music());
            else
                queue->add_album(dynamic_cast<Albumplace*>(current_place)->get_album());
    }      
}

void User::remove(string music_name)    
{
    if(current_place->get_type()=="album")
        throw NotAuthorized();
    else
      current_place->remove(music_name); 
}
 


void User::orderItem(string music_name, int order)
{
    current_place->orderItem( music_name,  order);
}








List User::list()
{
    List out;
    out=current_place->list();
   return out;
}

List User::listMusics()
{
    //cout<<database->get_musics().size();
   return current_place->listMusics();
}

List User::listAlbums()
{
   return current_place->listAlbums();
}

List User::listPlaylists()
{
   return current_place->listPlaylists();
}

List User::listArtists()
{
    return current_place->listArtists();
}


void User::ratee(int score)
{
    current_place->rate(score);
}

string User::getArtist()
{
    return current_place->getArtist();
}
string User::getAlbum()
{
    return current_place->getAlbum();
}

string User::getName()
{
    return current_place->getName();
}
string User::getCompleteName()
{
    return current_place->getCompleteName();
}

int User::getRatee()
{
    return current_place->getRate();
}

int User::getUserRatee()
{
    return current_place->getUserRate();
}

int User::getCriticRatee()
{
    return current_place->getCriticRate();
}


void User::play()
{

    if (current_mode==Browse)  // we could have give the Queue pointer to these mentioned classes !
    {
        if (current_place->get_type()=="music")
            queue->add_music(dynamic_cast<Musicplace*>(current_place)->get_music());
        else if (current_place->get_type()=="album")
            queue->add_album(dynamic_cast<Albumplace*>(current_place)->get_album());
        else if (current_place->get_type()=="artist")
            queue->add_artist(dynamic_cast<Artistplace*>(current_place)->get_artist());
        else if (current_place->get_type()=="playlist")
            queue->add_playlist(dynamic_cast<SinglePlaylist*>(current_place)->get_playlist());
        //else
            //throw ...
        current_mode=Player;
        queue->play();
    }
    else
    {
        queue->play();
    }

}






void User::next()
{
    queue->next();
}
void User::previous()
{
    queue->previous();
}
void User::pause()
{
    queue->pause();
}


void User::shuffle()
{
    queue->shuffle();
}
void User::repeatOne()
{
    queue->repeatOne();
}
void User::repeat()
{
    queue->repeat();
}



    

	

   