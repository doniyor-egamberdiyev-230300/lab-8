//
// Created by degam on 11/3/2025.
//
#include <iostream>
#include <cmath>
using namespace std;

class Distance {
private:
    int meters;
    double centimeters;
public:
   Distance() {
       meters = 0;
       centimeters = 0;
   }
    Distance(int m, double cm):meters(m), centimeters(cm) {
       normalize();
   }
    void normalize() {
       if (centimeters >= 100) {
           meters += centimeters / 100;
           centimeters = fmod(centimeters, 100);
       }
       else if (centimeters <= 0){
           int borrow = (abs(centimeters)+99)/100;
           meters -= borrow;
           centimeters = centimeters + borrow * 100;
       }
       else if (meters <= 0) {
           meters = 0;
           centimeters = 0;
       }
   }
    void get_data() {
       cout<<"Enter the meters: "<<endl;
       cin>>meters;
       cout<<"Enter the centimeters: "<<endl;
       cin>>centimeters;
       normalize();
   }
    void show_data() {
       cout<<"Meters: "<< meters <<" centimeters: "<<centimeters<<endl;
   }
    Distance& operator++() {
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
    Distance& operator--() {
       centimeters--;
       normalize();
       return *this;
   }
    Distance operator--(int) {
       Distance temp = *this;
       centimeters--;
       normalize();
       return temp;
   }
    Distance  operator+(const Distance& d) const {
       Distance temp(meters+d.meters, centimeters+d.centimeters);
       temp.normalize();
       return temp;
   }
    Distance operator-(const Distance&  d) const {
       Distance temp(meters-d.meters, centimeters-d.centimeters);
       temp.normalize();
       return temp;
   }
    Distance operator*(const Distance& d) const {
       Distance temp(meters*d.meters, centimeters*d.centimeters);
       temp.normalize();
       return temp;
   }
    bool operator==(const Distance& d) const {
       return (meters == d.meters && centimeters == d.centimeters);

   }
    Distance operator+=(const Distance& d) {
       meters += d.meters;
       centimeters += d.centimeters;
       normalize();
       return *this;
   }
    Distance operator-=(const Distance& d) {
       meters -= d.meters;
       centimeters -= d.centimeters;
       normalize();
       return *this;
   }
    Distance operator*=(const Distance& d) {
       meters *= d.meters;
       centimeters *= d.centimeters;
       normalize();
       return *this;
   }
};
int main() {
    Distance d1(2, 75), d2(3, 50), d3;
    cout << "Initial Distances:\n";
    d1.show_data();
    d2.show_data();
    cout << "\nTesting + operator:\n";
    d3 = d1 + d2;
    d3.show_data();
    cout << "\nTesting - operator:\n";
    d3 = d1 - d2;
    d3.show_data();
    cout << "\nTesting * operator:\n";
    d3 = d1 * d2;
    d3.show_data();
    cout << "\nTesting prefix ++:\n";
    ++d1;
    d1.show_data();
    cout << "\nTesting postfix ++:\n";
    d1++;
    d1.show_data();
    cout << "\nTesting prefix --:\n";
    --d2;
    d2.show_data();
    cout << "\nTesting postfix --:\n";
    d2--;
    d2.show_data();
    cout << "\nTesting == operator:\n";
    if (d1 == d2)
        cout << "Equal distances\n";
    else
        cout << "Not equal\n";
    cout << "\nTesting +=, -=, *= operators:\n";
    d1 += d2;
    d1.show_data();
    d1 -= d2;
    d1.show_data();
    d1 *= d2;
    d1.show_data();
    return 0;
}
