#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
// #include "HashTable.hpp"
#include "IDictionary.hpp"
#include "sequence.hpp"
#include <ctime>





#include "Sequence.h"


#include <cstdlib>

#include "LinkedList.h"
#include "sorting.h"


// #include "HashTable.hpp"

#include "sequence.hpp"

#include "histogram.hpp"







template <typename T, typename Getter>
void print_histogram(Person<T>* persons, int count, Getter getter, const std::string& label) {
    // Инициализация максимального и минимального значений
    T max_value = getter(persons[0]);  // Для лямбда-функции
    T min_value = getter(persons[0]);  // Для лямбда-функции

    // Найдем минимальное и максимальное значение для указанной характеристики
    for (int i = 1; i < count; ++i) {
        T value = getter(persons[i]);
        max_value = std::max(max_value, value);
        min_value = std::min(min_value, value);
    }

    int interval_size = (max_value - min_value) / 10 + 1; // Размер интервала

    // Вывод гистограммы
    std::cout << label << " Histogram:\n";
    for (int i = min_value; i < max_value; i += interval_size) {
        std::cout.width(2);
        std::cout << i << " - " << i + interval_size << " | ";

        int count_in_interval = 0;
        for (int j = 0; j < count; ++j) {
            T value = getter(persons[j]);
            if (value >= i && value < i + interval_size) {
                std::cout << "x ";
                ++count_in_interval;
            }
        }

        std::cout << "\n";
    }
}


template <typename TKey, typename T>
class HashTable; // Предположим, что это ваш класс хеш-таблицы, как в предыдущем коде.

template <typename T, typename Getter>
void print_histogram(HashTable<int, Person<T>>* hash_table, Getter getter, const std::string& label) {
    // Если размер изменился после удаления дубликатов, нужно заново вычислять max_value и min_value
    T max_value = getter(hash_table->getValue(0));
    T min_value = getter(hash_table->getValue(0));

    for (int i = 1; i < hash_table->Getsize(); ++i) {
        T value = getter(hash_table->getValue(i));
        max_value = std::max(max_value, value);
        min_value = std::min(min_value, value);
    }

    int interval_size = (max_value - min_value) / 10 + 1;

    std::cout << label << " Histogram:\n";
    for (int i = min_value; i < max_value; i += interval_size) {
        std::cout.width(2);
        std::cout << i << " - " << i + interval_size << " | ";

        int count_in_interval = 0;
        for (int j = 0; j < hash_table->Getsize(); ++j) {
            T value = getter(hash_table->getValue(j));
            if (value >= i && value < i + interval_size) {
                std::cout << "x ";
                ++count_in_interval;
            }
        }

        std::cout << "\n";
    }
}






#include "HashTable.hpp"


inline bool ascendingInt(const int& first, const int& second) {
    return first < second;
}

inline bool descendingInt(const int& first, const int& second) {
    return first > second;
}

inline bool CompareByLastWeight(const Person<int>& a, const Person<int>& b) {
    return a.weight < b.weight;
}


inline bool CompareByHeight(const Person<int>& a, const Person<int>& b) {
    return a.height < b.height;
}




void interface_for_histogram_people() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Person<int> persons[100];

    for (int i = 0; i < 100; ++i) {
        persons[i].generation();
    }

    int variant = 0;
    std::cout << "Enter needed variant: 1 - age's histogram, 2 - height's histogram, 3 - weight's histogram, 4 - str's histogram\n";
    std::cin >> variant;

    switch (variant) {
    case 1:
        print_histogram(persons, 100, [](const Person<int>& p) { return p.age; }, "Age");
        break;
    case 2:
        print_histogram(persons, 100, [](const Person<int>& p) { return p.height; }, "Height");
        break;
    case 3:
        print_histogram(persons, 100, [](const Person<int>& p) { return p.weight; }, "Weight");
        break;
    case 4:
        print_histogram(persons, 100, [](const Person<int>& p) { return static_cast<int>(p.str[0]); }, "First letter of string");
        break;
    default:
        std::cout << "Invalid option\n";
        break;
    }

}




template <typename T>
class ISet {
public:
    // Конструктор с передачей последовательности
    ISet(Sequence<T>& seq) : sequence(seq) {}

    // Метод для удаления дубликатов
    void RemoveDuplicates() {
        LinkedList<T> unique_elements;  // Новый список для хранения уникальных элементов
        LinkedList<T> seen_elements;    // Список для хранения уже встреченных элементов

        // Итерация по всем элементам последовательности
        for (int i = 0; i < sequence.GetLength(); ++i) {
            T value = sequence.GetElement(i);
            // Проверяем, был ли этот элемент уже добавлен
            bool is_unique = true;
            for (int j = 0; j < seen_elements.GetLength(); ++j) {
                if (seen_elements.GetElement(j) == value) {
                    is_unique = false;
                    break;
                }
            }

            // Если элемент уникален, добавляем его в список уникальных элементов
            if (is_unique) {
                unique_elements.Append(value);
                seen_elements.Append(value);  // Добавляем в список встреченных элементов
            }
        }

        // Очистим исходную последовательность
        sequence.Clear();

        // Добавим уникальные элементы в исходную последовательность
        for (int i = 0; i < unique_elements.GetLength(); ++i) {
            sequence.InsertAt(unique_elements.GetElement(i), i);
        }
    }

private:
    Sequence<T>& sequence;  // Ссылка на последовательность
};















void interface_for_histogram_number(int change) {  // Принимаем флаг Iset как параметр
    LinkedList<int> numbers;
    QuickSort<int> sorterr;

    int max_value = -1;
    int min_value = 1000;

    // Ввод данных
    std::cout << "Enter 10 numbers" << '\n';
    for (int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        numbers.Append(num);  // Добавляем элемент в список
    }

    // Выводим список перед сортировкой для отладки
    std::cout << "Before sorting: ";
    numbers.Print();  // Используем метод Print(), чтобы вывести все элементы списка
    std::cout << std::endl;

    // Сортировка списка
    sorterr.Sort(numbers, ascendingInt);

    // Выводим список после сортировки для отладки
    std::cout << "After sorting: ";
    numbers.Print();  // Используем метод Print(), чтобы вывести отсортированные элементы
    std::cout << std::endl;

    // Если Iset == true, выполняем удаление дубликатов
    if (change == 1) {
        ISet<int> set(numbers);  // Создаём объект ISet для удаления дубликатов
        set.RemoveDuplicates();  // Удаляем дубликаты
        std::cout << "After removing duplicates: ";
        numbers.Print();  // Выводим результат после удаления дубликатов
    }

    // Получаем итераторы для начала и конца списка
    auto begin = numbers.GetFirstElement();  // Итератор на первый элемент
    auto end = numbers.GetLastElement();      // Итератор на "псевдоконец" списка

    std::cout << "Min value: " << numbers.GetFirstElement() << std::endl;
    std::cout << "Max value: " << numbers.GetLastElement() << std::endl;

    // Вычисляем размер интервала для гистограммы
    int interval_size = (numbers.GetLastElement() - numbers.GetFirstElement()) / 10 + 1;
    std::cout << "Interval size: " << interval_size << std::endl;

    // Строим гистограмму
    for (int i = numbers.GetFirstElement(); i < numbers.GetLastElement(); i += interval_size) {
        std::cout.width(2);
        std::cout << i << " - " << i + interval_size << " | ";

        // Маркировка значений в интервале
        bool found = false;

        auto it = 0;  // Итератор на первый элемент
        while ((numbers.GetElement(it) != numbers.GetLastElement()) && (numbers.GetLength() != it)) {  // Пока итератор не достигнет конца
            int value = numbers.GetElement(it); // Получаем значение с помощью GetValue() из элемента
            if ((value >= i) && (value < i + interval_size)) {
                std::cout << "x ";
                found = true;
            }
            ++it;  // Переходим к следующему элементу
        }

        // Если в интервале не было значений, выводим "-"
        if (!found) {
            std::cout << "- ";
        }

        std::cout << std::endl;
    }

    std::cout << "---------------------------------------" << std::endl;
}
