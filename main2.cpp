#include <iostream>
using namespace std;


/*
20 
Імітуйте дані про якість продукції (вага, форма, вологість). Напишіть
програму, яка аналізує ці параметри, щоб визначити якість врожаю та
повідомляти про будь-які відхилення.
*/

struct Product {
    double weight;  
    string shape;      
    double humidity;  

    void analyzeQuality() {
        bool isQualityGood = true;
        
        // Acceptable ranges(parameters)
        if (weight < 1.0 || weight > 5.0) {
            cout << "Warning: Weight deviation detected (" << weight << " kg)" << endl;
            isQualityGood = false;
        }
        
        if (shape != "round" && shape != "oval") {
            cout << "Warning: Shape deviation detected (" << shape << ")" << endl;
            isQualityGood = false;
        }
        
        if (humidity < 10.0 || humidity > 20.0) {
            cout << "Warning: Humidity deviation detected (" << humidity << "%)" << endl;
            isQualityGood = false;
        }

        // Quality output
        if (isQualityGood) {
            cout << "Product quality is within acceptable range." << endl;
        } else {
            cout << "Product quality does not meet the standards." << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of products to analyze: ";
    cin >> n;
    Product* products = new Product[n]; // Dynamic array of products

    for (int i = 0; i < n; ++i) {
        cout << "\nProduct " << i + 1 << ":" << endl;
        cout << "Enter weight (kg): ";
        cin >> products[i].weight;
        cout << "Enter shape: ";
        cin >> products[i].shape;
        cout << "Enter humidity (%): ";
        cin >> products[i].humidity;

        cout << "Analysis for Product " << i + 1 << ":" << endl;
        products[i].analyzeQuality();
        cout << endl;
    }

    delete[] products;
}