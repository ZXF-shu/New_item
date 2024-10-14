#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "global.h"


// 全局变量
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;
SDL_Surface *surface = NULL;
float scale = 1.0f;
int imgWidth, imgHeight, offsetX = 0, offsetY = 0;
bool dragging = false;
int lastMouseX, lastMouseY;
TTF_Font *font = NULL;
// 路线和图结构体
Route route;
// 图的邻接矩阵
int graph[NUM_POINTS][NUM_POINTS];
int dist[NUM_POINTS], prev[NUM_POINTS];
bool visited[NUM_POINTS];
int selectedStart = -1, selectedEnd = -1;