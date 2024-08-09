#ifndef STATTOOLS_H
#define STATTOOLS_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <iomanip>

using namespace std;

template<typename T>
class StatTools
{
public:
    static T Max(const vector<T>& data);
    static T Min(const vector<T>& data);
    static double Mean(const vector<T>& data);
    static T Mode(const vector<T>& data);
    static double Median(vector<T> data);

    static void StemAndLeaf(const vector<T>& data);
    static void BarChart(const vector<T>& data);
};

// Implementations
template<typename T>
T StatTools<T>::Max(const vector<T>& data)
{
    return *max_element(data.begin(), data.end());
}

template<typename T>
T StatTools<T>::Min(const vector<T>& data)
{
    return *min_element(data.begin(), data.end());
}

template<typename T>
double StatTools<T>::Mean(const vector<T>& data)
{
    if (data.empty()) return 0;
    double sum = accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

template<typename T>
T StatTools<T>::Mode(const vector<T>& data)
{
    map<T, int> frequency;
    for (const auto& item : data)
    {
        frequency[item]++;
    }

    T mode = data[0];
    int maxCount = 0;
    for (const auto& pair : frequency)
    {
        if (pair.second > maxCount)
        {
            mode = pair.first;
            maxCount = pair.second;
        }
    }

    return mode;
}

template<typename T>
double StatTools<T>::Median(vector<T> data)
{
    if (data.empty()) return 0;
    sort(data.begin(), data.end());
    size_t n = data.size();
    if (n % 2 == 0) {
        return (data[n / 2 - 1] + data[n / 2]) / 2.0;
    }
    else {
        return data[n / 2];
    }
}

template<typename T>
void StatTools<T>::StemAndLeaf(const vector<T>& data)
{
    map<int, vector<T>> stemLeafMap;
    for (const auto& num : data)
    {
        int stem = num / 10;
        int leaf = num % 10;
        stemLeafMap[stem].push_back(leaf);
    }

    for (const auto& pair : stemLeafMap)
    {
        cout << pair.first << " | ";
        for (const auto& leaf : pair.second)
        {
            cout << leaf << " ";
        }
        cout << endl;
    }
}

template<typename T>
void StatTools<T>::BarChart(const vector<T>& data)
{
    T maxValue = Max(data);
    cout << "Value -> Frequency\n";
    for (const auto& num : data) {
        cout << num << " -> " << string(num, '*') << endl;
    }
}

#endif
