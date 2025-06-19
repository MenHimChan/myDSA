#include "ADT.H"
#include <limits>
#include <cmath>
using namespace std;

////////////////////////////////////////// DiagMatrix //////////////////////////////////// 
DiagMatrix::DiagMatrix(int n)
{
    this -> n = n;
    ptr = new int[n];
}

DiagMatrix::DiagMatrix(const DiagMatrix& other)
{
    n = other.n;
    ptr = new int[n];
    for(int i = 0; i < n; i++)
        *(ptr + 1) = other.ptr[i];
}

DiagMatrix::~DiagMatrix()
{
    delete[] ptr;
}

void DiagMatrix::Set(int i, int j, int x)
{
    if(i == j)
        ptr[i] = x;
}

int DiagMatrix::Get(int i, int j)
{
    if(i == j)
        return ptr[i];
    else
        return 0;
}

void DiagMatrix::Display()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                cout << ptr[i] << ' ';
            else
                cout << '0' << ' ';
        }
        cout << endl;
    }
}

////////////////////////////////////////// LTriMatrix //////////////////////////////////// 
LTriMatrix::LTriMatrix(int n, StorageType type)
{
    this -> n = n;
    ptr = new int[n*(1+n) / 2];
    storagetype = type;
}

LTriMatrix::~LTriMatrix()
{
    delete[] ptr;
}

void LTriMatrix::Set(int i, int j, int x)
{
    int index;
    if(storagetype == ROW_MAJOR)
        index = i*(i + 1) / 2 + j;
    else
        index = i + j * n - j * (j + 1) / 2;
    if(i >= j)
        ptr[index] = x;
}

int LTriMatrix::Get(int i, int j)
{
    int index;
    if(storagetype == ROW_MAJOR)
        index = i * (i + 1) / 2 + j;
    else
        index = i + j * n - j * (j + 1) / 2;
    if(i < j)
        return 0;
    else
        return ptr[index];
}

void LTriMatrix::Display()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << Get(i, j) << ' ';
        cout << endl;
    }
}

void LTriMatrix::Display_1D()
{
    for(int i = 0; i < TotalElements(); i++)
        cout << *(ptr + i) << ' ';
}

/**
 * @brief 输入下三角矩阵的所有非零元素
 *
 * 示例输入与输出：
 * Input the non-zero elements of the Matrix: 1 2 3 4 5 6 7 8 9 10
 * ------
 * 1 0 0 0 
 * 2 5 0 0 
 * 3 6 8 0 
 * 4 7 9 10 
 * ------
 */
void LTriMatrix::Create()
{
    cout << "Input the non-zero elements of the Matrix:";
    for(int i = 0; i < TotalElements(); i++)
    {
        int tmp;
        cin >> tmp;
        ptr[i] = tmp;
    }
}

////////////////////////////////////////////////// Upper Triangle matrix //////////////////////////////////////
UTriMatrix::UTriMatrix(int n, StorageType type)
{
    this -> n = n;
    ptr = new int[n*(1+n) / 2];
    storagetype = type;
}

UTriMatrix::~UTriMatrix()
{
    delete[] ptr;
}

void UTriMatrix::Create()
{
    cout << "Input the non-zero elements of the Matrix:";
    for(int i = 0; i < TotalElements(); i++)
    {
        int tmp;
        cin >> tmp;
        ptr[i] = tmp;
    }
}

void UTriMatrix::Set(int i, int j, int x)
{
    if(i < n && j < n)
    {
        int index;
        if(storagetype == ROW_MAJOR)
            index = j + i*(2*n - i - 1)/2;
        else
            index = (1 + j)*j / 2 + i;
        if(i <= j)                      // 上三角矩阵只在i<=j时候才有非0值
            ptr[index] = x;
    }
}

int UTriMatrix::Get(int i, int j)
{
    if(i < n && j < n)
    {
        int index;
        if(storagetype == ROW_MAJOR)
            index = j + i*(2*n - i - 1)/2;
        else
            index = (1 + j)*j / 2 + i;
        
        if(i > j)
            return 0;
        else
            return ptr[index];
    }
    return numeric_limits<int>::min();              // 返回一个不正常的负值
}

void UTriMatrix::Display()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << Get(i, j) << ' ';
        cout << endl;
    }
}    

void UTriMatrix::Display_1D()
{
    for(int i = 0; i < TotalElements(); i++)
        cout << *(ptr + i) << ' ';
}

///////////////////////////////////// TriDiagMatrix ////////////////////////////
TriDiagMatrix::TriDiagMatrix(int n)
{
    this->n = n;
    ptr = new int[TotalElements()];
}

TriDiagMatrix::~TriDiagMatrix()
{
    delete[] ptr;
}

void TriDiagMatrix::Create()
{
    cout << "Input the non-zero elements of the Matrix:";
    for(int i = 0; i < TotalElements(); i++)
        cin >> ptr[i];
}

int TriDiagMatrix::Get(int i, int j)
{
    if(i < n && j < n)
    {
        if(abs(i - j) <= 1)
        {
            // main Diagnoal
            if(i == j)
                return ptr[n - 1 + j];
            // upper Diagnoal
            else if(i - j == -1)
                return ptr[2*n - 1 + i];
            // lower Diagnoal
            else
                return ptr[j];
        }
        else
            return 0;
    }
    else
        return numeric_limits<int>::min();              // 返回异常值
}

void TriDiagMatrix::Set(int i, int j, int x)
{
    if(i < n && j < n)
    {
        if(abs(i - j) <= 1)
        {
            // main Diagnoal
            if(i == j)
                ptr[n - 1 + j] = x;
            // upper Diagnoal
            else if(i - j == -1)
                ptr[j] = x;
            // lower Diagnoal
            else
                ptr[2*n - 1 + j] = x;
        }
    }
}

void TriDiagMatrix::Display()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << Get(i, j) << " ";
        cout << endl;
    }
}

void TriDiagMatrix::Display_1D()
{
    for(int i = 0; i < TotalElements(); i++)
        cout << *(ptr + i) << ' ';
}

/////////////////////////////////////// SparseMatrix /////////////////////////////////////
SparseMatrix::SparseMatrix(int n, int m, int nnz)
{
    this->n = n;
    this->m = m;
    this->nnz = nnz;

    val = new int[n*m];
    row = new int[n];
    col = new int[m];
}

SparseMatrix::SparseMatrix(const SparseMatrix& obj)
{
    n = obj.n;
    m = obj.m;
    nnz = obj.nnz;
    val = new int[n * m];
    row = new int[n];
    col = new int[m];
    for(int i = 0; i < nnz; i++)
    {
        val[i] = obj.val[i];
        row[i] = obj.row[i];
        col[i] = obj.col[i];
    }
}

SparseMatrix::~SparseMatrix()
{
    delete[] val;
    delete[] row;
    delete[] col;
}

void SparseMatrix::Create()
{
    for(int i = 0; i < nnz; i++)
    {
        printf("Input the nnz value of the Sparese Matrix, format is [row][backspace][col][backspace][val]: \n");
        cin >> row[i] >> col[i] >> val[i];
    }
}

std::istream& operator>>(std::istream& is, const SparseMatrix& mat)
{
    for(int i = 0; i < mat.nnz; i++)
        is >> mat.row[i] >> mat.col[i] >> mat.val[i];
    return is;
}

int SparseMatrix::Get(int i, int j) const
{
    if(i < n && j < m)
    {
        for(int k = 0; k < nnz; k++)
            if(row[k] == i && col[k] == j)
                return val[k];
        return 0;
    }
    else
        return numeric_limits<int>::min();              // return outliers
}

std::ostream& operator<<(std::ostream& os, const SparseMatrix& mat)
{
    os << "The sparse Matrix is: \n";
    for(int i = 0; i < mat.n; i++)
    {
        for(int j = 0; j < mat.m; j++)
            os << mat.Get(i, j) << ' ';
        os << '\n';
    }
    return os;
}

void SparseMatrix::Display()
{
    cout << "The sparse Matrix is: \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << Get(i, j) << ' ';
        cout << endl;
    }
}

void SparseMatrix::Set(int i, int j, int x)
{
    if(i < n && j < m)
    {
        for(int k = 0; k < nnz; k++)
        {
            if(row[k] == i && col[k] == j)
            {
                val[k] = x;
                return;
            }
        }
        val[nnz] = x;
        col[nnz] = j;
        row[nnz] = i;
        nnz++;
    }
    else
        cout << "Invalid Index !!!!" << endl;
}


// 两个待相加的矩阵必须满足非零元素数组（row、col、val）都按照“行优先，行相同时列递增”的顺序排列。
// 否则调用该函数得不到正确的结果。
// eg1: √
// row: 0 0 1 2 2
// col: 1 3 0 0 2
// val: ...

// eg2: ×
// row: 2 0 1 2 0
// col: 2 1 0 0 3
// val: ...
SparseMatrix SparseMatrix::operator+(const SparseMatrix& other) const
{
    if(m == other.m && n == other.n)
    {
        SparseMatrix ret(n, m, 0);
        int i = 0, j = 0;
        while(i < nnz && j < other.nnz)
        {
            if(row[i] == other.row[j] && col[i] == other.col[j])
            {
                ret.row[ret.nnz] = row[i];
                ret.col[ret.nnz] = col[i];
                ret.val[ret.nnz] = val[i] + other.val[j];
                ret.nnz++;
                i++; j++;
            }
            else if(row[i] < other.row[j] || (row[i] == other.row[j] && col[i] < other.col[j]))
            {
                ret.row[ret.nnz] = row[i];
                ret.col[ret.nnz] = col[i];
                ret.val[ret.nnz] = val[i];
                ret.nnz++;
                i++;
            }
            else
            {
                ret.row[ret.nnz] = other.row[j];
                ret.col[ret.nnz] = other.col[j];
                ret.val[ret.nnz] = other.val[j];
                ret.nnz++;
                j++;
            }
        }
        while(i < other.nnz)
        {
            ret.row[ret.nnz] = row[i];
            ret.col[ret.nnz] = col[i];
            ret.val[ret.nnz] = val[i];
            ret.nnz++;
            i++;
        }
        while(j < other.nnz)
        {
            ret.row[ret.nnz] = other.row[j];
            ret.col[ret.nnz] = other.col[j];
            ret.val[ret.nnz] = other.val[j];
            ret.nnz++;
            j++;
        }
        return ret;
    }
    else
    {
        throw invalid_argument("Matrix dimensions must agree");
        return SparseMatrix(0, 0, 0);
    }
}

SparseMatrix SparseMatrix::Add(const SparseMatrix& A, const SparseMatrix& B)
{
    if(A.m == B.m && A.n == B.n)
    {
        SparseMatrix ret(A.n, A.m, 0);          // n*m return matrix 
        int i=0, j =0;
        while (i < A.nnz && j < B.nnz)
        {
            if(A.row[i] == B.row[j] && A.col[i] == B.col[j])        // 行列均匹配上
            {
                ret.row[ret.nnz] = A.row[i];
                ret.col[ret.nnz] = A.col[i];
                ret.val[ret.nnz] = A.val[i] + B.val[j];
                ret.nnz++;
                i++; j++;
            }
            else if (A.row[i] < B.row[j] || (A.row[i] == B.row[j] && A.col[i] < B.col[j]))
            {
                ret.row[ret.nnz] = A.row[i];
                ret.col[ret.nnz] = A.col[i];
                ret.val[ret.nnz] = A.val[i];
                ret.nnz++;
                i++;
            }
            else
            {
                ret.row[ret.nnz] = B.row[j];
                ret.col[ret.nnz] = B.col[j];
                ret.val[ret.nnz] = B.val[j];
                ret.nnz++;
                j++;
            }
        }
        while(i < A.nnz)
        {
            ret.row[ret.nnz] = A.row[i];
            ret.col[ret.nnz] = A.col[i];
            ret.val[ret.nnz] = A.val[i];
            ret.nnz++;
            i++;
        }
        while (j < B.nnz)
        {
            ret.row[ret.nnz] = B.row[j];
            ret.col[ret.nnz] = B.col[j];
            ret.val[ret.nnz] = B.val[j];
            ret.nnz++;
            j++;  
        }
        return ret;
    }
    else
    {
        throw invalid_argument("Matrix dimensions must agree");
         // Add a dummy return to satisfy all code paths (should never reach here)
        return SparseMatrix(0, 0, 0);
    }
}

///////////////////////////// Polynomial ///////////////////////////
Poly::Poly(int n)
{
    this->n = n;
    ptr = new Term[n];
}

Poly::~Poly()
{
    delete[] ptr;
}

std::istream& operator>>(std::istream& is, Poly& poly)
{
    cout << "Input the Polynomial, format is [coeff][blankspace][exp]: \n";
    for(int i = 0; i < poly.n; i++)
        is >> poly.ptr[i].coeff >> poly.ptr[i].exp;
    return is;
}

int Poly::Sum(int x)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += ptr[i].coeff * (int)pow(x, ptr[i].exp);
    
    return sum;
}

std::ostream& operator<<(std::ostream& os, Poly& poly)
{
    os << "The Polynomial is : " << endl;
    for(int i = 0; i < poly.n; i++)
    {
        if(i == poly.n - 1)
            os << poly.ptr[i].coeff << "x^" << poly.ptr[i].exp;
        else
            os << poly.ptr[i].coeff << "x^" << poly.ptr[i].exp << " + ";
    }
    return os << '\n';
}

// The input of the exp term of the Polynomial has to be from high to low
// 高次幂到低次幂的顺序进行输入的多项式才能被这个函数进行相加，否则会出错
Poly Poly::operator+(const Poly& other) const
{
    int i=0, j=0;
    Poly ret(n + other.n);
    ret.n = 0;                                                  // 一个都没选进去
    while(i < n && j < other.n)
    {
        if(ptr[i].exp == other.ptr[j].exp)
        {
            int sum = ptr[i].coeff + other.ptr[j].coeff;
            if(sum != 0)                                        // 非0值才存
            {
                ret.ptr[ret.n].coeff = sum;
                ret.ptr[ret.n].exp = ptr[i].exp;
                ret.n++;
            }
            i++; j++;
        }

        else if(ptr[i].exp > other.ptr[j].exp)                  // 若exp项不相等，则先存高次幂项到ret中
        {
            ret.ptr[ret.n] = ptr[i];
            ret.n++;
            i++;
        }

        else
        {
            ret.ptr[ret.n] = other.ptr[j];
            ret.n++;
            j++;
        }
    }

    while(i < n)
    {
        ret.ptr[ret.n] = ptr[i];
        ret.n++;
        i++;
    }

    while(j < other.n)
    {
        ret.ptr[ret.n] = other.ptr[j];
        ret.n++;
        j++;
    }

    return ret;
}