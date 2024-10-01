/*
 * @lc app=leetcode.cn id=1812 lang=c
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lc code=start
bool squareIsWhite(char* coordinates) {
    int x = coordinates[0] - 'a' + 1;
    int y = coordinates[1] - '0';
    return (x + y) % 2;
}
// @lc code=end

