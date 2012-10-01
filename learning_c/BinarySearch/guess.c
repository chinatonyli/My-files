#include <stdio.h>
#include <math.h>

int main(void) {
    int low = 0;
    int high;
    int mid;
    int LessBiggerEqual;
    int counter = 0;

    printf("二分查找猜数字：心中想一个正整数，然后输入此数字的范围。\n");
    printf("范围的最小值是0，最大值是用户输入的数字\n");
    printf("程序不断告诉用户一个数字，通过询问实际数字大于、小于\n");
    printf("用户所想的数字，还是已经猜对了。\n");
    printf("\n按回车键继续……\n\n");
    getchar();

    printf("请输入数字的最大值 (最小值为0): ");
    scanf("%i", &high);
    printf("\n");
    printf("我最多只需猜约%.0f次！\n", log2(high));

    while (low <= high) {
        counter++;
        mid = (low + high) / 2;

        printf("\n您所想的数字是%i吗?\n输入1：小于这个数\n输入2：大于这个数\n输入3：就是这个数。\n输入: ", mid);
        scanf("%i", &LessBiggerEqual);

        if (LessBiggerEqual == 1) {
            high = mid - 1;
        }
        else if (LessBiggerEqual == 2) {
            low = mid + 1;
        }
        else {
            printf("\n我仅用%i次就猜对了这个数！\n", counter);
            return 0;
        }
    }
    printf("\n您想的这个数不可能存在哦！您确定：\n1.您所想的是正整数吗？\n2.您所有的问题都回答正确了吗？\n");
    return 0;
}
