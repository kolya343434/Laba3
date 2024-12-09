#ifndef IDICTIONARY_HPP_INCLUDED
#define IDICTIONARY_HPP_INCLUDED
#include "HashTable.hpp"

template <class TKey, class T>
class IDictionary
{

public:
    HashTable<TKey, T>* HT;
    IDictionary(int count) : HT(new HashTable<TKey, T>(count)) {}
    IDictionary() : HT(nullptr) {}
    int GetCount()
    {
        return this->HT->Getsize();
    }
    int GetCapacity()
    {
        return this->HT->Getcount();
    }
    T isIndexFree(TKey key)
    {
        return this->HT->getHT(key);
    }

    T Get(TKey key)
    {
        return this->HT->getHT(key);
    }
    Ht_item<TKey, T> GetNode(TKey key)
    {
        return this->HT->getHT(key);
    }
    bool ContainsKey(TKey key)
    {
        if (this->HT.items->key != 0)
        {
            return false;
        }
        else
            return true;
    }
    T print(TKey key)
    {
        return this->Get(key);
    }
    void Add(TKey key, T element)
    {
        this->HT->insert(key, element);
    }
    void Remove(TKey key)
    {
    }
    void generation()
    {
        for (TKey i = 0; i < 10; ++i)
        {
            this->Add(i, rand() % 256);
            ++this->HT->size;
        }
    }
};
#endif