#include "ent.h"
int main() 
{
    SDL_Surface *ecran;
    image t_menu_button[5];
    image t_play_button[4];
    image t_settings_button[5];
    SDL_Event event;
    Mix_Music *music;
    Mix_Chunk *clavierbref;
    Mix_Chunk *mousebref;
    int volume = 100;
    int quit = 1;
    int level = 0;
    int fullscreen = 1;
    int menu_level=0;
    //initialisation de jaw ili tebe3 background animation 
    const int numImages = 40;
    SDL_Surface *images[numImages];
    int currentFrame = 0;

    Uint32 lastTime = SDL_GetTicks();
    const Uint32 targetFrameTime = 45;
    //initialisation de jaw ili tebe3 text
    SDL_Surface *surfaceTexte;
    SDL_Rect positiontext;
    TTF_Font *font;
    SDL_Color textColor;
    //position du texte
    positiontext.x=2;
    positiontext.y=0;
    // Code RGB pour la couleur noire
    textColor.r=0;
    textColor.g=0;
    textColor.b=0;
    //image ili hya gameplay mba3ed
    image gameplay;
    gameplay.butt = IMG_Load("thelastofus.png");
    gameplay.pose.x = 0;
    gameplay.pose.y = 0;
    gameplay.pose.h = gameplay.butt->h;
    gameplay.pose.w = gameplay.butt->w;
    //----------------------------------------
    init();
    font = TTF_OpenFont( "Retro Gaming.ttf", 20 );
    surfaceTexte = TTF_RenderText_Solid(font, "V1.0 Copyright (C) 2024 Human right", textColor );
    ecran = make_window();
    loadImages(images, numImages);
    load_menu_button(t_menu_button);
    load_play_button(t_play_button);
    load_setings_button(t_settings_button);
    music = Mix_LoadMUS("Travis Scott - My Eyes - (Second Half Extended).mp3");
    Mix_PlayMusic(music, -1);
    clavierbref=Mix_LoadWAV("Keyboard Click Sound Effect No Copyright.wav");
    mousebref=Mix_LoadWAV("Click - Sound Effect (HD).wav");
    //od5el al3ebbb w a3mel jaw
    while (quit) 
    {
        while(SDL_PollEvent(&event))
        {
            switch (level)
            {
                case 0:
                    switch (event.type)
                    {
                        case SDL_MOUSEMOTION:
                            //int pos=mouse_position(event,t_menu_button,menu_level);
                            break;
                        case SDL_KEYDOWN:
                            switch (event.key.keysym.sym)
                            {
                                case SDLK_ESCAPE:
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    quit = 0;
                                    break;
                                case SDLK_n:
                                    level = 1;
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    Mix_HaltMusic();
                                    SDL_BlitSurface(gameplay.butt, NULL, ecran, NULL);
                                    break;
                                case SDLK_f:
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    fullscreen=full_screen_mode_on_off(ecran,fullscreen);
                                    break;
                                case SDLK_u:
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    volume=music_volume_up(volume);
                                    break;
                                case SDLK_d:
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    volume=music_volume_down(volume);
                                    break;
                                case SDLK_m:
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    volume=music_mute_unmute(volume);
                                    break;
                                case SDLK_p:
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    menu_level=1;
                                    play_menu(t_play_button,ecran);
                                    break;
                                case SDLK_o:
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    menu_level=2;
                                    setting_menu(t_settings_button,ecran);
                                    break;
                                case SDLK_BACKSPACE:
                                    switch(menu_level)
                                    {
                                        case 1:
                                            menu_level=0;
                                            blit_menu_button(t_menu_button,ecran);
                                            break;
                                        case 2:
                                            menu_level=0;
                                            blit_menu_button(t_menu_button,ecran);
                                    }
                                    break;
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            switch (menu_level)
                            {
                                case 0:
                                    if (event.button.button == SDL_BUTTON_LEFT)
                                    {
                                        menu_mouse_click(t_menu_button,t_play_button,t_settings_button, ecran, event, &quit, mousebref, &menu_level);
                                    }
                                    break;
                                case 1:
                                    if (event.button.button==SDL_BUTTON_LEFT)
                                    {
                                        play_mouse_clicked(ecran,event,mousebref,&level,&menu_level,t_menu_button,gameplay);
                                    }
                                    break;
                                case 2:
                                    if(event.button.button==SDL_BUTTON_LEFT)
                                    {
                                        settings_mouse_clicked(ecran,event,mousebref,&volume,&fullscreen,&menu_level,t_settings_button,t_menu_button);
                                    }
                                    break;
                            }
                            break;
                        case SDL_QUIT:
                            quit=0;
                            break;
                    }
                    break;
                case 1:
                    switch (event.type)
                    {
                        case SDL_MOUSEMOTION:
                            break;
                        case SDL_KEYDOWN:
                            switch (event.key.keysym.sym)
                            {
                                case SDLK_ESCAPE:
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    quit = 0;
                                    break;
                                case SDLK_f:
                                    fullscreen=full_screen_mode_on_off(ecran,fullscreen);
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    SDL_BlitSurface(gameplay.butt, NULL, ecran, NULL);
                                    break;
                                case SDLK_h:
                                    Mix_PlayChannel(-1,clavierbref,0);
                                    level=0;
                                    menu_level=0;
                                    Mix_PlayMusic(music, -1);
                                    blit_menu_button(t_menu_button,ecran);
                                    break;
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            break;
                        case SDL_QUIT:
                            quit=0;
                            break;
                    }
                    break;
            }
        }
        Uint32 currentTime = SDL_GetTicks();
        Uint32 elapsedTime = currentTime - lastTime;

        update(elapsedTime,targetFrameTime,&lastTime,ecran,images,&currentFrame,t_menu_button,t_play_button,t_settings_button,event,level,menu_level,surfaceTexte,positiontext,numImages);
    }
    // aya saye9 
    libere(numImages, images, ecran, music, surfaceTexte, font, t_menu_button, t_play_button, t_settings_button,clavierbref,mousebref);
    return 0;
}