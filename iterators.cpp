#include <iostream>
#include <cmath>
using namespace std;
struct node
{
	int coef;
	int exp;
	struct node *next;
};
class List
{
	node *head;
	node *tail;
	int count;
public:
	List()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}
	void insert(int c, int p);
	friend class myIterator;
};
void List::insert(int c, int p)
{
	node *tmp, *t;
	if (count == 0)
	{
		head = new node;
		head->coef = c;
		head->exp = p;
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
		tmp->coef = c;
		tmp->exp = p;
		tmp->next = NULL;
		t->next = tmp;
		tail = tmp;
		count++;
	}
}
class myIterator
{
	struct node *current;
	int c;
public:
	myIterator()
	{
		current = NULL;
		c = 0;
	}
	int getcurrentElement();
	struct node* begin(List l);
	bool isEmpty();
};
struct node* myIterator::begin(List l)
{
	current = l.head;
	return current;
}
int myIterator::getcurrentElement()
{
	int i, k=0;
	if(c == 0)
	{
		i = current->coef;
		c++;
	}
	else
	{
		i = current->exp;
		c--;
		k = 1;
	}
	if (k==1)
	{
		current = current->next;
	}
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
int evaluate(int x, int c, int p)
{
	return (c*pow(x, p));
}
int main()
{
	myIterator i;
	List l;
	int n, c, p, x, r=0;
	cout << "Enter the no. of terms " << endl;
	cin >> n;
    cout << "Enter the no. to be evaluated" << endl;
    cin >> x;
	for (int i = 0; i < n; ++i)
	 {
	 	cin >> c >> p;
	 	l.insert(c, p);
	 } 
	for (i.begin(l); i.isEmpty() == 0; )
	{
		c = i.getcurrentElement();
		p = i.getcurrentElement();
		r += evaluate(x, c, p);
	}
	cout << r << endl;
	return 0;
}