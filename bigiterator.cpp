#include <iostream>
#include <string>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
class Big
{
	node* head;
	node* tail;
	int count;
	int carry;
public:
	Big()
	{
		head = NULL;
		tail = NULL;
		count = 0;
		carry = 0;
	}
	void insert(int e);
	void add(int a, int b);
	int getcarry();
	void print();
	friend class myIterator;
};
void Big::insert(int e)
{
	node *tmp, *t;
	if (count == 0)
	{
		head = new node;
		head->data = e;
		head->next = NULL;
		tail = head;
		count++;
	}
	else
	{
		tmp = head;
		t = NULL;
		while(tmp!=NULL)
		{
			t = tmp;
			tmp = tmp->next;
		}
		tmp = new node;
		tmp->data = e;
		tmp->next = NULL;
		t->next = tmp;
		tail = tmp;
		count++;
	}
}
void Big::add(int a, int b)
{
	insert((carry+(a+b))%10);
	carry = (carry + (a+b))/10;
}
int Big::getcarry()
{
	return carry;
}
void Big::print()
{
	node *tmp = head;
	int s[1000];
	for (int i = 0; i < count; ++i)
	{
		s[i] = tmp->data;
		tmp = tmp->next;
	}
    for (int i = count-1; i >=0; i--)
    {
    	cout << s[i];
    }
    cout << endl;
}
///////////////////////////////////////////////////////////
class myIterator
{
	struct node* current;
	public:
		struct node* begin(Big n);
		struct node* getcurrent();
		int getcurrentElement();
		bool isEmpty();
};
struct node* myIterator::begin(Big n)
{
	current = n.head;
	return current;
}
struct node* myIterator::getcurrent()
{	
	return current;
}
int myIterator::getcurrentElement()
{
	int i;
	i = current->data;
	current = current->next;
	return i;
}
bool myIterator::isEmpty()
{
	if (current == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/////////////////////////////////////////////////////////
int main()
{
	Big n1, n2, n3;
	string s1, s2;
	myIterator i1, i2;
	int a, b, c=0;
	cout << "Enter the nos." << endl;
	cin >> s1 >> s2;
	for (int i = s1.size()-1; i >= 0; i--)
	{
		n1.insert(s1[i]-'0');
	}
	for (int i = s2.size()-1; i >= 0; i--)
	{
		n2.insert(s2[i]-'0');
	}
	for ((i1.begin(n1) && i2.begin(n2)); (i1.isEmpty() == 0 && i2.isEmpty() == 0); )
	{
		a = i1.getcurrentElement();
		b = i2.getcurrentElement();
		n3.add(a, b);
	}
	if (i1.isEmpty() == 1)
	{
		for (i2.getcurrent(); i2.isEmpty() == 0;)
		{
			a = 0;
			b = i2.getcurrentElement();
			n3.add(a, b);
		}
	}
	else
	{
		for (i1.getcurrent(); i1.isEmpty() == 0;)
		{
			b = 0;
			a = i1.getcurrentElement();
			n3.add(a, b);
		}
	}
	c = n3.getcarry();
	if (c!=0)
	{
		n3.insert(c);
	}
	n3.print();
	return 0;
}