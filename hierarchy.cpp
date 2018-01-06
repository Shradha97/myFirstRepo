#include <iostream>
#include <stack>
using namespace std;
struct node
{
	char data;
	struct node *l;
	struct node *r;
};
void Query(char b, char c, int ascii1[], int ascii2[])
{
	if ((ascii1[(int)b] > ascii1[(int)c]) && (ascii2[(int)b] < ascii2[(int)c]))
	{
		cout << c << " is the parent of " << b << endl;
	}
	else if ((ascii1[(int)b] < ascii1[(int)c]) && (ascii2[(int)b] > ascii2[(int)c]))
	{
		cout << b << " is the parent of " << c << endl; 
	}
}
void preorder(struct node *root, int ascii1[], int count)
{
	if (root == NULL)
	{
	    return;		
	}
	ascii1[(int)root->data] = count;
	count++;
	preorder(root->l, ascii1, count);
	count++;
	preorder(root->r, ascii1, count);
}
void postorder(struct node *root, int ascii2[], int &count)
{
	if (root == NULL)
	{
	    return;		
	} 
	postorder(root->l, ascii2, count);
	postorder(root->r, ascii2, count);
	ascii2[(int)root->data] = count;
	count++;
}
int main()
{
	string s;
	stack <node*> a;
	char b; char c;
	struct node*root;
	int ascii1[256], ascii2[256], count = 1;
	cin >> s;
	cin >> b >> c;
	for (int i = 0; i < s.size(); ++i)
	{
		root = new node;
		root->data = s[i];
		root->l = NULL;
		root->r = NULL;
		if (s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/')
		{
			a.push(root);
		}
		else
		{
			if(a.size()>1)
			{
				root->r = a.top();
				a.pop();
				root->l = a.top();
				a.pop();
				a.push(root);
			}
		}
	}
	preorder(root, ascii1, count);
	count = 1;
	//cout << endl;
	postorder(root, ascii2, count);
	Query(b, c, ascii1, ascii2);
	return 0;
}