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

                if (current != nullptr) // Checking if index is in the list
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
        else if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        else if (head->GetNext() == nullptr)
        {
            cout << "List contains only one node\n";
        }

        else if (secondNodeIndex - 1 != firstNodeIndex) // Checking whether the given indexes are consecutive or not
        {
            cout << "Given indexes are not cosecutive\n";
            return;   
        }
        else // If given indexes are consecutive, non-negative and the list is not empty
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
                cout << "List does not contains the specified nodes on given indexes\n";
                return;
            }
        }
    }

    int Findminimum()
    {
        // This function finds minimum from the whole list and returns -1 if the list is empty
        if (head != nullptr)
        {
            int minimum = head->GetData();
            Node *current = head->GetNext();
            while (current != nullptr)
            {
                if (current->GetData() < minimum)
                    minimum = current->GetData();

                current = current->GetNext();
            }

            return minimum;
        }
        else
        {
            return -1;
        }
    }

    int FindMaximum()
    {
        // This function finds minimum from the whole list and returns -1 if the list is empty
        if (head != nullptr)
        {
            int maximum = head->GetData();
            Node *current = head->GetNext();
            while (current != nullptr)
            {
                if (current->GetData() > maximum)
                    maximum = current->GetData();

                current = current->GetNext();
            }

            return maximum;
        }
        else
        {
            return -1;
        }
    }

    int Search(int data)
    {
        // This function returns the number of occurences of given data in the list
        int occurrence = 0;

        Node *current = head;
        while (current != nullptr)
        {
            if (current->GetData() == data)
                occurrence++;

            current = current->GetNext();
        }

        return occurrence;
    }

    void Insert(int data, int index)
    {
        // This overloaded function inserts an item at desired location (Not at end)

        // Case 1: if index is negative
        if (index < 0)
        {
            cout << "Please enter non-negative index\n";
            return;
        }

        // Case 2: if Index is at head
        else if (index == 0)
        {
            Node *newNode = new Node();
            newNode->SetData(data);
            newNode->SetNext(head); // If head is null then next will be null otherwise if head is not null then newnode will contain the address of head's ndoe

            head = newNode;
        }

        // Case 3: if Index is not at head
        else if (index > 0)
        {
            Node *newNode = new Node();
            newNode->SetData(data);

            Node *current = head;
            Node *previous = nullptr;

            while (index > 0 && current != nullptr)
            {
                previous = current;
                current = current->GetNext();

                index--;
            }

            if (current != nullptr)
            {
                previous->SetNext(newNode);
                newNode->SetNext(current);
            }
            else
            {
                cout << "Index out of bound\n";
            }
        }
    }

    void Swap (int firstNodeIndex, int secondNodeIndex)
    {
        // This functions swaps data of two nodes of given indexes (Index starts from 0) 

        if (head == nullptr) // checking if list is empty
        {
            cout << "List is empty\n";
            return;
        }

        else if (head->GetNext() == nullptr) // Checking if list only contains one node
        {
            cout << "List contains only one node\n";
            return;
        }

        else if (firstNodeIndex < 0 || secondNodeIndex < 0 || firstNodeIndex == secondNodeIndex) // Checking if indexes are negative or both indexes refer to the same node
        {
            cout << "Invalid node indexes\n";
            return;
        }

        else if (head->GetNext() != nullptr)
        {
            Node *firstNode = head;
            Node *secondNode = head;

            while (firstNodeIndex > 0 && firstNode != nullptr)
            {
                firstNode = firstNode->GetNext();

                firstNodeIndex--;
            }

            while (secondNodeIndex > 0 && secondNode != nullptr)
            {
                secondNode = secondNode->GetNext();

                secondNodeIndex--;
            }

            // Swapping
            if (firstNode != nullptr && secondNode != nullptr)
            {
                int temp = firstNode->GetData();
                firstNode->SetData(secondNode->GetData());
                secondNode->SetData(temp);
            }
            else
            {
                cout << "index out of bound\n";
            }
        }
    }

    int Size()
    {
        if (head == nullptr)
        {
            return 0;
        }
        else
        {
            int size = 0;

            Node *current = head;
            while (current != nullptr)
            {
                current = current->GetNext();

                size++;
            }

            return size;
        }
    }

    void Sort()
    {
        // This function sorts the list using bubble sort

        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        else if (head->GetNext() != nullptr)
        {   
            Node *current;
            Node *previous;
            int size = Size();

            for (int i=0; i < size - 1; i++)
            {
                current = head->GetNext();
                previous = head;

                for (int j=0; j < size -1 -i && current != nullptr; j++)
                {
                    if (previous->GetData() > current->GetData())
                    {
                        int temp = previous->GetData();
                        previous->SetData(current->GetData());
                        current->SetData(temp);
                    }
                    current = current->GetNext();
                    previous = previous->GetNext();
                }
            }
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
    List myList;

    // --> Testing Find Minimum (Tested)
    // Start
    // cout << "Minimum: " << myList.Findminimum() << endl;
    // myList.Insert(10);
    // myList.Insert(112);
    // myList.Insert(13);
    // myList.Insert(3);

    // cout << "Minimum: " << myList.Findminimum() << endl;

    // myList.Delete(3);
    // myList.Delete(2);
    // myList.Delete(1);
    // myList.Delete(0);
    // End

    // --> Testing Search function (Tested)
    // Start
    // myList.Insert(2);
    // myList.Insert(3);
    // myList.Insert(4);
    // myList.Insert(5);

    // cout << "Occurrences of 1: " << myList.Search(1) << endl;

    // myList.Delete(0);
    // myList.Delete(0);
    // myList.Delete(0);
    // myList.Delete(0);
    // End

    // --> Testing overloaded Insert Function with index (Tested)
    // Start
    // myList.Insert(1, 2);
    // myList.Insert(0, 0);
    // myList.Insert(1, 0);
    // myList.Insert(3, 1);
    // myList.Insert(4, 2);
    // myList.Insert(5, 8);
    // myList.Insert(1, -1);

    // myList.Delete(0);
    // myList.Delete(0);
    // myList.Delete(0);
    // myList.Delete(0);
    // myList.Delete(0);
    // myList.Delete(0);
    // End

    // --> Testing Swap Function (Tested)
    // Start
    // myList.Swap(-1, 1);
    // myList.Swap(0, 1);
    // myList.Insert(1);
    // myList.Insert(2);
    // myList.Swap(1,2);
    // myList.Swap(0,1);
    // myList.Swap(1,0);

    // myList.Delete(0);
    // myList.Delete(0);
    // End

    // --> Testing Sort function (Tested)
    // Start
    myList.Sort();
    myList.Insert(10);
    myList.Sort();

    myList.Insert(9);
    myList.Sort();

    myList.Insert(8);
    myList.Insert(7);
    myList.Insert(6);
    myList.Insert(5);
    myList.Insert(4);
    myList.Insert(3);
    myList.Insert(2);
    myList.Insert(1);
    myList.Sort();

    myList.Delete(0);
    myList.Delete(0);
    myList.Delete(0);
    myList.Delete(0);
    myList.Delete(0);
    myList.Delete(0);
    myList.Delete(0);
    myList.Delete(0);
    myList.Delete(0);
    myList.Delete(0);
    // End

    return 0;
}