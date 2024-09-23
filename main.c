#include <stdio.h>

int add(int x,int y);

int main()
{
    int result = add(3,5);
    printf("半动态链接，两数和为:%d\n",result);

    return 0;
}
