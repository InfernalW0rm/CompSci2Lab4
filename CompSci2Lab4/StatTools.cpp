#include "StatTools.h"
using namespace std;

template <typename T>
T StatTools<T>::max(const vector<T>& data) {
    return *max_element(data.begin(), data.end());
}

template <typename T>
T StatTools<T>::min(const vector<T>& data) {
    return *min_element(data.begin(), data.end());
}

template <typename T>
double StatTools<T>::mean(const vector<T>& data) {
    T sum = accumulate(data.begin(), data.end(), T(0));
    return static_cast<double>(sum) / data.size();
}

template <typename T>
T StatTools<T>::mode(const vector<T>& data) {
    unordered_map<T, int> frequency;
    for (const auto& num : data) {
        ++frequency[num];
    }

    T mode = data[0];
    int max_count = 0;
    for (const auto& [num, count] : frequency) {
        if (count > max_count) {
            max_count = count;
            mode = num;
        }
    }
    return mode;
}

template <typename T>
double StatTools<T>::median(vector<T>& data) {
    sort(data.begin(), data.end());
    size_t size = data.size();
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
    else {
        return data[size / 2];
    }
}

template <typename T>
void StatTools<T>::stemAndLeaf(const vector<T>& data) {
    vector<T> sorted_data = data;
    sort(sorted_data.begin(), sorted_data.end());

    T current_stem = sorted_data[0] / 10;
    cout << current_stem << " | ";
    for (const auto& num : sorted_data) {
        T stem = num / 10;
        T leaf = num % 10;

        if (stem != current_stem) {
            cout << endl << stem << " | ";
            current_stem = stem;
        }
        cout << leaf << " ";
    }
    cout << endl;
}

template <typename T>
void StatTools<T>::barChart(const vector<T>& data) {
    vector<T> sorted_data = data;
    sort(sorted_data.begin(), sorted_data.end());

    T current_value = sorted_data[0];
    int count = 0;

    for (const auto& num : sorted_data) {
        if (num == current_value) {
            ++count;
        }
        else {
            cout << setw(5) << current_value << ": ";
            cout << string(count, '*') << endl;
            current_value = num;
            count = 1;
        }
    }

    cout << setw(5) << current_value << ": ";
    cout << string(count, '*') << endl;
}
