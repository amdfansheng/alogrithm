#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
    // 传统 BFS
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> deads; // 记录需要跳过的死亡密码
        deads.insert(deadends.begin(), deadends.end());

        unordered_set<string> visited; // 记录已经穷举过的密码，防止走回头路
        visited.emplace("0000");

        queue<string> memo;
        memo.push("0000"); // 从起点开始启动广度优先搜索

        int step{};
        while (!memo.empty()) {
            int sz = memo.size();
            // 将当前队列中的所有节点向周围扩散
            for (int i = 0; i < sz; ++i) { // 这里不能用范围 for，因为循环体中会添加元素
                string str = memo.front();
                memo.pop();
                if (str == target) return step;
                if (deads.count(str)) continue;

                auto adj = buildAdj(str);
                for (auto &&s : adj) { // 将一个节点的未遍历相邻节点加入队列
                    if (visited.count(s)) continue;
                    visited.emplace(s);
                    memo.push(s);
                }
            }
            ++step;
        }
        return -1;
    }

    // 双向 BFS
    int openLock2(vector<string> &deadends, string target)
    {
        unordered_set<string> deads; // 记录需要跳过的死亡密码
        deads.insert(deadends.begin(), deadends.end());

        unordered_set<string> visited; // 记录已经穷举过的密码，防止走回头路

        unordered_set<string> q1;
        unordered_set<string> q2;
        q1.emplace("0000");
        q1.emplace(target);

        int step{};
        while (!q1.empty() && !q2.empty()) {
            unordered_set<string> temp; // 哈希集合在遍历的过程中不能修改，用 temp 存储扩散结果
            for (auto &&str : q1) { // 将 q1 中的所有节点向周围扩散
                if (deads.count(str)) continue;
                if (q2.count(str)) return step;

                visited.emplace(str);

                auto adj = buildAdj(str);
                for (auto &&s : adj) { // 将一个节点的未遍历相邻节点加入队列
                    if (visited.count(s)) continue;
                    temp.emplace(s);
                }
            }
            ++step;

            q1 = q2;
            q2 = temp;
        }
        return -1;
    }

    vector<string> buildAdj(const string &str)
    {
        vector<string> res;
        int sz = str.size();
        for (int i = 0; i < sz; ++i) {
            string str2 = str;
            char c = str2[i];
            if (c == '0') {
                str2[i] = '1'; res.emplace_back(str2);
                str2[i] = '9'; res.emplace_back(str2);
                continue;
            }
            if (c == '9') {
                str2[i] = '0'; res.emplace_back(str2);
                str2[i] = '8'; res.emplace_back(str2);
                continue;
            }
            str2[i] = c + 1; res.emplace_back(str2);
            str2[i] = c - 1; res.emplace_back(str2);
        }
        return res;
    }
};

int main()
{
    Solution s;
    auto adj = s.buildAdj("0000");
    for (auto &&s : adj) {
        printf("%s ", s.data());
    }
    printf("\n");

    vector<string> dead = {"0201","0101","0102","1212","2002"};
    printf("step: %d\n", s.openLock2(dead, "0202"));
}
