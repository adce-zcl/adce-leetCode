// 求两个链表的：拥有最小索引和的相同数据。
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;
class LeastIndexSum
{
private:
    vector<string> value;
    

public:
    vector<string>& violence(vector<string> &list1, vector<string> &list2);      // 暴力算法
    vector<string>& hashfunc(vector<string> &list1, vector<string> &list2);      // 哈希算法
};

vector<string>& LeastIndexSum::violence(vector<string> &list1, vector<string> &list2)
{
    multimap<int, string> indexsum;
    for (int i = 0; i < list1.size(); i++)
    {
        for (int j = 0; j < list2.size(); j++)
        {
            if(list1.at(i) == list2.at(j))
            {
                indexsum.insert(pair<int, string>(i + j, list1.at(i)));
                break;
            }
        }
    }
    int index = indexsum.begin()->first;
    for (auto &&i : indexsum)
    {
        if(i.first == index)
        {
            value.push_back(i.second);
        }
        else
        {
            break;
        }
    }
    return value;
}

vector<string>& LeastIndexSum::hashfunc(vector<string> &list1, vector<string> &list2)
{
    unordered_map<string, int> m;
    int minIndex = INT_MAX;
    for (int i = 0; i < list1.size(); i++)
    {
        m.insert(pair<string,int>(list1.at(i), i));
    }
    for (int j = 0; j < list2.size(); j++)
    {
        if(j >= minIndex)
        {
            break;
        }
        if(m.count(list2.at(j))>0)
        {
            int mindex = m[list2.at(j)];
            if(mindex + j < minIndex)
            {
                value.clear();
                value.push_back(list2.at(j));
                minIndex = mindex + j;
            }
            else if(mindex + j == minIndex)
            {
                value.push_back(list2.at(j));
            }
        }
    }
    return value;
}

int main()
{
    LeastIndexSum a;
    vector<string> list1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> value =  a.violence(list1,list2);
    for (auto &&i : value)
    {
        cout << i << endl;
    }
    
    system("pause");
    exit(0);
}