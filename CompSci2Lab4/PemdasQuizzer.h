#ifndef PEMDASQUIZZZER_H
#define PEMDASQUIZZZER_H

#include <string>

using namespace std;

void generateProblem(int numProblems);
int evaluateExpression(const string& expression);
string generateRandomExpression();
bool askUserQuestion(const string& expression, int correctAnswer);
double calculatePercentage(int total, int correct);

#endif
