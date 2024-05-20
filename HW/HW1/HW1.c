/**
 * @file HW1.c
 * @author MuCheng (MuChengZJU@qq.com)
 * @brief Homework of Week 1
 * @version 1.0
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <math.h>

#define MAXINT 2147483647
#define MAXARRSIZE 10 // a[10] > MAXINT

int problem_1_8_5();
int problem_1_8_5_function(int n);

int problem_1_8_7();
int problem_1_8_7_function(int x);

int problem_1_8_8();

int problem_1_19();
int problem_1_19_function(int n, int arrsize, int a[]);


int main(int argc, char *argv[])
{
    
    problem_1_8_5();
    problem_1_8_7();
    problem_1_8_8();
    problem_1_19();

    return 0;
}

int problem_1_8_5_function(int n)
{
    int i, j, k;
    int cnt = 0;
    for (i = 1; i <= n; i++ ) {
        for (j = 1; j <= i; j++) {
            for (k = 1; k <= j; k++) {
                cnt++;
            }
        }
    }
    return cnt;
}

int problem_1_8_5()
{
    printf("***************\n");
    printf("Answer of 1.8.5:\n");
    printf("Mathematical Analysis: n*(n+1)*(n+2)/6\n");
    printf("n\tProgram\tMath\n");
    int i;
    for(i=1; i<10; i++){
        printf("%d\t%d\t%d\n", i, problem_1_8_5_function(i), i*(i+1)*(i+2)/6);
    }
    printf("***************\n");
    return 0;
}

int problem_1_8_7()
{
    printf("***************\n");
    printf("Answer of 1.8.7: \n");
    printf("Mathematical Analysis: (int)sqrt(n)\n");
    printf("n\tProgram\tMath\n");
    int i;
    for(i=1; i<50; i+=5){
        printf("%d\t%d\t%d\n", i, problem_1_8_7_function(i), (int)sqrt(i));
    }
     printf("***************\n");
    return 0;
}

int problem_1_8_7_function(int x)
{
    int y = 0;
    int cnt = 0;
    while (x >= (y+1)*(y+1) )
    {
        y++;
        cnt++;
    }
    return cnt;
}

int problem_1_8_8()
{
    printf("***************\n");
    printf("Answer of 1.8.8: ");

    int x = 91;
    int y = 100;
    int cnt = 0;
    while (y>0)
    {
        if(x > 100)
        {
            x -= 10;
            y --;
            cnt++;
        }
        else
        {
            x ++;
        }
    }    
    printf(" %d\n", cnt);
    printf("***************\n");
    return 0;
}

int problem_1_19()
{
    int a[MAXARRSIZE];
    a[0] = 1;

    printf("***************\n");
    int n, arrsize;
    printf("Enter n for problem 1.19: ");
    scanf("%d", &n);
    printf("Enter arrsize for problem 1.19: ");
    scanf("%d", &arrsize);

    int runcode = problem_1_19_function(n, arrsize, a);

    int i=0;
    switch (runcode)
    {
    case 0:
        printf("Success: Array of [i!*2^i] has been successfully calculated and stored.\n");
        for(i=0; i < n; i++)
        {
            printf("a[%d]=%d\n", i, a[i]);
        }
        break;
    case 1:
        printf("Error 1: n > arrsize.\n");
        break;
    default:
        printf("Error 2: MAXINT overflow.\n");
        for(i=0; i < runcode; i++)
        {
            printf("a[%d]=%d\n", i, a[i]);
        }
        break;
    }    
    printf("***************\n");

    return 0;
}

int problem_1_19_function(int n, int arrsize,int a[])
{
    
    if(n > arrsize)
    {
        return 1; //1 means n > arrsize
    }
    else
    {
        int i;
        for(i = 1; i < n; i++)
        {
            a[i] = a[i-1]*2*i; // Recursion
            if(a[i] < a[i-1])// overflow
            {
                return i; // Overflow i
            }
        }
    }

    return 0;
}