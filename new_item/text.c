#include <stdio.h>

// 函数声明
int add(int a, int b);

int main() {
    int a = 111; // 示例值
    int b = 701; // 示例值
    printf("两数之和: %d\n", add(a, b));
    return 0;
}

// 计算两数之和的函数
int add(int a, int b) {
    while (b != 0) {
        // 计算不进位的和
        int sum = a ^ b;
        // 计算进位，并左移一位
        int carry = (a & b) << 1;
        // 更新a和b的值，继续循环直到没有进位
        a = sum;
        b = carry;
    }
    return a;
}