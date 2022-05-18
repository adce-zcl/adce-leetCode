// 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
// 增加删除的时间复杂度为1，说明得用链式结构
// 查找的复杂度为1，说明得用哈希结构
// 因为每次只能加1，或者减1，所以只需要跟链表中相邻得数据比较大小即可
// 规定头部插入，这样，数量最小得在头部，最大得在尾部
#include <string>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <iostream>
using namespace std;

class AllOne 
{
private:
    list<pair<unordered_set<string>, int>> lst;    // 模拟双向链表，保存两类数据，相同数量得字符串保存在同一个集合里
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> nodeits;    // 哈希映射指针
public:
    AllOne() 
    {

    }
    
    void inc(string key)
    {
        // 如果key不在链表中
        if(nodeits.count(key) == 0)
        {
            if(lst.empty()) // 如果链表为空
            {
                unordered_set s{key};
                lst.emplace_front(s, 1);
                nodeits.emplace(key, lst.begin());
            }
            else    // 如果链表不为空,只有两种情况，要么放在第一个集合，要么新建一个集合
            {
                if(lst.begin()->second == 1)    // 加入这个集合
                {
                    lst.begin()->first.emplace(key);
                    nodeits.emplace(key, lst.begin());
                }
                else    // 新建一个集合
                {
                    unordered_set s{key};
                    lst.emplace_front(s, 1);
                    nodeits.emplace(key, lst.begin());
                }
            }
        }
        else    // key存在于链表中,只有两种情况，要么去下一个已经存在得集合，要么去下一个新开辟得集合
        {
            auto current = nodeits[key];
            auto nextit = next(current);
            if(nextit == lst.end())    // 如果下一个集合不存在
            {
                // 把key从当前集合去除
                current->first.erase(key);
                //  新建一个集合
                unordered_set<string> s{key};
                lst.emplace_back(s, current->second + 1);
                nodeits[key] = prev(lst.end());
                if(current->first.empty())
                {
                    lst.erase(current);
                }
            }
            else    // 下一个集合存在，要看下一个集合是不是比它得计数大1，如果是，加入，如果不是，新建集合
            {
                if(nextit->second == current->second + 1)
                {
                    current->first.erase(key);
                    nextit->first.emplace(key);
                    nodeits[key] = nextit;
                    if(current->first.empty())
                    {
                        lst.erase(current);
                    }
                }
                else
                {
                    current->first.erase(key);
                    unordered_set<string> s{key};
                    nodeits[key] = lst.emplace(nextit, s, current->second + 1);
                    if(current->first.empty())
                    {
                        lst.erase(current);
                    }
                }
            }
        }
    }
    
    void dec(string key) 
    {
        auto current = nodeits[key];
        if(current->second == 1)    // 如果计数只有1个，那么直接从集合删除
        {
            current->first.erase(key);
            nodeits.erase(key);
            if(current->first.empty())  // 如果删除之后集合为空，则删除节点
            {
                lst.erase(current);
            }
        }
        else    // 计数大于1,要么移动到前一个集合，要么在前一个位置构造集合
        {
            if(current == lst.begin())  // 如果在第一个集合，则需要新建集合
            {
                current->first.erase(key); 
                unordered_set s{key};
                lst.emplace_front(s, current->second - 1);
                nodeits[key] = lst.begin();
                if(current->first.empty())
                {
                    lst.erase(current);
                }
            }
            else
            {
                auto it = prev(current);
                if(it->second == current->second - 1)   // 直接加入前一个集合
                {
                    current->first.erase(key);
                    it->first.emplace(key);
                    nodeits[key] = it;
                    if(current->first.empty())
                    {
                        lst.erase(current);
                    }
                }
                else    // 需要在前面新建一个集合
                {
                    unordered_set s{key};
                    current->first.erase(key);
                    nodeits[key] = lst.emplace(current, s, current->second - 1);
                    if(current->first.empty())
                    {
                        lst.erase(current);
                    }
                }
            }
        }
    }
    
    string getMaxKey() 
    {
        if(lst.empty())
        {
            return "";
        }
        else
        {
            return *(lst.back().first.begin());
        }
    }
    
    string getMinKey() 
    {
        if(lst.empty())
        {
            return "";
        }
        else
        {
            return *(lst.front().first.begin());
        }
    }
};
int main()
{
    AllOne one;
    one.inc("hello");
    one.inc("hello");
    cout << one.getMaxKey() << endl;
    cout << one.getMinKey() << endl;
    one.inc("leet");
    cout << one.getMaxKey() << endl;
    cout << one.getMinKey() << endl;
    system("pause");
    exit(0);
}