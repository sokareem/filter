//
//  main.cpp
//  Filter
//
//  Created by Sinmisola Kareem on 3/20/18.
//  Copyright © 2018 Sinmisola Kareem. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector <int> filter(int &X, int &Y, vector<int> &container, vector<int> &result){
    int greater_int = 0;
    int lesser_int = 0;
    if(X > Y){
        greater_int = X;
        lesser_int = Y;
    }
    else{
        greater_int = Y;
        lesser_int = X;
    }
    for(int i = 0; i < container.size(); i++){
        if(container.at(i) >= lesser_int && container.at(i) <= greater_int){
            result.push_back(container.at(i));
        }
    }
    return result;
}
//[1,2,3,4,5,56,6,7,7,8,10, 12, 13] as our test case for now
int main(int argc, const char * argv[]) {
    // we will use a vector to print out the filtered numbers.
    int size = 0;
    vector <int> vec;
    cout << "           THE FILTERER!!!        " << endl;

    cout << " Please state the size of your vector (vector must be between size of 3 to 10): " << endl;
    cin >> size;
    if(size < 3 || size > 10 ){
        cerr << " size out of bounds" << '\n';
        exit(1);
    }
    else{
        vec.reserve(size);
    }

    cout << "Great!! now let's put in values : " << endl;
    int i = 0;
    int value;
    while(i < size){
        cin >> value;
        vec.push_back(value);
        i++;
    }

    cout << " Awesome! all that you need now are two values to filter through! " << endl;
    cout << " Please give two values to filter through " << endl;
    int filter1 = 0;
    int filter2 = 0;
    cin >> filter1;
    cout << filter1 << " selected." << endl;
    cin >> filter2;
    cout << filter2 << " selected." << endl;

    cout << " time to filter! " << endl;
    vector<int> result;
    filter(filter1, filter2, vec, result);

    if(result.empty()){
        cout << "Filter failed no elements were found between range " << endl;
        return 0;
    }
    else{
        cout << "The filtered vector contains the following elements" << endl;
        for(int i = 0; i < result.size(); i++){
            if(i == result.size() - 1){
                cout << result[i] << '\n';
            }
            else{
                cout << result[i] << " " ;
            }
        }
    }

    cout << "Thanks for using the filter :) " << endl;

    return 0;
}

