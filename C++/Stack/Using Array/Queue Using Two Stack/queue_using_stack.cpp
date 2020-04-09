#include <iostream>

using namespace std;

#define MAX 1000 
  
class Stack
{ 
    int top; 

	public: 
	    int a[MAX]; // Maximum size of Stack 
	  
	    Stack() { top = -1; } 
	    bool push(int x); 
	    int pop(); 
	    int peek(); 
	    bool isEmpty(); 
}; 
  
bool Stack::push(int x) 
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
	Stack stack1, stack2;

	int ch=1, num;

	cout<<"\nWe are performing queue using two stack: ";
	do
	{
		cout<<"\n ---MENU--- ";
		cout<<"\n1. enqueue";
		cout<<"\n2. print top";
		cout<<"\n3. dequeuq";
		cout<<"\n4. EXIT";
		cout<<"\nenter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"\nenter number: ";
				cin>>num;
				stack1.push(num);
				break;

			case 2:
				if(stack1.isEmpty() && stack2.isEmpty())
					cout<<"\nqueue is empty!!";
				else
				{
					if(stack2.isEmpty())
						while(!stack1.isEmpty())
						{
							stack2.push(stack1.peek());
							stack1.pop();
						}

					cout<<"\ntop element is: "<<stack2.peek();
				}
				break;

			case 3:
				if(stack1.isEmpty() && stack2.isEmpty())
					cout<<"\nqueue is empty!!";
				else
				{
					if(stack2.isEmpty())
						while(!stack1.isEmpty())
						{
							stack2.push(stack1.peek());
							stack1.pop();
						}

					stack2.pop();
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