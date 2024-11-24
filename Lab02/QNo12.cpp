#include <iostream>
using namespace std;

void printValue(const int* ptr) 
{
    cout << "Value pointed to by the pointer: " << *ptr << endl;
}

int main() 
{
    int num = 10;
    const int* ptr = &num;
    
    printValue(ptr);

    char screenshot;
	cin >> screenshot; // For taking output's screenshot
    return 0;
}
