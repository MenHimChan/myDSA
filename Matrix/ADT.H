// ADT.h
#ifndef ADT_H  // 防止头文件重复包含
#define ADT_H
#include <iostream>

enum StorageType{ROW_MAJOR, COL_MAJOR};

// The Index of the matrix start from 0
class DiagMatrix
{
    private:
        int n;                                      // number of non-zero elements
        int* ptr;
    
    public:
        DiagMatrix(int n);                          // constructor
        DiagMatrix(const DiagMatrix& other);        // copy constructor
        ~DiagMatrix();                              // deconstructor
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
};

class LTriMatrix
{
    private:    
        int n;                                          // number of non-zero elements
        int* ptr;
        StorageType storagetype;                        // 代表着从矩阵映射到1D数组是Row major还是col major
    public:
        LTriMatrix(int n, StorageType type);            // parameters constructor
        ~LTriMatrix();                                  // deconstructor
        void Create();                                  // You just need to input the non-zero value of the matrix using this function
        void Set(int i, int j, int x);                  // Set the M[i][j] value to x
        int Get(int i, int j);                          // return the M[i][j] value
        int TotalElements() const {return n*(n+1)/2;}   // return the total elements num of the matrix
        int GetDim(){return n;}                         // return the dimension of the matrix
        void Display();                                 // Display the matrix
        void Display_1D();                              // Display the 1D array of the matrix
};

class UTriMatrix
{
    private:
        int n;                                          // number of non-zero elements
        int* ptr;
        StorageType storagetype;

    public:
        UTriMatrix(int n, StorageType type);            // parameters constructor
        ~UTriMatrix();                                  // deconstructor
        void Create();                                  // You just need to input the non-zero value of the matrix using this function
        void Set(int i, int j, int x);                  // Set the M[i][j] value to x
        int Get(int i, int j);                          // return the M[i][j] value
        int TotalElements() const {return n*(n+1)/2;}   // return the total elements num of the matrix
        int GetDim(){return n;}                         // return the dimension of the matrix
        void Display();                                 // Display the matrix
        void Display_1D();                              // Display the 1D array of the matrix 
};

class TriDiagMatrix
{
    private:
        int n;                                          // number of non-zero elements
        int* ptr;

    public:
        TriDiagMatrix(int n);                           // parameters constructor
        ~TriDiagMatrix();                               // deconstructor
        void Create();                                  // You just need to input the non-zero value of the matrix using this function
        int TotalElements() const {return 3*n - 2;}     // return the total elements num of the matrix
        int Get(int i, int j);                          // return the M[i][j] value
        void Set(int i, int j, int x);                  // set the M[i][j] to x
        void Display();                                 // Display the matrix
        void Display_1D();
};

class SparseMatrix
{
    private:
        int n,m;                                        // n*m 
        int nnz;                                        // number of non-zero elements
        int *row, *col, *val;                           // row, column, value array

    public:
        SparseMatrix(int n, int m, int nnz);            // parameters constructor
        SparseMatrix(const SparseMatrix& obj);          // copy constructor
        ~SparseMatrix();                                // deconstructor
        void Create();
        friend std::istream& operator>>(std::istream& is, const SparseMatrix& mat);      // overloading "cin >>"
        void Set(int i, int j, int x);
        int Get(int i, int j) const;
        void Display();
        friend std::ostream& operator<<(std::ostream& os, const SparseMatrix& mat);      // overloading "cout <<"
        SparseMatrix operator+(const SparseMatrix& other) const;                         // overloading "+"
        static SparseMatrix Add(const SparseMatrix& A, const SparseMatrix& B);
};

class Poly
{
    private:
        struct Term
        {
            int coeff;
            int exp;
        };
        int n;
        Term* ptr;
    
    public:
        Poly(int n);
        ~Poly();
        friend std::istream& operator>>(std::istream& is, Poly& poly);              // overloading cin >>
        friend std::ostream& operator<<(std::ostream& os, Poly& poly);              // overloading cout <<
        Poly operator+(const Poly& other) const;                                    // overloading +
        int Sum(int x);
};

#endif // ADT_H