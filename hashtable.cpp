#include "hashtable.h"

HashTable::HashTable(int _size)
{
    table = new Node[_size];
    size = _size;
    c1 = 1;
    c2 = 1;
}
int HashTable::hashFunction(int _key)
{
    return _key%size;
}
int HashTable::quadraticHashFunction(int _key, int i) {
    return (hashFunction(_key) + c1 * i + c2 * i * i) % size;
}
void HashTable::insert(int _key, QString _value)
{
    int index = hashFunction(_key);
    int i = 1;
    while (table[index].value!="") {
        index = quadraticHashFunction(_key, i);
        i++;
    }
    table[index].key = _key;
    table[index].value = _value;
}
void HashTable::remove(int _key)
{
    int index = hashFunction(_key);
    int i = 1;
    while (table[index].value!="") {
        if (table[index].key == _key) {
            table[index].key = -1;  // Помечаем удаленный элемент
            table[index].value = "";  // Очищаем значение
            return;
        }
        index = quadraticHashFunction(_key, i);
        i++;
    }
}
QString HashTable::search(int _key)
{
    int index = hashFunction(_key);
    int i = 1;
    while (table[index].value!="") {
        if (table[index].key == _key) {
            return table[index].value;
        }
        index = quadraticHashFunction(_key, i);
        i++;
    }
    return "";
}









