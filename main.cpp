#include <iostream>



template <class T>
class myStack
{
    private:
        T *array; /* finish at the end */
        int sizeMax;
        int top;
    public:
        myStack(int size = 10);
        myStack(myStack<T> &stack);
        ~myStack(){ delete [] array; }

        inline void newArray(int count);
         void push_backMy(T data);
         void pop_backMy();
         void clear();
        inline bool isEmpty() { return top == 0; }
        inline int size() const { return top; }
        inline void print() const;

        T &operator[] (int j);
        myStack<T>& operator= (myStack<T> &copyMyStack);
};



using namespace std;

// Stack 34
int main(int argc, char *argv[])
{
    myStack<int> stack(45);
    myStack<int> stack2(7);
    stack.push_backMy(34);
    stack.size();
    stack.push_backMy(35);
    stack.size();
    stack.push_backMy(36);
    stack.size();
    stack.push_backMy(37);
    stack.size();
    stack.print();
    stack.pop_backMy();
    stack.size();
    stack.print();
    stack.size();
    stack2.print();
    stack.size();
    stack2.push_backMy(56);
    stack.size();
    stack2.push_backMy(57);
    stack.size();
    stack2.push_backMy(58);
    stack.size();
    stack = stack2;
    stack.size();
    stack.print();

    return 0;
}

template <class T>
myStack<T>::myStack(int size) : sizeMax(size), top(0)
{
    if(size < 100000){
        array = new T[sizeMax];
    }
    else{
        cout << " Error. Stack overflow" <<endl; /* finish at the end */
    }
}

template <class T>
myStack<T>::myStack(myStack<T> &stack)
{
        int copySize = stack.size();
        newArray(copySize);
        for (int var = 0; var < copySize; ++var) {
            array[var] = stack[var];
        }
        top = copySize;
}

template <class T>
void myStack<T>::newArray(int count)
{
    T *newArr = new T[count];
    if(count >= sizeMax){// if we increase array we move the elements
        for (int var = 0; var < count; ++var){
            newArr[var] = array[var];
        }
    }
    sizeMax = count;
    delete [] array;
    array = newArr;
}

template <class T>
void myStack<T>::push_backMy(T data)
{
    if(top < sizeMax){
        array[top] = data;
        top++;
    }
    else{
        newArray(sizeMax * 2);
        push_backMy(data);
    }
}

template <class T>
void myStack<T>::pop_backMy()
{
    if(top > 0){
        top--;
        if((float(sizeMax) / float(2)) > top){
            sizeMax = sizeMax / 2;
            if(sizeMax < 1) sizeMax = 1;
            newArray(sizeMax);
        }
    }
}

template <class T>
void myStack<T>::clear()
{
    delete [] array;
    sizeMax = 1;
    top = 0;
    array = new T[1];
}

template <class T>
void myStack<T>::print() const
{
    for (int var = 0; var < top; ++var)
    {
        cout << array[var] << endl;
    }
    cout << "--------------" << endl;
}


template <class T>
T &myStack<T>::operator[] (int j)
{
    if(j <= top){
         return array[j];
    }
    //    cout << " Error. Array index out of bounds" <<endl; /* finish at the end */
    return array[j+1];
}

template <class T>
myStack<T>& myStack<T>::operator= (myStack<T> &copyMyStack)
{
    if (this != &copyMyStack){
        int copySize = copyMyStack.size();
        newArray(copySize);
        for (int var = 0; var < copySize; ++var) {
            array[var] = copyMyStack[var];
        }
        top = copySize;
    }
    return *this;
}
