#include <iostream>
#include <map> 
#include <limits> // för numeric_limits
#include <iomanip> // för utseende
#include <cctype> // för tolower
#include <algorithm> // för transform


class PhoneBook
{
    public:
    std::map<std::string, std::string> phoneBook;
    std::string name;
    std::string number; 

    PhoneBook(std::string name, std::string number){this->name = name; this->number = number;};
    

    void addContacts(std::string name, std::string number)
    {
        std::transform(name.begin(), name.end(), name.begin(), ::tolower);
        phoneBook.insert(make_pair(name, number)); // lägger till det i map
    }

    void removeContacts(std::string inputName) // funktion för att radera en kontakt
    {
        std::transform(inputName.begin(), inputName.end(), inputName.begin(), ::tolower);
        auto it = phoneBook.find(inputName); // letar i phonebook
        if(it != phoneBook.end())
        {
            std::cout << std::left;
            std::cout << "Name: " << std::setw(15) << it->first;
            std::cout << "Number: " << it->second << std::endl; // om den hittas så printar den namn och nummer och att den kommer att tas bort. 
            std::cout << inputName << " is deleted!" << std::endl;
            phoneBook.erase(inputName); // raderar kontakten
        }
        else
        {
            std::cout << inputName << " is not in the phonebook" << std::endl; // om den inte finns i phonebook.
        }
    }


    void searchContact(std::string searchName)
    {
        std::transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
        auto it = phoneBook.find(searchName); //Letar efter kontakten med namnet från cin.
        if(it != phoneBook.end())
        {
            std::cout << std::left;
            std::cout << "Contact found - " << "Name: " << std::setw(15) << it->first; // för att det ser böttre ut
            std::cout << "Number: " << it->second << std::endl; // vid hittad kontakt
        }
        else
        {
            std::cout << "Cannot find contact!" << std::endl; // om kontakten ej hittas
        }
    }

    void showContacts()
    {
        
        std::map<std::string, std::string>::iterator it = phoneBook.begin(); //iterator som jag använder för att gå igenom map
        while(it != phoneBook.end()) 
        {
            std::cout << std::left;
            std::cout << "Name: " << std::setw(15) << it->first;
            std::cout << " Number: " << it->second << std::endl;
            it++;
        }
        std::cout << "Size of the Phonebook: " << phoneBook.size() << std::endl; //storleken på telefonboken
    }
    friend void showMenu(PhoneBook);  // hittade en funktion som jag ville testa, friend. 

    
};


    
void showMenu(PhoneBook fr) // meny för telefonboken
{
    int userChoice;
    do
    {
        std::cout << "_____________________________________________" <<std::endl;
        std::cout << std::endl;
        std::cout << "Phonebook" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Detele Contact" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Show Contacts" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> userChoice;
        std::cout << "_____________________________________________" <<std::endl;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // failsafe om man skriver en sträng ist för int. 
        
        }

        if(userChoice == 1)
        {
            std::cout << std::endl;
            std::string name;
            std::string number;
            std::cout << "Add Contact" << std::endl;
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Number: ";
            std::cin >> number;
            fr.addContacts(name, number);
        }
        else if(userChoice == 2)
        {
            std::cout << std::endl;
            std::string inputName;
            std::cout << "Delete contact" << std::endl; 
            fr.showContacts();
            std::cout << "What contact do you want to delete? ";
            std::cin >> inputName;
            fr.removeContacts(inputName);
        }
        else if(userChoice == 3)
        {
            std::cout << "Search contact" << std::endl;
            std::string searchName;
            std::cin >> searchName;
            std::transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
            std::cout << std::endl;
            fr.searchContact(searchName);
        }
        else if(userChoice == 4)
        {
            std::cout << std::endl;
            std::cout << "Contacts" << std::endl;
            fr.showContacts();
        }
        else if(userChoice == 5)
        {
            break;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Invalid option!" << std::endl;
        }
    }while(true);
        
}


int main()
{
    
    PhoneBook fr("","");
    showMenu(fr);
 
    return 0;
}


