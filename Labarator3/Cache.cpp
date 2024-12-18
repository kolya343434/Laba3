#include "LRUCache.hpp"
#include "Person.hpp"
#include "Cache.hpp"




void runCacheOperations()
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
    std::cout << "Out all elements of sequence" << '\n';
    for (int i = 0; i < 10; ++i)
    {
        std::cout << lruCache->printList(i) << '\n';
    }
    std::cout << '\n';
    std::ofstream fout("tf.txt");
    for (int i = 0; i < 10; ++i)
    {
        fout << lruCache->get(1)  << '\n';
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
    std::cout << "\nTime for cache operations: " << seconds << " seconds\n";
  
    clock_t start1 = clock();
    for (int i = 0; i < 10; ++i)
    {
        std::cout << person[i].weight << '\n';
    }
    clock_t end1 = clock();
    float seconds2 = (float)(end1 - start1) / CLOCKS_PER_SEC;
    std::cout << "\nTime for direct person operations: " << seconds2 << " seconds\n";
    fout.close();
}




