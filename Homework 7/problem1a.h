#include <iostream>
#include <string>

using namespace std;

template <class A> class Stack{
	private:
        struct StackNode {
            A data;
            StackNode *next;
        };
        StackNode *top;
		int size;
        int current_size;
	public:
		Stack();
    	Stack(int);

    	void push(const A&);
    	A pop();
        bool isEmpty();
};

template<class A> Stack<A>::Stack(){
    size = -1;
    current_size = -1;
}

template<class A> Stack<A>::Stack(int newsize){
    size = newsize;
    current_size = -1;
}

template<class A> void Stack<A>::push(const A& p){
    current_size++;
    try {
        if (current_size > size) {
            throw "Overflow";
        } else {
            StackNode *s = new StackNode();
            if(top == nullptr) {       
                s->data = p;
                s->next = nullptr;
                top = s;
            } else {
                s->data = p;
                s->next = top;
                top = s;
            }
        }
    }
    catch (const char *str) {
        cout << "Exception: " << str << endl;
    }
}

template<class A> A Stack<A>::pop(){
    A temp;
    try {
        if(current_size == -1){
            throw "Underflow";
        } else {
            temp = top->data;
            top = top->next;
            current_size--;
        }
    }
    catch (const char *str){
        cout << "Exception: " << str << endl;
    }
    return temp;
}

template<class A> bool Stack<A>::isEmpty(){
    return current_size == -1;
}