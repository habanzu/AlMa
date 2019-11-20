#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

void convert_to_int(int* x, int length_x, string str){
    int j = 0;
    for(int i=length_x-1; i>=0; i--){
        x[j] = std::stoi(str.substr(i,1));
        j++;
    }
}

int* add(int *x, int *y, int length_x, int length_y){
    // Tausche die Argumente wenn nicht length_x >= length_y
    if (length_y > length_x){
        int * tmp = x;
        int tmp_l = length_x;
        x = y;
        y = tmp;
        length_x = length_y;
        length_y = tmp_l;
    }

    int *z = new int[length_x + 1];
    for(int i=0; i <= length_x; i++){
        z[i] = 0;
    }

    for(int i=0; i< length_x; i++){
        if(i < length_y){
            z[i] += x[i] + y[i];
        }
        else{
            z[i] += x[i];
        }
        if (z[i] > 9){
            z[i] -= 10;
            z[i +1]++;
        }
    }

    return z;
}

int main(){
    string str1, str2;

    cout << "x = "; cin >> str1;
    int length_x = str1.length();
    int *x; x = new int[length_x];
    convert_to_int(x, length_x, str1);

    cout << "y = "; cin >> str2;
    int length_y = str2.length();
    int *y; y = new int[length_y];
    convert_to_int(y, length_y, str2);

    int *z = add(x,y,length_x, length_y);

    cout << "x + y = ";
    for(int i=std::max(length_x,length_y); i >= 0; i--){
        cout << z[i];
    }
    cout << endl;
}
