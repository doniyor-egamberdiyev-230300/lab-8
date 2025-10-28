//
// Created by Doniyorbek Egamberdiyev on 28/10/25.
//
#include<iostream>
using namespace std;

class Time {
    int hours;
    int minutes;
 void normalize() {
        while (minutes >=60 ) {
            hours ++;
            minutes -= 60;
        }
        while (minutes <=0 ) {
            hours --;
            minutes += 60;
        }
        while (hours<=0) {
            hours = minutes = 0;
        }
    }

public:
    friend ostream& operator<<(ostream& out, Time t);
    friend istream& operator>>(istream& in, Time& t);

    Time() {
        hours = minutes = 0;
        cout<<"NA";
    }
    Time(int h, int m): hours(h), minutes(m) {
        normalize();
    }
    Time operator++() {
        minutes++;
        normalize();
        return *this;
    }
    Time operator++(int) {
        Time temp = *this;
        minutes++;
        normalize();
        return temp;
    }
    Time operator--() {
        minutes--;
        normalize();
        return *this;
    }
    Time operator--(int) {
        Time temp = *this;
        minutes--;
        normalize();
        return temp;
    }
};
ostream& operator <<(ostream& out, Time t) {
    out<<t.hours<<" hours "<<t.minutes<<" minutes";
    return out;
}

istream& operator>>(istream& in, Time& t) {
    cout<<"Enter the hours and minutes: ";
    in>>t.hours>>t.minutes;
    return in;
}

int main() {
    Time t;
    cin>>t;
    cout<<t;
}