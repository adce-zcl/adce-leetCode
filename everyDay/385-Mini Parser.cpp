// 迷你语法分析器
#include <vector>
#include <string>
using namespace std;
class NestedInteger 
{
  public:
    // 构造函数初始化空的嵌套列表。
      NestedInteger();
      // 构造函数初始化单个整数。
      NestedInteger(int value);
      // 如果此嵌套整数包含单个整数，而不是嵌套列表，则返回true。
      bool isInteger() const;
      //如果嵌套整数包含单个整数，则返回该嵌套整数包含的单个整数
      //如果此NestedInteger包含嵌套列表，则结果未定义
      int getInteger() const;
      // 将此嵌套整数设置为包含单个整数。
      void setInteger(int value);
      // 将此嵌套整数设置为包含嵌套列表，并向其中添加嵌套整数。
      void add(const NestedInteger &ni);
      //返回此NestedInteger包含的嵌套列表（如果它包含嵌套列表）
      //如果此嵌套整数包含单个整数，则结果未定义
      const vector<NestedInteger> &getList() const;
};
class Solution {
public:
    int index = 0;

    NestedInteger deserialize(string s) {
        if (s[index] == '[') {
            index++;
            NestedInteger ni;
            while (s[index] != ']') {
                ni.add(deserialize(s));
                if (s[index] == ',') {
                    index++;
                }
            }
            index++;
            return ni;
        } else {
            bool negative = false;
            if (s[index] == '-') {
                negative = true;
                index++;
            }
            int num = 0;
            while (index < s.size() && isdigit(s[index])) {
                num = num * 10 + s[index] - '0';
                index++;
            }
            if (negative) {
                num *= -1;
            }
            return NestedInteger(num);
        }
    }
};
