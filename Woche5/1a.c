#include <stdio.h>

unsigned sortPartly(unsigned char* array, const unsigned length){
    const unsigned char pivot = array[length -1];
    unsigned char tmp;
    for (unsigned i = 0; i < length; i++){
        if (array[i] <= pivot) {
            printf("%c war <= %c\n", array[i], pivot);
            continue;
        }
        for(int j = length -2 ; j >= 0; j--){
            if (array[j] >= pivot) {
                printf("%c war >= %c\n", array[j], pivot);
                continue;
            }
            //if (i < j) tausche die Daten
            tmp = array[i];
            if (i >= j){
                //if i > j tausche daten i mit pivot element
                array[i] = array[length -1];
                array[length - 1] = tmp;
                return i;
            }
            printf("Tausche %c mit %c\n", array[i], array[j]);
            array[i] = array[j];
            array[j] = tmp;
        }
        printf("Das rechte Element ist das kleinste Element.\n");
        tmp = array[0];
        array[0] = array[length - 1];
        array[length - 1] = tmp;
        return 0;
    }
    printf("Das rechte Element ist das größte Element.\n");
    return length - 1;

}

void quicksort(unsigned char* array, int length){
    if(length <= 1) return;
    const unsigned pivot_index = sortPartly(array, length);
    quicksort(array, pivot_index);
    quicksort(&(array[pivot_index + 1]), length - pivot_index - 1);
}

int main(){
    const unsigned length = 5;
    unsigned char chars[length] = "adbcd";
    quicksort(chars, length);
    printf("%s\n", chars);
}
