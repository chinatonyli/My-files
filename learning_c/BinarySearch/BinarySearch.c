#include <stdio.h>
#define MAX 5

int BinarySearch(int *a, int target, int len) { 
/* 如果low + high的和大于int的最大值, 比如2 ** 31 - 1, 计算便会发生溢出,
 * 使它成为一个负数, 然后被2除时结果仍为负数. 你会得到一个无法预测的越界的数组下标.
 * 推荐的解决方法是修改中间值的计算过程, 方法之一是用减法而不是加法——来实现:
 * mid = low + ((high - low) / 2). 如你所见, 移位是更好的方法. */
    
    int low = 0;
    int high = len - 1;
    int mid;
    int midVal;

    while (low <= high) {
        mid = (low + high) >> 1;
        midVal = a[mid];

        if (midVal < target) {
            low = mid + 1;
        }
        else if (midVal > target) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main(void) {
    int number[MAX] = {0, 1, 2, 4, 7};
    
    printf("%i\n", BinarySearch(number, 4, MAX));
    return 0;
}
