#include "ent.h"
void level_0(SDL_Event event,SDL_Surface* music,int *quit,int *level,image gameplay,int *fullscreen,SDL_Surface *ecran,int *volume,image t_menu[])
{
    switch (event.type)
                    {
                        case SDL_MOUSEMOTION:
                            break;
                        case SDL_KEYDOWN:
                            switch (event.key.keysym.sym)
                            {
                                case SDLK_ESCAPE:
                                    music = Mix_LoadMUS("Keyboard Click Sound Effect No Copyright.mp3");
                                    Mix_PlayMusic(music, 1);
                                    *quit = 0;
                                    break;
                                case SDLK_p:
                                    *level = 1;
                                    music = Mix_LoadMUS("Keyboard Click Sound Effect No Copyright.mp3");
                                    Mix_PlayMusic(music, 1);
                                    SDL_BlitSurface(gameplay.butt, NULL, ecran, NULL);
                                    break;
                                case SDLK_f:
                                    music=Mix_LoadMUS("Keyboard Click Sound Effect No Copyright.mp3");
                                    Mix_PlayMusic(music, 1);
                                    *fullscreen=full_screen_mode_on_off(ecran,*fullscreen);
                                    break;
                                case SDLK_u:
                                    *volume=music_volume_up(*volume);
                                    break;
                                case SDLK_d:
                                    *volume=music_volume_down(*volume);
                                    break;
                                case SDLK_m:
                                    *volume=music_mute_unmute(*volume);
                                    break;
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.button == SDL_BUTTON_LEFT)
                            {
                                menu_mouse_click(t_menu, ecran, event, quit, music, level);
                            }
                            break;
                        case SDL_QUIT:
                            *quit=0;
                            break;
                    }
}