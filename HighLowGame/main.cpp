#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int number = 1 + rand() % 100;
    int n = 0;
    int guess = 1;
    time_t start_time = time(NULL);

    cout << "Guess a number from 1 to 100: ";
    cin >> n;

    while(n != number) {
        if(n > number) {
            cout << "Too high" << endl;
        } else {
            cout << "Too low" << endl;
        }
        guess += 1;
        cout << "Guess again: ";
        cin >> n;
    }
    cout << "You won! on your " << guess;
    if(guess % 10 == 1) {
        cout << "st";
    } else if(guess % 10 == 2) {
        cout << "nd";
    } else if(guess % 10 == 3) {
        cout << "rd";
    } else {
        cout << "th";
    }
    cout << " try and in " << difftime(time(NULL), start_time) \
            << " seconds!" << endl;
    return 0;
}
