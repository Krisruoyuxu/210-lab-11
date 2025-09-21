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
    // first read the txt file and see how many elements are in it
    int n = 0, temp; 
    ifstream fin("ratings.txt");
    while (fin >> temp) {
        n++; // cout the num of elements
    }
    cout << "There are " << n <<" elements in the file. " <<endl;
    fin.close(); // close the file

    int* all_ratings = new int[n]; // Then add a dynamic array to store all the ratings 
    
    fin.open("ratings.txt"); // reread the file and add all the elements into the array
    for (int i = 0; i < n; i++){
        fin >> *(all_ratings+i);
    }
    fin.close();

    //We only keep the most recent 20 ratings stored in the array of the shop. ASSUME THE LAST 20 ARE THE MOST RECENT 20!
    Shop Muji; // Create a shop called "Muji"
    Muji.ratings = new int[recent_20ratings];

    for (int i = 0; i < recent_20ratings; i++){ // find the most recent 20 ratings in all_ratings, and move them into our ratings
        Muji.ratings[i] = *(all_ratings + (n - i - 1));
    }
    // Note: ASSUME THE LAST 20 ARE THE MOST RECENT 20! So it actually follows the reverse order
    
    input_shop(&Muji);
    display_shop(&Muji);

    delete [] all_ratings; // free the temp array
    
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
    cout << "The most recent 20 ratings are as follow: ";
    for (int i =0; i < recent_20ratings; i++){
        cout << *(Muji ->ratings+i) << " ";
    }
    cout << endl;
}

