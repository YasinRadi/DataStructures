#include <iostream>

// Table Size
const int TABLE_SIZE = 128;

// HashNode class
struct HashNode {
    public:
        // Key
        int key;

        // Value
        int value;

        HashNode(int key, int value) : key(key), value(value) {};
};

// HashTable class
class HashTable {
    private:
        // Elements storage
        HashNode** table;

        // Current map size
        int size_;

    public:
        HashTable() {
            size_ = 0;
            table = new HashNode*[TABLE_SIZE];
            // Init buckets
            for (int i = 0; i < TABLE_SIZE; i++) {
                table[i] = nullptr;
            }
        };

        ~HashTable() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                if (table[i] != nullptr)
                    delete table[i];
                delete[] table;
            }
        };

        // Hash Function
        std::size_t hashFunc(int key) {
            return key % TABLE_SIZE;
        };

        // Element insert
        void insert(int key, int value) {
            std::size_t hash = hashFunc(key);
            while (table[hash] != nullptr && table[hash]->key != key) {
                hash = hashFunc(++hash);
            }

            if (table[hash] != nullptr) {
                delete table[hash];
            }

            size_++;
            table[hash] = new HashNode(key, value);
        };

        // Element search
        int get(int key) {
            std::size_t hash = hashFunc(key);
            while (table[hash] != nullptr && table[hash]->key != key) {
                hash = hashFunc(++hash);
            }

            return table[hash] != nullptr ?  table[hash]->value : -1;
        };

        // Is key in map
        bool contains(int key) {
            return get(key) != -1;
        };

        // Display map content
        void display(void) {
            for (int i = 0; i < TABLE_SIZE; i++) {
                if (table[i] != nullptr) {
                    std::cout <<
                        "{K: " << table[i]->key <<
                        " V: " << table[i]->value << 
                        "}" << std::endl;
                }
            }
        };

        // Element delete
        void remove(int key) {
            std::size_t hash = hashFunc(key);
            while (table[hash] != nullptr) {
                if (table[hash]->key != key) {
                    hash = hashFunc(++hash);
                    continue;
                }

                break;
            }

            if (table[hash] == nullptr) 
                return;
            
            size_--;
            delete table[hash];
            table[hash] = nullptr;
        };

        // Size of map
        int size() {
            return size_;
        };
};