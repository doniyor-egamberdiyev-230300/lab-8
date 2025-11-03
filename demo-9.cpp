//
// Created by degam on 11/4/2025.
//
#include <iostream>
#include <cmath>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    void normalize() {
        if (minutes>= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
        else if (minutes <= 0) {
            int borrow = (abs(minutes)+59)/60;
            hours -= borrow;
            minutes += borrow*60;
        }
        else if (hours <= 0) {
            hours = 0;
            minutes = 0;
        }
    }
    public:
    Time():hours(0),minutes(0){}
    Time(int h, int min):hours(h),minutes(min) {
        normalize();
    }
    Time& operator++(){
    minutes++;
    normalize();
    return *this;
    }
    Time operator++(int){
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
    Time operator+(const Time& t) const {
        Time temp(hours + t.hours, minutes + t. minutes);
        temp.normalize();
        return temp;
    }
    Time operator-(const Time& t) const {
        Time temp(hours - t.hours, minutes - t. minutes);
        temp.normalize();
        return temp;
    }
    Time operator*(const Time& t) const {
        Time temp(hours * t.hours, minutes * t.minutes);
        temp.normalize();
        return temp;
    }
    bool operator==(const Time& t) {
        return (hours == t.hours && minutes == t.minutes);

    }
    Time operator+=(const Time& t) {
        hours += t.hours;
        minutes += t.minutes;
        normalize();
        return *this;
    }
    Time operator-=(const Time& t)  {
        hours -= t.hours;
        minutes -= t.minutes;
        normalize();
        return *this;
    }
    Time operator*=(const Time& t)  {
        hours *= t.hours;
        minutes *= t.minutes;
        normalize();
        return *this;
    }
    friend istream& operator>>(istream& in, Time t);
    friend ostream& operator<<(ostream& out, Time t);

};
istream& operator>>(istream& in, Time t) {
    in>>t.hours>>t.minutes;
    return in;
}
ostream& operator<<(ostream& out, Time t) {
    out<<t.hours<<" hours: " << t.minutes<< "minutes.";
    return out;
}
int main() {
    Time t1(2, 45), t2(1, 30), t3;

    cout << "Initial Times:\n";
    cout << t1 << endl;
    cout << t2 << endl;

    cout << "\nTesting input operator >> :\n";
    cout << "Enter a new time (hours and minutes): ";
    cin >> t3;
    cout << "You entered: " << t3 << endl;

    cout << "\nTesting + operator:\n";
    t3 = t1 + t2;
    cout << t3 << endl;

    cout << "\nTesting - operator:\n";
    t3 = t1 - t2;
    cout << t3 << endl;

    cout << "\nTesting * operator:\n";
    t3 = t1 * t2;
    cout << t3 << endl;

    cout << "\nTesting prefix ++ and postfix ++:\n";
    ++t1;
    cout << t1 << endl;
    t1++;
    cout << t1 << endl;

    cout << "\nTesting prefix -- and postfix --:\n";
    --t2;
    cout << t2 << endl;
    t2--;
    cout << t2 << endl;

    cout << "\nTesting == operator:\n";
    if (t1 == t2)
        cout << "Equal times\n";
    else
        cout << "Not equal\n";

    cout << "\nTesting +=, -=, *= operators:\n";
    t1 += t2;
    cout << t1 << endl;
    t1 -= t2;
    cout << t1 << endl;
    t1 *= t2;
    cout << t1 << endl;
    return 0;
}
