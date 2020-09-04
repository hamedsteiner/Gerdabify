#include "queue.h"

#include "music.h"
#include "album.h"
#include "Artist.h"





using namespace std;
Queue::Queue()
{
	already_started=false;
	repeatition=false;
	shuffler=false;
	one_music_repeat=false;
	
}
vector<Music*> Queue::get_musics()
{
	return musics;
}
void Queue::add_music(Music* new_music)
{
	musics.push_back(new_music);
}
void Queue::add_album(Album* added_album) // ahangaye album ro begir
{
	vector<Music*>new_album_songs= added_album->get_musics();

	for(int i=0;i<new_album_songs.size();i++)
		musics.push_back(new_album_songs[i]);

	album_names.push_back(added_album->get_name());
}
void Queue::add_artist(User* added_artist) // ahangaye artist ro begir
{
	vector<Music*>new_artist_songs= dynamic_cast<Artistt*>(added_artist)->get_musics();

	for(int i=0;i<new_artist_songs.size();i++)
		musics.push_back(new_artist_songs[i]);

}

void Queue::add_playlist(Playlist* added_playlist) // ahangaye playlist ro begir
{
	vector<Music*>new_playlist_songs= added_playlist->get_musics();

	for(int i=0;i<new_playlist_songs.size();i++)
		musics.push_back(new_playlist_songs[i]);
}

void Queue::clear()
{
	for (int i=musics.size() ;i>0;i--)
	{
		musics.erase(musics.begin()+i-1);
	}
}



void Queue::play()
{
	std::vector<string> queue; 
	if(already_started==true)
		player.resume();
	else
	{
		if(shuffler==true)
		{
		
			for(int i=musics.size()-1;i>=0;i--)
				queue.push_back(musics[i]->get_path());
		}
		else
		{
			for(int i=0;i<musics.size();i++)
				queue.push_back(musics[i]->get_path());
		}

		player.setQueue(queue);
		player.setRepeat(0);
		char c;
		while (1)
		{
			std::cin>>c;
		    if(c == 'p')
		    {
		      player.pause();
		      already_started=true;
		    }

		    else if(c == 's')
		      player.stop();
		    
		    else if(c == 'c')
		      player.resume();
		 	
		 	else if(c == 'r')
		      this->repeat();

		  	else if(c == 'h')
		      this->shuffle();
		    
		    else if(c == 'p')
		      player.pause();
		    
		    else if(c == 'o')
		      this->repeatOne();
		  	
		  	else if(c == 'l')
		      this->previous();
		  	
		  	else if(c == 'n')
		      this->next();

		    else
		    {
		    	if(already_started==true)
		    		player.resume();
		    	else
		    		player.play();
		    }
	    	//player.play();
		}
	}
}




void Queue::pause()
{
	status='p';
	player.pause();
}

void Queue::next()
{
	status='n';
	player.next();
}
void Queue::previous()
{
	status='l';
	player.previous();
}




void Queue::shuffle()
{
	status='h';
	if(shuffler==false)
	{
		shuffler=true;
		
	}
	else
	{
		shuffler=false;
	}


}




void Queue::repeat()
{
	/*if(repeatition==false)
		player.setRepeat(true);
	else
		player.setRepeat(false);*/
	if(repeatition==false)
	{
		repeatition=true;
		player.setRepeat(1);
		cout<<"repeat on \n";
	}
	else
	{
		repeatition=false;
		player.setRepeat(0);
		cout<<"repeat off \n";
	}
	
}
void Queue::repeatOne()
{
	if(one_music_repeat==false)
	{
		one_music_repeat=true;
		player.setRepeat(2);
	}
	else
	{
		one_music_repeat=false;
		player.setRepeat(0);
	}
}