//
// Created by Doniyorbek Egamberdiyev on 28/10/25.
//
#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
 void normalize() {
     if(minutes>=60){
         hours += minutes/60;
         minutes= minutes % 60;
     }
     else if (minutes <=0) {
         int borrow = (abs(minutes)+59)/60;
         hours-= borrow;
         minutes+= borrow*60;
     }
     else if (hours <=0) {
     hours = minutes = 0;
     }
 }

public:
    friend ostream& operator<<(ostream& out, Time t);
    friend istream& operator>>(istream& in, Time& t);

    Time() {
        hours = minutes = 0;
    }
    Time(int h, int m): hours(h), minutes(m) {
        normalize();
    }
    Time& operator++() {
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
    Time& operator--() {
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
    Time operator+(const Time& other )const {
        Time temp(hours+other.hours, minutes+other.minutes);
        temp.normalize();
        return temp;
    }
    Time operator-(const Time& t) {
        Time temp(hours-t.hours, minutes-t.minutes);
        temp.normalize();
        return temp;
    }
    Time operator*(const Time& t) {
        Time temp(hours*t.hours, minutes*t.minutes);
        temp.normalize();
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
    Time t(23, 100);
    cin>>t;
    return 0;
}