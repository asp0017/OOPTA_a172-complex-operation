#include <iostream>
using namespace std;

class Complex {
public:
    //constructor 1
    Complex() { 
        this->real = 0;
        this->imaginary = 0;
    }
    //constructor 2
    Complex(int r, int i) { 
        this->real = r;
        this->imaginary = i;
    }
    //copy constructor
    Complex(const Complex& n) {
        this->real = n.real;
        this->imaginary = n.imaginary;
    }
    //destructor
    ~Complex() {} 
    //operator overloading
    Complex& operator+(Complex n);
    Complex& operator-(Complex n);
    Complex& operator*(Complex n);
    Complex& operator+=(Complex n);
    Complex& operator++(); //++C1
    Complex& operator++(int); //C1++
    Complex& operator--(); //--C1
    Complex& operator--(int); //C1--
    //comparison overloading
    bool operator==(Complex n);
    bool operator>(Complex n);
    bool operator<(Complex n);
    friend ostream& operator<<(ostream& out, const Complex& n);
    friend istream& operator>>(istream& in, Complex& n);
private:
    int real;
    int imaginary;
};

Complex& Complex::operator+(Complex n) {
    Complex* temp = new Complex();
    temp->real = this->real + n.real;
    temp->imaginary = this->imaginary + n.imaginary;
    return *temp;
}
Complex& Complex::operator-(Complex n) {
    Complex* temp = new Complex();
    temp->real = this->real - n.real;
    temp->imaginary = this->imaginary - n.imaginary;
    return *temp;
}
Complex& Complex::operator*(Complex n) {
    /* this: a+bi
          n: c+di
       temp: (ac-bd)+(ad+bc)i */
    Complex* temp = new Complex();
    temp->real = (this->real * n.real) - (this->imaginary * n.imaginary);
    temp->imaginary = (this->real * n.imaginary) + (this->imaginary * n.real);
    return *temp;
}
Complex& Complex::operator+=(Complex n) {
    *this = *this + n;
    return *this;
}
//++C1
Complex& Complex::operator++() {
    this->real++;
    this->imaginary++;
    return *this;
}
//C1++
Complex& Complex::operator++(int) {
    Complex* temp = new Complex();
    temp->real = this->real;
    temp->imaginary = this->imaginary;
    ++(*this);
    return *temp;
}
//--C1
Complex& Complex::operator--() {
    this->real--;
    this->imaginary--;
    return *this;
}
//C1--
Complex& Complex::operator--(int) {
    Complex* temp = new Complex();
    temp->real = this->real;
    temp->imaginary = this->imaginary;
    --(*this);
    return *temp;
}
//comparison overloading
bool Complex::operator==(Complex n) {
    if (this->real != n.real) return false;
    else if (this->imaginary != n.imaginary) return false;
    return true;
}
bool Complex::operator>(Complex n) {
    if (*this == n) return false;
    else if (this->real == n.real) {
        if (this->imaginary < n.imaginary) return false;
        return true;
    }
    else {
        if (this->real < n.real) return false;
        else return true;
    }
}
bool Complex::operator<(Complex n) {
    if (*this == n) return false;
    else if (*this > n) return false;
    return true;
}
ostream& operator<<(ostream& out, const Complex& n) {
    if (n.imaginary < 0) out << n.real << n.imaginary << "i" << endl;
    else out << n.real << "+" << n.imaginary << "i" << endl;
    return out;
}
istream& operator>>(istream& in, Complex& n) {
    in >> n.real >> n.imaginary;
    return in;
}

int main() {

    Complex C1, C2;
    while (cin >> C1 >> C2) {
        cout << "C1 = " << C1 << endl;
        cout << "C2 = " << C2 << endl;

        cout << "C1==C2? " << ((C1 == C2) ? "true" : "false") << endl;
        cout << "C1<C2?  " << ((C1 < C2) ? "true" : "false") << endl;
        cout << "C1>C2?  " << ((C1 > C2) ? "true" : "false") << endl;

        cout << "C1+C2 = " << C1 + C2 << endl;
        cout << "C1-C2 = " << C1 - C2 << endl;
        cout << "C1*C2 = " << C1 * C2 << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "--C2  = " << --C2 << endl;
        cout << "--C2  = " << --C2 << endl;

        C1 += C2;
        cout << "C1+=C2  " << C1 << endl;
        cout << "==============" << endl;
    }
    return 0;
}