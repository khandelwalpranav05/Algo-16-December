#include<iostream>

using namespace std;

class Car{
private:
    int price;
    string name;
public:
    int modelNumber;

    Car(){
        cout<<"Making new Car"<<endl;

        this->name = "Type Car Name";
    }

    Car(string name,int price = 109){
        this->price = price;
        this->name = name;
    }

    void setPrice(int price){
        if(price<0){
            cout<<"Invalid Price"<<endl;
            return;
        }
        this->price = price;
    }

    int getPrice(){
        return this->price;
    }

    string getName(){
        return this->name;
    }

    ~Car(){
        cout<<"Destroying "<<name<<endl;
    }
};

int main(){

    Car c;
    c.modelNumber = 1;
    c.setPrice(-100);
    cout<<c.getPrice()<<endl;

    Car d("Jazz");

    cout<<d.getPrice()<<endl;
    cout<<d.getName()<<endl;

    Car x("Name");

//    Car d;
//    d.speed = 90;
//    d.name = "Honda";
//    d.modelNumber = 2;
//
//    string s1 = "Coding Blocks";
//    string s2 = "Lauchpad";
//
//    cout<<s1.length()<<endl;
//    cout<<s2.length()<<endl;
//
//    string s = "dbfjwbfjwbdj,sbjsbf,jsbvjksvk.snvd.kjwnv.kjsbv.kjsBV.ksJBvk.jsbv.kjsDBvk.sjbvk.sJbv.ksjvbk.dszjvb";
//    cout<< sizeof(s)<<endl;
//    cout<<s.length()<<endl;

//    Car* b = new Car("Honda");

    return 0;
}