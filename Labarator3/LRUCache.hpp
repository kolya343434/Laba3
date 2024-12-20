#ifndef LRUCACHE_HPP_INCLUDED
#define LRUCACHE_HPP_INCLUDED

#include "IDictionary.hpp"
#include "iterator.hpp"
//ƒŒ¡¿¬»“‹ —–¿¬Õ≈Õ»≈ — ŒÀ‹ Œ –¿¡Œ¿“≈“ —  ›ÿŒÃ » ¡≈«
template <class TKey, class TElement>
struct NodeList
{
    TKey key;
    TElement value;
    NodeList* prev = nullptr;
    NodeList* next = nullptr;
    void operator=(NodeList<TKey, TElement>* node)
    {
        key = node->key;
        value = node->value;
        next = node->next;
        prev = node->prev;
    }

    NodeList(TKey key, TElement value) : key(key), value(value), prev(nullptr), next(nullptr) {}
    NodeList() : prev(nullptr), next(nullptr) {}
};


template <class TKey, class TElement>
class LRUCache
{
private:
    NodeList<TKey, TElement>* head = nullptr, * tail = nullptr;
    int size;
    IDictionary<TKey, NodeList<TKey, TElement>*> id;
    IIterator<NodeList<TKey, TElement>*>* it;

public:
    LRUCache(int capacity, int capacity1)
    {
        size = capacity;
        head = nullptr;
        tail = nullptr;
        id.HT = new HashTable<TKey, NodeList<TKey, TElement>*>(capacity1);
    }
    ~LRUCache()
    {
        delete (id.HT);
    }

    TElement printList(TKey key)
    {
        NodeList<TKey, TElement>* node = head;
        for (int i = 0; i < key; ++i)
        {

            node = node->next;
        }
        return node->value;
    }
    IIterator<NodeList<TKey, TElement>*>* getIterator(TKey key)
    {
        IIterator<NodeList<TKey, TElement>*>* iter = new IIterator<NodeList<TKey, TElement>*>(id.isIndexFree(key));
        return iter;
    }
    void set(TKey key, TElement value)
    {

        it = this->getIterator(key);

        if (it == nullptr)
        {
            NodeList<TKey, TElement>* node = it->iter;

            node->value = value;
            remove(node);
            setHead(node);
        }
        else
        {
            NodeList<TKey, TElement>* newNode = new NodeList<TKey, TElement>(key, value);
            if (id.HT->Getsize() >= size)
            {
                it = this->getIterator(tail->key);
                remove(tail);
            }
            setHead(newNode);
            id.Add(key, newNode);
        }
    }

    TElement get(TKey key)
    {
        it = this->getIterator(key);
        if (it->iter != nullptr)
        {
            NodeList<TKey, TElement>* node = it->iter;
            remove(node);
            setHead(node);
            return node->value;
        }
        else
        {
            return -1;
        }
    }
    void remove(NodeList<TKey, TElement>* node)
    {
        if (node->prev != nullptr)
        {
            node->prev->next = node->next;
        }
        else
        {
            head = node->next;
        }
        if (node->next != nullptr)
        {
            node->next->prev = node->prev;
        }
        else
        {
            tail = node->prev;
        }
    }
    void printHT(TKey key)
    {
        this->id.print(key);
    }
    void setHead(NodeList<TKey, TElement>* node)
    {
        node->next = head;
        node->prev = nullptr;

        if (head != nullptr)
        {
            head->prev = node;
        }
        head = node;
        if (tail == nullptr)
        {
            tail = head;
        }
    }

    void printCache() {
        NodeList<TKey, TElement>* node = head;
        if (node == nullptr) {
            std::cout << "Cache is empty." << std::endl;
            return;
        }

        std::cout << "Cache state: " << std::endl;
        while (node != nullptr) {
            std::cout << "Key: " << node->key << ", Value: " << node->value << std::endl;
            node = node->next;
        }
    }
};
#endif