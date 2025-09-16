#include <iostream>
using namespace std;

const int recent_20ratings = 20; 

struct Shop{ //Create our struct which is called "Shop" and stores the basic info for it. 
    string name;
    string address;
    double *ratings; // A dynamic array the stores the ratings of the shop

};

void input_shop(Shop *);
void display_shop(Shop *);

int main(){
     //We only keep the most recent 20 ratings stored in the array of the shop.
    Shop *KFC = new Shop[recent_20ratings];
    return 0;
}