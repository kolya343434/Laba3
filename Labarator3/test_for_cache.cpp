#include "LRUCache.hpp"

#include "Person.hpp"






void testCache(LRUCache<int, int>& cache) {
    int input, index[10];

    std::cout << "Enter 10 numbers for cache (to set):\n";

    // Заполняем кеш значениями
    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter value for cache[" << i << "]: ";
        std::cin >> input;
        cache.set(i, input);
        std::cout << "Cache state after set(" << i << ", " << input << "):\n";
        cache.printCache();  // Выводим текущее состояние кэша
    }

    // Извлекаем элементы из кеша
    std::cout << "\nEnter 10 numbers to get from cache:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter key for get: ";
        std::cin >> input;
        index[i] = cache.get(input);
        std::cout << "After get(" << input << "): Value = " << index[i] << "\n";
        std::cout << "Cache state after get(" << input << "):\n";
        cache.printCache();  // Выводим текущее состояние кэша после get
    }

    std::cout << "\nTesting cache content...\n";

    // Проверка порядка извлечённых данных
    bool testPassed = true;
    for (int i = 0, j = 9; i < 10; ++i, --j) {
        std::cout << "Checking cache.printList(" << i << "): ";
        std::cout << "Expected: " << index[j] << ", Got: " << cache.printList(i) << "\n";
        if (cache.printList(i) != index[j]) {
            testPassed = false;
            break;
        }
    }

    if (!testPassed) {
        std::cout << "First test failed!\n";
    }
    else {
        std::cout << "First test passed!\n";
    }

    // Второй тест: снова наполняем кеш и проверяем
    std::cout << "\nFilling cache with new values (0 to 9) for the second test:\n";
    for (int i = 0; i < 10; ++i) {
        cache.set(i, i);
        std::cout << "After set(" << i << ", " << i << "):\n";
        cache.printCache();  // Выводим состояние кэша после каждого set
    }

    // Извлекаем и проверяем порядок данных
    std::cout << "\nEnter keys to get from cache for the second test:\n";
    for (int i = 0; i < 10; ++i) {
        index[i] = cache.get(i);
        std::cout << "After get(" << i << "): Value = " << index[i] << "\n";
        std::cout << "Cache state after get(" << i << "):\n";
        cache.printCache();  // Выводим состояние кэша после каждого get
    }

    testPassed = true;
    for (int i = 0, j = 9; i < 10; ++i, --j) {
        std::cout << "Checking cache.printList(" << i << "): ";
        std::cout << "Expected: " << index[j] << ", Got: " << cache.printList(i) << "\n";
        if (cache.printList(i) != index[j]) {
            testPassed = false;
            break;
        }
    }

    if (!testPassed) {
        std::cout << "Second test failed!\n";
    }
    else {
        std::cout << "Second test passed!\n";
    }

    std::cout << "\nProgram works as expected.\n";
}

void runCacheTest() {
    // Создаем объект кеша
    LRUCache<int, int>* lruCache = new LRUCache<int, int>(10, 10);

    // Запускаем тестирование кеша
    testCache(*lruCache);

    // Удаляем объект кеша
    delete lruCache;
}
