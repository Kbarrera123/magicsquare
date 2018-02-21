#include <iostream>
using namespace std;

int** siameseSquare(int n) {
  //dynamically initialize array of size n*
  int** arr = new int*[n];
  for(int i = 0; i < n; ++i)
      arr[i] = new int[n];

  int fillVal = 1;
  int lastNum = n * n;
  int row = 0;
  int col = (n-1) / 2;

  //Fill the array with zeroes
  for (int i = 0; i < n; i++) {  //for rows
    for (int j = 0; j < n; j++) {  //for columns
      arr[i][j] = 0;
    }
  }

  //Implement Siamese Method
  while (fillVal < lastNum + 1) {
    if (arr[row][col] == 0) { //check that cell is empty
      arr[row][col] = fillVal;
      row--; //Up one row
      col++; //Right one column
      //Handle when you cannot go up one row (go to bottom row)
      if (row < 0) {
        row = n - 1;
      }
      //Handle when you cannot go up one col (go to first col)
      if (col == n) {
        col = 0;
      }
      fillVal++;
    }
    else { //if cell is already filled, go down and left one
      row = row + 1;
      col = col - 1;
      //Handle when you are in nonexistent bottom/left square by going down from first row, last column
      if (row == n && col < 0) {
        row = 1;
        col = n - 1;
      }
      //Just go down one row
      else {
        row = row + 1;
      }
    }
  }

  return arr;
}

int** reverseRows(int** arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-1; j++) {
        int temporary = arr[i][j];
        arr[i][j] = arr[i][(n - 1) - j];
        arr[i][(n - 1) - j] = temporary;
    }
  }
  return arr;
}

int** reverseCols(int** arr, int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n; j++) {
        int temporary = arr[i][j];
        arr[i][j] = arr[(n-1) - i][j];
        arr[(n-1) - i][j] = temporary;
    }
  }
  return arr;
}

int** findTranspose(int** arr, int n) {
  //dynamically initialize array of size n*
  //Transpose = make rows into columns and vice versa
  int** transpose = new int*[n];
  for(int i = 0; i < n; ++i)
      transpose[i] = new int[n];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      transpose[j][i] = arr[i][j];
    }
  }

  return transpose;
}

int** swapRows(int** arr, int n, int row1, int row2) {
    for (int j = 0; j < n; j++) {
        int temporary = arr[row1][j];
        arr[row1][j] = arr[row2][j];
        arr[row2][j] = temporary;
    }
  return arr;
}

int printArray(int** arr, int n, int magicSquareNum) {
  if (magicSquareNum > 1) {
    std::cout <<"\nMagic Square #"<<magicSquareNum<<" is:\n"<<std::endl;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
    printf("%4d", arr[i][j]);
  }
  std::cout << std::endl;
 }

 return 0;
}

int checkSum(int** arr, int n) {
  int rowSum = 0;
  int colSum = 0;
  int topDiagSum = 0;
  int lowDiagSum = 0;

  std::cout<<"\nChecking the sums of every row: ";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rowSum = rowSum + arr[i][j];
    }
    std::cout<<rowSum<<" ";
    rowSum = 0;
  }

  std::cout<<"\nChecking the sums of every column: ";

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      colSum = colSum + arr[i][j];
    }
    std::cout<<colSum<<" ";
    colSum = 0;
  }

  std::cout<<"\nChecking the sums of every diagonal: ";

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      if (i == j) {
        topDiagSum = topDiagSum + arr[i][j];
      }
      if (i + j == n - 1) {
        lowDiagSum = lowDiagSum + arr[i][j];
      }
    }
  }

  std::cout<<topDiagSum<<" "<<lowDiagSum<<std::endl;

  return 0;
}
