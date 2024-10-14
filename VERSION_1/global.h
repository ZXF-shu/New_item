#ifndef _ROUTE_GLOBAL_H
#define _ROUTE_GLOBAL_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#define NUM_POINTS 8
#include "STRUCT.h"

// 全局变量
extern SDL_Window *window ;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;
extern SDL_Surface *surface;
extern float scale ;
extern int imgWidth, imgHeight, offsetX, offsetY ;
extern bool dragging  ;
extern int lastMouseX, lastMouseY;
extern TTF_Font *font ;
// 图的邻接矩阵
extern int graph[NUM_POINTS][NUM_POINTS];
extern int dist[NUM_POINTS], prev[NUM_POINTS];
extern bool visited[NUM_POINTS];
extern int selectedStart , selectedEnd ;
// 路线和图结构体


#endif // _ROUTE_GLOBAL_H
