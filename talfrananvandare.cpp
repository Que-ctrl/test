#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


void inputNumbers()
{
    int numbers;
    double avarage;
    std::cout << "How many numbers do you want to input? ";
    std::cin >> numbers;
    std::vector<int> tal(numbers);

    for (int i = 0; i < numbers; i++)
    {
        std::cout << "Number " << (i + 1) << ": ";
        std::cin >> tal[i];
    }
    for(int talen : tal)
    {
        std::cout << talen << ", ";
        
    }
    std::cout << std::endl;

    std::cout << "The sum of the numbers is: " <<  std::accumulate(tal.begin(), tal.end(), 0);
    std::cout << std::endl;
    std::cout << "The vector has: " << tal.size() << " numbers" << std::endl;
    avarage = std::accumulate(tal.begin(), tal.end(), 0) / tal.size();
    std::cout << "The average number in the vector is: " << avarage << std::endl;
    double max = *std::max_element(tal.begin(), tal.end());
    double min = *std::min_element(tal.begin(), tal.end());
    std::cout << "The highest number in the vector is: " << max << std::endl; 
    std::cout << "The smallest number in the vector is: " << min << std::endl; 



}



int main()
{
    inputNumbers();
    return 0;
}