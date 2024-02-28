#include "ent.h"
void load_menu_button(image t[]) 
{

    t[0].butt = IMG_Load("menu_folder/BUTTONS/play.png");
    t[0].butt_sel = IMG_Load("menu_folder/BUTTONS/play_sel.png");
    t[0].pose.x = 850;
    t[0].pose.y = 400;
    t[0].pose.h = t[0].butt->h;
    t[0].pose.w = t[0].butt->w;

    t[1].butt = IMG_Load("menu_folder/BUTTONS/settings.png");
    t[1].butt_sel = IMG_Load("menu_folder/BUTTONS/settings_sel.png");
    t[1].pose.x = 850;
    t[1].pose.y = 500;
    t[1].pose.h = t[1].butt->h;
    t[1].pose.w = t[1].butt->w;

    t[2].butt = IMG_Load("menu_folder/BUTTONS/about.png");
    t[2].butt_sel = IMG_Load("menu_folder/BUTTONS/about_sel.png");
    t[2].pose.x = 850;
    t[2].pose.y = 600;
    t[2].pose.h = t[2].butt->h;
    t[2].pose.w = t[2].butt->w;

    t[3].butt = IMG_Load("menu_folder/BUTTONS/exit.png");
    t[3].butt_sel = IMG_Load("menu_folder/BUTTONS/exit_sel.png");
    t[3].pose.x = 850;
    t[3].pose.y = 700;
    t[3].pose.h = t[3].butt->h;
    t[3].pose.w = t[3].butt->w;


    t[4].butt = IMG_Load("menu_folder/MENU.png");
    t[4].butt_sel = NULL;
    t[4].pose.x = 620;
    t[4].pose.y = 200;
    t[4].pose.h = t[4].butt->h;
    t[4].pose.w = t[4].butt->w;
}
void load_play_button(image t[])
{
    t[0].butt = IMG_Load("menu_folder/BUTTONS/new_game.png");
    t[0].butt_sel = IMG_Load("menu_folder/BUTTONS/new_game_sel.png");
    t[0].pose.x = 850;
    t[0].pose.y = 400;
    t[0].pose.h = t[0].butt->h;
    t[0].pose.w = t[0].butt->w;

    t[1].butt = IMG_Load("menu_folder/BUTTONS/continue.png");
    t[1].butt_sel = IMG_Load("menu_folder/BUTTONS/continue_sel.png");
    t[1].pose.x = 850;
    t[1].pose.y = 500;
    t[1].pose.h = t[1].butt->h;
    t[1].pose.w = t[1].butt->w;

    t[2].butt = IMG_Load("menu_folder/BUTTONS/back.png");
    t[2].butt_sel = IMG_Load("menu_folder/BUTTONS/back_sel.png");
    t[2].pose.x = 850;
    t[2].pose.y = 600;
    t[2].pose.h = t[2].butt->h;
    t[2].pose.w = t[2].butt->w;

    t[3].butt = IMG_Load("menu_folder/MENU.png");
    t[3].butt_sel = NULL;
    t[3].pose.x = 620;
    t[3].pose.y = 200;
    t[3].pose.h = t[3].butt->h;
    t[3].pose.w = t[3].butt->w;
}
void load_setings_button(image t[])
{
    t[0].butt = IMG_Load("menu_folder/BUTTONS/level_up.png");
    t[0].butt_sel = IMG_Load("menu_folder/BUTTONS/level_up_sel.png");
    t[0].pose.x = 1000;
    t[0].pose.y = 450;
    t[0].pose.h = t[0].butt->h;
    t[0].pose.w = t[0].butt->w;

    t[1].butt = IMG_Load("menu_folder/BUTTONS/level_down.png");
    t[1].butt_sel = IMG_Load("menu_folder/BUTTONS/level_down_sel.png");
    t[1].pose.x = 800;
    t[1].pose.y = 450;
    t[1].pose.h = t[1].butt->h;
    t[1].pose.w = t[1].butt->w;
    
    t[2].butt = IMG_Load("menu_folder/BUTTONS/fullscreen.png");
    t[2].butt_sel = IMG_Load("menu_folder/BUTTONS/window_mode.png");
    t[2].pose.x = 910;
    t[2].pose.y = 550;
    t[2].pose.h = t[2].butt->h;
    t[2].pose.w = t[2].butt->w;

    t[3].butt = IMG_Load("menu_folder/BUTTONS/back.png");
    t[3].butt_sel = IMG_Load("menu_folder/BUTTONS/back_sel.png");
    t[3].pose.x = 850;
    t[3].pose.y = 700;
    t[3].pose.h = t[3].butt->h;
    t[3].pose.w = t[3].butt->w;


    t[4].butt = IMG_Load("menu_folder/MENU.png");
    t[4].butt_sel = NULL;
    t[4].pose.x = 620;
    t[4].pose.y = 200;
    t[4].pose.h = t[4].butt->h;
    t[4].pose.w = t[4].butt->w;
}
void loadImages(SDL_Surface **images, int numImages) {
    char filename[50];

    for (int i = 0; i < numImages; ++i) {
        sprintf(filename, "menu_folder/emounti/Frame %d.png", i + 1);
        images[i] = IMG_Load(filename);

        if (images[i] == NULL) {
            fprintf(stderr, "Unable to load image %d: %s\n", i + 1, SDL_GetError());
            exit(1);
        }
    }
}
void blit_menu_button(image t_play[], SDL_Surface *ecran)
{
    SDL_BlitSurface(t_play[3].butt, NULL, ecran, &(t_play[3].pose));
    for(int i=0;i<3;i++)
    {
        SDL_BlitSurface(t_play[i].butt, NULL, ecran, &(t_play[i].pose));
    }
}
void blit_sell(image t[], SDL_Surface *ecran, SDL_Event e, int level)
{
    int pos=mouse_position(e,t,level);
    if (pos==1)
    {
        SDL_BlitSurface(t[4].butt,NULL,ecran,&(t[4].pose));
        SDL_BlitSurface(t[0].butt_sel, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[1].butt, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[2].butt, NULL, ecran, &(t[2].pose));
        SDL_BlitSurface(t[3].butt, NULL, ecran, &(t[3].pose));
    }
    else if (pos==2)
    {
        SDL_BlitSurface(t[4].butt,NULL,ecran,&(t[4].pose));
        SDL_BlitSurface(t[1].butt_sel, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[0].butt, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[2].butt, NULL, ecran, &(t[2].pose));
        SDL_BlitSurface(t[3].butt, NULL, ecran, &(t[3].pose));
    }
    else if (pos==3)
    {
        SDL_BlitSurface(t[4].butt,NULL,ecran,&(t[4].pose));
        SDL_BlitSurface(t[2].butt_sel, NULL, ecran, &(t[2].pose));
        SDL_BlitSurface(t[0].butt, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[1].butt, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[3].butt, NULL, ecran, &(t[3].pose));
    }
    else if(pos==4)
    {
        SDL_BlitSurface(t[4].butt,NULL,ecran,&(t[4].pose));
        SDL_BlitSurface(t[2].butt, NULL, ecran, &(t[2].pose));
        SDL_BlitSurface(t[0].butt, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[1].butt, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[3].butt_sel, NULL, ecran, &(t[3].pose));
    }
}
void render(SDL_Surface *ecran, SDL_Surface *images[], int currentFrame, image t_menu[],image t_play[],image t_settings[],SDL_Event event, int level,int level_menu,SDL_Surface *surfaceTexte,SDL_Rect positiontext)
{
    if (!level) {
        SDL_BlitSurface(images[currentFrame], NULL, ecran, NULL);
        int pos;
        pos=mouse_position(event,t_menu,level_menu);
        int pos_settings=mouse_position_settings(event,t_settings,level_menu);
        if ((pos!=1&&pos!=2&&pos!=3&&pos!=4)&&level_menu==0) 
        {
            SDL_BlitSurface(t_menu[4].butt,NULL,ecran,&(t_menu[4].pose));
            SDL_BlitSurface(t_menu[0].butt, NULL, ecran, &(t_menu[0].pose));
            SDL_BlitSurface(t_menu[1].butt, NULL, ecran, &(t_menu[1].pose));
            SDL_BlitSurface(t_menu[2].butt, NULL, ecran, &(t_menu[2].pose));
            SDL_BlitSurface(t_menu[3].butt, NULL, ecran, &(t_menu[3].pose));
            SDL_BlitSurface(surfaceTexte, NULL, ecran, &positiontext);
        } 
        else if((pos!=1&&pos!=2&&pos!=3)&&level_menu==1)
        {
            pos=mouse_position(event,t_play,level_menu);
            blit_menu_button(t_play,ecran);
        }
        else if((pos==1||pos==2||pos==3)&&level_menu==1)
        {
            pos=mouse_position(event,t_play,level_menu);
            blit_play_sel(t_play,ecran,event,level_menu);
        }
        else if((pos_settings!=1&&pos_settings!=2&&pos_settings!=3&&pos_settings!=4)&&level_menu==2)
        {
            blit_settings_button(t_settings,ecran);
        }
        else if((pos_settings==1||pos_settings==2||pos_settings==3||pos_settings==4)&&level_menu==2)
        {
            blit_settings_sel(t_settings,ecran,event,level_menu);
        }
        else if ((pos==1||pos==2||pos==3||pos==4)&&level_menu==0) 
        {
            blit_sell(t_menu, ecran, event, level);
            SDL_BlitSurface(surfaceTexte, NULL, ecran, &positiontext);
        }
    }
    SDL_Flip(ecran);
}
void blit_play_sel(image t[], SDL_Surface *ecran, SDL_Event e, int level)
{
    int pos=mouse_position(e,t,level);
    if (pos==1)
    {
        SDL_BlitSurface(t[3].butt, NULL, ecran, &(t[3].pose));
        SDL_BlitSurface(t[0].butt_sel, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[1].butt, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[2].butt, NULL, ecran, &(t[2].pose));
    }
    else if (pos==2)
    {
        SDL_BlitSurface(t[3].butt, NULL, ecran, &(t[3].pose));
        SDL_BlitSurface(t[1].butt_sel, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[0].butt, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[2].butt, NULL, ecran, &(t[2].pose));
    }
    else if (pos==3)
    {
        SDL_BlitSurface(t[3].butt, NULL, ecran, &(t[3].pose));
        SDL_BlitSurface(t[2].butt_sel, NULL, ecran, &(t[2].pose));
        SDL_BlitSurface(t[0].butt, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[1].butt, NULL, ecran, &(t[1].pose));
    }
}
void play_mouse_clicked(SDL_Surface *ecran,SDL_Event e,Mix_Chunk *music,int *level,int *level_menu,image t[],image gameplay)
{
    int pos=mouse_position(e,t,*level);
    if(pos==1||pos==2)
    {
        Mix_PlayChannel(-1,music,0);
        Mix_HaltMusic();
        SDL_BlitSurface(gameplay.butt,NULL,ecran,NULL);
        *level=1;
    }
    else if(pos==3)
    {
        Mix_PlayChannel(-1,music,0);
        *level_menu=0;
        blit_menu_button(t,ecran);
    }
}
void blit_settings_sel(image t[], SDL_Surface *ecran, SDL_Event e, int level)
{
    int pos=mouse_position(e,t,level);
    if (pos==1)
    {
        SDL_BlitSurface(t[4].butt, NULL, ecran, &(t[4].pose));
        SDL_BlitSurface(t[0].butt_sel, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[1].butt, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[2].butt, NULL, ecran, &(t[2].pose));
        SDL_BlitSurface(t[3].butt, NULL, ecran, &(t[3].pose));
    }
    else if (pos==2)
    {
        SDL_BlitSurface(t[4].butt, NULL, ecran, &(t[4].pose));
        SDL_BlitSurface(t[1].butt_sel, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[0].butt, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[2].butt, NULL, ecran, &(t[2].pose));
        SDL_BlitSurface(t[3].butt, NULL, ecran, &(t[3].pose));
    }
    else if (pos==3)
    {
        SDL_BlitSurface(t[4].butt, NULL, ecran, &(t[4].pose));
        SDL_BlitSurface(t[2].butt_sel, NULL, ecran, &(t[2].pose));
        SDL_BlitSurface(t[0].butt, NULL, ecran, &(t[0].pose));
        SDL_BlitSurface(t[1].butt, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[3].butt, NULL, ecran, &(t[3].pose));
    }
    else if(pos==4)
    {
        SDL_BlitSurface(t[4].butt, NULL, ecran, &(t[4].pose));
        SDL_BlitSurface(t[3].butt_sel, NULL, ecran, &(t[3].pose));
        SDL_BlitSurface(t[1].butt, NULL, ecran, &(t[1].pose));
        SDL_BlitSurface(t[2].butt, NULL, ecran, &(t[2].pose));
        SDL_BlitSurface(t[0].butt, NULL, ecran, &(t[0].pose));
    }
}
void settings_mouse_clicked(SDL_Surface *ecran,SDL_Event e,Mix_Chunk *music,int *volume,int *full,int *level_menu,image t[],image t_menu[])
{
    int pos=mouse_position_settings(e,t,*level_menu);
    switch (pos)
    {
        case 1:
            Mix_PlayChannel(-1,music,0);
            *volume=music_volume_up(*volume);
            break;
        case 2:
            Mix_PlayChannel(-1,music,0);
            *volume=music_volume_down(*volume);
            break;
        case 3:
            Mix_PlayChannel(-1,music,0);
            *full=full_screen_mode_on_off(ecran,*full);
            break;
        case 4:
            Mix_PlayChannel(-1,music,0);
            *level_menu=0;
            blit_menu_button(t_menu,ecran);
            break;
    }
}