#include <iostream>

using namespace std;

void cube_by_reference(int *numptr) {
    *numptr = *numptr * *numptr * *numptr;
}

int main() {
    cout << "Hello world!" << endl;

    int number = 5;
    cout << "The number " << number << " cubed is ";
    cube_by_reference(&number);
    cout << number << endl;

    return 0;
}
