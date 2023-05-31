#include <iostream>
#include <vector>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++) {
        int discount = 0;
        for (int j = i + 1; j < n; j++) {
            if (prices[j] <= prices[i]) {
                discount = prices[j];
                break;
            }
        }
        result[i] = prices[i] - discount;
    }

    return result;
}

int main() {
    vector<int> prices = {8, 4, 6, 2, 3};
    vector<int> discountedPrices = finalPrices(prices);

    cout << "Original Prices: ";
    for (int price : prices) {
        cout << price << " ";
    }

    cout << "\nDiscounted Prices: ";
    for (int price : discountedPrices) {
        cout << price << " ";
    }
    
    return 0;
}
//Kompleksiteti kohor:O(n^2)
//Kompleksiteti hapesinor:O(n)
