// O(1) 时间插入、删除和获取随机元素
#include <unordered_set>
#include <queue>
#include <random>
using namespace std;
class RandomizedSet 
{
private:
    unordered_set<int> se;

public:
    RandomizedSet() 
    {
    }
    
    bool insert(int val) 
    {
        if (se.count(val) == 0)
        {
            se.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) 
    {
        if (se.count(val) == 1)
        {
            se.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() 
    {
        int index = rand() % se.size();
        auto it = se.begin();
        for (int i = 0; i < index; ++i)
        {
            ++it;
        }
        int value = *it;
        //se.erase(it);
        return value;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */