#include <chrono>
#include <random>

template <typename K, typename V>
class SkipList {
  struct Node {
    K key;
    V value;
    size_t level;
    Node *next;
    Node *down;

    Node(size_t level, Node *next, Node *down) 
      : level(level), next(next), level(level) {}
    Node(K key, V value, size_t level, Node *next, Node *down) 
      : key(key), value(value), level(level), next(next), level(level) {}
  };

  Node *head;
  size_t size;
  double p;

  size_t level()
  {
    std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dist(0, 1);
    
    size_t level = 0;
    while (level <= size && dist(gen) < p) level++;
    return level;
  }

  public:
    SkipList() : head(new Node(0, nullptr, nullptr)), size(0), p(0.5) {}


};
