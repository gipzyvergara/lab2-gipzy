#include <iostream>
#include "SolutionB.h"

using namespace std;

int main() {
    Participant* p = createParticipant("101", "Gipzy", 1);

    addScore(p, 9.5);
    addScore(p, 8.0);
    addScore(p, 10.0);

    cout << "ID: " << p->id << endl;
    cout << "Nombre: " << p->name << endl;
    cout << "Promedio: " << calculateAverage(p) << endl;

    freeParticipant(p);

    return 0;
}