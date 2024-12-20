#include "LRUCache.hpp"
#include "Person.hpp"
#include "Cache.hpp"


void runCacheOperations()
{
    srand(time(nullptr));
    Person<int> person[20];
    LRUCache<int, int>* lruCache = new LRUCache<int, int>(20, 20);
    for (int i = 0; i < 20; ++i)
    {
        person[i].generation();
    }
    for (int i = 0; i < 20; ++i)
    {
        lruCache->set(i, person[i].weight);

    }
    std::cout << "Out all elements of sequence" << '\n';
    for (int i = 0; i < 20; ++i)
    {
        std::cout << lruCache->printList(i) << '\n';
    }
    std::cout << '\n';
    std::ofstream fout("tf.txt");
    for (int i = 0; i < 20; ++i)
    {
        fout << lruCache->get(1) << '\n';
    }
    clock_t start = clock();
    for (int i = 0; i < 19; ++i)
    {
        std::cout << lruCache->printList(i) << '\n';
    }
    clock_t end = clock();
    std::cout << '\n';
    std::cout << '\n';
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    std::cout << "\nTime for cache operations (with cash): " << seconds << " seconds\n";

    clock_t start1 = clock();
    for (int i = 0; i < 20; ++i)
    {
        std::cout << person[i].weight << '\n';

    }
    clock_t end1 = clock();
    float seconds2 = (float)(end1 - start1) / CLOCKS_PER_SEC;
    std::cout << "\nTime for direct person operations(without cash): " << seconds2 << " seconds\n";


    fout.close();
}











/*
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
    for (int i = 0; i < 9; ++i)
    {
        std::cout << lruCache->printList(i) << '\n';
    }
    clock_t end = clock();
    std::cout << '\n';
    std::cout << '\n';
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    std::cout << "\nTime for cache operations (with cash): " << seconds << " seconds\n";
  
    clock_t start1 = clock();
    for (int i = 0; i < 10; ++i)
    {
        std::cout << person[i].weight << '\n';
      
    }
    clock_t end1 = clock();
    float seconds2 = (float)(end1 - start1) / CLOCKS_PER_SEC;
    std::cout << "\nTime for direct person operations(without cash): " << seconds2 << " seconds\n";


    fout.close();
}

*/
/*













#include "LRUCache.hpp"
#include "Person.hpp"
#include "Cache.hpp"



#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <chrono>

void runCacheOperations()
{
    const int numPersons = 10000;      // Количество элементов
    const int cacheCapacity = 100;   // Вместимость кэша

    srand(static_cast<unsigned>(time(nullptr)));

    // Динамическое выделение памяти для массива Person
    Person<int>* persons = new Person<int>[numPersons];

    // Создание экземпляра LRUCache с заданной вместимостью
    LRUCache<int, int>* lruCache = new LRUCache<int, int>(cacheCapacity, cacheCapacity);

    // Генерация данных для каждого Person
    for (int i = 0; i < numPersons; ++i)
    {
        persons[i].generation();
    }

    // Заполнение кэша
    for (int i = 0; i < numPersons; ++i)
    {
        lruCache->set(i, persons[i].weight);
    }

    std::cout << "Все элементы успешно добавлены в кэш.\n\n";

    // Запись результатов операций get в файл
    std::ofstream fout("tf.txt");
    if (!fout)
    {
        std::cerr << "Ошибка при открытии файла tf.txt для записи.\n";
        // Освобождение памяти перед выходом
        delete[] persons;
        delete lruCache;
        return;
    }

    // Имитируем частые обращения к одному ключу для тестирования LRU поведения
    for (int i = 0; i < numPersons; ++i)
    {
        try
        {
            int value = lruCache->get(1); // Получаем значение для ключа 1
            fout << value << '\n';
        }
        catch (const std::exception& e)
        {
            fout << "key not found\n"; // Запись ошибки в файл
        }
    }

    // Измерение времени операций с кэшем с использованием std::chrono
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numPersons; ++i)
    {
        try
        {
            lruCache->get(i);  // Выполняем операции get для разных ключей
        }
        catch (const std::exception& e)
        {
            std::cerr << "Ошибка при получении ключа " << i << ": " << e.what() << '\n';
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Время для операций с кэшем: " << elapsed.count() << " секунд\n";

    // Измерение времени прямых операций без кэша с использованием std::chrono
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numPersons; ++i)
    {
        // Предполагается, что доступ к person.weight эквивалентен прямому доступу без кэша
        volatile int weight = persons[i].weight;  // volatile предотвращает оптимизацию
        (void)weight;  // Избегаем предупреждений о неиспользуемой переменной
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end1 - start1;
    std::cout << "Время для прямых операций без кэша: " << elapsed2.count() << " секунд\n";

    fout.close();


    delete[] persons;
    delete lruCache;
}


*/