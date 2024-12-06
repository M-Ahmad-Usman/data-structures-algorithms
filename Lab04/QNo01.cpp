#include <iostream>
using namespace std;

// Node class
class Node
{
    // Private data members
    int data;
    Node *next;

    public:

    // Constructor
    Node ()
    {
        data = 0;
        next = nullptr;
    }

    // Getters
    int GetData ()
    {
        return data;
    }

    Node *GetNext()
    {
        return next;
    }

    // Setters
    void SetData (int data)
    {
        this->data = data;
    }

    void SetNext (Node *next)
    {
        this->next = next;
    }
};

int main ()
{

    return 0;
}