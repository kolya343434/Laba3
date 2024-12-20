#include "histogram.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include "ISortedSequence.h"
#include "ISet.hpp"

//отделить интерфейс от логики



void interface_for_histogram_people() {
    srand(static_cast<unsigned int>(time(nullptr)));

    
    LinkedList<Person<int>> persons;

    for (int i = 0; i < 100; ++i) {
        Person<int> p;
        p.generation();
        persons.Append(p);
    }

    std::string variant1;
    std::cout << "вывести? (Y/N)" << std::endl;
    std::cin >> variant1;

    // Преобразуем строку к верхнему регистру для упрощения сравнения
    std::transform(variant1.begin(), variant1.end(), variant1.begin(), ::toupper);

    if (!variant1.empty()) {
        char firstChar = variant1[0];
        switch (firstChar) {
        case 'Y':
            persons.Print();
            break;
        case 'N':
            
            break;
        default:
            std::cout << "Invalid input. Exiting." << std::endl;
            return;
        }
    }
    else {
        std::cout << "Invalid input. Exiting." << std::endl;
        return;
    }

    
    std::cout << "должны ли мы удалять дубликаты: (Y/N): " << std::endl;

    std::string change;
    std::cin >> change;

    auto getAge = [](const Person<int>& person) -> int {
        return person.age;
        };
    auto getheight = [](const Person<int>& person) -> int {
        return person.height;
        };
    auto getweight = [](const Person<int>& person) -> int {
        return person.weight;
        };


    if (!change.empty()) { // Проверяем, что строка не пуста
        char option = toupper(change[0]); // Приводим к верхнему регистру для удобства

        switch (option) {
        case 'Y': {
           // print_histogram(persons, [](const Person<int>& p) { return p.age; }, "Age");
           // IsetSequence<Person<int>> iset(persons);
           // iset.RemoveDuplicates();
            ISet<Person<int>> mySet(persons);
            int variant = 0;
            std::cout << "выберите нужный вариант: 1 - age's histogram, 2 - height's histogram, 3 - weight's histogram\n";
            std::cin >> variant;


            switch (variant) {
            case 1:
                print_histogram<Person<int>, int>(mySet, getAge, "Age");
                //pprint(mySet,"Age");
                break;
            case 2:
                // print_histogram(persons,[](const Person<int>& p) { return p.height; },"Height");
                print_histogram<Person<int>, int>(mySet, getheight, "Height");
                break;
            case 3:
                print_histogram<Person<int>, int>(mySet, getweight, "Weight");

                //  print_histogram(persons,[](const Person<int>& p) { return p.weight; },"Weight");
                break;

            default:
                std::cout << "Invalid option\n";
                break;
            }
           

           // persons.Print();  
            break;
        }
        case 'N': {
         
            std::cout << "Duplicates were not removed." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid input. Please enter 'Y' or 'N'." << std::endl;
            break;
        }
        }
    }
    else {
        std::cout << "No input provided." << std::endl;
    }

   
    ISortedSequence<Person<int>> sortedSeq(persons, CompareByLastAge);
    int variant = 0;
    cout << "without delete Duplicates" << endl;
    std::cout << "выберите нужный вариант: 1 - age's histogram, 2 - height's histogram, 3 - weight's histogram\n";
    std::cin >> variant;

  
    switch (variant) {
    case 1:
        print_histogram<Person<int>, int>(sortedSeq, getAge, "Age");
        //pprint(mySet,"Age");
        break;
    case 2:
       // print_histogram(persons,[](const Person<int>& p) { return p.height; },"Height");
        print_histogram<Person<int>, int>(sortedSeq, getheight, "Height");
        break;
    case 3:
        print_histogram<Person<int>, int>(sortedSeq, getweight, "Weight");

      //  print_histogram(persons,[](const Person<int>& p) { return p.weight; },"Weight");
        break;
    
    default:
        std::cout << "Invalid option\n";
        break;
    }
}



void interface_for_histogram_number(int change) {
    LinkedList<int> numbers;
    
  // QuickSort<int> sorterr;
 //   SortSequence(numbers, ascendingInt);

    std::cout << "Enter 10 numbers:\n";
    for (int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        numbers.Append(num);
    }

   // sorterr.Sort(numbers, ascendingInt);

    

   // ISortedSequence<int> sortedSeq(numbers, ascendingInt);
    auto getValue = [](const int& x) -> int { return x; };
    if (change == 1) {
        ISet<int> mySet(numbers);
        // IsetSequence<int> set(numbers);
         //set.RemoveDuplicates();
         //removeDuplicates(numbers);
        if (numbers.GetLength() == 0) {
            std::cout << "No data available after processing.\n";
            return;
        }

        std::cout << "Min value: " << mySet.getFirstElement() << std::endl;
        std::cout << "Max value: " << mySet.getLastElement() << std::endl;
        print_histogram<int, int, decltype(getValue)>(mySet, getValue, "Numbers");

        std::cout << "---------------------------------------" << std::endl;
    }

    ISortedSequence<int> sortedSeq(numbers, ascendingInt);
    if (numbers.GetLength() == 0) {
        std::cout << "No data available after processing.\n";
        return;
    }

   
  
    
    std::cout << "Min value: " << sortedSeq.getFirstElement() << std::endl;
    std::cout << "Max value: " << sortedSeq.getLastElement() << std::endl;
    print_histogram<int, int, decltype(getValue)>(sortedSeq, getValue, "Numbers");
   // pprint(sortedSeq, "Number");

    std::cout << "---------------------------------------" << std::endl;
}





































/*
#include <iomanip>
void interface_for_histogram_number(int change) {
    LinkedList<int> numbers;

    std::cout << "Введите 10 чисел:\n";
    for (int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        numbers.Append(num);
    }

    // Если требуется изменить данные, например, удалить дубликаты
    if (change == 1) {
        ISet<int> sortedSeq(numbers);
        // Предполагается, что ISet<int> удаляет дубликаты из numbers
        // Например:
        // mySet.RemoveDuplicates();
        // Или другая необходимая обработка
    }
    ISet<int> sortedSeq(numbers);
    // Создаём отсортированную последовательность после обработки
    //ISortedSequence<int> sortedSeq(numbers, ascendingInt);

    if (sortedSeq.GetLength() == 0) {
        std::cout << "Нет данных для отображения после обработки.\n";
        return;
    }

    // Вывод минимального и максимального значений
    std::cout << "Минимальное значение: " << sortedSeq.GetFirstElement() << std::endl;
    std::cout << "Максимальное значение: " << sortedSeq.GetLastElement() << std::endl;

    // Реализация гистограммы внутри функции

    std::cout << "\nГистограмма распределения чисел:\n";
    std::cout << "---------------------------------\n";

    // Поскольку последовательность отсортирована, можно пройтись по ней один раз и подсчитать частоты
    int currentNumber = sortedSeq.GetElement(0);
    int count = 1;

    for (int i = 1; i < sortedSeq.GetLength(); ++i) {
        int num = sortedSeq.GetElement(i);
        if (num == currentNumber) {
            count++;
        }
        else {
            // Вывод текущего числа и соответствующего количества звездочек
            std::cout << std::setw(5) << currentNumber << " | ";
            for (int j = 0; j < count; ++j) {
                std::cout << "*";
            }
            std::cout << " (" << count << ")\n";

            // Обновление текущего числа и сброс счётчика
            currentNumber = num;
            count = 1;
        }
    }

    // Вывод последнего числа
    std::cout << std::setw(5) << currentNumber << " | ";
    for (int j = 0; j < count; ++j) {
        std::cout << "*";
    }
    std::cout << " (" << count << ")\n";

    std::cout << "---------------------------------\n\n";
    std::cout << "---------------------------------------" << std::endl;
}*/


/*
template <typename T>
void pprint(seq<T>& seq, const std::string& label) {
    int count = seq.getLength();

    if (count == 0) {
        std::cout << label << " Histogram: No data available.\n";
        return;
    }

    // Находим min и max
    T first_value = seq.getElement(0);
    T max_value = first_value;
    T min_value = first_value;

    for (int i = 1; i < count; ++i) {
        T value = seq.getElement(i);
        if (value > max_value) {
            max_value = value;
        }
        if (value < min_value) {
            min_value = value;
        }
    }

    // Если все значения одинаковы, то сделаем интервал равным 1
    int diff = max_value - min_value;
    int interval_size = diff / 10 + 1;

    std::cout << label << " Histogram:\n";

    // Инициализируем список частот 10 интервалов нулями
    LinkedList<int> frequencies;
    for (int i = 0; i < 10; ++i) {
        frequencies.Append(0);
    }

    // Заполняем частоты
    for (int i = 0; i < count; ++i) {
        T value = seq.getElement(i);
        int index = (value - min_value) / interval_size;
        if (index >= 10) index = 9; // Обработка верхней границы
        frequencies[index] = frequencies[index] + 1;
    }

    // Выводим гистограмму
    for (int i = 0; i < 10; ++i) {
        int range_min = min_value + i * interval_size;
        int range_max = min_value + (i + 1) * interval_size - 1;
        // Если вы хотите чтобы верхняя граница была включительно без -1, уберите "- 1"
        // это зависит от того, как вы хотите отобразить интервалы

        std::cout << range_min << " - " << range_max << " | ";

        int freq = frequencies[i];
        if (freq > 0) {
            for (int j = 0; j < freq; ++j) {
                std::cout << "x";
            }
        }
        else {
            std::cout << "-";
        }

        std::cout << "\n";
    }
}
*/