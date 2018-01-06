#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 		
struct node
{
	int data;
	struct node *next;
};

class List
{

	struct node *head;
	int count;
	struct node *tail;
public:
	List()
	{
		head = NULL;
		count = 0;
		tail = NULL;
	}; // constructor
	void insert(int position, int element); // if position is invalid, false need to be returned
	void insert(int element); //insert the element in first position
	void deleteElement(int position);
	void update(int position, int element);
	int size();
	void print();	
}; 
void List::insert(int i, int a)
{
	if(i > count+1 || i == 0)
	{
	    return ;	
	}
	else
	{
		node *tmp = new node;
		node *p, *k;
		k = NULL;
		p = head->next;
		for(int j = 1; j <= i-1; j++)
		{
			k = p;
			p = p->next;
		}
		tmp->next = p;
		k->next = tmp;
		tmp->data = a;
		if(i == count + 1)
		{
			tail = tmp;
		}
		count++;
		p = NULL;
		return ;
	}
}
void List::insert(int a)
{
	if(head == NULL)
	{
		node *tmp = new node;
		head = tmp;
		tail = tmp;
		head->next = NULL;
		tail->next = NULL;
		//delete tmp;
		//cout << head << endl; 
	}
	else
	{
		node *tmp = new node;
		count = count+1; 
		if(count == 1)
		{
			tmp->data = a;
		    tmp->next = NULL;
		    head->next = tmp;
		    tail = tmp;
		}
		if(count > 1)
		{
			tmp->data = a;
		    tmp->next = head->next;
		    head->next = tmp;
		}
		//delete tmp;
	}
}
void List::deleteElement(int p)
{
	if(p > count || p == 0 || head->next == NULL)
	{
		return ;
	}
	else
	{
	    node *k = NULL, *j = NULL; 
	    k = head->next;
	    for (int i = 1; i <= p-1; ++i)
	    {
	    	j = k;
		    k = k->next;
	    }	
	    if(head->next->next!=NULL && p==1)
	    {
	    	head->next = head->next->next;
	    }
	    else if(k->next == NULL)
	    {
	    	tail = j;
	    	k = NULL;

	    }
	    else
	    {
	    	j->next = k->next;
	    }
	    count--;
	    delete k;
	    return ;
	}
}
void List::update(int p, int a)
{
	if(p > count || p == 0)
	{
		return ;
	}
	else
	{
		node *k = NULL;
	    k = head->next;
	    for (int i = 1; i <= p-1; ++i)
	    {
		    k = k->next;
	    }
	    k->data = a;
	    return ;
	}
}
void List::print()
{	
    node* tmp;
    tmp = head->next;
    if(head->next == NULL)
    {
    	return;
    }
    for (int i = 1; i <= count; ++i)
    {
    	cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl; 
}
int List::size()
{
	return count;
}
int main()
{
	bool k=1;
    int n, j, e, p;
	List l;
    cin >> n;
    l.insert(0);
	for(int i=0; i<n; i++)
    {
        cin >> j;
        if(j==1)
        {
            cin >> e >> p;
            if (p == 1)
            {
            	l.insert(e);
            }
            else
            {
                l.insert(p, e);	
            }
        }
        if(j==2)
        {
            cin >> p;
            l.deleteElement(p);
        }
        if(j==3)
        {
            cin >> e >> p;
            l.update(p, e);
        }
    }
    //cout << l.size() << endl;
    l.print();
	return 0;
}