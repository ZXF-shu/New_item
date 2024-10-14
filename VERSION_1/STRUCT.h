#ifndef _ROUTE_STRUCT_H
#define _ROUTE_STRUCT_H
#ifndef NUM_POINTS
#define NUM_POINTS 8
#endif
typedef struct {
    int x, y;
    char name[20];  // 存储点的名称
} Point;

typedef struct {
    Point points[NUM_POINTS];
    int numPoints;
} Route;

Route route;
#endif
