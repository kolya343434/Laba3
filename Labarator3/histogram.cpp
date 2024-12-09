

/*
int main() {
    // Создаем хеш-таблицу с размером 10
    HashTable<int, std::string> ht(10);

    // Вставка данных в хеш-таблицу
    ht.insert(0, "Alice");
    ht.insert(1, "Bob");
    ht.insert(2, "Charlie");

    // Печать значений по ключам
    ht.print(0);  // Ожидается "Alice"
    ht.print(1);  // Ожидается "Bob"
    ht.print(2);  // Ожидается "Charlie"

    // Удаляем элемент с ключом 1 (Bob)
    ht.remove(1);

    // Попытка печати удаленного элемента
    ht.print(1);  // Ожидается сообщение о пустом значении или ошибка, так как Bob был удален

    // Проверка размера хеш-таблицы
    std::cout << "Size of hash table: " << ht.Getsize() << std::endl;

    return 0;
}*/

//рабочий для хистограммы и человека 
/*
int main() {
    srand(time(0));

    // Создаем хеш-таблицу
    HashTable<int, Person<int>> hashTable(10);

    // Заполняем хеш-таблицу случайными людьми
    for (int i = 0; i < 10; ++i) {
        Person<int> person;
        person.generation(); // Генерация случайных данных для каждого человека
        hashTable.insert(i, person); // Добавляем объект в хеш-таблицу
    }

    // Пример: построение гистограммы по возрасту
    auto age_getter = [](const Person<int>& person) {
        return person.getAge();
        };

    print_histogram(&hashTable, age_getter, "Age");

    return 0;
}*/
/*
int main() {
    // Создаём хеш-таблицу с 10 элементами
    HashTable<int, std::string> hashTable(10);

    // Вставляем элементы
    hashTable.insert(0, "Alice");
    hashTable.insert(1, "Bob");
    hashTable.insert(2, "Alice");  // Дубликат
    hashTable.insert(3, "Charlie");

    // Выводим таблицу до удаления дубликатов
    std::cout << "Before RemoveDuplicates:" << std::endl;
    for (int i = 0; i < hashTable.Getcount(); ++i) {
        if (!hashTable.indexIsFree(i)) {
            std::cout << "Key " << i << ": " << hashTable.getValue(i) << std::endl;
        }
    }

    // Удаляем дубликаты
    hashTable.RemoveDuplicates();

    // Выводим таблицу после удаления дубликатов
    std::cout << "\nAfter RemoveDuplicates:" << std::endl;
    for (int i = 0; i < hashTable.Getcount(); ++i) {
        if (!hashTable.indexIsFree(i)) {
            std::cout << "Key " << i << ": " << hashTable.getValue(i) << std::endl;
        }
    }

    return 0;
}*/


///last
/*
void ghghg() {
    srand(time(0));  // Инициализация генератора случайных чисел

    // Создаем хеш-таблицу
    HashTable<int, Person<int>> hashTable(10);

    // Заполняем хеш-таблицу случайными людьми
    for (int i = 0; i < 10; ++i) {
        Person<int> person;
        person.generation();  // Генерация случайных данных для каждого человека
        hashTable.insert(i, person);  // Вставка объекта Person в хеш-таблицу
    }

    // Выводим содержимое до удаления дубликатов
    std::cout << "Before RemoveDuplicates:\n";
    print_histogram(&hashTable, [](const Person<int>& person) { return person.getAge(); }, "Age");

    
    std::cout << "\nAfter RemoveDuplicates:\n";
    print_histogram(&hashTable, [](const Person<int>& person) { return person.getAge(); }, "Age");

   
}
*/




//work histogram but do not delte double
/*
int main() {
    srand(time(0));

    // Создаем хеш-таблицу
    HashTable<int, Person<int>> hashTable(10);

    // Заполняем хеш-таблицу случайными людьми
    for (int i = 0; i < 10; ++i) {
        Person<int> person;
        person.generation(); // Генерация случайных данных для каждого человека
        hashTable.insert(i, person); // Добавляем объект в хеш-таблицу
    }

    // Пример: построение гистограммы по возрасту
    auto age_getter = [](const Person<int>& person) {
        return person.getAge();
        };

    // Строим гистограмму до удаления дубликатов
    std::cout << "Before RemoveDuplicates:\n";
    print_histogram(&hashTable, age_getter, "Age");

    // Удаляем дубликаты
    hashTable.RemoveDuplicates();

    // Строим гистограмму после удаления дубликатов
    std::cout << "\nAfter RemoveDuplicates:\n";
    print_histogram(&hashTable, age_getter, "Age");

    return 0;
}*/
/*
int main() {
    // Создаем хеш-таблицу с размером 10
    HashTable<int, std::string> ht(10);

    // Вставка данных в хеш-таблицу
    ht.insert(0, "Alice");
    ht.insert(1, "Bob");
    ht.insert(2, "Charlie");

    // Печать значений по ключам
    ht.print(0);  // Ожидается "Alice"
    ht.print(1);  // Ожидается "Bob"
    ht.print(2);  // Ожидается "Charlie"

    // Удаляем элемент с ключом 1 (Bob)
   // ht.remove(1);

    // Попытка печати удаленного элемента
   // ht.print(1);  // Ожидается сообщение об ошибке, так как Bob был удален

    // Проверка размера хеш-таблицы
    std::cout << "Size of hash table: " << ht.Getsize() << std::endl;

    return 0;
}
*/
/*
int main() {
   
   // interface_for_histogram_people();
   // interface_for_histogram_number();
    return 0;
}*/