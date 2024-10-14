#include "global.h"
#include "load_data.h"
#include "dijkstra.h"
#include "graphics.h"
#include "events.h"
#include "destroyall.h"
int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return -1;
    if (TTF_Init() == -1) {
    printf("TTF 初始化失败: %s\n", TTF_GetError());
    return -1;
}
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    // 创建窗口
    window = SDL_CreateWindow("校园最短路径搜索", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 640, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    surface = IMG_Load("campus_map.jpg");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &imgWidth, &imgHeight);
    font = TTF_OpenFont("C:\\Windows\\Fonts\\Arial.ttf", 24);  // 使用真实的字体路径
    if (!font) {
        printf("无法加载字体: %s\n", TTF_GetError());
        return -1;
    }
    // 从文件中加载节点和路径信息
    loadPoints("points.txt");
    loadGraph("graph.txt");

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            handleEvents(event);  // 事件处理函数
        }
        renderImage();  // 渲染图片函数
    }
    // 清理SDL资源
    destroyall(texture,surface,renderer,window,font);
    return 0;
}
