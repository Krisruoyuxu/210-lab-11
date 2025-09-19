#include <iostream>
using namespace std;

const int recent_20ratings = 20; 

struct Shop{ //Create our struct which is called "Shop" and stores the basic info for it. 
    
    string name;
    int ID;
    double *ratings; // A dynamic array the stores the each rating of the shop

    ~Shop(){
        if (ratings != nullptr){
            delete [] ratings;
        ratings = nullptr;
        }
    }
};

void input_shop(Shop *);
void display_shop(Shop *);

int main(){
     //We only keep the most recent 20 ratings stored in the array of the shop.
    Shop Muji; // Create a shop called "Muji"
    Muji.ratings = new double[recent_20ratings];
    
    input_shop(&Muji);

    return 0;
}

void input_shop(Shop *Muji){
    // Prompt the user to populate his/her shop, finish all the basic info.
    cout << "Input the name for the Shop: "<<endl;
    getline(cin, Muji->name);
    cout << "Provide your shop ID: "<<endl;
    cin >> Muji->ID;
}

void display_shop(Shop *Muji){
    cout << "The name of the shop is: " << Muji->name << endl;
    cout << "Shop ID:# " << Muji->ID << endl;

}