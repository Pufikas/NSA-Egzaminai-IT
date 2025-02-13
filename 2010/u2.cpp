#include <iostream>
#include <fstream>

using namespace std;

#define MAX_PRODUCT_AMOUNT 10
#define MAX_DISH_AMOUNT 12
#define MAX_DISH_NAME 15 + 1

struct Dish {
    char name[MAX_DISH_NAME];
    int products[MAX_PRODUCT_AMOUNT];
    struct DishSet* dishSet;

    int calculate();
};

struct DishSet {
    Dish dishes[MAX_DISH_AMOUNT];
    int productCosts[MAX_PRODUCT_AMOUNT];
    size_t dishAmount, productAmount;

    int calculate();
};

bool load(const char* path, DishSet& data);
bool save(const char* path, DishSet& data);

int main() {
    DishSet data;
    if (!load("u2.txt", data)) return 1;
    return !save("u2res.txt", data);   
}

bool load(const char* path, DishSet& data) {
    ifstream fin(path);
    if (!fin.is_open()) return false;

    fin >> data.productAmount >> data.dishAmount;
    
    // cost for each product
    for (size_t i = 0; i < data.productAmount; i++) {
        fin >> data.productCosts[i];
    }

    // for each dish
    for (size_t i = 0; i < data.dishAmount; i++) {
        fin.ignore(); // ignore newline char
        fin.get(data.dishes[i].name, sizeof(data.dishes[i].name));

        // quantity of each product in the dish
        for (size_t j = 0; j < data.productAmount; j++) {
            fin >> data.dishes[i].products[j];
        }
        data.dishes[i].dishSet = &data;
    }
    return true;
}

bool save(const char* path, DishSet& data) {
    ofstream fout(path);
    if (!fout.is_open()) return false;

    // for all dishes in DishSet
    for (size_t i = 0; i < data.dishAmount; i++) {
        fout << data.dishes[i].name << data.dishes[i].calculate() << '\n';
    }

    int cents = data.calculate();
    int lt = cents / 100;
    cents -= lt * 100;

    fout << lt << ' ' << cents;

    return true;
}

// one dish cost
int Dish::calculate() {
    int sum = 0;

    for (size_t i = 0; i < this->dishSet->productAmount; i++) {
        sum += this->products[i] * this->dishSet->productCosts[i];
    }

    return sum;
}


//
int DishSet::calculate() {
    int sum = 0;

    for (size_t i = 0; i < this->dishAmount; i++) {
        sum += this->dishes[i].calculate();
    }

    return sum;
}