#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include "Gerdabify_logic.h"
//#include "User.h"


using namespace std;


    Gerdabify_logic::Gerdabify_logic(){
        cout<<"";
    }

    bool Gerdabify_logic::Is_iterative(UserData _new_user)
    {
        for(int i=0;i<users.size();i++)
            if(users[i]->getUserDetails().username == _new_user.username || 
               users[i]->getUserDetails().firstname == _new_user.firstname ||
               users[i]->getUserDetails().lastname == _new_user.lastname
               )
                return true;
        return false;
    }


// i intentionaly didnt initiate validate at first casue it would be too hard to use and actuall if admin can not be admin, then who would verify?


    void Gerdabify_logic::signup(UserData _new_user, string password)//////// no vverify in PROJECT
    {
        if(Is_iterative(_new_user)==true)
            throw AlreadyExists();
        else
        {
            User* new_user;

            if(_new_user.userType==Admin)
            {
                 new_user=new Adminn;//Admin
                 new_user->set_person(_new_user);
                 new_user->set_password(password);
                 new_user->set_database(&main_database);
            }

            else if(_new_user.userType==Artist)
            {
                new_user=new Artistt;//Artist////////////////////////////////////nashod !
                new_user->set_person(_new_user);
                new_user->set_password(password);

                new_user->set_database(&main_database);

                main_database.add_artist(new_user);
            }
            else if(_new_user.userType==Editor)
            {
                 new_user=new Editorr;//Editor
                 new_user->set_person(_new_user);
                 new_user->set_password(password);
                 new_user->set_database(&main_database);
            }
            else
            {
                 new_user=new User;
                 new_user->set_person(_new_user);
                 new_user->set_password(password);
                 new_user->set_database(&main_database);
            }
            users.push_back(new_user);
        }
         cout<<"Signed up, welcome \n";
         //cout<<users[0]->getUserDetails().firstname;
        
    }

    void Gerdabify_logic::login(string user_name, string password)
    {
        bool exist=false;
        for(int i=0;i<users.size();i++)
            if(users[i]->getUserDetails().username==user_name)
                if(users[i]->get_password()==password)
                {
                    active_user=users[i];
                    cout<<"Welcome back , "<<active_user->getUserDetails().firstname<<" "<<active_user->getUserDetails().lastname<<endl;
                    exist=true;
                }
               // cout<<"SAKHT1";
        if(exist==false)
            throw InvalidCredentials();
    }



    void Gerdabify_logic::enterBrowserMode()
    {
        active_user->enterBrowserMode();
    }
    void Gerdabify_logic::enterPlayMode()
    {
        active_user->enterPlayMode();
    }


    void Gerdabify_logic::addMusic(string music, string path)
    {
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->addMusic(music,path);
    }

    void Gerdabify_logic::addAlbum(string artist_name, string album_name)
    {
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->addAlbum(artist_name,album_name);
    }

    UserData Gerdabify_logic::getUserDetails(string user_name)
    {
        bool exist=false;
        for(int i=0;i<users.size();i++)
            if(users[i]->getUserDetails().username==user_name) ///  FUNCTION OVERLOADING !
                {
                    exist=true;
                    return users[i]->getUserDetails();
                }

        if(exist==false)
            throw InvalidCredentials();
    }



    
    void Gerdabify_logic::goToHome()
    {

        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->goToHome();
    }
    void Gerdabify_logic::goToPlayLists()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->goToPlayLists();
    }

    void Gerdabify_logic::goToLibrary()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->goToLibrary();
    }

    void Gerdabify_logic::goToAlbum()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->goToAlbum();
    }

    void Gerdabify_logic::goToArtist()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->goToArtist();
    }

    List Gerdabify_logic::search(string thing)
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
        return active_user->search(thing);
    }


    void Gerdabify_logic::select(string thing)
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->select(thing);
    }

    


    void Gerdabify_logic::goTo(string thing)
    {  
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->goTo(thing);
    } 

    void Gerdabify_logic::addTo(string name)
    {

        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
        {
            for(int i =0;i<users.size();i++)
                if(users[i]->getUserDetails().username!=active_user->getUserDetails().username)
                {
                    for(int j =0;j<users[i]->get_playlists().size();j++)
                        if(users[i]->get_playlists()[j]->get_name()==name)
                            throw NotAuthorized();
                }
            active_user->addTo(name);
        }
    }

    void Gerdabify_logic::remove(string thing)
    {

        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->remove(thing);
    }


    void Gerdabify_logic::orderItem(string music_name, int order)
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->orderItem(music_name,order);
    }


    List Gerdabify_logic::list()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->list();
    }

    List Gerdabify_logic::listMusics()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->listMusics();
    }

    List Gerdabify_logic::listAlbums()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->listAlbums();
    }

    List Gerdabify_logic::listPlaylists()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->listPlaylists();
    }

    List Gerdabify_logic::listArtists()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->listArtists();
    }




    void Gerdabify_logic::rate(int thing)
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->ratee(thing);
    }

    string Gerdabify_logic::getArtist()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->getArtist();
    }

    string Gerdabify_logic::getAlbum()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->getAlbum();
    }

    string Gerdabify_logic::getName()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->getName();
    }

    string Gerdabify_logic::getCompleteName()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->getCompleteName();
    }

    int Gerdabify_logic::getRate()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return  active_user->getRatee();
    }

    int Gerdabify_logic::getUserRate()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->getUserRatee();
    }

    int Gerdabify_logic::getCriticRate()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            return active_user->getCriticRatee();
    }


    void Gerdabify_logic::createPlaylist(string name)
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->createPlaylist(name);
    } 

    void Gerdabify_logic::validate()
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
            active_user->validate();
    }




    void Gerdabify_logic::play()
    {
        active_user->play();
    }




    

    void Gerdabify_logic::clearPlaylist(string thing)
    {    
        if(active_user->get_mode()==Player)
            throw MethodNotAvailable();
        else
        {
            //cout<<active_user->get_playlists()[0]->get_name()<<endl;
            active_user->clearPlaylist(thing);
        }
    }





    void Gerdabify_logic::next()
    {    
        if(active_user->get_mode()==Browse)
            throw MethodNotAvailable();
        else
            active_user->next();
    }

    void Gerdabify_logic::previous()
    {    
        if(active_user->get_mode()==Browse)
            throw MethodNotAvailable();
        else
            active_user->previous();
    }

    void Gerdabify_logic::pause()
    {    
        if(active_user->get_mode()==Browse)
            throw MethodNotAvailable();
        else
            active_user->pause();
    }


    void Gerdabify_logic::shuffle()
    {    
        if(active_user->get_mode()==Browse)
            throw MethodNotAvailable();
        else
            active_user->shuffle();
    }

    void Gerdabify_logic::repeatOne()
    {    
        if(active_user->get_mode()==Browse)
            throw MethodNotAvailable();
        else
            active_user->repeatOne();
    }

    void Gerdabify_logic::repeat()
    {    
        if(active_user->get_mode()==Browse)
            throw MethodNotAvailable();
        else
            active_user->repeat();
    }



////////////////over ride mishe


    









    

    //void verifyUser(string);





