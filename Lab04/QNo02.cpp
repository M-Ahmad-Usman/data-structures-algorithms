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
    Node()
    {
        data = 0;
        next = nullptr;
    }

    // Getters
    int GetData()
    {
        return data;
    }

    Node *GetNext()
    {
        return next;
    }

    // Setters
    void SetData(int data)
    {
        this->data = data;
    }

    void SetNext(Node *next)
    {
        this->next = next;
    }
};

// List Class
class List
{
    // Private data member
    Node *head;

public:
    // Constructor
    List()
    {
        head = nullptr;
    }

    void Insert(int data)
    {
        // This functions insert a new node at the end of the list
        Node *newNode = new Node();
        newNode->SetData(data);

        if (head != nullptr)
        {
            Node *current = head;
            while (current->GetNext() != nullptr) // Traversing current to the last node
            {
                current = current->GetNext();
            }

            current->SetNext(newNode); // Linking the last node to the newNode
        }
        else
        {
            head = newNode;
        }
    }

    void Print()
    {
        // This function prints the data of all the nodes in the list.
        if (head != nullptr)
        {
            Node *current = head;

            while (current != nullptr)
            {
                cout << current->GetData() << "->";
                current = current->GetNext();
            }
        }
        else
        {
            cout << "List is empty\n";
        }
    }

    void Delete(int index)
    {
        // This function delete a node from the given index. The index numbers start from 0
        if (head != nullptr)
        {
            if (index == 0)
            {
                Node *current = head;
                head = head->GetNext();
                delete current;
                current = nullptr;
            }
            else if (index > 0)
            {
                Node *current = head;
                Node *previous = nullptr;

                while (index > 0 && current != nullptr)
                {
                    previous = current;
                    current = current->GetNext();

                    index--;
                }

                if (current != nullptr) // Checking if index is in the list size
                {
                    previous->SetNext(current->GetNext());
                    delete current;
                    current = nullptr;

                    return;
                }
                else
                {
                    cout << "Index out of bound\n";
                    return;
                }
            }
            else if (index < 0)
            {
                cout << "Please enter a valid Node's index\n";
            }
        }
        else
        {
            cout << "List is empty\n";
        }
    }

    void AddBetween(int data, int firstNodeIndex, int secondNodeIndex)
    {
        // This function adds a new node between two existing nodes of given indexes.
        if (firstNodeIndex < 0 || secondNodeIndex < 0)
        {
            cout << "Please enter non-negative indexes\n";
            return;
        }
        else if (head == nullptr || head->GetNext() == nullptr)
        {
            cout << "List contains less than 2 nodes\n";
            return;
        }

        else if (secondNodeIndex - 1 == firstNodeIndex) // Checking if list contains more tha one node and the second node and first node addresses are consecutive and firstNodeIndex is a positive index
        {
            Node *current = head;
            Node *previous = nullptr;

            while (firstNodeIndex >= 0 && current != nullptr) // Traversing current node to second NodeIndex and previous node to firstNodeindex
            {
                previous = current;
                current = current->GetNext();

                firstNodeIndex--;
            }

            if (current != nullptr) // Checking if the addresses were valid there is no node at secondNodeIndex
            {
                Node *newNode = new Node();
                newNode->SetData(data);
                previous->SetNext(newNode);
                newNode->SetNext(current);
            }
            else
            {
                cout << "List does not contains the specified nodes\n";
            }
        }
        else
        {
            cout << "Indexes are not consecutive\n";
            return;
        }
    }

    ~List()
    {
        if (head != nullptr)
        {
            Node *current = head;
            Node *next;
            while (current != nullptr)
            {
                next = current->GetNext(); // Traversing to second node before deleting the first node
                delete current;
                current = next;
            }
        }
    }
};

int main()
{

    return 0;
}