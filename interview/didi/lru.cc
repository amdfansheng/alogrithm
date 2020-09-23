#include <cstdio>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int cap)
        : cap(cap) {}

    // 先找hash table，有则复制到头部，再删除原有位置
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

        return n.second;
    }

    // 检查是否有相同key，有则删除，放到头部，如超出容量弹出
    void put(int key, int val)
    {
        auto it = mp.find(key);
        if (it != mp.end()) {
            cache.erase(it->second);
            mp.erase(key);
        }

        pair<int, int> n {key, val};
        cache.push_front(n);
        mp.emplace(key, cache.begin());

        if (cache.size() > cap) {
            mp.erase(cache.back().first);
            cache.pop_back();
        }
    }


private:
    list<pair<int, int>> cache; // <key, val>
    unordered_map<int, list<pair<int, int>>::iterator> mp; // <key, cache::iterator>

    size_t cap = 0;
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(10, 10);
    printf("%d\n", cache.get(1));
    cache.put(20, 20);
    printf("%d\n", cache.get(1));
    printf("%d\n", cache.get(10));
}
