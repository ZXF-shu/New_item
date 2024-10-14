
#include "destroyall.h"
#include "global.h"  
void destroyall(SDL_Texture *texture,
                SDL_Surface *surface, 
                SDL_Renderer *renderer, 
                SDL_Window *window, 
                TTF_Font *font) {   
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}