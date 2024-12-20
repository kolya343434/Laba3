#pragma once

#include "Sequence.h"
#include "sorting.h"
#include "Person.hpp"
#include "HashTable.hpp"


void interface_for_histogram_people();
void interface_for_histogram_number(int change);

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




template <typename U, typename V, typename Getter>
void print_histogram(seq<U>& seq, Getter getter, const std::string& label) {
    int count = seq.getLength();

    if (count == 0) {
        std::cout << label << " Histogram: No data available.\n";
        return;
    }

    // ѕолучаем первое значение и определ€ем min и max
    V first_value = getter(seq.getElement(0));
    V max_value = first_value;
    V min_value = first_value;

    for (int i = 1; i < count; ++i) {
        V value = getter(seq.getElement(i));
        if (value > max_value) {
            max_value = value;
        }
        if (value < min_value) {
            min_value = value;
        }
    }

    // »збежим делени€ на ноль, если все значени€ одинаковы
    int interval_size = (max_value - min_value) / 10 + 1;

    std::cout << label << " Histogram:\n";
    for (V i = min_value; i < max_value; i += interval_size) {
        std::cout.width(2);
        std::cout << i << " - " << (i + interval_size) << " | ";

        bool found = false; // ‘лаг дл€ проверки наличи€ значений в интервале

        for (int j = 0; j < count; ++j) {
            V value = getter(seq.getElement(j));
            if (value >= i && value < (i + interval_size)) {
                std::cout << "x ";
                found = true;
            }
        }

        if (!found) {
            std::cout << "- ";
        }

        std::cout << "\n";
    }
}


template <typename T, typename Getter>
void print_histogram(seq<T>& seq, Getter getter, const std::string& label) {
    int count = seq.GetLength();

    if (count == 0) {
        std::cout << label << " Histogram: No data available.\n";
        return;
    }

    // ѕолучаем первое значение и определ€ем min и max
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

    // »збежим делени€ на ноль, если все значени€ одинаковы
    int interval_size = (max_value - min_value) / 10 + 1;

    std::cout << label << " Histogram:\n";
    for (int i = min_value; i < max_value; i += interval_size) {
        std::cout.width(2);
        std::cout << i << " - " << (i + interval_size) << " | ";

        bool found = false; // ‘лаг дл€ проверки наличи€ значений в интервале

        for (int j = 0; j < count; ++j) {
            T value = getter(seq.GetElement(j));
            if (value >= i && value < (i + interval_size)) {
                std::cout << "x ";
                found = true;
            }
        }

        if (!found) {
            std::cout << "- ";
        }

        std::cout << "\n";
    }
}



















/*
    const Sequence<T>& getSequence() const {
        return sequence;
    }*/
    /*
    // ”даление элемента
    void remove(const T& element) {
        auto it = std::find(sequence.begin(), sequence.end(), element);
        if (it != sequence.end()) {
            sequence.erase(it);
        }
        else {
            throw std::runtime_error("Element not found in the sequence.");
        }
    }*/

    // ѕолучение доступа к последовательности
  
    /*
    // ѕерегрузка оператора [] дл€ доступа к элементам
    const T& operator[](std::size_t index) const {
        if (index >= sequence.()) {
            throw std::out_of_range("Index out of range.");
        }
        return sequence[index];
    }*/
    /*
    // ѕолучение размера последовательности
    std::size_t size() const {
        return sequence.size();
    }
    */
    // ѕроверка на пустоту
   
//};





//класс SortedSequence
//поле: sequence - пос-ть элементов (должна быть всегла отсортирована)
//конструктор по умолчанию
//конструктор, принимающий какой-то массив и из него мы делаем отсортированный
//добавление должно вставл€ть на нужную позицию
//остальной интерфейс как у обычного sequence
//в гистограмме работаем с объектом этого класса




template <typename T, typename Getter>
void print_histogram(Sequence<Person<T>>& seq, Getter getter, const std::string& label) {
    int count = seq.GetLength();

    if (count == 0) {
        std::cout << label << " Histogram: No data available.\n";
        return;
    }

    // ѕолучаем первое значение и определ€ем min и max
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



template <typename T, typename Getter>
void print_histogram(Sequence<T>& seq, Getter getter, const std::string& label) {
    int count = seq.GetLength();

    if (count == 0) {
        std::cout << label << " Histogram: No data available.\n";
        return;
    }

    // ѕолучаем первое значение и определ€ем min и max
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

    // »збежим делени€ на ноль, если все значени€ одинаковы
    int interval_size = (max_value - min_value) / 10 + 1;

    std::cout << label << " Histogram:\n";
    for (int i = min_value; i < max_value; i += interval_size) {
        std::cout.width(2);
        std::cout << i << " - " << (i + interval_size) << " | ";

        bool found = false; // ‘лаг дл€ проверки наличи€ значений в интервале

        for (int j = 0; j < count; ++j) {
            T value = getter(seq.GetElement(j));
            if (value >= i && value < (i + interval_size)) {
                std::cout << "x ";
                found = true;
            }
        }

        if (!found) {
            std::cout << "- ";
        }

        std::cout << "\n";
    }
}










/*
class Numbers {
public:
    Numbers(const LinkedList<int>& nums) : data(nums) {}

    int GetLength() const {
        return static_cast<int>(data.size());
    }

    int GetElement(int index) const {
        if (index >= 0 && index < static_cast<int>(data.Getlength())) {
            return data[index];
        }
        throw std::out_of_range("Index out of range");
    }

private:
    LinkedList<int> data;
};

*/

/*
template <typename T>
void print_histogram(ISortedSequence<T>& seq, const std::string& label) {
    int count = seq.GetLength();

    if (count == 0) {
        std::cout << label << " Histogram: No data available.\n";
        return;
    }

    // ѕолучаем первое значение и определ€ем min и max
    T first_value = seq.GetElement(0);
    T max_value = first_value;
    T min_value = first_value;

    for (int i = 1; i < count; ++i) {
        T value = seq.GetElement(i);
        if (value > max_value) {
            max_value = value;
        }
        if (value < min_value) {
            min_value = value;
        }
    }

    // »збежим делени€ на ноль, если все значени€ одинаковы
    int interval_size = (max_value - min_value) / 10 + 1;

    std::cout << label << " Histogram:\n";

    // ѕодсчЄт количества элементов в каждом интервале
    std::vector<int> frequencies;
    int current_min = min_value;
    for (int i = 0; i < 10; ++i) {
        frequencies.push_back(0);
        current_min += interval_size;
    }

    // «аполнение частот
    for (int i = 0; i < count; ++i) {
        T value = seq.GetElement(i);
        int index = (value - min_value) / interval_size;
        if (index >= 10) index = 9; // ќбработка верхней границы
        frequencies[index]++;
    }

    // ¬ывод гистограммы
    current_min = min_value;
    for (int i = 0; i < 10; ++i) {
        int range_min = current_min;
        int range_max = current_min + interval_size;
        std::cout << range_min << " - " << range_max << " | ";

        if (frequencies[i] > 0) {
            for (int j = 0; j < frequencies[i]; ++j) {
                std::cout << "x";
            }
        }
        else {
            std::cout << "-";
        }

        std::cout << "\n";
        current_min += interval_size;
    }
}
*/

