#include "dijkstra.h"
// Dijkstra算法
void dijkstra(int start) {
    for (int i = 0; i < NUM_POINTS; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
        prev[i] = -1;
    }
    dist[start] = 0;

    for (int i = 0; i < NUM_POINTS; ++i) {
        int u = -1;
        for (int j = 0; j < NUM_POINTS; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) u = j;
        }
        if (dist[u] == INT_MAX) break;
        visited[u] = true;

        for (int v = 0; v < NUM_POINTS; ++v) {
            if (graph[u][v] != -1 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

void updateRouteWithShortestPath(int start, int end) {
    Point tempRoute[NUM_POINTS];  // 用来存储临时路径
    int pathLength = 0;
    int u = end;

    // 追溯最短路径，直到到达起点
    while (u != -1) {
        tempRoute[pathLength].x = route.points[u].x;
        tempRoute[pathLength].y = route.points[u].y;
        strcpy(tempRoute[pathLength].name, route.points[u].name);  // 拷贝名称
        pathLength++;
        u = prev[u];  // 通过 prev[] 追溯到前一个点
    }

    // 翻转路径
    for (int i = 0; i < pathLength; ++i) {
        route.points[i] = tempRoute[pathLength - 1 - i];
    }
    route.numPoints = pathLength;  // 更新路径点数量
}
