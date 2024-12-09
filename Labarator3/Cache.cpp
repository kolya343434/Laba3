#include "LRUCache.hpp"
#include <fstream>
#include "sequence.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <memory>
#include "Cache.hpp"


void printCache(LRUCache<int, int>& cache) {
    std::cout << "Out all elements of sequence:\n";
    for (int i = 0; i < PERSON_COUNT; ++i) {
        std::cout << cache.printList(i) << '\n';
    }
    std::cout << '\n';
}

void writeToFile(LRUCache<int, int>& cache) {
    std::ofstream fout("tf.txt");
    if (!fout) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }
    for (int i = 0; i < PERSON_COUNT; ++i) {
        fout << cache.get(1) << '\n';
    }
    fout.close();
}

void measureTimeForCache(LRUCache<int, int>& cache) {
    clock_t start = clock();
    for (int i = 0; i < PERSON_COUNT; ++i) {
        std::cout << cache.printList(i) << '\n';
    }
    clock_t end = clock();
    float seconds = static_cast<float>(end - start) / CLOCKS_PER_SEC;
    std::cout << "\nTime for cache operations: " << seconds << " seconds\n";
}

void measureTimeForPerson(Person<int> person[]) {
    clock_t start = clock();
    for (int i = 0; i < PERSON_COUNT; ++i) {
        std::cout << person[i].weight << '\n';
    }
    clock_t end = clock();
    float seconds = static_cast<float>(end - start) / CLOCKS_PER_SEC;
    std::cout << "\nTime for direct person operations: " << seconds << " seconds\n";
}



void runCacheOperations() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Person<int> person[PERSON_COUNT];
    auto lruCache = std::make_unique<LRUCache<int, int>>(CACHE_SIZE, CACHE_SIZE);

    // Инициализация объектов Person
    for (int i = 0; i < PERSON_COUNT; ++i) {
        person[i].generation();
    }

    // Добавление объектов в кеш
    for (int i = 0; i < PERSON_COUNT; ++i) {
        lruCache->set(i, person[i].weight);
    }

    // Вывод содержимого кеша
    printCache(*lruCache);

    // Запись кеша в файл
    writeToFile(*lruCache);

    // Измерение времени для операций с кешем
    measureTimeForCache(*lruCache);

    // Измерение времени для операций с объектами Person
    measureTimeForPerson(person);
}
