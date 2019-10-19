#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>

int main() {
	int a[50];
	int m, n;
	printf("请输入被除数M和除数N:\n");
	scanf("%d %d", &m, &n);
	printf("%d.",  m/n);
	m = m % n;
	int i, k, mark = 0;
	for (k = 0; ; k++) {
		if (k == 20) {
			break;
		}
		m *= 10;
		a[k] = m / n;

		for (i = 0; i < k; ++i) {
			if (a[i] == a[k]) {
				mark = 1;
				break;
			}
		}
		if (mark) {
			break;
		}
		m = m % n;
		if (m == 0) {
			break;
		}
	}
	if (mark) {
		for (i = 0; i < k; ++i) {
			printf("%d", a[i]);
		}

		printf("商是无线小数\n");
	}
	else {
		for (i = 0; i <= k; ++i) {
			printf("%d", a[i]);
		}
		printf("商是有线小数\n");
	}

	return 0;
}
#endif

#if 0
#include<stdio.h>
int flag = 0;//进位标志，1代表进位
int num = 0;//递归次数
void fun(int *a, int *b, int *c)//递归函数
{
	if (num == 99)
		return;
	int m = *a + *b + flag;
	*c = m % 10;
	if (m > 9)
		flag = 1;
	else
		flag = 0;
	num++;
	fun(++a, ++b, ++c);
	return;
}

void Product(int* a, int* b, int* c) {
	int num = 0;
	int f = 0;
	for (int i = 0; i < 100; ++i) {
		int k = 0;
		int tmp[100] = {};
		for (int j = 0; j < 100; ++j) {
			num = a[i] * b[j] + f;
			f = num / 10;
			tmp[k] = num % 10;
			++k;
		}
		fun(tmp, c+i, c+i);
	}
	
}
int main()
{
	int c[100] = {};
	int a[100] = { 3,2 };
	int b[100] = { 8 };//a[0]is low and the other is high
	Product(a, b, c);
	int i;
	int flag2 = 0;//标志
	for (i = 99; i >= 0; i--)//从不为0的位开始输出
	{
		if (flag2 == 0)
		{
			if (c[i])
			{
				flag2 = 1;
				printf("%d", c[i]);
			}
		}
		else
		{
			printf("%d", c[i]);
		}
	}
	printf("\n");
	return 0;
}
#endif

#if 0
#include <cstdio>
void fun(int a[], int b[], int c[], int len) {
	int flag = 0;
	int num = 0;
	for (int i = 0; i < len; ++i) {
		num = a[i] + b[i] + flag;
		flag = num / 10;
		c[i] = num % 10;

	}
}
void Product(int a[], int b[], int c[]) {
	int num = 0;
	int f = 0;
	for (int i = 0; i < 100; ++i) {
		int k = 0;
		int tmp[100] = {};
		for (int j = 0; j < 100; ++j) {
			num = a[i] * b[j] + f;
			f = num / 10;
			tmp[k] = num % 10;
			++k;
		}
		fun(tmp, c+i, c+i, 100-i);
	}
	
}
int main()
{
	printf("请输入两个正整数:/n");
	int num1;
	int num2;
	int c[100] = {};
	int a[100] = { 3,6,5,3,4,6};
	int b[100] = { 3,6,1 };//a[0]is low and the other is high
	Product(a, b, c);
	int i;
	int flag2 = 0;//标志
	for (i = 99; i >= 0; i--)//从不为0的位开始输出
	{
		if (flag2 == 0)
		{
			if (c[i])
			{
				flag2 = 1;
				printf("%d", c[i]);
			}
		}
		else
		{
			printf("%d", c[i]);
		}
	}
	printf("\n");
	return 0;
}
#endif
#if 0
int main()
{
	printf("请输入两个正整数:/n");
	int num1;
	int num2;
	scanf("%d %d", &num1, &num2);
	int c[100] = {};
	int a[100] = {};
	int b[100] = {};//a[0]is low and the other is high
	int i = 0;
	while (num1) {
		a[i] = num1 % 10;
		num1 /= 10;
	}
	i = 0;
	while (num2) {
		b[i] = num2 % 10;
		num2 /= 10;
	}
	Product(a, b, c);
	int i;
	int flag2 = 0;//标志
	for (i = 99; i >= 0; i--)//从不为0的位开始输出
	{
		if (flag2 == 0)
		{
			if (c[i])
			{
				flag2 = 1;
				printf("%d", c[i]);
			}
		}
		else
		{
			printf("%d", c[i]);
		}
	}
	printf("\n");
	return 0;
}
#endif
#include <cstdio>
#include <cmath>

bool isPrime(int num) {
	for (int i = 2; i < sqrt(num); ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	int num = 0;
	scanf("%d", &num);
	for (int i = 2; i < num/2; ++i) {
		if (isPrime(i) && isPrime(num - i)) {
			printf("%d = %d + %d\n", num, i, num - i);
		}
	}

	return 0;
}
