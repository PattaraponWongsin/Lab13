#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double arr[], int size, double result[]) {
   
    double sum = 0.0;
    double SquaredDiff = 0.0;
    double product = 1.0;
    double reciprocalSum = 0.0;
    double maxVal = arr[0];
    double minVal = arr[0];


    for (int i = 0; i < size; ++i) {
        sum += arr[i];
        product *= arr[i];
        reciprocalSum += 1.0 / arr[i];
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        else if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    double arithmeticMean = sum / size;
    result[0] = arithmeticMean;

   
    double meanSquared = sum / size;
    for (int i = 0; i < size; ++i) {
        SquaredDiff += pow(arr[i] - meanSquared, 2);
    }
    double standardDeviation = sqrt(SquaredDiff / size);
    result[1] = standardDeviation;

    
    double geometricMean = pow(product, 1.0 / size);
    result[2] = geometricMean;

    double harmonicMean = size / reciprocalSum;
    result[3] = harmonicMean;

 
    result[4] = maxVal;
    result[5] = minVal;
}