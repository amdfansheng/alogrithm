#include <cstdio>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity)
        : cap(capacity) {}

    // 先找hash table，如有，复制到头部，再删除原有位置元素
    int get(int key)
    {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        auto target_it = it->second;
        pair<int, int> n {target_it->first, target_it->second};
        cache.push_front(n);
        cache.erase(target_it);
        mp.erase(key);
        mp.emplace(key, cache.begin());

        printf("after get %d, ", key);
        dump();
        return n.second;
    }

    // 先检查cache里是否已经有相同key， 有则删除，放至头部, 如超出容量则再弹出末尾
    void put(int key, int value)
    {
        auto it = mp.find(key);
        if (it != mp.end()) {
            cache.erase(it->second);
            mp.erase(key);
        }

        pair<int, int> n {key, value};
        cache.push_front(n);
        mp.emplace(key, cache.begin());

        if (cache.size() > cap) {
            mp.erase(cache.back().first);
            cache.pop_back();
        }

        printf("after put %d:%d, ", key, value);
        dump();
    }

    void dump()
    {
        for (auto &&kv : cache) {
            printf("%d:%d, ", kv.first, kv.second);
        }
        printf("mp size: %zu\n", mp.size());
    }

private:
    size_t cap = 0;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
};

int main()
{
    LRUCache cache(2);

    //cache.put(1, 1);
    //cache.put(2, 2);
    //printf("%d\n", cache.get(1)); // 返回  1
    //cache.put(3, 3);    // 该操作会使得密钥 2 作废
    //printf("%d\n", cache.get(2));  // 返回 -1 (未找到)
    //cache.put(4, 4);    // 该操作会使得密钥 1 作废
    //printf("%d\n", cache.get(1));  // 返回 -1 (未找到)
    //printf("%d\n", cache.get(3));  // 返回 3
    //printf("%d\n", cache.get(4));  // 返回 4
    cache.put(2, 1);
    cache.put(2, 2);
    printf("%d\n", cache.get(2)); // 返回  1
    //cache.put(3, 3);    // 该操作会使得密钥 2 作废
    //printf("%d\n", cache.get(2));  // 返回 -1 (未找到)
    //cache.put(4, 4);    // 该操作会使得密钥 1 作废
    //printf("%d\n", cache.get(1));  // 返回 -1 (未找到)
    //printf("%d\n", cache.get(3));  // 返回 3
    //printf("%d\n", cache.get(4));  // 返回 4
}

