#pragma once

#include "Sequence.h"
#include "sorting.h"
#include "Person.hpp"
#include "HashTable.hpp"


void interface_for_histogram_people();
void interface_for_histogram_number(int change);


template <typename T, typename Getter>
void print_histogram(Sequence<Person<T>>& seq, Getter getter, const std::string& label) {
    int count = seq.GetLength(); // Теперь проблем нет, seq не const

    if (count == 0) {
        std::cout << label << " Histogram: No data available.\n";
        return;
    }

    // Получаем первое значение и определяем min и max
    T first_value = getter(seq.GetElement(0));
    T max_value = first_value;
    T min_value = first_value;

    for (int i = 1; i < count; ++i) {
        T value = getter(seq.GetElement(i));
        if (value > max_value) {
            max_value = value;
        }
        if (value < min_value) {
            min_value = value;
        }
    }

    int interval_size = (max_value - min_value) / 10 + 1;

    std::cout << label << " Histogram:\n";
    for (int i = min_value; i < max_value; i += interval_size) {
        std::cout.width(2);
        std::cout << i << " - " << (i + interval_size) << " | ";

        for (int j = 0; j < count; ++j) {
            T value = getter(seq.GetElement(j));
            if (value >= i && value < (i + interval_size)) {
                std::cout << "x ";
            }
        }

        std::cout << "\n";
    }
}

/*
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
*/

template <typename TKey, typename T>
class HashTable; 
/*
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

*/



inline bool ascendingInt(const int& first, const int& second) {
    return first < second;
}

inline bool descendingInt(const int& first, const int& second) {
    return first > second;
}

inline bool CompareByLastAge(const Person<int>& a, const Person<int>& b) {
    return a.age < b.age;
}


inline bool CompareByLastWeight(const Person<int>& a, const Person<int>& b) {
    return a.weight < b.weight;
}


inline bool CompareByHeight(const Person<int>& a, const Person<int>& b) {
    return a.height < b.height;
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

