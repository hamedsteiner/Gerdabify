#include <vector>
#include <string>
#include "Gerdabify_logic.h"

using namespace std;



class GerdabifyAPI
{
public:

    GerdabifyAPI();
    void enterBrowserMode();//user
    
    void goToHome();//
    void goToPlayLists();//
    void goToLibrary();//
    void goToAlbum();//
    void goToArtist();//

    List search(string);//
    void select(string);//
    
    List list();//
    List listMusics();//
    List listAlbums();//
    List listPlaylists();//
    List listArtists();//


    void play();

    void addTo(string name);
    void goTo(string name);

    void createPlaylist(string name);
    void clearPlaylist(string name);

    void remove(string name);

    void orderItem(string name, int rate);
    void rate(int score);

    string getArtist();//
    string getAlbum();//
    string getName();//
    string getCompleteName();//
    int getRate();//
    int getUserRate();//
    int getCriticRate();//





//user

    void enterPlayMode();//

    void next();
    void previous();
    void pause();
    void shuffle();
    void repeatOne();
    void repeat();
//

    void signup(UserData user, string name);//
    void login(string x, string y);//
    void addMusic(string name, string m_name);
    void addAlbum(string name, string path);
    void validate();
    UserData getUserDetails(string user);//
private:
    Gerdabify_logic* logic;
};

