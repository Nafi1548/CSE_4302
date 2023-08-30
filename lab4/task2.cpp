#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accNum;
    string holderName;
    string accType;
    float currBal;
    float minBal;

public:
    BankAccount(int acc, string holder, string accT, float curr)
    {
        if (accT == "Current" || accT == "Savings")
        {
            accNum = acc;
            holderName = holder;
            if (accT == "Current")
                accType = "Current";
            else
                accType = "Savings";
                    currBal = curr;
            minBal = 8000;
        }
        else
        {
            cout << "error type" << endl;
        }
    }
    void set_num(int acc)
    {
        accNum = acc;
    }
    void set_name(string holder)
    {
        holderName = holder;
    }
    void set_accT(string accT)
    {
        if (accT == "Current" || accT == "Savings")
        {
            if (accT == "Current")
                accType = "Current";
            else
                accType = "Savings";
        }
        else
        {
            cout << "error type" << endl;
        }
    }
    void set_currbal(float curr)
    {
        currBal = curr;
    }
    void display()
    {
        cout << holderName << " " << accNum << ' ' << accType << ' ' << currBal << ' ' << minBal << endl;
    }
    void showBalance()
    {
        cout << currBal << endl;
    }
    void deposit(int value)
    {
        currBal += value;
    }
    void withDrawal(int value)
    {
        if (currBal - value < minBal)
        {
            cout << "cannot witdraw" << endl;
            return;
        }
        currBal -= value;
    }
    void giveInterest()
    {
        float interest = currBal * .03;
        interest = interest - interest * .1;
        currBal += interest;
    }
    void giveInterest(float rate)
    {
        float interest = currBal * rate * .01;
        interest = interest - interest * .1;
        currBal += interest;
    }
    ~BankAccount()
    {
        cout << "Account of " << holderName << " with account no " << accNum << " is destroyed whit a balance of BDT " << currBal << endl;
    }
};

int main()
{
    BankAccount b(13234, "Nafi", "Savings", 12000);
    b.display();
    b.deposit(3000);
    b.display();
    b.withDrawal(1000);
    b.display();
}