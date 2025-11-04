//
// Created by Doniyorbek Egamberdiyev on 04/11/25.
//
#include<iostream>
#include <string>
using namespace std;
// class Instrument {
// protected:
//     string name;
//     string type;
// public:
//     Instrument(string name, string type):name(name), type(type){}
//     virtual void play() {
//     cout<<"Playing a generic instrument sound...\n";
//     }
// };
// class Guitar: public Instrument {
// private:
//     int strings;
//     public:
//     Guitar(string name, string type, int strings):Instrument(name,type), strings(strings) {
//
//     }
//     void play() override {
//         cout<<"Strumming a guitar with X strings.\n";
//     }
// };
// class Drum: public Instrument {
//     private:
//     double diameter;
//     public:
//     Drum(string name, string type, double diameter):Instrument(name,type), diameter(diameter){}
//     void play() override {
//         cout<< "Beating a drum of diameter X cm."<<endl;
//     }
// };
// class Flute: public Instrument {
//     private:
//     string material;
//     public:
//   Flute(string n, string t, string m):Instrument(n,t), material(m){}
//     void play() override {
//       cout<< "Blowing a flute made of X."<<endl;
//   }
// };
class MusicRecord {
    private:
    string title;
    int duration;
    public:
    MusicRecord(): title (""),duration (0) {}
    MusicRecord(string title, int duration):title(title), duration(duration) {
    }
    MusicRecord(const MusicRecord& other) {
        cout << "Copy constructor is called"<<endl;
        title=other.title;
        duration=other.duration;
    }
    MusicRecord& operator=(const MusicRecord& other) {
       if (this != &other) {
           title=other.title;
           duration = other.duration;
       }
        return *this;
    }
    void display() {
        cout<<title<<endl;
        cout<<duration<<endl;
    }
};
int main() {
    // Instrument* i= new Guitar("Guitar","String",6);
    // i->play();
    // Instrument* orchestra[3];
    // orchestra[0] = new Guitar("Guitar", "String", 6);
    // orchestra[1] = new Drum("Drum", "Percussion", 40.5);
    // orchestra[2] = new Flute("Flute", "Wind", "Bamboo");
    // for (int i = 0; i < 3; i++)
    //     orchestra[i]->play();
    MusicRecord r1("Bohemian Rhapsody", 354);
    MusicRecord r2 = r1;
    MusicRecord r3;
    r3 = r1;
    r1.display();
    r2.display();
    r3.display();

}