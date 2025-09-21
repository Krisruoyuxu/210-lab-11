#include <iostream>
#include <fstream> // I add this because this program include "File Input & Output" this week as practise
using namespace std;

const int recent_20ratings = 20; 

struct Shop{ //Create our struct which is called "Shop" and stores the basic info for it. 
    
    string name;
    int ID;
    int *ratings; // A dynamic array the stores the each rating of the shop, from 1-5, bad to great

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
    Muji.ratings = new int[recent_20ratings];
    ifstream fin("ratings.txt"); // read the txt file that stores the ratings
    if (!fin) {
    cerr << "Cannot open ratings.txt\n";
    return 1; // exit
}
    for (int i = 0; i < recent_20ratings; i++){  // traverse the file and add the first 20 elements into the array 
        fin >> Muji.ratings[i];
    }
    
    input_shop(&Muji);
    display_shop(&Muji);

    for ()
        fin >> Muji.ratings[i]; // read the last 20 elements in the file(that represents the new 20 ratings
    // and display it agian
    display_shop(&Muji);
    
    fin.close(); // close the file

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
    cout << "The ratings are as follow: ";
    for (int i =0; i < recent_20ratings; i++){
        cout << *(Muji ->ratings+i) << " ";
    }
    cout << endl;
}

