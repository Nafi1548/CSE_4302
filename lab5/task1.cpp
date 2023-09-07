#include <iostream>
using namespace std;

class Category
{
    string catName;
    int id;
    string productName[5];
    float price[5] = {0};
    float quantity[5] = {0};
    int flag;
    int numOproducts;
    int findIndex(string name)
    {
        if (numOproducts == 0)
            return -1;
        for (int i = 0; i < numOproducts; i++)
        {
            if (name == productName[i])
                return i;
        }
        return -1;
    }

public:
    Category()
    {
        flag = 0;
        numOproducts = 0;
    }
    Category(string name, int pid)
    {
        catName = name;
        id = pid;
        flag = 0;
        int numOproducts = 0;
    }
    void addProduct(string product, float added_quantity, float Price)
    {
        productName[numOproducts] = product;
        price[numOproducts] = Price;
        quantity[numOproducts] = added_quantity;
        numOproducts++;
    }
    void addToInventory(string product_name, float added_quantity)
    {
        int index = findIndex(product_name);
        quantity[index] += added_quantity;
    }
    void purchase(string product_name, int purchased_quantity)
    {
        int index = findIndex(product_name);
        if (index == -1)
            cout << "product not available" << endl;
        else
        {
            if (purchased_quantity > quantity[index])
                cout << "product short" << endl;
            else
                quantity[index] -= purchased_quantity;
        }
    }
    void applyCategoryDiscount(float percent)
    {
        flag = 1;
        for (int i = 0; i < numOproducts; i++)
        {
            price[i] -= price[i] * percent * .001;
        }
    }
    void applyProductDiscount(string product_name, float percent)
    {
        if (flag == 1)
            return;
        int index = findIndex(product_name);
        price[index] = price[index] - price[index] * percent * .001;
    }
    void updatePrice(string product_name, float percent)
    {
        // if(flag == 1) return;
        int index = findIndex(product_name);
        price[index] = price[index] + price[index] * percent * .001;
    }
    float displayInventoryValue(string product_name)
    {
        int index = findIndex(product_name);
        return price[index] * quantity[index];
    }
    void getTotalInventoryValue()
    {
        float total = 0;
        for (int i = 0; i < numOproducts; i++)
        {
            total = price[i] * quantity[i];
        }
        cout << "TotalInventoryValue = " << total << endl;
    }
    ~Category()
    {
        for (int i = 0; i < numOproducts; i++)
        {
            cout << productName[i] << " " << price[i] << " " << quantity[i] << endl;
        }
    }

};

int main()
{
    Category c1, c2;
    c1.addProduct("a", 5, 3000);
    c1.addProduct("b", 5, 3000);
    c1.addProduct("c", 5, 3000);
    c1.addProduct("d", 5, 3000);
    c1.addToInventory("a", 5);
    c1.purchase("a",2);
    c1.applyProductDiscount("b",1.5);
    c1.applyCategoryDiscount(3);
    float a_value = c1.displayInventoryValue("a");
    cout<<a_value<<endl;
    c1.getTotalInventoryValue();
}