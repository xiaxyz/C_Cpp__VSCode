#include <iostream>
#include <sstream>

using namespace std;

template<class T>
class list
{
public:
    T data;
    list *next;
};
template<class T>
class  Stack
{
public:
    Stack();
    ~Stack();
    void initStack();
    int getNum();
    void push(T n);
    T pop();
    void print();
    void deleteStack();
    void command(string comm);
private:
    list<T> *head;
    list<T> *tail;
};

template<class T>
Stack<T>::Stack()
{
    head = nullptr;
    tail = nullptr;
    initStack();
}
template<class T>
Stack<T>::~Stack()
{
    deleteStack();
}
template<class T>
void Stack<T>::initStack()
{
    if(head == nullptr)
    {
        head = new list<T>;
        head->next = nullptr;
    }
    tail = head;
}
template<class T>
int Stack<T>::getNum()
{
    if(head == nullptr)
        return 0;
    int n = 0;
    list<T> *t = head;
    while(t->next != nullptr)
    {
        t = t->next;
        n++;
    }
    return n;
}
template<class T>
void Stack<T>::push(T n)
{
    list<T> *temp;
    temp = new list<T>;
    temp->data = n;
    temp->next = nullptr;
    tail->next = temp;
    tail = temp;
}
template<class T>
T Stack<T>::pop()
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    T d = tail->data;
    list<T> *temp = head;
    while (temp->next != nullptr && temp->next->next != nullptr)
        temp = temp->next;
    temp->next = nullptr;
    delete tail;
    tail = temp;
    return d;
}
template<class T>
void Stack<T>::print()
{
    list<T> *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
        cout << curr->data << ' ';
    }
    cout << endl;
}
template<class T>
void Stack<T>::deleteStack()
{
    list<T> *curr = head;
    while(curr != nullptr)
    {
        list<T> *temp = curr->next;
        delete curr;
        curr = temp;
    }
}
template<class T>
void Stack<T>::command(string comm)
{
    if(comm.find("push") != string::npos)
    {
        if(comm.length() <= 5)
            return;
        comm = comm.substr(5);
        stringstream i(comm);
        T temp;
        i >> temp;
        push(temp);
    }
    if(comm == "pop")
        cout << pop();
    if(comm == "print")
        print();
    if(comm == "exit")
        exit(0);
}

int main(void)
{
    Stack<string> s;
    cout << "push X:往堆栈里添加元素X; pop:弹出并打印栈顶元素; print: 打印所有元素; exit:退出" << endl;
    while(1)
    {
        cout << "请输入命令:";
        string comm;
        getline(cin, comm);
        s.command(comm);
        cout << endl;
    }
    return 0;
}
