#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Sentence 
{
public:
	void init(string s);
	void convert(int i);
	void print();
};

int main()
{
   char str[100];
   Sentence S;
   gets(str);
   S.init(str);
   S.print();
   S.convert(1); S.print();
   S.convert(3); S.print();
   S.convert(8); S.print();
   S.convert(11); S.print();
   S.undo(); S.print();
   S.undo(); S.print();
   S.redo(); S.print();
   S.redo(); S.print();
   S.undo(); S.print();
   return 0;
}