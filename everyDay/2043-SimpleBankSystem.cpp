#include <vector>
#include <iostream>
using namespace std;

class Bank 
{
private:
    vector<long long> counts;

public:
    Bank(vector<long long>& balance) 
    {
        counts = balance;
    }
    
    bool transfer(int account1, int account2, long long money) 
    {
        if(account1 > counts.size() || account2 > counts.size() || counts.at(account1-1) < money)
        {
            return false;
        }
        counts.at(account1 - 1) -= money;
        counts.at(account2 - 1) += money;
        return true;
    }
    
    bool deposit(int account, long long money) 
    {
        if(account > counts.size())
        {
            return false;
        }
        counts.at(account - 1) += money;
        return true;
    }
    
    bool withdraw(int account, long long money) 
    {
        if(account > counts.size() || counts.at(account - 1) < money)
        {
            return false;
        }
        counts.at(account - 1) -= money;
        return true;
    }
};