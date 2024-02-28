#ifndef ENT_H_INCLUDED
#define ENT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct 
{
    SDL_Rect pose;
    SDL_Surface *butt;
    SDL_Surface *butt_sel;
} image;

typedef struct
{
    SDL_Rect pos;
    SDL_Surface *back;
} background;

void init();
SDL_Surface* make_window();
void load_menu_button(image t[]);
void load_play_button(image t[]);
void load_setings_button(image t[]);
void loadImages(SDL_Surface **images, int numImages);
void blit_menu_button(image t_play[], SDL_Surface *ecran);
void blit_sell(image t[], SDL_Surface *ecran, SDL_Event e, int level);
void menu_mouse_click(image t[],image t_play_button[],image t_settings_menu[], SDL_Surface *ecran, SDL_Event e, int *x, Mix_Chunk *music, int *level);
int full_screen_mode_on_off(SDL_Surface *ecran,int fullscreen);
void render(SDL_Surface *ecran, SDL_Surface *images[], int currentFrame, image t_menu[],image t_play[],image t_settings[],SDL_Event event, int level,int level_menu,SDL_Surface *surfaceTexte,SDL_Rect positiontext);
int music_volume_up(int volume);
int music_volume_down(int volume);
int music_mute_unmute(int volume);
void update(Uint32 elapsedTime,Uint32 targetFrameTime,Uint32 *lastTime,SDL_Surface *ecran, SDL_Surface *images[],int *currentFrame, image t_menu[],image t_play[],image t_settings[], SDL_Event event, int level,int level_menu,SDL_Surface *surfaceTexte,SDL_Rect positiontext,int numImages);
void libere(int numImages, SDL_Surface *images[], SDL_Surface *ecran, Mix_Music *music, SDL_Surface *surfaceTexte, TTF_Font *font, image t_menu_button[], image t_play_button[], image t_settings_button[],Mix_Chunk *clavierbref,Mix_Chunk *mousebref) ;
int mouse_position(SDL_Event e,image t[],int level);
void play_menu(image t[],SDL_Surface *e);
void blit_play_sel(image t[], SDL_Surface *ecran, SDL_Event e, int level);
void play_mouse_clicked(SDL_Surface *ecran,SDL_Event e,Mix_Chunk *music,int *level,int *level_menu,image t[],image gameplay);
void setting_menu(image t[],SDL_Surface *e);
void blit_settings_button(image t[],SDL_Surface *e);
void blit_settings_sel(image t[], SDL_Surface *ecran, SDL_Event e, int level);
int mouse_position_settings(SDL_Event e,image t[],int level);
void settings_mouse_clicked(SDL_Surface *ecran,SDL_Event e,Mix_Chunk *music,int *volume,int *full,int *level_menu,image t[],image t_menu[]);
//void level_0(SDL_Event event,SDL_Surface* music,int *quit,int *level,image gameplay,int *fullscreen,SDL_Surface *ecran,int *volume,image t_menu[]);


#endif // ENT_H_INCLUDED