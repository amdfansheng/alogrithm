// 自己写的
// 执行用时： 112 ms , 在所有 C++ 提交中击败了 76.86% 的用户
// 内存消耗： 42.4 MB , 在所有 C++ 提交中击败了 63.09% 的用户
#include <string>
#include <cstdio>

using namespace std;

class Trie {
private:
    struct Node {
        Node *childs[26] = {nullptr}; // 每个链接对应字母表数据集中的一个字母
        bool is_word = false; // 指定节点是对应键的结尾还是只是键前缀。
        char c = 0; // 表示本节点代码的字母，也就是从父节点到本节点的边代表的含义
    };

    Node root_;

public:
    /** Initialize your data structure here. */
    Trie() { }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *pn = &root_;
        for (auto &&c : word) {
            int index = c - 'a';
            if (!pn->childs[index]) pn->childs[index] = new Node();
            pn = pn->childs[index];
            pn->c = c;
        }
        pn->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *pn = &root_;
        for (auto &&c : word) {
            int index = c - 'a';
            if (!pn->childs[index]) return false;
            pn = pn->childs[index];
        }
        return pn->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *pn = &root_;
        for (auto &&c : prefix) {
            int index = c - 'a';
            if (!pn->childs[index]) return false;
            pn = pn->childs[index];
        }
        return true;
    }
};

int main()
{
    Trie* obj = new Trie();
    obj->insert("apple");

    bool param_1 = obj->search("apple");
    printf("%s\n", param_1 ? "true" : "false");

    bool param_2 = obj->search("app");
    printf("%s\n", param_2 ? "true" : "false");

    bool param_3 = obj->startsWith("app");
    printf("%s\n", param_3 ? "true" : "false");

    obj->insert("app");
    bool param_4 = obj->search("app");
    printf("%s\n", param_4 ? "true" : "false");
}
