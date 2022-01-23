#include <iostream>
#include <vector>

using namespace std;

int countWord(vector<int> numberList, int number){
    int left = 0;
    int right = numberList.size() - 1;
    int itemMiddle = 0;
    while(left + 1 < right) {
        int middle = (left + right) / 2;
        if(numberList[middle] < number){
            left = middle;
        } 
        else if(numberList[middle] > number){
            right = middle - 1;
        } 
        else if(numberList[middle] == number) {
            if(numberList[middle - 1] != number && numberList[middle + 1] != number) return 1;
            itemMiddle = middle;
            break;
        } 
        else return 0;
    }
    int newRight = itemMiddle;
    while(left + 1 < newRight) {
        int middle = (left + newRight) / 2;
        if(numberList[left] == number) break;
        if (numberList[middle] == number) newRight = middle;
        else if (numberList[middle] < number) left = middle + 1;
    }
    int newLeft = itemMiddle;
    while (newLeft + 1 < right) {
        int middle = (newLeft + right) / 2;
        if (numberList[right] == number) break;
        if (numberList[middle] == number) newLeft = middle;
        else if (numberList[middle] > number) right = middle - 1;
    }
    return right - left;
}

int main(){ 
    vector<int> valores = {0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 7, 8};
    cout << countWord(valores, 0);
}




