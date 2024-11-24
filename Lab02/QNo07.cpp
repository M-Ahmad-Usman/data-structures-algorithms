#include <iostream>
using namespace std;

int countEven(int *arr, int size) 
{
    int count = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (*(arr+i) % 2 == 0) 
        {
            count++;
        }
    }
    return count;
}

int main() 
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int evenCount = countEven(arr, 10);
    cout << "Number of even numbers in the array: " << evenCount;

    char screenshot;
	cin >> screenshot; // For taking output's screenshot
    return 0;
}
