#define hly "\033[3;43;30m"
#define hlg "\033[3;42;30m"
#define fin "\033[0m"
#include <iostream>
#include <fstream>
#include <string>
#include "slot.cpp"
using namespace std;
ofstream fout("debug.out");
struct item{
    string item_string;
    bool start_hl = false, stop_hl = false;
}a[4][6];
int credit = 5;
int bet = 5;
int ai,aj;
int main(int argc, char *argv[]){
    cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n";
    srand((unsigned) time(NULL));

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 5; j++){
            a[i][j].item_string = slot_random_item();
        }
    }
    a[1][5].stop_hl = true;
    a[2][5].stop_hl = true;
    a[3][5].stop_hl = true;
    for(int i = 1; i <= 3; i++){
        for(int j = 2; j <= 5; j++){
            if(a[i][j].item_string != "😞" && a[i][j].item_string == a[i][j-1].item_string){
                a[i][j-1].start_hl = true;
            }else{
                if(j >= 3){
                    if(a[i][j-1].item_string != a[i][j].item_string){
                        a[i][j-1].stop_hl = true;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= 3; i++){
        cout << "| ";
        int no_of_items = 1;
        for(int j = 1; j <= 5; j++){
            if(a[i][j].start_hl){
                cout << hly;
            }
            cout << a[i][j].item_string;
            if(a[i][j].stop_hl){
                if(a[i][j].item_string == "🍒"){
                    cout << no_of_items;
                    switch(no_of_items){
                        case 2:
                            credit += bet/5;
                            fout << '\n' << bet/5;
                        case 3:
                            credit += bet/2;
                            fout << '\n' << bet/2;    
                        case 4:
                            credit += bet;
                            fout << '\n' << bet;
                        case 5:
                            credit += bet*2;
                            fout << '\n' <<bet*2;
                    }
                }
                no_of_items = 0;
                cout << fin;
            }
            no_of_items++;
            cout << ' ';
        }
        cout << " |\n";
    }
    cout << "|5 50 100 500 " << hlg << "1000" << fin << "|\n";
    cout << "|CREDIT: "<< credit << "|\n";
    cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n";
    cout << "|                 |\n";
    cout << "|                 |\n";
    cout << "|_________________|\n";
}