#include "graphics.h"
#include "dijkstra.h"
// 计算缩放和偏移后的坐标
void getTransformedPos(int *x, int *y, int routeX, int routeY) {
    int scaledWidth = imgWidth * scale, scaledHeight = imgHeight * scale;
    int centerXOffset = offsetX + (1080 - scaledWidth) / 2;
    int centerYOffset = offsetY + (640 - scaledHeight) / 2;
    *x = centerXOffset + routeX * scale;
    *y = centerYOffset + routeY * scale;
}

// 渲染点
void renderPoints() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for (int i = 0; i < route.numPoints; ++i) {
        int x, y;
        getTransformedPos(&x, &y, route.points[i].x, route.points[i].y);
        //printf("Point %d (%s) at transformed position: (%d, %d)\n", i, route.points[i].name, x, y);  // 调试信息
        SDL_Rect rect = {x - 5, y - 5, 10, 10}; 
        SDL_RenderFillRect(renderer, &rect);
    }
}

// 渲染路径
void renderRoute() {
    if (route.numPoints > 0) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for (int i = 0; i < route.numPoints - 1; ++i) {
            int x1 = offsetX + (1080 - imgWidth * scale) / 2 + route.points[i].x * scale;
            int y1 = offsetY + (640 - imgHeight * scale) / 2 + route.points[i].y * scale;
            int x2 = offsetX + (1080 - imgWidth * scale) / 2 + route.points[i + 1].x * scale;
            int y2 = offsetY + (640 - imgHeight * scale) / 2 + route.points[i + 1].y * scale;
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }
    }
}

// 渲染图像
void renderImage() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    int scaledWidth = imgWidth * scale, scaledHeight = imgHeight * scale;
    int posX = offsetX + (1080 - scaledWidth) / 2, posY = offsetY + (640 - scaledHeight) / 2;
    SDL_Rect dstRect = {posX, posY, scaledWidth, scaledHeight};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    renderPoints();
    renderShortestPathText(renderer, font, selectedStart, selectedEnd);
    renderShortestPath();
    SDL_RenderPresent(renderer);
}

void renderShortestPathText(SDL_Renderer *renderer, TTF_Font *font, int start, int end) {
    char buffer[256];
    sprintf(buffer, "Shortest path from %d to %d:", start, end);

    // 设置文本颜色（白色）
    SDL_Color color = {255, 255, 255, 255};

    // 创建文本表面
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, buffer, color);
    if (!textSurface) {
        printf("创建文本表面失败: %s\n", TTF_GetError());
        return;
    }

    // 创建纹理
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);  // 不再需要表面，释放内存

    if (!textTexture) {
        printf("创建纹理失败: %s\n", SDL_GetError());
        return;
    }

    // 获取文本宽度和高度，用于确定在屏幕上的位置
    int textWidth = 0, textHeight = 0;
    SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);

    // 定义渲染矩形
    SDL_Rect renderQuad = {10, 10, textWidth, textHeight};  // 在左上角显示

    // 渲染纹理
    SDL_RenderCopy(renderer, textTexture, NULL, &renderQuad);

    // 销毁纹理
    SDL_DestroyTexture(textTexture);
}
void renderShortestPath() {
    if (selectedStart != -1 && selectedEnd != -1) {
        dijkstra(selectedStart);
        if (dist[selectedEnd] != INT_MAX) {
            updateRouteWithShortestPath(selectedStart, selectedEnd);  // 更新route为最短路径
            renderRoute();  // 渲染更新后的路线
        }
        else {
            printf("No path found from point %d to point %d.\n", selectedStart, selectedEnd);
        }
        // 绘制最短路径
    }
}
