#pragma once

#include <iostream>
#include "Person.hpp"
#include "LinkedList.h"


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
       
            return T(); // Возвращаем значение по умолчанию
        }
        return items[key].value;
    }

    bool indexIsFree(TKey key) const {
        if (key >= count) {
           
            return false;
        }
        return this->items[key].indexIsFree();
    }

    T getHT(TKey key) const {
        return this->getValue(key);
    }

    void print(TKey key) const {
        if (key >= count) {

            return;
        }
        std::cout << "Value at key " << key << ": " << getValue(key) << std::endl;
    }

    void remove(TKey key) {
        if (key >= count) {
         
            return;
        }

        if (!items[key].indexIsFree()) {
            items[key].value = T();  // Устанавливаем значение по умолчанию
            --size;
        }
    }
    
};


