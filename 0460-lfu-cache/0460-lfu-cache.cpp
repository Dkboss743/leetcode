class LFUCache {
    struct Node {
        int key, val, freq;
        Node() : key(-1), val(-1), freq(0) {}
        Node(int k,int v) : key(k), val(v), freq(1) {}
    };
    list<Node> head;
    unordered_map<int,list<Node>::iterator> cache;
    unordered_map<int,list<Node>::iterator> freqs;
    int capacity;
    
    void create(int key,int value) {
        cache[key] = freqs[1] = head.emplace(freqs.count(1) ? freqs[1] : head.end(), key,value);
    }
    void evict() {
        if (! head.empty()) {
            auto node = prev(head.end());
            if (freqs[node->freq]->key == node->key)
                freqs.erase(node->freq); // we are the only node
            cache.erase(node->key);
            head.erase(node);
        }
    }
    void bump(list<Node>::iterator& node) {
        bool tail = node == freqs[node->freq++];
        int  freq = node->freq;      
        auto last = next(node);
        
        head.splice(freqs.count(freq) ? freqs[freq] : freqs[freq-1], head,node);
        freqs[freq] = node;
        
        if (tail) {
            if (last != head.end() && last->freq == freq-1)
                freqs[last->freq] = last;
            else
                freqs.erase(freq-1);
        }
    }
public:
    LFUCache(int capacity) { this->capacity = capacity; }
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        bump(it->second);
        return it->second->val;
    }
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second->val = value;
            bump(it->second);
        }
        else if (capacity) {
            if (cache.size() == capacity) evict();
            create(key,value);
        }
    }   
};