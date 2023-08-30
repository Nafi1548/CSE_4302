#include<iostream>
using namespace std;

class Calculator{
    private:
        int field;
    public:
        Calculator(){
            field = 0;
        }
        Calculator(int val){
            field = val;
        }
        int getValue(){
            return field;
        }
        void setValue(int val){
            field = val;
        }
        void add( int Value ){
            field +=Value;
        }
        void subtract( int Value ){
            field -=Value;
        }
        void multiply( int Value ){
            field *=Value;
        }
        void divideBy( int Value ){
            if(Value == 0)
            {
                cout<<"Error : divide by 0 is undefined."<<endl;
                return;
            }
            field /=Value;
        }
        void clear(){
            field = 0;
        }
        void display(){
            cout<<"Calculator Display - "<<field<<endl;
        }
        ~Calculator() {
            cout<<"Calculator object is destroyed."<<endl;
        }
};

int main(){
    Calculator c1;
    c1.add(10);
    c1.display();
    c1.add(7);
    c1.display();
    c1.multiply(31);
    c1.display();
    c1.subtract(42);
    c1.display();
    c1.divideBy(7);
    c1.display();
    c1.divideBy(0);
    c1.display();
    c1.add(3);
    c1.display();
    c1.subtract(1);
    c1.display();
    c1.clear();
    c1.display();
}