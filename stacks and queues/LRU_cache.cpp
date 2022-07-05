// Implementation of LRU cache using queue and hashmap
# include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value;
    Node *prev, *next;
    
    Node(int k, int val){
        key = k;
        value = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
private:
    Node *head, *tail;
    int capacity;
    unordered_map<int, Node*> hash;
    
public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addToHead(Node *node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void deleteNode(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    int get(int key) {
        if(hash.find(key) == hash.end())
            return -1;

        Node *cur = hash[key];
        int val = cur->value;

        deleteNode(cur);
        addToHead(cur);

        return val;
    }

    void set(int key, int value) {
        if(hash.find(key) != hash.end()) {
            Node *cur = hash[key];
            cur->value = value;
            deleteNode(cur);
            addToHead(cur);

        } else {
            Node *cur = new Node(key, value);
            if(hash.size() < capacity) {
                hash[key] = cur;
                addToHead(cur);
            } else{
                hash.erase(tail->prev->key);
                hash[key] = cur;
                deleteNode(tail->prev);
                addToHead(cur);
            }
        }
    }
};

int main() {
    int capacity = 3;
    LRUCache cache(3);
    cache.set(1,10);
    cache.set(3,10);
    cache.set(2,12);
    cout << "GET 3: " << cache.get(3) << "\n";
    cache.set(4,20);
    cout << "GET 2: " <<  cache.get(2) << "\n";
    cache.set(4,25);
}