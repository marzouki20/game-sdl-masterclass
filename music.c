#include "ent.h"
int music_volume_up(int volume)
{
    //ti ziiidd fi sout
    if (volume < 100) 
    {
        volume += 10; //rigel jawek
    }
    Mix_VolumeMusic(volume);
    return volume;
}
int music_volume_down(int volume)
{
    // ya 3issam 9atlek mama na9es fi soutek 5ali **** nor9dou
    if (volume >0) 
    {
        volume -= 10; //rigel jawek
    }
    Mix_VolumeMusic(volume);
    return volume;
}
int music_mute_unmute(int volume)
{
    //ya hassen saker fomek
    if(volume)
    {
        volume=0;
    }
    else{volume=100;}
    Mix_VolumeMusic(volume);
    return volume;
}