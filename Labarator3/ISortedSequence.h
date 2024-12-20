#pragma once

#include "Sequence.h"
#include <iostream>
#include "histogram.hpp"




template <typename T>
class ISortedSequence : public seq<T> {
private:
    LinkedList<T> sequence; 
    bool (*comp)(const T& first, const T& second); 

    void sortSequence() {
        QuickSort<T> sorter;
        sorter.Sort(sequence, comp);
    }

public:
   
    ISortedSequence() : comp(nullptr) {}

    // Конструктор, принимающий произвольную последовательность и функцию сравнения
    template <typename Iterable>
    ISortedSequence(Iterable& inputSequence, bool (*precedes)(const T& first, const T& second)) {
        comp = precedes;
        int length = inputSequence.GetLength();
        for (int i = 0; i < length; ++i) {
            sequence.Append(inputSequence.GetElement(i)); 
        }
        sortSequence();
    }

    
    void append(T element) override {
        sequence.Append(element);
        sortSequence();
    }

    
    int getLength()  override {
        return sequence.GetLength();
    }

    T& getElement(int index) override {
        return sequence[index];
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

    void print() override {
        for (int i = 0; i < sequence.GetLength(); ++i) {
            std::cout << sequence[i] << " ";
        }
        std::cout << std::endl;
    }
};





















/*
template <typename T>
class ISortedSequence : public Sequence<T> {
    
private:
    LinkedList<T> sequence;
    bool (*comp)(const T& first, const T& second);

    void sortSequence() {
        QuickSort<T> sorter;
        sorter.Sort(sequence, comp);
    }

public:
    ISortedSequence() : comp(nullptr) {}

    // Конструктор, принимающий произвольную последовательность
    template <typename Iterable>
    ISortedSequence(Iterable& inputSequence, bool (*precedes)(const T& first, const T& second)) {
        comp = precedes;
        int length = inputSequence.GetLength();
        for (int i = 0; i < length; ++i) {
            sequence.Append(inputSequence[i]);
        }
        sortSequence();
    }

    void Append(T element) override {
        sequence.Append(element);
        sortSequence();
    }

    int GetLength() override {
        return sequence.GetLength();
    }

    T& GetElement(int index) override {
        return sequence[index];
    }

    void Clear() override {
        sequence.Clear();
    }

    T& GetFirstElement() override {
        return sequence.GetFirstElement();
    }

    T& GetLastElement() override {
        return sequence.GetLastElement();
    }

    // Заглушки для остальных методов
    void InsertAt(T item, int index) override {
        // Заглушка: метод ничего не делает
    }

    void Union(Sequence<T>* list) override {
        // Заглушка: метод ничего не делает
    }

    void Swap(T& a, T& b) override {
        // Заглушка: метод ничего не делает
    }

    void Set(int index, T value) override {
        // Заглушка: метод ничего не делает
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        return nullptr; // Заглушка: возвращает nullptr
    }

    void Prepend(T item) override {
        // Заглушка: метод ничего не делает
    }

    typename Sequence<T>::Iterator* ToBegin() override {
        return nullptr; // Заглушка: возвращает nullptr
    }

    typename Sequence<T>::Iterator* ToEnd() override {
        return nullptr; // Заглушка: возвращает nullptr
    }
};
*/
/*
template <typename T>
class ISortedSequence  {
private:
    LinkedList<T> sequence;
    bool (*comp)(const T& first, const T& second);


    void sortSequence() {
        QuickSort<T> sorter;
        sorter.Sort(sequence, comp);
    }

public:

    ISortedSequence() : comp(nullptr) {}

    // Конструктор, принимающий произвольную последовательность
    template <typename Iterable>
    ISortedSequence(Iterable& inputSequence, bool (*precedes)(const T& first, const T& second)) {
        // Инициализируем компаратор внутри тела конструктора
        comp = precedes;

        // Получаем длину последовательности
        int length = inputSequence.GetLength();
        for (int i = 0; i < length; ++i) {
            sequence.Append(inputSequence[i]);
        }

        sortSequence(); // Сортируем после добавления всех элементов
    }
    // Метод для добавления элемента с автоматической сортировкой
    void Append(const T& element) {
        sequence.Append(element);
        sortSequence();
    }


    const LinkedList<T>& getSequence() {
        return sequence;
    }

    /*
     bool Empty()  {
         return sequence.GetLength() == 0;
     }*/
/*

    int GetLength() {
        return sequence.GetLength();
    }


    void Print() {
        for (size_t i = 0; i < sequence.GetLength(); ++i) {
            std::cout << sequence[i] << " ";
        }
        std::cout << std::endl;
    }


    T& GetElement(int index) {
        return sequence[index];
    }

    typename LinkedList<T>::Iterator ToEnd() {
        return sequence.end();
    }

    typename LinkedList<T>::Iterator ToBegin() {
        return sequence.begin();
    }

    void Clear() {
        sequence.Clear();
    }

    // Получение первого элемента
    T& GetFirstElement() {
        return sequence.GetFirstElement();
    }

    // Получение последнего элемента
    T& GetLastElement() {
        return sequence.GetLastElement();
    }

};

*/