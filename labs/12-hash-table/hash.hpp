#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <optional>
#include <cmath>
#include <string>
#include <sstream>
enum class HashMethod {
    DIVISION,      // key % capacity
    FOLDING,       // split key in half and add parts
    MID_SQUARE     // square key and take middle digits
};
enum class CollisionResolution {
    NOT_SET,       // Not yet chosen
    CHAINING,      // Separate chaining with linked lists
    LINEAR,        // Linear probing
    QUADRATIC,     // Quadratic probing
    DOUBLE_HASH    // Double hashing
};
template <typename K, typename V>
class HashTable {
private:
    class Node {
      public:
        K key;
        V value;
        Node(const K& k, const V& v) : key(k), value(v) {}
    };   
    struct Entry {
        K key;
        V value;
        bool isDeleted;
        
        Entry() : isDeleted(false) {}
        Entry(const K& k, const V& v) : key(k), value(v), isDeleted(false) {}
    };  
    // For chaining
    std::vector<std::list<Node>> chainingTable;   
    // For open addressing
    std::vector<std::optional<Entry>> openTable;
     int capacity;
    int size;
    HashMethod hashMethod;
    CollisionResolution collisionMethod;
    bool collisionDetected;
    bool collisionMethodChosen;
    // Hash functions
    int hash1(const K& key) const;
    int hash2(const K& key) const;
    int hashDivision(const K& key) const;
    int hashFolding(const K& key) const;
    int hashMidSquare(const K& key) const;
    int probe(const K& key, int i) const;
    // Helper functions
    long long keyToInt(const K& key) const;
    bool isSlotOccupied(int index) const;
    void promptCollisionResolution();
    void convertToOpenAddressing();
    
public:
    HashTable(int cap = 10, HashMethod method = HashMethod::DIVISION);
    void insert(const K& key, const V& value);
    bool search(const K& key, V& value) const;
    bool remove(const K& key);
    void display() const;
    void setHashMethod(HashMethod method);
    std::string getHashMethodName() const;
    std::string getCollisionMethodName() const;
    bool isCollisionMethodChosen() const;
};

// Constructor
template <typename K, typename V>
HashTable<K, V>::HashTable(int cap, HashMethod method) 
    : capacity(cap), size(0), hashMethod(method), 
      collisionMethod(CollisionResolution::NOT_SET),
      collisionDetected(false), collisionMethodChosen(false) {
    chainingTable.resize(capacity);
    openTable.resize(capacity);
}

// Convert key to integer
template <typename K, typename V>
long long HashTable<K, V>::keyToInt(const K& key) const {
    if constexpr (std::is_integral_v<K>) {
        return static_cast<long long>(key);
    } else if constexpr (std::is_same_v<K, std::string>) {
        long long result = 0;
        for (char c : key) {
            result = result * 31 + static_cast<long long>(c);
        }
        return std::abs(result);
    } else {
        std::hash<K> hasher;
        return static_cast<long long>(hasher(key));
    }
}

// Division Method
template <typename K, typename V>
int HashTable<K, V>::hashDivision(const K& key) const {
    long long intKey = keyToInt(key);
    return std::abs(static_cast<int>(intKey % capacity));
}

// Folding Method
template <typename K, typename V>
int HashTable<K, V>::hashFolding(const K& key) const {
    long long intKey = keyToInt(key);
    std::string keyStr = std::to_string(intKey);
    
    int mid = keyStr.length() / 2;
    long long part1 = 0, part2 = 0;
    
    if (mid > 0) {
        part1 = std::stoll(keyStr.substr(0, mid));
    }
    if (mid < keyStr.length()) {
        part2 = std::stoll(keyStr.substr(mid));
    }
    
    long long sum = part1 + part2;
    return std::abs(static_cast<int>(sum % capacity));
}

// Mid-Square Method
template <typename K, typename V>
int HashTable<K, V>::hashMidSquare(const K& key) const {
    long long intKey = keyToInt(key);
    long long squared = intKey * intKey;
    
    std::string squaredStr = std::to_string(squared);
    int len = squaredStr.length();
    
    int digitsNeeded = std::to_string(capacity).length();
    int start = std::max(0, (len - digitsNeeded) / 2);
    int end = std::min(len, start + digitsNeeded);
    
    std::string middleStr = squaredStr.substr(start, end - start);
    long long middle = std::stoll(middleStr);
    
    return std::abs(static_cast<int>(middle % capacity));
}

// Primary hash function
template <typename K, typename V>
int HashTable<K, V>::hash1(const K& key) const {
    switch (hashMethod) {
        case HashMethod::DIVISION:
            return hashDivision(key);
        case HashMethod::FOLDING:
            return hashFolding(key);
        case HashMethod::MID_SQUARE:
            return hashMidSquare(key);
        default:
            return hashDivision(key);
    }
}

// Secondary hash function for double hashing
template <typename K, typename V>
int HashTable<K, V>::hash2(const K& key) const {
    long long intKey = keyToInt(key);
    int h = std::abs(static_cast<int>(intKey % (capacity - 1)));
    return h == 0 ? 1 : h;
}

// Probing function
template <typename K, typename V>
int HashTable<K, V>::probe(const K& key, int i) const {
    int h1 = hash1(key);
    
    switch (collisionMethod) {
        case CollisionResolution::LINEAR:
            return (h1 + i) % capacity;
            
        case CollisionResolution::QUADRATIC:
            return (h1 + i * i) % capacity;
            
        case CollisionResolution::DOUBLE_HASH:
            return (h1 + i * hash2(key)) % capacity;
            
        default:
            return h1;
    }
}

// Check if slot is occupied
template <typename K, typename V>
bool HashTable<K, V>::isSlotOccupied(int index) const {
    if (collisionMethod == CollisionResolution::CHAINING || 
        collisionMethod == CollisionResolution::NOT_SET) {
        return !chainingTable[index].empty();
    } else {
        return openTable[index].has_value() && !openTable[index]->isDeleted;
    }
}

// Prompt user for collision resolution method
template <typename K, typename V>
void HashTable<K, V>::promptCollisionResolution() {
    if (collisionMethodChosen) return;
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "    COLLISION DETECTED!" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Please choose a collision resolution method:" << std::endl;
    std::cout << "1. Chaining (Separate Chaining)" << std::endl;
    std::cout << "2. Linear Probing" << std::endl;
    std::cout << "3. Quadratic Probing" << std::endl;
    std::cout << "4. Double Hashing" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Enter your choice (1-4): ";
    
    int choice;
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            collisionMethod = CollisionResolution::CHAINING;
            std::cout << "\nChaining selected." << std::endl;
            break;
        case 2:
            collisionMethod = CollisionResolution::LINEAR;
            std::cout << "\nLinear Probing selected." << std::endl;
            convertToOpenAddressing();
            break;
        case 3:
            collisionMethod = CollisionResolution::QUADRATIC;
            std::cout << "\nQuadratic Probing selected." << std::endl;
            convertToOpenAddressing();
            break;
        case 4:
            collisionMethod = CollisionResolution::DOUBLE_HASH;
            std::cout << "\nDouble Hashing selected." << std::endl;
            convertToOpenAddressing();
            break;
        default:
            std::cout << "\nInvalid choice! Using Chaining as default." << std::endl;
            collisionMethod = CollisionResolution::CHAINING;
    }
    
    collisionMethodChosen = true;
}

// Convert existing chaining entries to open addressing
template <typename K, typename V>
void HashTable<K, V>::convertToOpenAddressing() {
    std::cout << "Converting existing entries to open addressing..." << std::endl;
    
    for (int i = 0; i < capacity; i++) {
        for (const auto& node : chainingTable[i]) {
            // Find position using probing
            for (int j = 0; j < capacity; j++) {
                int index = probe(node.key, j);
                if (!openTable[index].has_value() || openTable[index]->isDeleted) {
                    openTable[index] = Entry(node.key, node.value);
                    break;
                }
            }
        }
    }
    
    // Clear chaining table
    for (int i = 0; i < capacity; i++) {
        chainingTable[i].clear();
    }
}

// Insert
template <typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value) {
    int index = hash1(key);
    
    // Detect collision
    if (!collisionMethodChosen && isSlotOccupied(index)) {
        // Check if it's an update (same key)
        bool isUpdate = false;
        for (const auto& node : chainingTable[index]) {
            if (node.key == key) {
                isUpdate = true;
                break;
            }
        }
        
        if (!isUpdate) {
            promptCollisionResolution();
        }
    }
    
    // Insert based on collision method
    if (collisionMethod == CollisionResolution::CHAINING || 
        collisionMethod == CollisionResolution::NOT_SET) {
        // Chaining method
        for (auto& node : chainingTable[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        chainingTable[index].push_back(Node(key, value));
        size++;
        
    } else {
        // Open addressing methods
        if (size >= capacity) {
            std::cout << "Hash table is full!" << std::endl;
            return;
        }
        
        for (int i = 0; i < capacity; i++) {
            int idx = probe(key, i);
            
            if (!openTable[idx].has_value() || openTable[idx]->isDeleted) {
                openTable[idx] = Entry(key, value);
                size++;
                return;
            }
            
            if (openTable[idx]->key == key && !openTable[idx]->isDeleted) {
                openTable[idx]->value = value;
                return;
            }
        }
        
        std::cout << "Could not insert key " << key << std::endl;
    }
}

// Search
template <typename K, typename V>
bool HashTable<K, V>::search(const K& key, V& value) const {
    if (collisionMethod == CollisionResolution::CHAINING || 
        collisionMethod == CollisionResolution::NOT_SET) {
        // Chaining method
        int index = hash1(key);
        for (const auto& node : chainingTable[index]) {
            if (node.key == key) {
                value = node.value;
                return true;
            }
        }
        return false;
        
    } else {
        // Open addressing methods
        for (int i = 0; i < capacity; i++) {
            int index = probe(key, i);
            
            if (!openTable[index].has_value()) {
                return false;
            }
            
            if (openTable[index]->key == key && !openTable[index]->isDeleted) {
                value = openTable[index]->value;
                return true;
            }
        }
        return false;
    }
}

// Remove
template <typename K, typename V>
bool HashTable<K, V>::remove(const K& key) {
    if (collisionMethod == CollisionResolution::CHAINING || 
        collisionMethod == CollisionResolution::NOT_SET) {
        // Chaining method
        int index = hash1(key);
        for (auto it = chainingTable[index].begin(); it != chainingTable[index].end(); ++it) {
            if (it->key == key) {
                chainingTable[index].erase(it);
                size--;
                return true;
            }
        }
        return false;
        
    } else {
        // Open addressing methods
        for (int i = 0; i < capacity; i++) {
            int index = probe(key, i);
            
            if (!openTable[index].has_value()) {
                return false;
            }
            
            if (openTable[index]->key == key && !openTable[index]->isDeleted) {
                openTable[index]->isDeleted = true;
                size--;
                return true;
            }
        }
        return false;
    }
}

// Set hash method
template <typename K, typename V>
void HashTable<K, V>::setHashMethod(HashMethod method) {
    hashMethod = method;
}

// Get hash method name
template <typename K, typename V>
std::string HashTable<K, V>::getHashMethodName() const {
    switch (hashMethod) {
        case HashMethod::DIVISION:
            return "Division Method";
        case HashMethod::FOLDING:
            return "Folding Method (Split in Half)";
        case HashMethod::MID_SQUARE:
            return "Mid-Square Method";
        default:
            return "Unknown";
    }
}

// Get collision method name
template <typename K, typename V>
std::string HashTable<K, V>::getCollisionMethodName() const {
    switch (collisionMethod) {
        case CollisionResolution::NOT_SET:
            return "Not Set (Will prompt on first collision)";
        case CollisionResolution::CHAINING:
            return "Separate Chaining";
        case CollisionResolution::LINEAR:
            return "Linear Probing";
        case CollisionResolution::QUADRATIC:
            return "Quadratic Probing";
        case CollisionResolution::DOUBLE_HASH:
            return "Double Hashing";
        default:
            return "Unknown";
    }
}

// Check if collision method is chosen
template <typename K, typename V>
bool HashTable<K, V>::isCollisionMethodChosen() const {
    return collisionMethodChosen;
}

// Display
template <typename K, typename V>
void HashTable<K, V>::display() const {
    std::cout << "\n===== Hash Table =====" << std::endl;
    std::cout << "Hash Method: " << getHashMethodName() << std::endl;
    std::cout << "Collision Resolution: " << getCollisionMethodName() << std::endl;
    std::cout << "=======================" << std::endl;
    
    if (collisionMethod == CollisionResolution::CHAINING || 
        collisionMethod == CollisionResolution::NOT_SET) {
        // Display chaining table
        for (int i = 0; i < capacity; i++) {
            std::cout << "[" << i << "]: ";
            if (chainingTable[i].empty()) {
                std::cout << "Empty";
            } else {
                for (const auto& node : chainingTable[i]) {
                    std::cout << "(" << node.key << "," << node.value << ") -> ";
                }
                std::cout << "NULL";
            }
            std::cout << std::endl;
        }
    } else {
        // Display open addressing table
        for (int i = 0; i < capacity; i++) {
            std::cout << "[" << i << "]: ";
            if (!openTable[i].has_value()) {
                std::cout << "Empty";
            } else if (openTable[i]->isDeleted) {
                std::cout << "DELETED";
            } else {
                std::cout << "(" << openTable[i]->key << "," << openTable[i]->value << ")";
            }
            std::cout << std::endl;
        }
    }
    std::cout << "=======================\n" << std::endl;
}
