//
// Created by Doniyorbek Egamberdiyev on 24/10/25.
//
#include <cmath>
#include <iostream>
#include<string>
using namespace std;
class Distance {
    int meters;
    double centimeters;
public:
    Distance() {
        meters = 0;
        centimeters = 0;
    }
    Distance(int m, double c):meters(m), centimeters(c) {}

void normalize() {
        while (centimeters >= 100) {
            centimeters -= 100;
            meters+=1;
        }
        while (centimeters <= 0) {
            centimeters += 100;
            meters-=1;
        }
    }
    void get_data() {
        cout << "Enter meters: ";
        cin >> meters;
        cout << "Enter centimeters: ";
        cin >> centimeters;
        normalize();
    }
    void show_data() const {
        cout << "Distance: " << meters << " meters and "
             << centimeters << " centimeters." << endl;
    }
    Distance operator++() {
        ++centimeters;
        normalize();
        return *this;
    }
    Distance operator++(int) {
        Distance temp = *this;
        centimeters++;
        normalize();
        return temp;
    }
    Distance operator+(Distance d) const {
        Distance result;
        result.meters = meters + d.meters;
        result.centimeters = centimeters + d.centimeters;
        result.normalize();
        return result;
    }

};
int main() {
Distance d1(2,99),d2(2,55),d3;
    d3=(d1+d2);
    d1.show_data();
    d2.show_data();
    d3.show_data();
}