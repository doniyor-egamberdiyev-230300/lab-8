//
// Created by Doniyorbek Egamberdiyev on 04/11/25.
//
#include <iostream>
using namespace std;

class Score {
private:
    int points;
public:
    Score(int p=0):points(p){}
    Score operator+=(const Score& p) {
        points += p.points;
        return *this;
    }
    bool operator==(const Score& p) const {
        return points == p.points;
    }
    friend ostream& operator<<(ostream& out, Score p);
};
ostream& operator<<(ostream& out, Score p) {
    out<<p.points;
    return out;
}
int main() {
    Score score(7);
    Score score2(7);
    cout<<"before adding: "<<score<<" ";
    cout << score2 << endl;
    score += score2;
    cout<<"after adding: "<<score<<endl;
    if (score == score2) {
        cout<<"score equals score2"<<endl;
    }
    else {
        cout<<"score does not equal score2"<<endl;
    }
}