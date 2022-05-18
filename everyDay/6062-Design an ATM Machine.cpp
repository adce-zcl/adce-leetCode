// 设计一个 ATM 机器
#include <vector>
using namespace std;
class ATM 
{
private:
    
    long long num_20;
    long long num_50;
    long long num_100;
    long long num_200;
    long long num_500;
    

public:
    ATM():num_20(0), num_50(0), num_100(0), num_200(0), num_500(0) 
    {
        
    }
    
    void deposit(vector<int> banknotesCount) 
    {
        num_20 += banknotesCount.at(0);
        num_50 += banknotesCount.at(1);
        num_100 += banknotesCount.at(2);
        num_200 += banknotesCount.at(3);
        num_500 += banknotesCount.at(4);
    }
    
    vector<int> withdraw(int amount) 
    {
        vector<int> result{0,0,0,0,0};
        while (true)
        {
            while (amount >= 500 && num_500 > 0)
            {
                int n = amount / 500;
                if (num_500 >= n)
                {
                    num_500 -= n;
                    amount -=  n * 500;
                    result.at(4) += n;
                }
                else
                {
                    amount -= num_500 * 500;
                    result.at(4) += num_500;
                    num_500 = 0;
                }
                
            }
            while (amount >= 200 && num_200 > 0)
            {
                int n = amount / 200;
                if (num_200 >= n)
                {
                    num_200 -= n;
                    amount -=  n * 200;
                    result.at(3) += n;
                }
                else
                {
                    amount -= num_200 * 200;
                    
                    result.at(3) += num_200;
                    num_200 = 0;
                }
            }
            while (amount >= 100 && num_100 > 0)
            {
                int n = amount / 100;
                if (num_100 >= n)
                {
                    num_100 -= n;
                    amount -=  n * 100;
                    result.at(2) += n;
                }
                else
                {
                    amount -= num_100 * 100;
                    result.at(2) += num_100;
                    num_100 = 0;
                }
            }
            while (amount >= 50 && num_50 > 0)
            {
                int n = amount / 50;
                if (num_50 >= n)
                {
                    num_50 -= n;
                    amount -=  n * 50;
                    result.at(1) += n;
                }
                else
                {
                    amount -= num_50 * 50;
                    result.at(1) += num_50;
                    num_50 = 0;
                }
            }
            while (amount >= 20 && num_20 > 0)
            {
                int n = amount / 20;
                if (num_20 >= n)
                {
                    num_20 -= n;
                    amount -=  n * 20;
                    result.at(0) += n;
                }
                else
                {
                    amount -= num_20 * 20;
                    result.at(0) += num_20;
                    num_20 = 0;
                }
            }
            
            if (amount == 0)
            {
                break;
            }
            else
            {
                num_20 += result.at(0);
                num_50 += result.at(1);
                num_100 += result.at(2);
                num_200 += result.at(3);
                num_500 += result.at(4);
                result.clear();
                result.push_back(-1);
                break;
            }
        }
        return result;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */