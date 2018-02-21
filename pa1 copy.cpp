#include "pa1.h"
#include <iostream>

using namespace std;

int main() {

  //Specify size of the array
  int n;
  int midRowNum;
  std::cout<<"Enter the size of a magic square: ";
  std::cin>>n; //n = array size

  midRowNum = (n-1) / 2;

  if (n < 3 || n > 15 || n%2 != 1) {
    std::cout<<"Error, size must be an odd number between 3 and 15"<<std::endl;
    return -1;
  }

  //Magic Square 1
  std::cout <<"\nMagic Square #1 is:\n"<<std::endl;
  int** array = siameseSquare(n);
  printArray(array, n, 1);
  checkSum(array, n);
  //Magic Square 2
  array = reverseRows(array, n);
  printArray(array, n, 2);
  checkSum(array, n);
  //Magic Square 3
  array = reverseCols(array, n);
  printArray(array, n, 3);
  checkSum(array, n);
  //Magic Sqaure 4
  array = reverseCols(siameseSquare(n), n);
  printArray(array, n, 4);
  checkSum(array, n);
  //Magic Square 5
  array = findTranspose(siameseSquare(n), n);
  printArray(array, n, 5);
  checkSum(array, n);
  //Magic Square 6
  array = reverseCols(array, n);
  printArray(array, n, 6);
  checkSum(array, n);
  //Magic Square 7
  array = reverseRows(array, n);
  printArray(array, n, 7);
  checkSum(array, n);
  //Magic Square 8
  array = reverseRows(findTranspose(siameseSquare(n), n), n);
  printArray(array, n, 8);
  checkSum(array, n);
  //For magic squares of size n > 3, swap 2 rows or 2 columns (mirroring ones)
  if (n > 3) {
    //Magic Square 9
    array = swapRows(siameseSquare(n), n, midRowNum - 1, midRowNum + 1);
    printArray(array, n, 9);
    checkSum(array, n);
    //Magic Sqaure 10
    array = swapRows(siameseSquare(n), n, midRowNum - 2, midRowNum + 2);
    printArray(array, n, 10);
    checkSum(array, n);
  }

  delete[] array; //Free memory of dynamic array of pointers

  return 0;
}
