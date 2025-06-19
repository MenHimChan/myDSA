#include "ADT.H"
using namespace std;

int main()
{
    // DiagMatrix test
    // DiagMatrix diagmat(10);
    // for(int i = 0; i < 10; i++)
    //     diagmat.Set(i, i, 5);
    // diagmat.Display();

    // Low triangle matrix test
    // int tmp;
    // cout << "Input Dimension you want: ";
    // cin >> tmp;
    // LTriMatrix ltm(tmp, COL_MAJOR);
    // ltm.Create();
    // cout << "------" << endl;
    // ltm.Display();
    // cout << "------" << endl;
    // cout << ltm.Get(1, 0) << " " << ltm.Get(1,1) << " " << ltm.Get(1,2);       // M[1][0] , M[1][1], M[1][2]

    // Upper triangle matrix test
    // int tmp;
    // cout << "Input Dimension you want: ";
    // cin >> tmp;
    // UTriMatrix utm(tmp, COL_MAJOR);
    // utm.Create();
    // cout << "-------" << endl;
    // utm.Display();
    // cout << "------" << endl;
    // cout << utm.Get(1, 0) << " " << utm.Get(1,1) << " " << utm.Get(1,2) << endl;       // M[1][0] , M[1][1], M[1][2]
    // cout << "------" << endl;
    // utm.Display_1D();

    // TriDiagMatrix
    // TriDiagMatrix tdm(3);
    // tdm.Create();
    // tdm.Display();
    // cout << "------" << endl;
    // cout << tdm.Get(1, 0) << " " << tdm.Get(1,1) << " " << tdm.Get(1,2) << endl;       // M[1][0] , M[1][1], M[1][2]
    // cout << "------" << endl;
    // tdm.Display_1D();

    // Sparse Matrix
    // SparseMatrix sm1(3,4,4);
    // cin >> sm1;
    // sm1.Display();
    // cout << endl;

    // SparseMatrix sm2(3,4,4);
    // sm2.Create();
    // cout << sm2;
    // cout << endl;

    // SparseMatrix sm3 = SparseMatrix::Add(sm1,sm2);
    // sm3.Display();
    // cout << endl;

    // SparseMatrix sm4 = sm1 + sm2;
    // cout << sm4;

    // Polynomial 
    Poly p1(5);
    Poly p2(3);
    cin >> p1;
    cin >> p2;
    Poly p3 = p1 + p2;
    cout << p3;
    return 0;
}