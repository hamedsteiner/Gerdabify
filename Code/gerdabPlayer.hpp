#include "sdlHeaders.hpp"
#include <iostream>
#include <string>
#include <vector>

void Delay(int milis);
class GerdabPlayer
{
  public:
    GerdabPlayer();
    static void play();
    static void setMusic(std::string path);
    static void pause();
    static void resume();
    static void next();
    static void previous();
    static void stop();
    //static void setRepeat(bool repeat);
    static void setRepeat(int repeat);
    static void setQueue(std::vector<std::string> queue);
    friend void musicFinishCallback();
    static std::string nextMusic;


    //static void setRepeatmusic(bool repeat){repeat_this_music=repeat;}
    //static bool repeat_this_music;

  private:
    static Mix_Music *music;
    static std::vector<std::string> queue;
    //static bool repeat;
    static int repeat;
    static int index;
    static void goToNext();
    //bool repeat_this_music;
    
};





class GerdabError{
private:
  std::string message;
public:
  GerdabError();
  GerdabError(std::string errorMessage);
  std::string getMessage();
};