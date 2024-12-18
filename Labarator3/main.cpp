//#include "histogram.hpp"
//#include "Cache.hpp"
//#include "test_for_cash.hpp"



#include <locale>  
#include <clocale> 
#include "interface.hpp"




#include "LRUCache.hpp"
#include <fstream>
#include "Person.hpp"


 
int main() {

    std::setlocale(LC_ALL, "Russian");
    interface();
    return 0;
}
/*
void cash()
{
    srand(time(nullptr));
    Person<int> person[10];
    LRUCache<int, int>* lruCache = new LRUCache<int, int>(10, 10);
    for (int i = 0; i < 10; ++i)
    {
        person[i].generation();
    }
    for (int i = 0; i < 10; ++i)
    {
        lruCache->set(i, person[i].weight);
    }
    std::cout << "Out all elmts of sequence" << '\n';
    for (int i = 0; i < 10; ++i)
    {
        std::cout << lruCache->printList(i) << '\n';
    }
    std::cout << '\n';
    std::ofstream fout("tf.txt");
    for (int i = 0; i < 10; ++i)
    {
        fout << lruCache->get(1) << '\n';
    }
    clock_t start = clock();
    for (int i = 0; i < 10; ++i)
    {
        std::cout << lruCache->printList(i) << '\n';
    }
    clock_t end = clock();
    std::cout << '\n';
    std::cout << '\n';
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << '\n';
    clock_t start1 = clock();
    for (int i = 0; i < 10; ++i)
    {
        std::cout << person[i].weight << '\n';
    }
    clock_t end1 = clock();
    float seconds2 = (float)(end1 - start1) / CLOCKS_PER_SEC;
    std::cout << seconds << " " << seconds2 << '\n';
    fout.close();
}
int main() {
    cash();
    return 0;
}




*/