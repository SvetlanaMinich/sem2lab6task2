#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <QString>
#include <iostream>

struct Node
{
    int key;
    QString value;
    bool is_used;
    Node():key(-1),value(""),is_used(false){}
    Node(int _key, QString _value):key(_key),value(_value),is_used(true){}
};

template<size_t K = 2048>
class HashTable
{
private:
    Node* table;
    size_t size;
    int c1, c2;
public:
    HashTable();
    size_t hashFunction(int _key);
    size_t quadraticHashFunction(int _key, int i);
    void insert(int _key, QString _value);
    void remove(int _key);
    QString search(int _key);
};

#endif // HASHTABLE_H
