class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash(key)
        chain = self.table[index]
        for item in chain:
            if item[0] == key:
                item[1] = value
                return
        chain.append((key, value))

    def find(self, key):
        index = self._hash(key)
        chain = self.table[index]
        for item in chain:
            if item[0] == key:
                return item[1]
        return None

    def delete(self, key):
        index = self._hash(key)
        chain = self.table[index]
        for i, item in enumerate(chain):
            if item[0] == key:
                del chain[i]
                return

    def display(self):
        for i, chain in enumerate(self.table):
            if chain:
                print(f"Index {i}:")
                for item in chain:
                    print(f" Key: {item[0]}, Value: {item[1]}")


# Create a hash table
hash_table = HashTable(10)

# Insert key-value pairs
hash_table.insert("apple", 5)
hash_table.insert("banana", 3)
hash_table.insert("orange", 2)

# Find values by key
print(hash_table.find("apple"))  # Output: 5
print(hash_table.find("banana"))  # Output: 3
print(hash_table.find("pear"))  # Output: None

# Delete key-value pair
hash_table.delete("banana")
print(hash_table.find("banana"))  # Output: None

# Display the hash table
hash_table.display()
