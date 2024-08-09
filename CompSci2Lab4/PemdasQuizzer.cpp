#include "PemdasQuizzer.h"
#include <iostream>
#include <cstdlib>    
#include <ctime>      
#include <sstream>
#include <stack>
#include <cctype>

using namespace std;

int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

int applyOp(int a, int b, char op) 
{
    switch (op) 
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '%': return a % b;
    default: return 0;
    }
}

int evaluateExpression(const string& expression) 
{
    stack<int> values; 
    stack<char> ops;   

    for (size_t i = 0; i < expression.length(); i++) 
    {
        if (isspace(expression[i]))
            continue;

        
        if (isdigit(expression[i])) 
        {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) 
            {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
       
        else if (expression[i] == '(') 
        {
            ops.push(expression[i]);
        }
       
        else if (expression[i] == ')') 
        {
            while (!ops.empty() && ops.top() != '(') 
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.pop();
        }
      
        else if (expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*' || expression[i] == '/' || expression[i] == '%') 
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) 
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }

   
    while (!ops.empty()) 
    {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

  
    return values.top();
}

void generateProblem(int numProblems) 
{
    int correctAnswers = 0;

    for (int i = 0; i < numProblems; ++i) 
    {
        string expression = generateRandomExpression();
        int correctAnswer = evaluateExpression(expression);

        bool isCorrect = askUserQuestion(expression, correctAnswer);
        if (isCorrect) 
        {
            ++correctAnswers;
        }
    }

    double percentage = calculatePercentage(numProblems, correctAnswers);
    cout << "Your score: " << percentage << "%" << endl;
}

string generateRandomExpression() 
{
    string expression;
    for (int i = 0; i < 9; ++i) 
    {
        expression += to_string(rand() % 20 + 1);
        if (i < 8) 
        {
            char operators[] = { '+', '-', '*', '/', '%' };
            expression += operators[rand() % 5];
        }
    }
    return expression;
}

bool askUserQuestion(const string& expression, int correctAnswer) 
{
    int userAnswer;
    cout << "Solve this problem: " << expression << " = ";
    cin >> userAnswer;

    if (userAnswer == correctAnswer) 
    {
        cout << "Correct!" << endl;
        return true;
    }
    else 
    {
        cout << "Incorrect. The correct answer is " << correctAnswer << "." << endl;
        return false;
    }
}

double calculatePercentage(int total, int correct) 
{
    return (static_cast<double>(correct) / total) * 100.0;
}
