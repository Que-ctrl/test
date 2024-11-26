#include <iostream>


class Student
{
    private:
    std::string name;

    public:
    double betyg1;
    double betyg2;
    double betyg3;
    double mediumValue;

    Student(std::string name, double betyg1, double betyg2, double betyg3){this->name = name; this->betyg1 = betyg1; this->betyg2 = betyg2; this->betyg3 = betyg3;};

    std::string getName()
    {
        return name;
    }
    void setName(std::string name)
    {
        this->name = name;
    }

    double hasPassed()
    {
        
        
        mediumValue = (betyg1 + betyg2 + betyg3) / 3;
        if(mediumValue >= 60)
        {
            std::cout << "The student has passed the course! The grade is: " << mediumValue << ". Which is over 60!" << std::endl;
        }
        else
        {
            std::cout << "The student have failed the course! The grade is: " << mediumValue << ". Which is less than 60!" << std::endl;
        }
        return mediumValue;
    }

    void showInfo()
    {

        std::cout << "Students name: " << name << std::endl;
        std::cout << "Students grade one: " << betyg1 << std::endl;
        std::cout << "Students grade two: " << betyg2 << std::endl;
        std::cout << "Students grade three: " << betyg3 << std::endl;
        std::cout << "Students madian value: " << mediumValue << std::endl;
        std::cout << "==========================================" << std::endl;
    }


};

int main()
{
    Student student1("Hello", 20, 11, 25);
    Student student2("Goodbye", 480, 36, 84);
    Student student3("HelloAgain", 2, 0, 484);
    Student student4("GoodbyeAgain", 45, 84, 10);
    
    student1.hasPassed();
    student1.showInfo();
    student2.hasPassed();
    student2.showInfo();
    student3.hasPassed();
    student3.showInfo();
    student4.hasPassed();
    student4.showInfo();
   
    return 0;
}