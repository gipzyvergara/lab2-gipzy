#include <string>
#include <iostream>
#include "SolutionB.h"

using namespace std;

Participant* createParticipant(string id, string name, int category) {
    Participant* newParticipant = new Participant();
    newParticipant->id = id;
    newParticipant->name = name;
    newParticipant->category = category;
    newParticipant->scores = nullptr;
    newParticipant->scoresCount = 0;
    return newParticipant;
}

void addScore(Participant* participant, double score) {
    if (participant == nullptr) {
        return;
    }

    int newCount = participant->scoresCount + 1;
    double* newScores = new double[newCount];

    for (int i = 0; i < participant->scoresCount; i++) {
        newScores[i] = participant->scores[i];
    }

    newScores[participant->scoresCount] = score;

    if (participant->scores != nullptr) {
        delete[] participant->scores;
    }

    participant->scores = newScores;
    participant->scoresCount = newCount;
}

double calculateAverage(Participant* participant) {
    if (participant == nullptr) {
        return 0.0;
    }
    if (participant->scoresCount == 0) {
        return 0.0;
    }

    double suma = 0.0;
    for (int i = 0; i < participant->scoresCount; i++) {
        suma = suma + participant->scores[i];
    }

    return suma / participant->scoresCount;
}

void freeParticipant(Participant* participant) {
    if (participant == nullptr) {
        return;
    }

    if (participant->scores != nullptr) {
        delete[] participant->scores;
        participant->scores = nullptr;
    }

    delete participant;
}