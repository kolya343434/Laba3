#include "histogram.hpp"
#include <iostream>
#include <string>
#include <algorithm>

void interface_for_histogram_people() {

  
    srand(static_cast<unsigned int>(time(nullptr)));


    Person<int> persons[100];


    for (int i = 0; i < 100; ++i) {
        persons[i].generation();
    
    }

    std::string variant1;
    std::cout << "Should we print people? (Yes/No)" << std::endl;
    std::cin >> variant1;

    // Преобразуем строку к верхнему регистру для упрощения сравнения
    std::transform(variant1.begin(), variant1.end(), variant1.begin(), ::toupper);

    if (!variant1.empty()) {
        char firstChar = variant1[0];
        switch (firstChar) {
        case 'Y':
            for (int i = 0; i < 100; ++i) {
                persons[i].print();
            }
            break;
        case 'N':
            // Не делаем ничего
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
