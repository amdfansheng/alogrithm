#include <chrono>
#include <random>
#include <vector>

template <typename K, typename V>
class SkipList {
  struct Node {
    K key;
    V value;
    size_t level;
    Node *next;
    Node *down;

    Node(size_t level, Node *next, Node *down) 
      : level(level), next(next), down(down) {}
    Node(K key, V value, size_t level, Node *next, Node *down) 
      : key(key), value(value), level(level), next(next), down(down) {}
  };

  Node *head;
  size_t size;
  double p;

  size_t level()
  {
    static std::default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_real_distribution<double> dist(0, 1);
    
    size_t level = 0;
    // <= , 新节点层数最多比当前节点大1
    while (level <= size && dist(gen) < p) level++;
    return level;
  }

public:
    SkipList() : head(new Node(0, nullptr, nullptr)), size(0), p(0.5) {}
    ~SkipList()
    {
      while (head) {
        Node *cur = head;
        head = head->down;
        while (cur) {
          Node *next = cur->next;
          delete cur;
          cur = next;
        }
      }
    }

    size_t get_size() { return size; }
 
    void add(K key, V val)
    {
      size_t lv = level();
      if (lv > head->level) {
        head = new Node(lv, nullptr, head);
      }

      Node *cur = head;
      Node *last = nullptr;
      while (cur) {
        // 在最高层找到下探点
        if (!cur->next || cur->next->key > key) {
          // 下探到新节点的所在层后，开始创建新节点
          if (lv >= cur->level) {
            Node *node = new Node(key, val, cur->level, cur->next, nullptr);
            cur->next = node;
            if (last) last->down = node;
            last = node;
          }
          cur = cur->down;
          continue;
        } else if (cur->next->key == key) {
          cur->next->value = val;
          return;
        }
        cur = cur->next;
      }
      size++;
    }

    V search(K key)
    {
      V ret;
      Node *cur = head;
      while (cur) {
        if (!cur->next || cur->next->key > key) {
          cur = cur->down;
          continue;
        } else if (cur->next->key == key) {
          return cur->next->value;
        }
        cur = cur->next;
      }
      return ret;
    }

    V remove(K key)
    {
      V ret;
      Node *cur = head;

      while (cur) {
        if (!cur->next || cur->next->key >= key) {
          if (cur->next && cur->next->key == key) {
            Node *node = cur->next;
            ret = node->value;
            cur->next = cur->next->next;
            if (!node->level) size--; 
            delete node;
          }
          cur = cur->down;
          continue;
        }
        cur = cur->next;
      }
      return ret;
    }

    bool contains(K key)
    {
      return search(key) != V();
    }

    std::vector<V> range(K start, K end)
    {
      std::vector<V> ret;
      Node *cur = head;
      while (cur) {
        if (!cur->next || cur->next->key > start) {
          cur = cur->down;
          continue;
        } else if (cur->next->key == start) {
          Node *node = cur->next;
          while (node && node->key <= end) {
            ret.push_back(node->value);
            node = node->next;
          }
        }
        cur = cur->next;
      }
      return ret;
    }

    V findMin()
    {
      Node *cur = head;
      if (!cur || !size) return V();
      while (cur->down) cur = cur->down;
      return cur->next->value;
    }

    V findMax()
    {
      Node *cur = head;
      if (!cur || !size) return V();
      while (cur->next->next) cur = cur->next;
      while (cur->down) cur = cur->down;
      while (cur->next->next) cur = cur->next;
      return cur->next->value;
    }
};
