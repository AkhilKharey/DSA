#include <iostream>
#include <list>
#include <vector>
#include <utility> // For std::pair

using namespace std; // Allows us to use standard library names without the std:: prefix

// Template class HashMap that can work with any data types for keys (K) and values (V)
template <typename K, typename V>
class HashMap
{
private:
    int bucketCount;                // Number of buckets in the hashmap
    vector<list<pair<K, V>>> table; // Vector of lists to hold chains (buckets)

    // Hash function to calculate the index for a given key
    int hashFunction(K key)
    {
        // Uses the std::hash function to generate a hash value and maps it to bucketCount
        return hash<K>{}(key) % bucketCount;
    }

public:
    // Constructor to initialize the hashmap with a specified number of buckets
    HashMap(int size)
    {
        bucketCount = size;
        table.resize(bucketCount); // Resizes the table to hold 'size' number of lists
    }

    // Insert a key-value pair into the hashmap
    void insert(K key, V value)
    {
        int index = hashFunction(key); // Get the bucket index using the hash function
        auto &chain = table[index];    // Reference to the chain (list) at the bucket index

        // Check if the key already exists in the chain and update the value if found
        for (auto &kv : chain)
        {
            if (kv.first == key)
            {
                kv.second = value; // Update the value for the existing key
                return;
            }
        }

        // If the key doesn't exist, add the new key-value pair
        chain.push_back({key, value});
    }

    // Search for a value by key in the hashmap
    bool search(K key, V &value)
    {
        int index = hashFunction(key); // Get the bucket index using the hash function
        auto &chain = table[index];    // Reference to the chain (list) at the bucket index

        // Iterate through the list to find the key
        for (auto &kv : chain)
        {
            if (kv.first == key)
            {
                value = kv.second; // Set the found value
                return true;       // Return true if key is found
            }
        }
        return false; // Return false if key is not found
    }

    // Delete a key-value pair from the hashmap
    void remove(K key)
    {
        int index = hashFunction(key); // Get the bucket index using the hash function
        auto &chain = table[index];    // Reference to the chain (list) at the bucket index

        // Iterate to find the key and remove it if found
        for (auto it = chain.begin(); it != chain.end(); ++it)
        {
            if (it->first == key)
            {
                chain.erase(it); // Remove the key-value pair
                return;
            }
        }
    }

    // Display the contents of the hashmap
    void display()
    {
        // Iterate through each bucket in the table
        for (int i = 0; i < bucketCount; i++)
        {
            cout << "Bucket " << i << ": ";
            // Print each key-value pair in the bucket
            for (auto &kv : table[i])
            {
                cout << "{" << kv.first << ": " << kv.second << "} -> ";
            }
            cout << "NULL\n"; // Indicate end of the bucket chain
        }
    }
};

int main()
{
    HashMap<string, int> hashMap(7); // Create a hashmap with 7 buckets

    // Insert key-value pairs into the hashmap
    hashMap.insert("apple", 3);
    hashMap.insert("banana", 5);
    hashMap.insert("orange", 7);
    hashMap.insert("grape", 2);
    hashMap.insert("melon", 4);

    // Display the hashmap
    hashMap.display();

    // Search for keys in the hashmap
    int value;
    // Searching for "apple", should find it and print the value
    cout << "Searching for 'apple': " << (hashMap.search("apple", value) ? "Found, Value: " + to_string(value) + "\n" : "Not Found\n");
    // Searching for "pear", should not find it
    cout << "Searching for 'pear': " << (hashMap.search("pear", value) ? "Found, Value: " + to_string(value) + "\n" : "Not Found\n");

    // Delete a key-value pair from the hashmap
    hashMap.remove("grape");
    cout << "After removing 'grape':\n";
    hashMap.display(); // Display the hashmap after removal

    return 0;
}
