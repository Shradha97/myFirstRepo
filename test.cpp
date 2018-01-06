#include <iostream>
#include <stdio.h>
using namespace std;
struct check
{
   int c;
   float a;
};
int main()
{
	printf("%d\n", sizeof(struct check));
	return 0;
}