#include<iostream>
using namespace std;
class Time{
    private:
        int hour;
        int min;
        int sec;
    public:
        int hours(){return hour;}
        int minutes(){return min;}
        int seconds(){return sec;}
        void reset(int h, int m, int s)
        {
            hour=(h + m/60)%24;
            min=(m + s/60)%60;
            sec=s%60 ;
        }
        void advance(int h, int m, int s)
        {
            hour = (hour + h + (min + m + (sec+s)/60)/60)%24;
            min = (min + m + (sec+s)/60)%60;
            sec = (sec+s)%60;
        }
        void print(){
            cout<<hour<<':'<<min<<':'<<sec<<endl;
        }
};

int main()
{
    Time time1;
    time1.reset(24,100,100);
    time1.print();

    time1.advance(3,100,100);
    time1.print();
}
