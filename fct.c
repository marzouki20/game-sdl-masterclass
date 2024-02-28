#include "ent.h"
void init() 
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) 
    {
        fprintf(stderr, "Error 404!! Echec d'initialisation: %s\n", SDL_GetError());
        exit(-1);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0) 
    {
        fprintf(stderr, "Error 404!! Echec d'initialisation de l'audio: %s\n", Mix_GetError());
        exit(-1);
    }
    if (TTF_Init() == -1) {
        fprintf(stderr, "Error initializing SDL_ttf: %s\n", TTF_GetError());
        exit(-1);
    }

    printf("SDL_ttf initialized successfully.\n");

    printf("SDL est initialise avec succes.\n");
}

SDL_Surface* make_window() 
{
    SDL_Surface *ecran;
    ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_FULLSCREEN|SDL_HWSURFACE );
    if (ecran == NULL) 
    {
        fprintf(stderr, "Error 404!! Echec de creation de la fenetre de 1383x796: %s\n", SDL_GetError());
        exit(-1);
    }
    return ecran;
}

void menu_mouse_click(image t[],image t_play_button[],image t_settings_menu[], SDL_Surface *ecran, SDL_Event e, int *x, Mix_Chunk *music, int *level)
{
    int pos=mouse_position(e,t,*level);
    if (pos==1)
    {
        // Handle play button click
        *level = 1;
        Mix_PlayChannel(-1,music,0);
        play_menu(t_play_button,ecran);
    }
    else if (pos==2)
    {
        // Handle settings button click
        *level=2;
        Mix_PlayChannel(-1,music,0);
        setting_menu(t_settings_menu,ecran);
    }
    else if (pos==3)
    {
        // Handle settings button click
        Mix_PlayChannel(-1,music,0);
    }
    else if (pos==4)
    {
        Mix_PlayChannel(-1,music,0);
        *x = 0; 
    }
}
int full_screen_mode_on_off(SDL_Surface *ecran,int fullscreen)
{
    if (fullscreen == 0) 
    {
        ecran = make_window();
        fullscreen = 1;
    }
    else 
    {
        ecran = SDL_SetVideoMode(1800, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);; // 0 means windowed mode
        fullscreen = 0;
    }
    return fullscreen;
}

void update(Uint32 elapsedTime,Uint32 targetFrameTime,Uint32 *lastTime,SDL_Surface *ecran, SDL_Surface *images[],int *currentFrame, image t_menu[],image t_play[],image t_settings[], SDL_Event event, int level,int level_menu,SDL_Surface *surfaceTexte,SDL_Rect positiontext,int numImages)
{
    if (elapsedTime < targetFrameTime) {
            SDL_Delay(targetFrameTime - elapsedTime);
        }
        *lastTime = SDL_GetTicks();
        // Draw the current frame
        render(ecran,images,*currentFrame,t_menu,t_play,t_settings,event,level,level_menu,surfaceTexte,positiontext);
        if(!level)
        {
            // Delay for a short period to control the animation speed
            SDL_Delay(45);
            // Clear the ecran for the next frame
            SDL_FillRect(ecran, NULL, 0);
            // Move to the next frame
            *currentFrame = (*currentFrame + 1) % numImages;
        }
}
void libere(int numImages, SDL_Surface *images[], SDL_Surface *ecran, Mix_Music *music, SDL_Surface *surfaceTexte, TTF_Font *font, image t_menu_button[], image t_play_button[], image t_settings_button[],Mix_Chunk *clavierbref,Mix_Chunk *mousebref) 
{
    for (int i = 0; i < numImages; ++i) {
        SDL_FreeSurface(images[i]);
    }

    for (int i = 0; i < 5; ++i) {
        SDL_FreeSurface(t_menu_button[i].butt);
        SDL_FreeSurface(t_menu_button[i].butt_sel); 
    }

    for (int i = 0; i < 4; ++i) {
        SDL_FreeSurface(t_play_button[i].butt);
        SDL_FreeSurface(t_play_button[i].butt_sel); 
    }

    for (int i = 0; i < 5; ++i) {
        SDL_FreeSurface(t_settings_button[i].butt);
        SDL_FreeSurface(t_settings_button[i].butt_sel); 
    }

    SDL_FreeSurface(ecran);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_FreeSurface(surfaceTexte);
    TTF_CloseFont(font);
    Mix_FreeChunk(clavierbref);
    Mix_FreeChunk(mousebref);
    SDL_Quit();
}

int mouse_position(SDL_Event e,image t[],int level)
{
    if((e.motion.x >= t[0].pose.x) && (e.motion.x <= (t[0].pose.x + t[0].butt->w)) && (e.motion.y >= t[0].pose.y) && (e.motion.y <= t[0].pose.y + t[0].butt->h)&& (level == 0||level==1||level==2))
        return 1;
    else if((e.motion.x >= t[1].pose.x) && (e.motion.x <= (t[1].pose.x + t[1].butt->w)) && (e.motion.y >= t[1].pose.y) && (e.motion.y <= t[1].pose.y + t[1].butt->h)&& (level == 0||level==1||level==2))
        return 2;
    else if((e.motion.x >= t[2].pose.x) && (e.motion.x <= (t[2].pose.x + t[2].butt->w)) && (e.motion.y >= t[2].pose.y) && (e.motion.y <= t[2].pose.y + t[2].butt->h)&& (level == 0||level==1||level==2))
        return 3;
    else if((e.motion.x >= t[3].pose.x) && (e.motion.x <= (t[3].pose.x + t[3].butt->w)) && (e.motion.y >= t[3].pose.y) && (e.motion.y <= t[3].pose.y + t[3].butt->h)&& (level == 0||level==1||level==2))
        return 4;
}

void play_menu(image t[],SDL_Surface *e)
{
    blit_menu_button(t,e);
}
void setting_menu(image t[],SDL_Surface *e)
{
    blit_settings_button(t,e);
}
void blit_settings_button(image t[],SDL_Surface *e)
{
    SDL_BlitSurface(t[4].butt, NULL, e, &(t[4].pose));
    for(int i=0;i<4;i++)
    {
        SDL_BlitSurface(t[i].butt, NULL, e, &(t[i].pose));
    }
}
int mouse_position_settings(SDL_Event e,image t[],int level)
{
    if((e.motion.x >= t[0].pose.x) && (e.motion.x <= (t[0].pose.x + t[0].butt->w)) && (e.motion.y >= t[0].pose.y) && (e.motion.y <= t[0].pose.y + t[0].butt->h)&& (level==2))
        return 1;
    else if((e.motion.x >= t[1].pose.x) && (e.motion.x <= (t[1].pose.x + t[1].butt->w)) && (e.motion.y >= t[1].pose.y) && (e.motion.y <= t[1].pose.y + t[1].butt->h)&& (level==2))
        return 2;
    else if((e.motion.x >= t[2].pose.x) && (e.motion.x <= (t[2].pose.x + t[2].butt->w)) && (e.motion.y >= t[2].pose.y) && (e.motion.y <= t[2].pose.y + t[2].butt->h)&& (level==2))
        return 3;
    else if((e.motion.x >= t[3].pose.x) && (e.motion.x <= (t[3].pose.x + t[3].butt->w)) && (e.motion.y >= t[3].pose.y) && (e.motion.y <= t[3].pose.y + t[3].butt->h)&& (level==2))
        return 4;
}