#pragma once

#include "histogram.hpp"
#include "Cache.hpp"
#include "test_for_cash.hpp"


void interface() {
    int choice;

    while (true) {
        cout << "\nВыберите опцию:" << endl;
        cout << "1. Интерфейс для гистограммы людей" << endl;
        cout << "2. Интерфейс для гистограммы числа" << endl;
        cout << "3. Интерфейс для кэша" << endl;
        cout << "0. Выход" << endl;

        cout << "Введите номер выбора: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Вы выбрали интерфейс для гистограммы людей." << endl;
            // Здесь может быть код для работы с гистограммой людей
            interface_for_histogram_people();
        }
        else if (choice == 2) {
            cout << "Вы выбрали интерфейс для гистограммы числа." << endl;

            // Дополнительный выбор для работы с множеством Iset
            int isetChoice;
            cout << "Хотите ли вы удалить дубликаты из чисел (использовать множество Iset)? (1 - да, 0 - нет): ";
            cin >> isetChoice;

            // В зависимости от выбора вызываем нужную функцию
            if (isetChoice == 1) {
                cout << "Вы выбрали вывести гистограмму с множеством Iset (с удалением дубликатов)." << endl;
                interface_for_histogram_number(true);  // Вызов с удалением дубликатов
            }
            else if (isetChoice == 0) {
                cout << "Вы выбрали вывести гистограмму отсортированную " << endl;
                interface_for_histogram_number(false);  // Вызов без удаления дубликатов
            }
            else {
                cout << "Неверный выбор. Попробуйте снова." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Вы выбрали интерфейс для проверки работы кэша" << endl;

            // Показать пользователю выбор
            int cacheChoice;
            cout << "Выберите опцию для работы с кэшем:" << endl;
            cout << "1. Тестирование работы кэша" << endl;
            cout << "2. Выполнение операций с кэшем" << endl;
            cout << "Введите номер выбора: ";
            cin >> cacheChoice;

            if (cacheChoice == 1) {
                runCacheTest();
            }
            else if (cacheChoice == 2) {
                runCacheOperations();
            }
            else {
                cout << "Неверный выбор. Попробуйте снова." << endl;
            }
        }
        else if (choice == 0) {
            cout << "Выход из программы..." << endl;
            break;  // Выход из цикла
        }
        else {
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }
}
