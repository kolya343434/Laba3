#include "histogram.hpp"
#include <iostream>
#include <string>
#include <algorithm>

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

    if (!change.empty()) { // Проверяем, что строка не пуста
        char option = toupper(change[0]); // Приводим к верхнему регистру для удобства

        switch (option) {
        case 'Y': {
            print_histogram(persons, [](const Person<int>& p) { return p.age; }, "Age");
            ISet<Person<int>> iset(persons);
            iset.RemoveDuplicates();
           
            persons.Print();  
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
   

    int variant = 0;
    std::cout << "выберите нужный вариант: 1 - age's histogram, 2 - height's histogram, 3 - weight's histogram, 4 - str's histogram\n";
    std::cin >> variant;

    switch (variant) {
    case 1:
        print_histogram(persons,[](const Person<int>& p) { return p.age; },"Age");
        break;
    case 2:
        print_histogram(persons,[](const Person<int>& p) { return p.height; },"Height");
        break;
    case 3:
        print_histogram(persons,[](const Person<int>& p) { return p.weight; },"Weight");
        break;
    case 4:
        print_histogram(persons,[](const Person<int>& p) { return static_cast<int>(p.str[0]); },"First letter of string");
        break;
    default:
        std::cout << "Invalid option\n";
        break;
    }
}




void interface_for_histogram_number(int change) {  
    LinkedList<int> numbers;
    QuickSort<int> sorterr;

    int max_value = -1;
    int min_value = 1000;


    std::cout << "Enter 10 numbers" << '\n';
    for (int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        numbers.Append(num); 
    }

    sorterr.Sort(numbers, ascendingInt);

   
    if (change == 1) {
        ISet<int> set(numbers);  
        set.RemoveDuplicates();  
      
    }

    // Получаем итераторы для начала и конца списка
    auto begin = numbers.GetFirstElement();  
    auto end = numbers.GetLastElement();      

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
            ++it;  
        }

        
        if (!found) {
            std::cout << "- ";
        }

        std::cout << std::endl;
    }

    std::cout << "---------------------------------------" << std::endl;
}
