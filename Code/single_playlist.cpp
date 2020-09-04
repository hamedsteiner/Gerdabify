

#include "single_playlist.h"

#include "playlist.h"
#include "music.h"


SinglePlaylist::SinglePlaylist()
{
	type="playlist";
}


void SinglePlaylist::set_playlist(Playlist* _pointed_playlist)
{
	pointed_playlist=_pointed_playlist;
}




void SinglePlaylist::remove(string music_name)
{

	pointed_playlist->remove(music_name);
}

void SinglePlaylist::orderItem(string music_name, int order)
{

	pointed_playlist->orderItem( music_name, order);
}



List SinglePlaylist::list()
{
	
	List output;
	std::vector<Music*> temp ;
	temp=pointed_playlist->get_musics() ;
	for(int i=0 ; i<temp.size();i++)
	output.push_back(temp[i]->get_name());
	return output;
}


List SinglePlaylist::listMusics()
{
	List output;
	std::vector<Music*> temp ;

	temp=pointed_playlist->get_musics() ;
	for(int i=0 ; i<temp.size();i++)
	output.push_back(temp[i]->get_name());
	return output;
}



List SinglePlaylist::listAlbums()
{
	List output;
	output=pointed_playlist->get_albums();
	return output;
}




string SinglePlaylist::getName()
{
	//return pointed_playlist->get_name();
	return pointed_playlist->get_name()  ; 
}

string SinglePlaylist::getCompleteName()
{
	//return(username + "- " +pointed_playlist->get_name());
	return (pointed_playlist->get_owner()+ " - " +pointed_playlist->get_name() ) ; 
}

