#include <stdio.h>

int main(void)
{
    char c;
    long long num = 0;      /* 当前正在读入的运算数 */
    long long res = 0;      /* 累计结果 */
    char op = 0;            /* 待执行的运算符 */
    int hasOp = 0;          /* 是否已有待执行运算符 */

    while ((c = getchar()) != '=' && c != EOF) {
        if (c >= '0' && c <= '9') { 
            num = num * 10 + (c - '0');   /* 继续拼接数字 */
        } else {
            /* 遇到运算符：先把上一段算完，再记下新运算符 */
            if (hasOp) {
                if (op == '+')      res += num;
                else if (op == '-') res -= num;
                else if (op == '*') res *= num;
                else if (op == '/') {
                    if (num == 0) { printf("错误：除数为0\n"); return 0; }
                    res /= num;
                } else {
                    printf("错误的运算符:%c\n", op);   /* 非法运算符 */
                    return 0;
                }
            } else {
                res = num;      /* 第一个数直接作为初始结果 */
                hasOp = 1;
            }
            op = c;
            num = 0;
        }
    }

    /* 收尾：执行最后一个运算符 */
    if (hasOp) {
        if (op == '+')      res += num;
        else if (op == '-') res -= num;
        else if (op == '*') res *= num;
        else if (op == '/') {
            if (num == 0) { printf("错误：除数为0\n"); return 0; }
            res /= num;
        } else {
            printf("错误的运算符:%c\n", op);
            return 0;
        }
    } else {
        res = num;      /* 形如 "123=" */
    }

    printf("%lld\n", res);
    return 0;
}
