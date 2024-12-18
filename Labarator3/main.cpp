#include "histogram.hpp"

#include <locale>  
#include <clocale> 
#include "interface.hpp"
#include "LinkedList.h"



#include "LRUCache.hpp"
#include <fstream>
#include "Person.hpp"


 
int main() {
    /*
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    Person<int> persons[12];
    for (int i = 0; i < 12; ++i) {
        persons[i].generation();
    }


    LinkedList<Person<int>> seq;
    for (int i = 0; i < 12; ++i) {
        seq.Append(persons[i]);
    }
    print_histogram(seq, [](const Person<int>& p) -> int { return p.age; }, "Age");
   // seq.Print();
    ISet<Person<int>> iset(seq);
    iset.RemoveDuplicates();


     seq.Print();
     print_histogram(seq,[](const Person<int>& p) -> int { return p.age; },"Age");
     */
    std::setlocale(LC_ALL, "Russian");
    interface();
    return 0;
}