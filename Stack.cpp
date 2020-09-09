//Stack Implementation

/*top variable will trace how many variables are stored in stack
top = -1 initially.
In simple words, the top variable stores the index location of the top value in stack.
isEmpty() :- if top == -1 

*/


#include<iostream>
#include<string>

using namespace std;

class Stack {
    private:
        int top; // To track no. Of entries in a stack 
        int arr[5]; // hard coded to keep it simple 
    public:
        Stack() //Creating Constructor
        {
            top = -1; //Intializing 
            for (int i = 0; i < 5; i++)
            {
                arr[i] = 0; //When we are creating a stack we should initialize every element with 0
            }
        }

        bool isEmpty() //Check if stack is empty.
        {
            if(top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isFull() //Check if stack is full
        {
            if(top == 4) // 4 becuase index starts at 0 and array size is 5
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        
        void push(int val) //To push an integer element in stack.
        {
            if(isFull()) // We should check if the stack is full or not to avoid errors.
            {
                cout<<"Stack Overflow"<<endl;
            }

            else 
            {
                top++; //Top becomes 0 first time
                arr[top] = val;
            }
        }

        int pop() //it will return the element that is popped.
        {
            if(isEmpty()) //To Check if stack is underflow so that it can't be popped.
            {
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            else
            {
                int popValue = arr[top]; //Since top will be storing the value of element at the top
                arr[top] = 0;
                top--;
                return popValue; //Return Top Value
            }
        }

        int count()
        {
            return(top+1); //Since top always stores the index position of top element, so it will always be 1 less than the total no. of elements.
        }

        
        int peek(int pos) // Position at which the value need to be accessed in the stack
        {
            if(isEmpty()) //To check if stack is empty or not.
            {
                cout<<"Stack underflow"<<endl;
                return 0;
            }

            else
            {
                return arr[pos]; //Returning The Array Position at Index pos
            }
            
        }

        void change(int pos, int val) // We need to pass two paramters position at where the element need to be changed and value which needs to be changed.
        {
            arr[ pos ] = val;
            cout<<"Value Changed at the location "<<pos<<endl;
        }

        
        void display() //We need to print data in descending order 
        {
            cout<<"All values in stack are "<<endl;
            for(int i=4; i>=0; i++)
            {
                cout<<arr[i]<<endl;
            }
        }
};

int main() 
{
    Stack s1;
    int option, position, value;

    do 
    {
        cout<<"What operation do you want to perform, Enter 0 to exit"<<endl;
        cout<<"1. Push()"<<endl;
        cout<<"2. Pop()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. Peek()"<<endl;
        cout<<"6. Count()"<<endl;
        cout<<"7. Change()"<<endl;
        cout<<"8. Display()"<<endl;
        cout<<"9. Clear Screen"<<endl;

        cin>>option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter an item to push in the stack"<<endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                cout << "Pop Function Called - Poped Value: " << s1.pop() << endl;
                break;
            case 3:
                if (s1.isEmpty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is not Empty" << endl;
                break;
            case 4:
                if (s1.isFull())
                    cout << "Stack is Full" << endl;
                else
                    cout << "Stack is not Full" << endl;
                break;
            case 5:
                cout << "Enter position of item you want to peek: " << endl;
                cin >> position;
                cout << "Peek Function Called - Value at position " << position << " is " << s1.peek(position) << endl;
                break;
            case 6:
                cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << endl;
                break;
            case 7:
                cout << "Change Function Called - " << endl;
                cout << "Enter position of item you want to change : ";
                cin >> position;
                cout << endl;
                cout << "Enter value of item you want to change : ";
                cin >> value;
                s1.change(position, value);
                break;
            case 8:
                cout << "Display Function Called - " << endl;
                s1.display();
                break;
            case 9:
                system("clear");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
        }

    }while (option!=0);
    
    return 0;
}
