#include <iostream>

using namespace std;


template <class T>
class myStack
{
    private:
        T *array;
        int sizeMax;
        int top;
    public:
        myStack(int size = 10);
        myStack(myStack<T> &stack);
        ~myStack(){ delete [] array; }

        inline void newArray(int count);

        inline void push_backMy(T data);
        inline void pop_backMy();
        inline void clear();
        inline bool isEmpty() { return bool(top == 0); }
        inline int size() const { return top; }
        inline void print() const;

        T &operator[] (int j);
        myStack<T>& operator= (myStack<T> &copyMyStack);


};


bool equal(char char1, char char2){
    if(char1 == '(' && char2 == ')') return true;
    if(char1 == '{' && char2 == '}') return true;
    if(char1 == '[' && char2 == ']') return true;
    return false;
}

string checkBrackets(string input)
{
    string result = "Success";
//    myStack <char> stackBrackets(1000); // If you want your code to run quickly
//    myStack <int> stackPosition(1000); // If you want your code to run quickly
    myStack <char> stackBrackets;
    myStack <int> stackPosition;
    int step = 0;

    for (size_t var = 0; var < input.size(); ++var)
    {
        step++;
        char br = input[var];
        if(br == '(' || br == ')' || br == '{' || br == '}' || br == '[' || br == ']'){
            if(br == '(' || br == '{' || br == '['){
                stackBrackets.push_backMy(input[var]);
                stackPosition.push_backMy(step);
            }
            else{// closed bracket
                if(!stackBrackets.isEmpty()){
                    if(equal(stackBrackets[stackBrackets.size() - 1], input[var])){
                        stackBrackets.pop_backMy();
                        stackPosition.pop_backMy();
                    }
                    else{
                        return to_string(step);
                    }
                }
                else{// if you enter closed bracket and stackBrackets.isEmpty()
                    return to_string(step);
                }
            }
        }
    }
    if(step == 0){
        return to_string(step);
    }
    if(!stackBrackets.isEmpty()){
       return to_string(stackPosition[stackPosition.size() - 1]);
    }
    return result;
}

// Stack 34
int main(int argc, char *argv[])
{

//    string str = "";
//    cin >> str;
//    cout << str << endl;
//    cout << checkBrackets(str) << endl;

    myStack <string> textBrackets;
    textBrackets.push_backMy("([](){([])})");
    textBrackets.push_backMy("()[]}");
    textBrackets.push_backMy("{{[()]]");
    textBrackets.push_backMy("foo(bar);");
    textBrackets.push_backMy("foo(bar[i);");
    for (int var = 0; var < textBrackets.size(); ++var)
    {
        cout << textBrackets[var] << endl;
        cout << checkBrackets(textBrackets[var]) << endl;
    }


    return 0;
}

template <class T>
myStack<T>::myStack(int size) : sizeMax(size), top(0)
{
    if(size < 100000){
        array = new T[sizeMax];
    }
    else{
        cout << " Error. Stack overflow" <<endl;
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
//        if((float(sizeMax) / float(2)) > top){
//            sizeMax = sizeMax / 2;
//            if(sizeMax < 1) sizeMax = 1;
//            newArray(sizeMax);
//        }
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
    if(j <= top && j >= 0 ){
         return array[j];
    }
    cout << " Error. Array index out of bounds" <<endl;
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
