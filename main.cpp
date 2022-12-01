#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main() {


    std::list<const char*> yamanotesen = {
        "Tokyo","Kanda","Akihabara","Okatimati","Ueno",
        "Uguisudani","Nippori","Tabata","Komagome","Sugamo",
        "Ootuka","Ikebukuro","Mejiro","Takadanobaba","sinokubo",
        "Shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu","Meguro",
        "Gotanda","Oosaki","Shinagawa","Tamati","Hamamatutyou",
        "Shinbasi","Yurakutyou" 
    };

    cout << "1970\n";
    for (auto itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {
        cout << *itr << "\n";
    }

    cout << "\n";

    cout << "2019\n";
    for (auto itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {
        if (*itr == "Tabata") {
            itr = yamanotesen.insert(itr, "Nisinippori");
            ++itr;
        }
    }
    for (auto itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {
        cout << *itr << "\n";
    }

    cout << "\n";

    cout << "2022\n";
    for (auto itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {
        if (*itr == "Tamati") {
            itr = yamanotesen.insert(itr, "Takanawagettoway");
            ++itr;
        }
    }
    for (auto itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {
        cout << *itr << "\n";
    }

    system("pause");
    return 0;
}
