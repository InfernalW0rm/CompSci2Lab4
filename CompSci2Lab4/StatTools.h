#ifndef STATTOOLS_H
#define STATTOOLS_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class StatTools
{
public:
    static T max(const vector<T>& data);
    static T min(const vector<T>& data);
    static double mean(const vector<T>& data);
    static T mode(const vector<T>& data);
    static double median(vector<T>& data);
    static void stemAndLeaf(const vector<T>& data);
    static void barChart(const vector<T>& data);
};

#endif