class MyHashSet {
private:
    static const int SIZE = 1000;          
    vector<list<int>> table;               

    int hash(int key) {                    
        return key % SIZE;
    }

public:
    MyHashSet() {
        table.resize(SIZE);
    }

    void add(int key) {
        int idx = hash(key);
        for (int val : table[idx]) {
            if (val == key) return;        
        }
        table[idx].push_back(key);         
    }

    void remove(int key) {
        int idx = hash(key);
        table[idx].remove(key);            
    }

    bool contains(int key) {
        int idx = hash(key);
        for (int val : table[idx]) {
            if (val == key) return true;
        }
        return false;
    }
};
