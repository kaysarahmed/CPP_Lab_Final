#include <iostream>
using namespace std;

class Person
{
public:

       string name,birthday;
       Person(){};
       Person(string name, string birthday)
       {
           this->name=name;
           this->birthday;
       }
       void viewPerson()
       {
           cout<<"Name : "<<this->name<<endl;
           cout<<"Birtdhay : "<<this->birthday<<endl;
       }
};

class Customer_Category
{
    string gender;
public:
    Customer_Category(){};
    Customer_Category(string gender)
    {
        this->gender=gender;
    }
    void viewCustomerCategory()
    {
        cout<<"Gender : "<<this->gender<<endl;
    }
};

class Customer : public Person
{
    Customer_Category category;
    string city;
    string contact_number;
public:
    Customer(){};
    Customer(string name, string birthday, string city, string contact_number, Customer_Category category) : Person(name, birthday)
    {
        this->city=city;
        this->contact_number=contact_number;
        this->category=category;
    }
    void viewCustomer()
    {
        viewPerson();
        category.viewCustomerCategory();
        cout<<"City : "<<this->city<<endl;
        cout<<"Contact Number : "<<this->contact_number<<endl;
    }
    void viewCustomerName()
    {
        cout<<"Customer Name : "<<this->name<<endl;
    }
    friend void viewDiscountInfo(Customer customer, int noOfPurchases);
};

class ProductCategory
{
    string category;
public:
    ProductCategory(){};
    ProductCategory(string category)
    {
        this->category=category;
    }
    void viewProductCategory()
    {
        cout<<"Product Category : "<<this->category<<endl;
    }
};

class Product
{
    string name,origin;
    int price,quantity;
    ProductCategory category;
public:
    Product(){};
    Product(string name, string origin, int price, int quantity, ProductCategory category)
    {
        this->name=name;
        this->origin=origin;
        this->price=price;
        this->quantity=quantity;
        this->category=category;
    }

    void viewProduct()
    {
        cout<<"Product Name : "<<this->name<<endl;
        category.viewProductCategory();
        cout<<"Origin : "<<this->origin<<endl;
        cout<<"Price : "<<this->price<<endl;
        cout<<"Available Quantity : "<<this->quantity<<endl;
    }

    friend void viewDiscountInfo();
};

void viewDiscountInfo(Customer customer, int noOfPurchases)
{
   if(noOfPurchases>=20)
   {
       cout<<"Customer : "<<customer.name<<endl;
       cout<<"Has 60% discount in all of future purchases"<<endl<<endl;
   }
   else if(noOfPurchases>=15 && noOfPurchases<20)
   {
       cout<<"Customer : "<<customer.name<<endl;
       cout<<"Has 50% discount in all of future purchases"<<endl<<endl;
   }
   else if(noOfPurchases>=10 && noOfPurchases<15)
   {
       cout<<"Customer : "<<customer.name<<endl;
       cout<<"Has 40% discount in all of future purchases"<<endl<<endl;
   }
   else if(noOfPurchases>=5 && noOfPurchases<10)
   {
       cout<<"Customer : "<<customer.name<<endl;
       cout<<"Has 30% discount in all of future purchases"<<endl<<endl;
   }
   else
   {
       cout<<"Customer : "<<customer.name<<endl;
       cout<<"Extremly Sorry Sir, Stay with us for discount"<<endl<<endl;
   }


}

int main()
{
    Customer_Category *customer_categories[3]=
    {
        new Customer_Category("Male"),
        new Customer_Category("Female"),
        new Customer_Category("Children")
    };
    int numberOfCusomers=5;
    Customer *customers[numberOfCusomers]=
    {
        new Customer("Kaysar Ahmed","13-03-1996","Tangail","09876545678",*customer_categories[0]),
        new Customer("Rakib Mia","01-11-1995","Narsingdi","34567898765",*customer_categories[0]),
        new Customer("Najratun Ruba","23-11-1986","Dhaka","34567887659",*customer_categories[1]),
        new Customer("Anika Tahmee","17-02-2000","Chattogram","98765456787",*customer_categories[2]),
        new Customer("Hasan Khan","13-03-1996","Mymensingh","68765345677",*customer_categories[0])
    };
    ProductCategory *product_categories[4]=
    {
        new ProductCategory("Cosmetic"),
        new ProductCategory("Garment"),
        new ProductCategory("Toys"),
        new ProductCategory("Stationary")
    };

    Product *products[5]=
    {
        new Product("Saree","Tangail",3580,12,*product_categories[1]),
        new Product("Helicopter","China",1200,140,*product_categories[2]),
        new Product("Lipstick","United Kingdom",580,50,*product_categories[0]),
        new Product("Pencils","Dhaka",10,350,*product_categories[3]),
        new Product("Shirts","Gazipur",1560,35,*product_categories[2])
    } ;

    cout<<"******   : Customers :    ******"<<endl<<endl;
    for(int i=0;i<numberOfCusomers;i++)
    {
        customers[i]->viewCustomer();
        cout<<endl;
    }

    cout<<"****    _____ Available Products In Store ______     ****"<<endl<<endl;

    for(int i=0;i<5;i++)
    {
      products[i]->viewProduct();
      cout<<endl;
    }
    int purchaseFrequency[5]={12,5,20,10,3};

    cout<<"_____________ Discount Info _____________"<<endl<<endl;

    for(int i=0;i<numberOfCusomers;i++)
    {
        viewDiscountInfo(*customers[i],purchaseFrequency[i]);
    }


}
