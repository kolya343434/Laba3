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
    /*
    bool operator==(const Person<T>& other) const {
        return (age == other.age && weight == other.weight && height == other.height && str == other.str);
    }*/

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


/*
template <class T>
class Sequence
{

public:
    T GetFirst();
    T GetLast();
    T Get(int index);
    Sequence<T> GetSubsequence(int startIndex, int endIndex);
    int GetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    Sequence<T> Concat(Sequence<T> const& list);
    void quicksort(Sequence<T>& seq, int (*cmp)(T, T));
    void insertionsort(Sequence<T>& seq, int (*cmp)(T, T));
    void bubblesort(Sequence<T>& seq, int (*cmp)(T, T));
};
*/
#endif // SEQUENCE_HPP_INCLUDED
