#ifndef SEQUENCE_HPP_INCLUDED
#define SEQUENCE_HPP_INCLUDED
#include <cstdlib>
#include <ctime>

template <class T>
class Person
{
public:
    int age;
    int weight;
    int height;
    std::string str;
   

    friend std::ostream& operator<<(std::ostream& os, const Person<T>& person) {
        os << "Age: " << person.age << ", Weight: " << person.weight
            << ", Height: " << person.height << ", Name: " << person.str;
        return os;
    }

    bool operator==(const Person& other) const {
        return age == other.age ;
    }
    bool operator<(const Person& other) const {
        return age < other.age;
    }
    bool operator>(const Person& other) const {
        return age > other.age;
    }

    void generation()
    {

        age = rand() % 101;
        weight = rand() % 150 + 20;
        height = 150 + rand() % 50;
        str.resize(10);
        for (int i = 0; i < 10; ++i)
        {
            str[i] = rand() % 25 + 97;
        }
    }
    void print()
    {
        std::cout << age << " age " << weight << " weight " << height << " height " << str << " str " << '\n';
    }

    int getAge() const {
        return age;
    }


    

};

#endif 
