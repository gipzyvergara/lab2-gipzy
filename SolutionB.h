#ifndef SOLUTION_B_H
#define SOLUTION_B_H

#include <string>

using namespace std;

struct Participant {
    string id;
    string name;
    double* scores;
    int scoresCount;
    int category;
};

Participant* createParticipant(string id, string name, int category);
void addScore(Participant* participant, double score);
double calculateAverage(Participant* participant);
void freeParticipant(Participant* participant);

#endif