#include <iostream>

using namespace std;

#define MAX 1000 

class Stack
{ 
    int top; 

	public: 
	    int a[MAX]; // Maximum size of Stack 
	  
	    Stack() { top = -1; } 
	    bool push(const int x); 
	    int pop(); 
	    int peek(); 
	    bool isEmpty(); 
}; 
  
bool Stack::push(const int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x;
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = a[top]; 
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
}

int main(int argc, char const *argv[])
{
	Stack elemStack, minStack;

	int ch=1, num;

	//"get minimum in O(1) time using stack: "
	do
	{
		cout<<"\n ---MENU--- ";
		cout<<"\n1. push";
		cout<<"\n2. pop";
		cout<<"\n3. get minimum";
		cout<<"\n4. EXIT";
		cout<<"\nenter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"\nenter number: ";
				cin>>num;
				if(num<minStack.peek() || minStack.isEmpty())
					minStack.push(num);
				elemStack.push(num);
				break;

			case 2:
				if(!elemStack.isEmpty())
				{
					if(elemStack.peek() == minStack.peek())
						minStack.pop();
					elemStack.pop();
				}
				else
					cout<<"\nstack is empty!!";
				break;

			case 3:
				if(elemStack.isEmpty())
					cout<<"\nstack is empty!!";
				else
				{
					cout<<"\nminimum element is: "<<minStack.peek();
				}
				break;

			case 4:
				cout<<"\ngood bye.";
				break;	
			default:
				cout<<"\nwrong choice!!!";
		}
	}while(ch != 4);

	return 0;
}