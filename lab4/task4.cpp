#include <iostream>
#include <cmath>
using namespace std;

class Product
{
private:
    string name;
    int id;
    float price;
    float quantity;
    bool availability;
public:
    static float total;
    Product(string nme, int nid)
    {
        name = nme;
        id = nid;
        price = 0;
        quantity = 0;
    }
    Product(string nme, int nid, float prce, float quant)
    {
        name = nme;
        id = nid;
        price = prce;
        quantity = quant;
        total = price*quantity;
    }
    void set_name(string nme) { name = nme; }
    void set_id(int nid) { id = nid; }
    void set_price(float prce) { 
        total-= price*quantity;
        price = prce;
        total+= price*quantity;

        }
    void set_quantity(float quant) {
        total-= price*quantity;
         quantity = quant;
         total-= price*quantity; }

    int get_id() { return id; }
    string get_name() { return name; }
    float get_price() { return price; }
    float get_quantity() { return quantity; }

    void addToInventory(int added_quantity)
    {
        quantity += added_quantity;
    }
    bool isAvailable()
    {
        if (quantity != 0)
            availability = true;
        return availability;
    }
    void purchase(int purchased_quantity)
    {
        if (quantity - purchased_quantity >= 0)
        {
            quantity -= purchased_quantity;
        }
        else
        {
            cout << "not avaliable" << endl;
        }
    }
    void updatePrice(int percent)
    {
        price += price * percent * .01;
    }
    void displayInventoryValue()
    {
        cout << "inventory value of " << name << " is " << quantity * price<<endl;
    }
    void displayDetails(){
    cout<<name<<' '<<id<<' '<<price<<' '<<quantity<<endl;
    }
    void displayTotalInventoryValue(){
        cout<<total<<endl;
    }

}; 
float Product::total = 0;
int main()
{
    Product p1("p1",2100,30.5,25),p2("p2",2110,20.5,25),p3("p3",200,304.5,25);
    p1.displayDetails();
    p1.displayInventoryValue();
    
    p1.displayTotalInventoryValue();
    p2.displayTotalInventoryValue();
}