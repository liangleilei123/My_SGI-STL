#include <iostream>
#include<vector>
#include<string>
using namespace std;


int main() {
    int a = 0;      
    int b = 0;      
    int* lis = new int[3]{1,2,3};
    vector<int> vec_int{1,2,3,4};
    vector<string> vec_str{"igjj","fadf"};

    cout << &lis[0] << endl;
    cout << &lis[1] << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &vec_int[0] << endl;
    cout << &vec_int[1] << endl;
    cout << &vec_str[0] << endl;
    cout << &vec_str[1] << endl;
   



    return 0;
}