//#include "histogram.hpp"
//#include "Cache.hpp"
//#include "test_for_cash.hpp"



#include <locale>  
#include <clocale> // Äëÿ setlocale

#include "LinkedList.h"

#include <iostream>
using namespace std;


#include "interface.hpp"


#include <iostream>



#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>
#include <string>



/*
// Предварительное объявление шаблонного класса HashTable
template <class TKey, class T>
class HashTable;

// Шаблон класса для элемента хеш-таблицы
template <class TKey, class T>
class Ht_item {
    // Дружественные шаблонные классы HashTable и LinkedList
    template <class U, class V>
    friend class HashTable;

    template <class U, class V>
    friend class LinkedList;

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


// Узел для связного списка
template <class TKey, class T>
struct Node {
    Ht_item<TKey, T> data;
    Node<TKey, T>* next;

    Node(const Ht_item<TKey, T>& item) : data(item), next(nullptr) {}
};

// Простая реализация односвязного списка
template <class TKey, class T>
class LinkedList {
private:
    Node<TKey, T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    // Вставка элемента. Если ключ уже существует, обновляем значение
    void insert(const Ht_item<TKey, T>& item) {
        Node<TKey, T>* current = head;
        while (current != nullptr) {
            if (current->data.key == item.key) {
                current->data.value = item.value;
                return;
            }
            current = current->next;
        }
        // Вставка в начало списка
        Node<TKey, T>* new_node = new Node<TKey, T>(item);
        new_node->next = head;
        head = new_node;
    }

    // Поиск элемента по ключу
    Ht_item<TKey, T>* find(TKey key) const {
        Node<TKey, T>* current = head;
        while (current != nullptr) {
            if (current->data.key == key) {
                return &(current->data);
            }
            current = current->next;
        }
        return nullptr;
    }

    // Удаление элемента по ключу
    bool remove(TKey key) {
        Node<TKey, T>* current = head;
        Node<TKey, T>* prev = nullptr;

        while (current != nullptr) {
            if (current->data.key == key) {
                if (prev == nullptr) {
                    // Удаление головы списка
                    head = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                return true; // Удаление выполнено
            }
            prev = current;
            current = current->next;
        }
        return false; // Элемент не найден
    }

    // Очистка списка
    void clear() {
        Node<TKey, T>* current = head;
        while (current != nullptr) {
            Node<TKey, T>* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    // Печать всех элементов в списке
    void printAll() const {
        Node<TKey, T>* current = head;
        while (current != nullptr) {
            std::cout << "(" << current->data.key << ", " << current->data.value << ") ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};




// Шаблон класса хеш-таблицы с обработкой коллизий через связные списки
template <class TKey, class T>
class HashTable {
private:
    LinkedList<TKey, T>** items; // Массив указателей на связные списки
    size_t size;      // Количество занятых элементов
    size_t count;     // Общее количество "ведер"

    // Простая хеш-функция
    size_t hashFunction(TKey key) const {
        return static_cast<size_t>(key) % count;
    }

public:
    // Конструктор с параметром count, инициализация массива элементов
    HashTable(int count) : count(count), size(0) {
        items = new LinkedList<TKey, T>* [count];
        for (size_t i = 0; i < count; ++i) {
            items[i] = new LinkedList<TKey, T>();
        }
    }

    // Деструктор
    ~HashTable() {
        for (size_t i = 0; i < count; ++i) {
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

    // Получение количества "ведер"
    int Getcount() const {
        return static_cast<int>(count);
    }

    // Получение значения по ключу
    T getValue(TKey key) const {
        size_t hash = hashFunction(key);
        Ht_item<TKey, T>* item = items[hash]->find(key);
        if (item != nullptr) {
            return item->value;
        }
        else {
            std::cerr << "Key not found!" << std::endl;
            return T(); // Возвращаем значение по умолчанию
        }
    }

    // Получение элемента по ключу (Ht_item)
    T getHT(TKey key) const {
        size_t hash = hashFunction(key);
        Ht_item<TKey, T>* item = items[hash]->find(key);
        if (item != nullptr) {
            return item->value;
        }
        else {
            std::cerr << "Key not found!" << std::endl;
            return T(); // Возвращаем значение по умолчанию
        }
    }

    // Получение размера (количество занятых элементов)
    int Getsize() const {
        return static_cast<int>(size);
    }

    // Проверка, свободен ли индекс (наличие элемента)
    bool indexIsFree(TKey key) const {
        size_t hash = hashFunction(key);
        Ht_item<TKey, T>* item = items[hash]->find(key);
        return (item == nullptr);
    }

    // Вывод значения по ключу
    void print(TKey key) const {
        size_t hash = hashFunction(key);
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
        size_t hash = hashFunction(key);
        bool removed = items[hash]->remove(key);
        if (removed) {
            size--;
        }
        else {
            std::cerr << "Key not found!" << std::endl;
        }
    }
};

*/

/*

template <class TKey, class T>
class HashTable;

// Шаблон класса для элемента хеш-таблицы
template <class TKey, class T>
class Ht_item {
    // Дружественные классы
    template <class U, class V>
    friend class HashTable;

private:
    TKey key;
    T value;

public:
    // Конструктор по умолчанию
    Ht_item() : key(TKey()), value(T()) {}

    // Конструктор с параметрами
    Ht_item(TKey key, const T& value) : key(key), value(value) {}

    Ht_item& operator=(const T& element) {
        this->value = element;
        return *this;
    }
    // Оператор присваивания
   

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

// Шаблон класса хеш-таблицы с обработкой коллизий через связные списки
template <class TKey, class T>
class HashTable {
private:
    LinkedList<Ht_item<TKey, T>>* items; // Массив указателей на связные списки
    size_t size;      // Количество занятых элементов
    size_t count;     // Общее количество "ведер"

    // Простая хеш-функция
    size_t hashFunction(TKey key) const {
        return static_cast<size_t>(key) % count;
    }

public:
    // Конструктор с параметром count, инициализация массива элементов
    HashTable(int count) : count(count), size(0) {
        items = new LinkedList<Ht_item<TKey, T>>[count];
    }

    // Деструктор
    ~HashTable() {
        delete[] items;
    }

    // Вставка элемента
    void insert(TKey key, const T& value) {
        size_t hash = hashFunction(key);
        Ht_item<TKey, T> new_item(key, value);

        // Проверяем, существует ли уже элемент с таким ключом
        T* existing_value = items[hash].find(key);
        if (existing_value == nullptr) {
            size++;
        }

        items[hash].InsertAt(new_item, 0); // Вставляем в начало списка
    }

    // Получение количества "ведер"
    int Getcount() const {
        return static_cast<int>(count);
    }

    // Получение значения по ключу
    T getValue(TKey key) const {
        size_t hash = hashFunction(key);
        T* value = items[hash].find(key);
        if (value != nullptr) {
            return *value;
        }
        else {
            std::cerr << "Key not found!" << std::endl;
            return T(); // Возвращаем значение по умолчанию
        }
    }

    // Получение элемента по ключу (Ht_item)
    T getHT(TKey key) const {
        return getValue(key);
    }

    // Получение размера (количество занятых элементов)
    int Getsize() const {
        return static_cast<int>(size);
    }

    // Проверка, свободен ли индекс (наличие элемента)
    bool indexIsFree(TKey key) const {
        size_t hash = hashFunction(key);
        T* value = items[hash].find(key);
        return (value == nullptr);
    }




    // Вывод значения по ключу
    void print(TKey key) const {
        size_t hash = hashFunction(key);
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
        size_t hash = hashFunction(key);
        bool removed = items[hash].remove(key);
        if (removed) {
            size--;
        }
        else {
            std::cerr << "Key not found!" << std::endl;
        }
    }
};




// Пример использования
int main() {
    std::setlocale(LC_ALL, "Russian");
    // Создаём хеш-таблицу с емкостью 5
    HashTable<int, std::string> ht(5);

    // Вставляем элементы
    ht.insert(1, "Один");
    ht.insert(6, "Шесть");        // Коллизия с ключом 1 (6 % 5 == 1)
    ht.insert(11, "Одиннадцать"); // Коллизия с ключом 1 (11 % 5 == 1)
    ht.insert(2, "Два");
    ht.insert(7, "Семь");         // Коллизия с ключом 2 (7 % 5 == 2)

    // Печать отдельных значений
    ht.print(1);   // Должно вывести "Одиннадцать"
    ht.print(6);   // Должно вывести "Шесть"
    ht.print(11);  // Должно вывести "Одиннадцать"
    ht.print(2);   // Должно вывести "Два"
    ht.print(7);   // Должно вывести "Семь"

    // Удаляем элемент
    // 
   // ht.remove(6);

    ht.print(6);  // Должно вывести "Key not found!"

    // Проверяем размер
    std::cout << "Размер хеш-таблицы: " << ht.Getsize() << std::endl;

    // Печать всех элементов путем перебора всех возможных ключей
    std::cout << "\nПечать всех элементов хеш-таблицы:" << std::endl;
    for (int key = 0; key < ht.Getcount(); ++key) {
        ht.print(key);
    }

    return 0;
}



*/
   

int main() {

    std::setlocale(LC_ALL, "Russian");
    interface();
    return 0;
}




