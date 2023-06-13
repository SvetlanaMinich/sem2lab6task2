#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <QString>

struct Node
{
    int key;
    QString value;
    bool is_used;
};


class HashTable
{
private:
    Node* table;
    int size;
    int c1, c2;
public:
    HashTable(int _size);
    int hashFunction(int _key);
    int quadraticHashFunction(int _key, int i);
    void insert(int _key, QString _value);
    void remove(int _key);
    QString search(int _key);
};

#endif // HASHTABLE_H
