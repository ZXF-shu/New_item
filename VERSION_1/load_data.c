#include "load_data.h"
// 从文件中读取点信息
void loadPoints(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法打开点信息文件\n");
        return;
    }

    route.numPoints = 0;  // 初始化点的数量
    char buffer[256];
    int id;

    while (fgets(buffer, sizeof(buffer), file)) {
        // 打印每行内容，调试查看是否读取成功
     //   printf("读取行: %s", buffer);

        // 使用 sscanf 来解析每一行
        int result = sscanf(buffer, "point%d:%d, %d, %[^\n]", &id, &route.points[route.numPoints].x, &route.points[route.numPoints].y, route.points[route.numPoints].name);

        // 检查是否匹配成功
        if (result == 4) {
        //    printf("Point %d: (%d, %d), name: %s\n", id, route.points[route.numPoints].x, route.points[route.numPoints].y, route.points[route.numPoints].name);
            route.numPoints++;
        } else {
            printf("读取点信息出错，格式不匹配或行数不足\n");
            break;
        }
    }

    fclose(file);
}
// 从文件中读取路径信息（邻接矩阵）
void loadGraph(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法打开路径信息文件\n");
        return;
    }

    for (int i = 0; i < NUM_POINTS; ++i) {
        for (int j = 0; j < NUM_POINTS; ++j) {
            // 读取每个点的权重，-1 表示无连接
            fscanf(file, "%d,", &graph[i][j]);
        }
    }
    fclose(file);
}
