
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>


#include "Database.h"
#include "Artist.h"
#include "Album_place.h"
#include "Home.h"
#include "Artist_place.h"
#include "Playlist_place.h"
#include "place.h"
#include "Library.h"
#include "Music_place.h"
#include "playlist.h"
#include "queue.h"
using namespace std;


	Artistt::Artistt()
	{
		validated=false;

	}


	void Artistt::get_validate()
	{
		validated=true;
	}

	 vector<Album*> Artistt::get_albums()
	 {
	 	return albums;
	 }
	 vector<Music*> Artistt::get_musics()
	 {
	 	return musics;
	 }
	 string Artistt::get_name()
	 {
	 	return (this_person.firstname + this_person.lastname);
	 }


	 void Artistt::addMusic(string music_name,string file_path)
	 {
	 	Music* new_music;
	 	new_music=new Music;
	 	new_music->set_author(this);
	 	new_music->set_name(music_name);
	 	new_music->set_path(file_path);
	 	musics.push_back(new_music);
	 	database->add_music(new_music);

	 	//for(int i=0;i<database->get_musics().size();i++)
		//cout<<database->get_musics()[i]->get_name()<<endl;
		//cout<<music_name<<"\n";

	 }
	 void Artistt::addAlbum(string artist_name,string album_name)
	 {
	 	Album* new_album;
	 	new_album=new Album;
	 	new_album->set_author(this);
	 	new_album->set_name(album_name);
	 	albums.push_back(new_album);
	 	database->add_album(new_album);

	 	//cout<<database->get_album(0)->get_name();

	 }



	void Artistt::addTo(string music_thing)
	{
		//cout<<current_place->get_type()<<endl;
	 	bool AlbumFound=false;
	    bool PlaylistFound=false;
	    Album* temp_album;
	    Playlist* temp_playlist;
	    if(current_place->get_type()!="music" && current_place->get_type()!="album")
	        throw MethodNotAvailable();

	    else
	    {
	        for(int i =0;i<database->get_albums().size();i++)
	            if(database->get_albums()[i]->get_name()==music_thing)
	            {
	                
	                temp_album=database->get_albums()[i];
	                if(temp_album->get_author()->get_name()!= this->get_name())
	                	throw NotAuthorized();
	                AlbumFound=true;
	                break;	            
	            }
	        if(AlbumFound==false) // will search among playlists only if the album is not found
	        {
	            for(int i =0;i<playlists.size();i++)
	                if(playlists[i]->get_name()==music_thing)
	                {
	                    PlaylistFound=true;
	                    temp_playlist=playlists[i];
	                    break;
	                }
	        }
	    }

	    if(PlaylistFound==false && AlbumFound==false && music_thing!="queue")
        	throw ItemDoesNotExists();
	    else if(PlaylistFound==true)
	    {
		    if(current_place->get_type()=="music")
		        temp_playlist->set_music(dynamic_cast<Musicplace*>(current_place)->get_music());
		    else
		        temp_playlist->set_album(dynamic_cast<Albumplace*>(current_place)->get_album());
	    }

	    else if(AlbumFound==true)
	    {
	    	if(current_place->get_type()=="music")
		        temp_album->add_music(dynamic_cast<Musicplace*>(current_place)->get_music());
		    else
		        temp_album->add_album(dynamic_cast<Albumplace*>(current_place)->get_album());
		}

		else if(music_thing=="queue")
    	{
	        if(current_place->get_type()=="music")
	                queue->add_music(dynamic_cast<Musicplace*>(current_place)->get_music());
	            else
	                queue->add_album(dynamic_cast<Albumplace*>(current_place)->get_album());
	    }


	}
	void Artistt::remove(string music_name)
	{
      	current_place->remove(music_name);
	}






