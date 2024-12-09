#pragma once
#include "LRUCache.hpp"
#include <fstream>
#include "sequence.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <memory>

const int CACHE_SIZE = 10;
const int PERSON_COUNT = 10;


void runCacheOperations();
// Функция для печати содержимого кеша
void printCache(LRUCache<int, int>& cache);

// Функция для записи содержимого кеша в файл
void writeToFile(LRUCache<int, int>& cache);

// Функция для измерения времени операций с кешем
void measureTimeForCache(LRUCache<int, int>& cache);

// Функция для измерения времени операций с объектами Person
void measureTimeForPerson(Person<int> person[]);
