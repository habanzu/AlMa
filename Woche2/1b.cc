#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

void convert_to_bool(bool* x, int length_x, string str){
    int j = 0;
    for(int i=length_x-1; i>=0; i--){
        x[j] = std::stoi(str.substr(i,1));
        j++;
    }
}

bool* add(bool *x, bool *y, int length_x, int length_y){
    // Tausche die Argumente wenn nicht length_x >= length_y
    if (length_y > length_x){
        bool * tmp = x;
        bool tmp_l = length_x;
        x = y;
        y = tmp;
        length_x = length_y;
        length_y = tmp_l;
    }

    bool *z = new bool[length_x + 1];
    for(int i=0; i <= length_x; i++){
        z[i] = 0;
    }

    for(int i=0; i< length_x; i++){
        if(i < length_y){
            z[i + 1] = (z[i] & (x[i] ^ y[i])) | (x[i]&y[i]);
            z[i] = x[i] ^ y[i] ^ z[i];
        }
        else{
            z[i + 1] = (z[i] & (x[i] ^ 0)) | (x[i]&0);
            z[i] = x[i] ^ 0 ^ z[i];
        }
    }

    return z;
}

int main(){
    string str1, str2;

    cout << "x = "; cin >> str1;
    int length_x = str1.length();
    bool *x; x = new bool[length_x];
    convert_to_bool(x, length_x, str1);

    cout << "y = "; cin >> str2;
    int length_y = str2.length();
    bool *y; y = new bool[length_y];
    convert_to_bool(y, length_y, str2);

    bool *z = add(x,y,length_x, length_y);

    cout << "x + y = ";
    for(int i=std::max(length_x,length_y); i >= 0; i--){
        cout << z[i];
    }
    cout << endl;
}
