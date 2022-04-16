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
    int valsSize = vals.size();
    if(index < 0 || index > valsSize - 1)
    {
        throw runtime_error("std::out_of_range");
    }
    return vals.at(index);
}

vector<char> createVector() {
    int vecSize = rand() % 26;
    char letter = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(letter);
        letter++;
    }
    return vals;
}

int main(){
    //Part B
    srand(time(0));

    vector<char> vals = createVector();
    char curChar;
    int index;
    int numRuns = 10;


    while(numRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        try {
        curChar = getElement(vals,index);
        cout << "Value at " << index << " = " << curChar << endl;
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << " exception occurred." << endl;
        }
        numRuns--;
    }
//    selection_sort(vals);
//    for (unsigned i = 0; i < vals.size(); i++)
//    {
//        cout << "vector after sorting: " << endl;
//        cout << vals.at(i);
//    }
    return 0;
}
