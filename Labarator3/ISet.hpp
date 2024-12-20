#pragma once
#include "Sequence.h"


template <typename T>
class ISet : public seq<T> {
private:
    LinkedList<T> sequence;

    
    void RemoveDuplicates() {
        LinkedList<T> unique_elements;  
        LinkedList<T> seen_elements;    

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

            if (is_unique) {
                unique_elements.Append(value);
                seen_elements.Append(value);
            }
        }

        sequence.Clear();

        // Добавим уникальные элементы в исходную последовательность
        for (int i = 0; i < unique_elements.GetLength(); ++i) {
            // Используем InsertAt для сохранения порядка, если необходимо
            sequence.InsertAt(unique_elements.GetElement(i), i);
           
        }
    }

public:
    
    ISet() {}

    
    template <typename Iterable>
    ISet(Iterable& inputSequence)
    {
        // Добавляем элементы из inputSequence в LinkedList с обеспечением уникальности
        int length = inputSequence.GetLength();
        for (int i = 0; i < length; ++i) {
            append(inputSequence.GetElement(i)); // Используем метод Append для обеспечения уникальности
        }

        // Дополнительно удаляем дубликаты, на случай если были добавлены без проверки
        RemoveDuplicates();
    }

    // Метод для добавления элемента с проверкой на уникальность
    void append( T element) override {
        // Проверяем, существует ли уже элемент в множестве
        for (int i = 0; i < sequence.GetLength(); ++i) {
            if (sequence.GetElement(i) == element) {
                return; // Элемент уже существует, не добавляем
            }
        }

        // Добавляем элемент, если его нет
        sequence.Append(element);
    }

  
    void clear() override {
        sequence.Clear();
    }

    
    T& getFirstElement() override {
        return sequence.GetFirstElement();
    }

    T& getLastElement() override {
        return sequence.GetLastElement();
    }



    T& getElement(int index) override {
        return sequence.GetElement(index);
    }

    
    int getLength() override {
        return sequence.GetLength();
    }


    void print() override {
        for (int i = 0; i < sequence.GetLength(); ++i) {
            std::cout << sequence.GetElement(i) << " ";
        }
        std::cout << std::endl;
    }
};