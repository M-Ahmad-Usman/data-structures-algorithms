#include <iostream>
using namespace std;


double calculateArea(const double* side) 
{
    return (*side) * (*side);
}

double calculateArea(const double* length, const double* width) 
{
    return (*length) * (*width);
}

double calculateArea(const double* radius, double pie) 
{
    return pie * (*radius) * (*radius);
}

int main() 
{
    double side = 5.0;
    double length = 6.0;
    double width = 4.0;
    double radius = 3.0;

    cout << "Area of square: " << calculateArea(&side) << endl;

    cout << "Area of rectangle: " << calculateArea(&length, &width) << endl;

    cout << "Area of circle: " << calculateArea(&radius, 3.14) << endl;

    char screenshot;
	cin >> screenshot; // For taking output's screenshot
    return 0;
}
