#include<iostream>
using namespace std;

class Medicine{
    private:
        string name;
        string genericName;
        int discountParcent;
        float initialPrice;
        float unitPrice;
        int numOfItem;
        int req;

    public:
        Medicine(){
            unitPrice = 0;
            initialPrice = unitPrice;
            discountParcent = 5;
            numOfItem = 10;
            req = unitPrice*numOfItem;
        }
        Medicine(string Name,string generic,int price)
        {
            name = Name;
            genericName = generic;
            unitPrice = price;
            numOfItem = 10;
            initialPrice = unitPrice;
            discountParcent = 5;
            req = unitPrice*numOfItem;

        }
        double updatedPrice(int percent)
        {
            discountParcent = percent;
            
            unitPrice -= unitPrice*percent*.01;
            return unitPrice;
            
        }
        double getSellingPrice(int nos)
        {
            return nos*(unitPrice - unitPrice*discountParcent*.01);
        }
        double readjustedPrice(int soldItems){
            numOfItem -= soldItems;
            cout<<unitPrice<<req<<endl;
            unitPrice = (req-(soldItems*(unitPrice)))/(numOfItem);
            return unitPrice;
        }
        void resetPrice()
        {
            unitPrice = initialPrice;
        }
        ~ Medicine (){
            cout<<name<<" "<<genericName<<" "<<unitPrice<<" "<<numOfItem<<endl;
        }
};
int main()
{
    Medicine m1("a","ab",10);
    
    m1.updatedPrice(1);
    double sellingPrice = m1.getSellingPrice(3);
    cout<<sellingPrice<<endl;
    m1.readjustedPrice(5);
    // m1.resetPrice();


}