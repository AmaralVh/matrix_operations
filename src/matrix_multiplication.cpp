#include <iostream>
#include <vector>

using namespace std;


typedef vector<vector<double>> vvd;
typedef struct Matrix {
    int sizei;
    int sizej;
    vvd mt;
} matrix;

void print_matrix(matrix m) {
    for(int i = 0; i < m.sizei; i++){
        for(int j = 0; j < m.sizej; j++) {
            cout << m.mt[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void allocate_matrix(matrix &m) {
    m.mt.resize(m.sizei);
    
    for(int i = 0; i < m.sizei; i++) {
        m.mt[i].resize(m.sizej);
    }
}

void input_matrix(matrix &m) {
    for(int i = 0; i < m.sizei; i++) {
        for(int j = 0; j < m.sizej; j++) {
            cin >> m.mt[i][j];
        }
    }
}

matrix multiply_matrices(matrix m1, matrix m2) {
    matrix r;
    r.sizei = m1.sizei;
    r.sizej = m2.sizej;
    allocate_matrix(r);

    for(int i = 0; i < r.sizei; i++) {
        for(int j = 0; j < r.sizej; j++) {
            double soma = 0;
            for(int k = 0; k < m1.sizej; k++) {
                soma += m1.mt[i][k] * m2.mt[k][j];
            }
            r.mt[i][j] = soma;
        }
    }

    return r;
}

void copy_matrix(matrix &m1, matrix m2) {
    for(int i = 0; i < m1.sizei; i++) {
        for(int j = 0; j < m1.sizej; j++) {
            m1.mt[i][j] = m2.mt[i][j];
        }
    }
}

void simple_multiplication() {
    matrix m1, m2;

    cout << "Type the dimensions of matrix 1:" << endl;
    cin >> m1.sizei >> m1.sizej;
    cout << "Type the dimensions of matrix 2:" << endl;
    cin >> m2.sizei >> m2.sizej;

    // Verify if it is possible to multiply the matrices:
    if(m1.sizej != m2.sizei) {
        cout << "It's not possible to multiply the matrices due to their dimensions." << endl;
        return;
    }

    allocate_matrix(m1);
    allocate_matrix(m2);

    cout << "Type the elements of matrix 1: " << endl;
    input_matrix(m1);
    cout << "Type the elements of matrix 2: " << endl;
    input_matrix(m2);

    cout << endl;

    print_matrix(m1);
    print_matrix(m2);

    matrix res = multiply_matrices(m1, m2);

    print_matrix(res);
}

void power_multiplication() {
    matrix m;
    int power;

    cout << "Type the dimensions of the matrix:" << endl;
    cin >> m.sizei >> m.sizej;
    allocate_matrix(m);

    cout << "Type the elements of the matrix: " << endl;
    input_matrix(m);

    cout << endl;

    cout << "Type the number of the power: ";
    cin >> power;

    matrix res;

    if(power < 0) {
        cout << "Invalid value of power!" << endl;
        return;
    }

    if(power == 0) {
        res.mt.resize(m.sizei);
        for(int i = 0; i < m.sizei; i++) {
            res.mt[i].assign(m.sizej, 1);
        }
    }
    else if(power == 1) {
        res = m;
    }
    else {
        matrix mAux;
        mAux.sizei = m.sizei;
        mAux.sizej = m.sizej;
        allocate_matrix(mAux);
        copy_matrix(mAux, m);

        for(int n = 0; n < power-1; n++) {
            mAux = multiply_matrices(mAux, m);
        }

        res = mAux;
    }

    print_matrix(res);
}


int main() {
    int option = 0;

    

    do {
        cout << "Choose an option:" << endl << endl;
        cout << "1 - Multiplication of two matrices." << endl;
        cout << "2 - Matrix raised to a power." << endl;
        cout << "3 - Close calculator." << endl;

        cin >> option;

        switch(option) {
            case 1:
                simple_multiplication();
                break;
            case 2:
                power_multiplication();
                break;
            case 3:
                cout << "Closing calculator, see you soon!" << endl;
                break;
            default:
                cout << "Invalid choice, choose another one." << endl;
                break;
        }
    } while(option != 3);

    return 0;
}