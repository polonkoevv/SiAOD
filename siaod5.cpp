#include <iostream>
#include <Windows.h>

using namespace std;

struct Node
{
public:
    Node* pNext;
    int data;
    Node(int data = int(), Node* pNext = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
    }
};

struct List
{
public:
    List();
    int Size;
    Node* head;
};

List::List()
{
    Size = 0;
    head = nullptr;
}

void push_front(List& L, int data)
{
    L.head = new Node(data,L.head);
    L.Size++;
}

void print(List& L)
{
    Node* current = L.head;

    while (current != nullptr)
    {
        cout << current->data << "\t";
        current = current->pNext;
    }
    cout << endl;
}

bool checkSame(List L)
{
    Node* current = L.head;
    Node* current_next = L.head;

    while(current!=nullptr){
        current_next = current->pNext;
        while(current_next!=nullptr){
            if (current_next->data == current->data) {
                cout << "В списке есть одинаковые числа\n";
                return true;
            }
            current_next = current_next->pNext;
        }
        current = current->pNext;
    }
    cout << "В списке нет одинаковых элементов\n";
    return false;
}

void removeAt(List& L, int index)
{
    Node* current = L.head;
    if (index == 0)
    {
        Node *temp = current;
        current = current->pNext;
        delete temp;
        L.Size--;
    }
    else
    {
        Node* previous = current;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;
        L.Size--;
    }
}

void removeMax(List& L)
{
    int counter = 0;
    int counterMax = 0;
    Node* current = L.head;
    int maxNum = current->data;
    while(current->pNext != nullptr)
    {
        counter++;
        if(maxNum < current->pNext->data)
        {
            maxNum = current->pNext->data;
            counterMax = counter;
        }
        current = current->pNext;
    }

    cout << counterMax << '\t' << maxNum << endl;

    removeAt(L,counterMax);

}

void insert(List& L,int data, int index)
{
    Node* current = L.head;
    if (index == 0)
    {
        push_front(L,data);
    }
    else
    {
        Node* previous = current;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node* newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;
        L.Size++;
    }

}

void insertAtEven(List& L)
{
    int Size = L.Size;
    if (L.Size % 2 == 0)
    {
        Size--;
    }
    int n;
    for (int i = Size - 1 ; i >= 0; i = i - 2)
    {
        cout << "Какое значение добавить в узел № " << i << endl;
        cin >> n;
        insert(L,n, i);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    List lst;
    //Автоматически добавляется 7 рандомных чисел %47
    for (int i = 0; i < 7; ++i) {push_front(lst,rand()%47);}

    print(lst);

    checkSame(lst);

    removeMax(lst);

    print(lst);

    insertAtEven(lst);

    print(lst);

    return 0;
}
