
#pragma once
#include <iostream>
#include <iostream>
#include "sequence.h"
#include "LinkedList.h"




/*

template <class TKey, class T>
class Ht_item {
    friend class HashTable<TKey, T>;

private:
    TKey key;
    T value;

public:
    // Конструктор по умолчанию
    Ht_item() : key(TKey()), value(T()) {}

    // Конструктор с параметрами
    Ht_item(TKey key, const T& value) : key(key), value(value) {}

    // Оператор присваивания
    Ht_item& operator=(const T& element) {
        this->value = element;
        return *this;
    }

    // Геттер для значения
    T getEl() const {
        return this->value;
    }

    // Геттер для ключа
    TKey first() const {
        return this->key;
    }

    // Геттер для адреса значения
    T* second() {
        return &this->value;
    }

    // Проверка, свободен ли индекс (значение по умолчанию)
    bool indexIsFree() const {
        return this->value == T();
    }
};




template <class TKey, class T>
class HashTable {
private:
    LinkedList<TKey, T>** items; // Массив указателей на связные списки
    size_t size;      // Количество занятых элементов
    size_t capacity;  // Общее количество "ведер"

    // Простая хеш-функция
    size_t hashFunction(TKey key) const {
        return static_cast<size_t>(key) % capacity;
    }

public:
    // Конструктор с параметром capacity, инициализация массива элементов
    HashTable(size_t capacity) : capacity(capacity), size(0) {
        items = new LinkedList<TKey, T>* [capacity];
        for (size_t i = 0; i < capacity; ++i) {
            items[i] = new LinkedList<TKey, T>();
        }
    }

    // Деструктор
    ~HashTable() {
        for (size_t i = 0; i < capacity; ++i) {
            delete items[i];
        }
        delete[] items;
    }

    // Вставка элемента
    void insert(TKey key, const T& value) {
        size_t hash = hashFunction(key);
        Ht_item<TKey, T> new_item(key, value);

        Ht_item<TKey, T>* existing_item = items[hash]->find(key);
        if (existing_item == nullptr) {
            size++;
        }

        items[hash]->insert(new_item);
    }

    // Получение размера (количество занятых элементов)
    size_t getSize() const {
        return size;
    }

    // Получение емкости таблицы
    size_t getCapacity() const {
        return capacity;
    }

    // Получение значения по ключу
    T getValue(TKey key) const {
        size_t hash = static_cast<size_t>(key) % capacity;
        Ht_item<TKey, T>* item = items[hash]->find(key);
        if (item != nullptr) {
            return item->value;
        }
        else {
            std::cerr << "Key not found!" << std::endl;
            return T(); // Возвращаем значение по умолчанию
        }
    }

    // Проверка, свободен ли индекс (наличие элемента)
    bool indexIsFree(TKey key) const {
        size_t hash = static_cast<size_t>(key) % capacity;
        Ht_item<TKey, T>* item = items[hash]->find(key);
        return (item == nullptr);
    }

    // Вывод значения по ключу
    void print(TKey key) const {
        size_t hash = static_cast<size_t>(key) % capacity;
        Ht_item<TKey, T>* item = items[hash]->find(key);
        if (item != nullptr) {
            std::cout << "Value at key " << key << ": " << item->value << std::endl;
        }
        else {
            std::cerr << "Key not found!" << std::endl;
        }
    }

    // Удаление элемента по ключу
    void remove(TKey key) {
        size_t hash = static_cast<size_t>(key) % capacity;
        bool removed = items[hash]->remove(key);
        if (removed) {
            size--;
        }
        else {
            std::cerr << "Key not found!" << std::endl;
        }
    }

    // Печать всей хеш-таблицы
    void printTable() const {
        for (size_t i = 0; i < capacity; ++i) {
            std::cout << "Bucket " << i << ": ";
            items[i]->printAll();
        }
    }
};

*/












template <class TKey, class T>
class HashTable;

template <class TKey, class T>
class Ht_item {
    friend class HashTable<TKey, T>;

private:
    TKey key;
    T value;

public:
    Ht_item() : key(TKey()), value(T()) {}

    void operator=(T element) {
        this->value = element;
    }

    T getEl() const {
        return this->value;
    }

    TKey first() const {
        return this->key;
    }

    T* second() {
        return &this->value;
    }

    bool indexIsFree() const {
        // Возвращаем true, если значение по ключу пустое (по умолчанию T()).
        return this->value == T();
    }





};

template <class TKey, class T>
class HashTable {
private:
    Ht_item<TKey, T>* items;
    int size = 0;
    int count;

public:
    // Конструктор с параметром count, инициализация массива элементов
    HashTable(int count) : count(count) {
        items = new Ht_item<TKey, T>[count];
        for (int i = 0; i < count; ++i) {
            items[i].key = i; // Инициализация ключей
        }
    }

    ~HashTable() {
        delete[] items;  // Используем delete[] для удаления массива
    }

    void insert(TKey key, T value) {
        if (key >= count) {
            std::cerr << "Key out of bounds!" << std::endl;
            return;
        }

        if (items[key].indexIsFree()) {
            ++size;
        }

        items[key].value = value;
    }

    int Getsize() const {
        return this->size;
    }

    int Getcount() const {
        return this->count;
    }

    T getValue(TKey key) const {
        if (key >= count) {
            std::cerr << "Key out of bounds!" << std::endl;
            return T(); // Возвращаем значение по умолчанию
        }
        return items[key].value;
    }

    bool indexIsFree(TKey key) const {
        if (key >= count) {
            std::cerr << "Key out of bounds!" << std::endl;
            return false;
        }
        return this->items[key].indexIsFree();
    }

    T getHT(TKey key) const {
        return this->getValue(key);
    }

    void print(TKey key) const {
        if (key >= count) {
            std::cerr << "Key out of bounds!" << std::endl;
            return;
        }
        std::cout << "Value at key " << key << ": " << getValue(key) << std::endl;
    }

    void remove(TKey key) {
        if (key >= count) {
            std::cerr << "Key out of bounds!" << std::endl;
            return;
        }

        if (!items[key].indexIsFree()) {
            items[key].value = T();  // Устанавливаем значение по умолчанию
            --size;
        }
    }

    // Метод для удаления дубликатов с использованием лямбда-функции
    
};


