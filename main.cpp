#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned int min = index;
    
    if(vals.size() > 0)
    {
        for (unsigned int i = index; i < vals.size(); i++) {
            if (vals.at(i) < vals.at(min)) {
                min = i;
            }
        }
        return min;
    }
    
    return -1;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    if (vals.size() > 0)
    {
        for (unsigned i = 0; i < vals.size(); i++)
        {
            unsigned minIndex = min_index(vals, i);
            T tempVal = vals.at(minIndex);

            vals.at(minIndex) = vals.at(i);
            vals.at(i) = tempVal;
        }
    }
}

template<typename T>
T getElement(vector<T> vals, int index) {
    if(index < 0 || index > vals.size() - 1)
    {
        throw runtime_error("std::out_of_range");
    }
    return vals.at(index);
}

vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){
    //Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        try {
        curChar = getElement(vals,index);
        cout << "Element located at " << index << ": is " << curChar << endl;
        }
    }
    catch (runtime_error& excpt) {
        cout << excpt.what() << " exception occurred." << endl;
    }
    return 0;
}
