#include<iostream>
#include <cstring>
using namespace std;
class Medicine{
    private:
        char generic_name[50];
        char m_name[50];
        double discountPercent = 5 ;
        double unitPrice = 0;
    public:
        void assignName(char name[],char genericName[]){
            strcpy (m_name,name);
            strcpy (generic_name , genericName );
        }
        void assignPrice(double price){
            if(price>0) unitPrice = price;

        }
       void setDiscountPercent(double percent){
            if(percent>=0 && percent<=45)
            {
                discountPercent = percent;
            }
        }
        double getSellingPrice(int nos){
            return ((unitPrice -((discountPercent/100)*unitPrice))*nos);
        }
        void displaay(){
            cout<<m_name<<" ("<<generic_name<<") has a unt price BDT "<<unitPrice<<". Current discount "<<discountPercent<<"%."<< endl;
        }


};

int main(){
    Medicine napa;
    napa.assignName("Napa","Paracetamol");
    napa.assignPrice(-9);
    napa.setDiscountPercent(80);
    cout<<napa.getSellingPrice(10)<<endl;
    napa.displaay();

}