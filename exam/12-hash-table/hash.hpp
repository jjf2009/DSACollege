#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <optional>

template <typename K, typename V>
class HashTable {
private:
    // Node for chaining
    struct Node {
        K key;
        V value;
        Node(const K& k, const V& v) : key(k), value(v) {}
    };

    // Entry for open addressing
    struct Entry {
        K key;
        V value;
        bool isDeleted;
        Entry() : isDeleted(false) {}
        Entry(const K& k, const V& v) : key(k), value(v), isDeleted(false) {}
    };

    std::vector<std::list<Node>> chainingTable;
    std::vector<std::optional<Entry>> openTable;

    int capacity;
    int size;
    int hashMethod;        // 1=division, 2=folding, 3=mid-square
    int collisionMethod;   // 1=chaining, 2=linear probing , 

    int hashDivision(const K& key) const;
    int hashFolding(const K& key) const;
    int hashMidSquare(const K& key) const;
    int hash1(const K& key) const;
    int probe(const K& key, int i) const;

public:
    HashTable(int cap, int hMethod, int cMethod);


    void insert(const K& key, const V& value);
    bool search(const K& key, V& value) const;
    bool remove(const K& key);
    void display() const;
};

template <typename K, typename V>
HashTable<K,V>::HashTable(int cap, int hMethod, int cMethod)
    : capacity(cap), size(0), hashMethod(hMethod), collisionMethod(cMethod) {
    chainingTable.resize(capacity);
    openTable.resize(capacity);
}

template <typename K, typename V>
int HashTable<K,V>::hashDivision(const K& key) const {
    return key % capacity;
}

template <typename K, typename V>
int HashTable<K,V>::hashFolding(const K& key) const {
    int half = key / 1000;
    int rest = key % 1000;
    return (half + rest) % capacity;
}

template <typename K, typename V>
int HashTable<K,V>::hashMidSquare(const K& key) const {
    int sq = key * key;
    int mid = (sq / 100) % 1000;
    return mid % capacity;
}

template <typename K, typename V>
int HashTable<K,V>::hash1(const K& key) const {
    if (hashMethod == 1) return hashDivision(key);
    if (hashMethod == 2) return hashFolding(key);
    return hashMidSquare(key);
}

template <typename K, typename V>
int HashTable<K,V>::probe(const K& key, int i) const {
    int h1 = hash1(key);

    if (collisionMethod == 2) {            // Linear probing
        return (h1 + i) % capacity;
    }
    else if (collisionMethod == 3) {       // Quadratic probing
        return (h1 + i*i) % capacity;
    }
    else {                             // Double hashing
        int step = (key % (capacity - 1)) + 1;
        return (h1 + i * step) % capacity;
    }
}

template <typename K, typename V>
void HashTable<K,V>::insert(const K& key, const V& value) {
    int index = hash1(key);

    if (collisionMethod == 1) { // chaining
        for (auto& node : chainingTable[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        chainingTable[index].push_back(Node(key, value));
    }
    else { // open addressing
        int i = 0;
        while (openTable[index].has_value()) {
            index = probe(key, ++i);
        }
        openTable[index] = Entry(key, value);
    }
    size++;
}

// Search
template <typename K, typename V>
bool HashTable<K,V>::search(const K& key, V& value) const {
    int index = hash1(key);

    if (collisionMethod == 1) { // chaining
        for (auto& n : chainingTable[index]) {
            if (n.key == key) {
                value = n.value;
                return true;
            }
        }
    } else { // open addressing
        for (int i = 0; i < capacity; i++) {
            int idx = probe(key, i);
            if (!openTable[idx].has_value())
                return false;
            if (openTable[idx]->key == key) {
                value = openTable[idx]->value;
                return true;
            }
        }
    }
    return false;
}


template <typename K, typename V>
bool HashTable<K,V>::remove(const K& key) {
    int index = hash1(key);

    if (collisionMethod == 1) { // chaining
        for (auto it = chainingTable[index].begin();
             it != chainingTable[index].end(); ++it) {
            if (it->key == key) {
                chainingTable[index].erase(it);
                size--;
                return true;
            }
        }
    } else { // open addressing
        for (int i = 0; i < capacity; i++) {
            int idx = probe(key, i);
            if (!openTable[idx].has_value())
                return false;
            if (openTable[idx]->key == key) {
                openTable[idx].reset();
                size--;
                return true;
            }
        }
    }
    return false;
}


template <typename K, typename V>
void HashTable<K,V>::display() const {
    for (int i = 0; i < capacity; i++) {
        std::cout << i << ": ";
        if (collisionMethod == 1) {
            for (auto& n : chainingTable[i])
                std::cout << "(" << n.key << "," << n.value << ") ";
        } else {
            if (openTable[i].has_value())
                std::cout << "(" << openTable[i]->key << "," << openTable[i]->value << ")";
            else
                std::cout << "Empty";
        }
        std::cout << "\n";
    }
}
