#include <iostream>
#include <cmath>
#include <bitset>

using std::cout;
using std::endl;

unsigned ceilingBaseTwo(unsigned long num){
    int i = 0;
    while(num){
        num >>= 1;
        i++;
    }
    return i;
}

unsigned ceilingBaseTen(unsigned num){
    // Returns the amount of significant digits base 10
    int i = 0;
    unsigned pwr = 1;
    while(num >= pwr){
        i++;
        pwr *= 10;
    }
    return i ;
}

unsigned reverseNumber(unsigned n){
    int reversedNumber = 0, remainder;
    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    return reversedNumber;
}

unsigned long reverseBits(unsigned long num)
{
    int number_of_significant_bits = ceilingBaseTwo(num) - 1;
    unsigned long one = 1;
    unsigned long reverse_num = 0;
    int i;
    for (i = 0; i <= number_of_significant_bits; i++)
    {
        if((num & (one << i)))
           reverse_num |= one << (number_of_significant_bits - i);
   }
    return reverse_num;
}


bool checkPalindromeBaseTwo(unsigned long num){
    if (num - reverseBits(num) == 0)
        return 1;
    return 0;
}

unsigned long evenPalindrome(unsigned number){
    unsigned long mirrored = number;
    int significant_length = ceilingBaseTen(number);
    mirrored += pow(10, significant_length) * reverseNumber(number);
    return mirrored;

}

unsigned long unevenPalindrome(unsigned number){
    unsigned long mirrored = number;
    int significant_length = ceilingBaseTen(number);
    unsigned long reversed = reverseNumber(number);
    mirrored += pow(10, significant_length - 1) * (reversed - reversed % 10) ;
    return mirrored;
}

unsigned long sumPalindromes(){
    unsigned long sum = 0;
    unsigned long x = 0;
    for(unsigned int i = 0; i < 1e5; i++){
        x = evenPalindrome(i);
        if(checkPalindromeBaseTwo(x) && x%10 != 0){
            sum += x;
            std::bitset<64> y(x);
            cout << "Palindrome found: (DEC) "<< x << " = (BIN) " << y << endl;
        }
    }
    for(unsigned int i = 0; i < 1e5; i++){
        x = unevenPalindrome(i);
        if(checkPalindromeBaseTwo(x) && x%10 != 0){
            sum += x;
            std::bitset<64> y(x);
            cout << "Palindrome found: (DEC) "<< x << " = (BIN) " << y << endl;
        }
    }
    return sum;
}

int main()
{
    //unsigned long x = sumPalindromes();
    //cout << "Summe: " << x << endl;
    cout << checkPalindromeBaseTwo(9009) << endl;
}
