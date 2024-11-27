#include <iostream>
using namespace std;

int main() 
{
    int numbers[] = {1, 2, 3, 4, 5}; // ska vara en } inte )
    int sum = 0; // det är bättre att initialisera sum med 0. 
    
    for(int i = 0; i < 5; i++) // tog bort =.
    {
        sum += numbers[i];
    }
    
    cout << "The average is: " << sum/5.0; 
}