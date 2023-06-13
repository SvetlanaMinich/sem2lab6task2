#include "hashtable.h"

template<size_t K>
HashTable<K>::HashTable()
{
    table = new Node[K];
    size = 0;
    c1 = 1;
    c2 = 1;
}
template<size_t K>
size_t HashTable<K>::hashFunction(int _key)
{
    return _key%size;
}
template<size_t K>
size_t HashTable<K>::quadraticHashFunction(int _key, int i) {
    return (hashFunction(_key) + c1 * i + c2 * i * i) % size;
}
template<size_t K>
void HashTable<K>::insert(int _key, QString _value)
{
    if(size==K)
    {
        throw std::out_of_range("cannot insert (there is no space in the table)");
    }
    size_t i = hashFunction(_key);
    size_t j = i;
    int step = 1;
    while (table[j].is_used)
    {
        if (table[j].key == _key)
        {
            table[j].value = _value;
            return;
        }
        j = quadraticHashFunction(_key, step++);
        if (j == i)
            throw std::runtime_error("HashTable is full.");
    }
    table[j].key = _key;
    table[j].value = _value;
    table[j].is_used = true;
    size++;
}
template<size_t K>
void HashTable<K>::remove(int _key)
{
    size_t i = hashFunction(_key);
    size_t j = i;
    int step = 1;
    while (table[j].is_used)
    {
        if (table[j].key == _key)
        {
            table[j].value = "";
            table[j].is_used = false;
            size--;
            return;
        }
        j = quadraticHashFunction(_key, step++);
        if (j == i)
            break;
    }
}
template<size_t K>
QString HashTable<K>::search(int _key)
{
    size_t i = hashFunction(_key);
    size_t j = i;
    int step = 1;
    while (table[j].is_used)
    {
        if (table[j].key == _key)
        {
            return table[j].value;
        }
        j = quadraticHashFunction(_key, step++);
        if (j == i)
            break;
    }
    return "";
}









