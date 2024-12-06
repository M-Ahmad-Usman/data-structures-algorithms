#include <iostream>
using namespace std;

int* FindMaximum (int array[], int size)
{
    int *ptr = array;
    int maximum = array[0];
    
    for (int i=0; i<size; i++)
    {
        if (maximum<*(ptr+i))
        {
            maximum = *ptr+i;
        }
        
    }

    ptr = &maximum;
    return ptr;
}

void Display (int *ptr)
{
    cout << "The maximum value is " << *ptr;
}

int main ()
{
    int arr[5] = {1,2,3,4,5};
    Display(FindMaximum(arr,5));

    return 0;
}