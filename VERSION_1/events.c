#include "events.h"
#include "graphics.h"
int getPointAtMouse(int mouseX, int mouseY) {
    for (int i = 0; i < NUM_POINTS; ++i) {
        int x, y;
        getTransformedPos(&x, &y, route.points[i].x, route.points[i].y);
        if (mouseX >= x - 5 && mouseX <= x + 5 && mouseY >= y - 5 && mouseY <= y + 5) return i;
    }
    return -1;
}

void handleEvents(SDL_Event event) {
    switch (event.type) {
        case SDL_QUIT: SDL_Quit(); exit(0); break;
        case SDL_MOUSEWHEEL: scale *= (event.wheel.y > 0) ? 1.1f : 0.9f; break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                dragging = true; lastMouseX = event.button.x; lastMouseY = event.button.y;
                int point = getPointAtMouse(event.button.x, event.button.y);
                if (point != -1) {
                    if (selectedStart == -1) selectedStart = point;
                    else if (selectedEnd == -1) selectedEnd = point;
                }
            }
            break;
        case SDL_MOUSEBUTTONUP: if (event.button.button == SDL_BUTTON_LEFT) dragging = false; break;
        case SDL_MOUSEMOTION:
            if (dragging) {
                offsetX += event.motion.x - lastMouseX;
                offsetY += event.motion.y - lastMouseY;
                lastMouseX = event.motion.x;
                lastMouseY = event.motion.y;
            }
            break;
        default: break;
    }
}