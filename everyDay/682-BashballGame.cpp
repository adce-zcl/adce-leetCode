// 棒球比赛
#include <vector>
#include <string>
#include <numeric>
using namespace std;
class Solution 
{
public:
    int calPoints(vector<string>& ops) 
    {
        vector<int> grade;
        int grade_index = 0;
        for (size_t i = 0; i < ops.size(); i++)
        {
            if(ops[i] == "+")
            {
                grade.push_back(grade[grade_index - 1] + grade[grade_index - 2]);
                ++grade_index;
            }
            else if(ops[i] == "C")
            {
                grade.erase(grade.begin() + grade_index - 1);
                --grade_index;
            }
            else if(ops[i] == "D")
            {
                grade.push_back(grade[grade_index - 1] * 2);
                ++grade_index;
            }
            else
            {
                grade.push_back(atoi(ops[i].c_str()));
                ++grade_index;
            }
        }
        return accumulate(grade.begin(), grade.end(), 0);
    }
};