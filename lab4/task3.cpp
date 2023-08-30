#include <iostream>
#include <cmath>
using namespace std;

class Rectangle{
    private:
        float length,width;
    public:
        Rectangle(){
            length = 1;
            width = 1;
        }
        Rectangle(float len,float wid){
            if(len<1 || len>20){
                cout<<"invalid length"<<endl;
                return;
            }
            if(wid<1 || wid>20){
                cout<<"invalid width"<<endl;
                return;
            }
            length = len;
            width = wid;
        }
        void calPerimeter()
        {
            float ans = (length+width);
            cout<<2*ans<<endl;
        }
        void calArea()
        {
            float ans = length*width;
            cout<<ans<<endl;
        }
        void calDiagonal()
        {
            float ans;
            ans =(length*length+width*width);
            ans = sqrtf(ans);
            cout<<ans<<endl;
        }
        void calAngle()
        {
            float ans =  width/length;
            cout<<atan(ans)*180/3.1416<<"degree"<<endl;
        }
        float getLen()
        {
            return length;
        }
        float getWid()
        {
            return width;
        }
        void setLen(float x)
        {
            if(x<1 || x>20){
                cout<<"invalid input"<<endl;
                return;
            }
            length = x;
        }
        void setWid(float x)
        {
            if(x<1 || x>20){
                cout<<"invalid input"<<endl;
                return;
            }
            width = x;
        }
};

int main()
{
    Rectangle r(-6,31);
    r.calArea();
    r.calAngle();
    r.calDiagonal();
    r.calPerimeter();

}