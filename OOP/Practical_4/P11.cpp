#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int **matrix;
int row, col;

void input();
void display();
void display_upper_half();
void display_lower_half();
void display_middle_row();
void display_middle_col();
int sum();
int sum_rows(int);
int sum_cols(int);
int sum_primary_diagonal();
int sum_secondary_diagonal();
bool is_symmetric();

void display_sum();
void display_row(int);

inline bool is_square() {
    return row == col;
}

inline bool odd_row() {
    return row&1;
}

inline bool odd_col() {
    return col&1;
}

int main() {
    input();
    
    cout << "You entered the following matrix:\n"; display(); cout << endl;
    cout << "The matrix is " << (is_symmetric()?"":"not ") << "symmetric"; cout << endl;
    cout << "The sum of its elements is " << sum(); cout << endl;
    cout << "The sum of its pirmary diagonal elements is " << sum_primary_diagonal(); cout <<endl;
    cout << "The sum of its secondary diagonal elements is " << sum_secondary_diagonal(); cout << endl;
    cout << "The following shows the sum of each row and colum:\n"; display_sum(); cout << endl;
    cout << "The upper half is \n"; display_upper_half(); cout << endl;
    cout << "The lower half is \n"; display_lower_half(); cout << endl;
    
    if(odd_col()) {
        cout << "The middle column is \n"; display_middle_col(); cout << endl;
    } else {
        cout << "There is no middle column."; cout << endl;
    }

    if(odd_row()) {
        cout << "The middle row is \n"; display_middle_row(); cout << endl;
    } else {
        cout << "There is no middle row."; cout << endl;
    }
}

void input() {
    cout << "Enter the number of columns: ";
    cin >> col;
    cout << "Enter the number of rows: ";
    cin >> row;

    matrix = new int*[row];
    for(int i=0; i<row; i++) {
        matrix[i] = new int[col];
        for(int j=0; j<col; j++) {
            cout << "["<< i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void display() {
    for(int i=0; i<row; i++) {
        display_row(i);
        cout << endl;
    }
}

bool is_symmetric() {
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            if(matrix[i][j] != matrix[j][i])
                return false;
    return true;
}

int sum() {
    int sum = 0;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            sum+=matrix[i][j];
    return sum;
}

int sum_primary_diagonal() {
    int sum = 0;
    for(int i=0; i<row; i++) {
        sum+=matrix[i][i];
    }
    return sum;
}

int sum_secondary_diagonal() {
    int sum = 0;
    for(int i=col-1; i>=0; i--) {
        sum+=matrix[col-1-i][i];
    }
    return sum;
}

int sum_rows(int r) {
    int sum = 0;
    for(int i=0; i<col; i++)
        sum+=matrix[r][i];
    return sum;
}

int sum_cols(int c) {
    int sum = 0;
    for(int i=0; i<row; i++)
        sum+=matrix[i][c];
    return sum;
}

void display_sum() {
    for(int i=0; i<row; i++) {
        display_row(i); cout << "= " << sum_rows(i) << endl;
    }
    for(int i=0; i<col; i++) {
        cout << "= ";
    }
    cout << endl;
    for(int i=0; i<col; i++) {
        cout << sum_cols(i) << " ";
    }
}

void display_row(int r) {
    for(int i=0; i<col; i++) {
        cout << matrix[r][i] << " ";
    }
}

void display_upper_half() {
    for(int i=0; i<row/2; i++) {
        display_row(i);
        cout << endl;
    }
}

void display_lower_half() {
    for(int i=row/2; i<row; i++) {
        display_row(i);
        cout << endl;
    }
}

void display_middle_row() {
    display_row(row/2 + 1);
}

void display_middle_col() {
    int c = col/2 + 1;
    for(int i=0; i<row; i++)
        cout << matrix[i][c] << endl;
}