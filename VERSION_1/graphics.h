#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "global.h"
void getTransformedPos(int *x, int *y, int routeX, int routeY) ;
void renderPoints() ;
void renderImage();
void renderImage();
void renderShortestPathText(SDL_Renderer *renderer, TTF_Font *font, int start, int end);
void renderShortestPath() ;
#endif