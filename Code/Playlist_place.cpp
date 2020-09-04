

#include "Playlist_place.h"

#include "playlist.h"
#include "music.h"


Playlistplace::Playlistplace()
{
	type="Playlistplace";
}


void Playlistplace::set_playlists(vector<Playlist*> _pointed_playlists)
{
	pointed_playlists=_pointed_playlists;
}




List Playlistplace::list()
{
	List output;
	std::vector<Music*> temp ;
	for(int j=0 ; j<pointed_playlists.size();j++)
	{
		temp=pointed_playlists[j]->get_musics() ;
		for(int i=0 ; i<temp.size();i++)
		output.push_back(temp[i]->get_name());
	}
	return output;
}


List Playlistplace::listMusics()
{
	List output;
	std::vector<Music*> temp ;
	for(int j=0 ; j<pointed_playlists.size();j++)
	{
		temp=pointed_playlists[j]->get_musics() ;
		for(int i=0 ; i<temp.size();i++)
		output.push_back(temp[i]->get_name());
	}
	return output;
}



List Playlistplace::listAlbums()
{
	List output;
	for(int i=0;i<pointed_playlists.size();i++)
		output=pointed_playlists[i]->get_albums();
	return output;
}


List Playlistplace::listPlaylists()
{
	List output;
	for(int i=0 ; i<pointed_playlists.size();i++)
		output.push_back(pointed_playlists[i]->get_name());
	return output;
}


string Playlistplace::getName()
{
	//return pointed_playlist->get_name();
	return "playlists" ; 
}

string Playlistplace::getCompleteName()
{
	//return(username + "- " +pointed_playlist->get_name());
	return "playlists" ; 
}

