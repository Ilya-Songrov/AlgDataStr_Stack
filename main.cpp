#include <iostream>

class myStack
{
    private:
        int *array;
        int size_;
        int top;
    public:
        myStack(int maxSize = 10);
        ~myStack(){ delete [] array; }

        inline void push_backMy(int data);
        inline void pop_backMy();
        inline void print() const;

        myStack& operator= (const myStack& copyMyStack);
};

using namespace std;

// Stack 34
int main(int argc, char *argv[])
{
    myStack stack(4);
    stack.print();
    stack.push_backMy(34);
    stack.push_backMy(35);
    stack.push_backMy(36);
    stack.push_backMy(37);
    stack.push_backMy(38);
    stack.print();

    return 0;
}



myStack::myStack(int size) : size_(size), top(0)
{
    if(size < 100000){
        array = new int[size_];
    }
    else{
        cout << " Error. Stack overflow" <<endl;
    }
}

void myStack::push_backMy(int data)
{
    if(top < size_){
        array[top] = data;
        top++;
    }
    else{

        delete [] array;
        size_ = size_ * 2;
        array = new int[size_];
        push_backMy(data);
    }
}

void myStack::pop_backMy()
{
    if(size_ > 0){
        top--;
    }
}

void myStack::print() const
{
    for (int var = 0; var < top; ++var)
    {
        cout << array[var] << endl;
    }
}

myStack &myStack::operator=(const myStack &copyMyStack)
{
    if (this != &copyMyStack){
        swap();
    }
    return *this;
}
