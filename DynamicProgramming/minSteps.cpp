#include<iostream>
using namespace std;

/*
Time Complexity : O(3^N)
Space Complexity : O(N)
where N is the given positive integer
*/
#include <climits>
int countMinStepsToOne(int n) {
if (n == 1) {
return 0;
}
int subtractOne = countMinStepsToOne(n - 1);
int divideByTwo = INT_MAX;
int divideByThree = INT_MAX;
if (n % 2 == 0) {
divideByTwo = countMinStepsToOne(n / 2);
}
if (n % 3 == 0) {
divideByThree = countMinStepsToOne(n / 3);
}
return 1 + min(subtractOne, min(divideByTwo, divideByThree));
}

int main(){

int n;
cin>>n;

cout <<countMinStepsToOne(n);
	
}
