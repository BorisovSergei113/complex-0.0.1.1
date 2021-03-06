#include <iostream>
#include <sstream>
using namespace std;
struct complex_t
{
    
    float real;
    float imag;
    
    complex_t()
    {
        real=0.0f; imag=0.0f;
    }
    
    complex_t add(complex_t other)
    const {
        complex_t result;
        result.real=real+other.real;       //this -complex_t const
        result.imag=imag+other.imag;
        return result;
    }
    complex_t sub(complex_t other) const {
        complex_t result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }
    complex_t mult(complex_t other) const {
        complex_t result;
        result.real = real*other.real - imag*other.imag;
        result.imag = real*other.imag + other.real*imag;
        return result;
    }
    complex_t div(complex_t other )
    const {
        complex_t result;
        result.real = (real*other.real + imag*other.imag) / (other.real*other.real + other.imag*other.imag);
        result.imag = (imag*other.real - real*other.imag) / (other.real*other.real + other.imag*other.imag);
        return result;
    }
    istream & read (istream & stream) {
        char op1, op2, op3;
        float real, imag;
        if (stream >> op1 && op1 == '(' && stream >> real && stream >> op2 && op2 == ',' && stream >> imag && stream >> op3 && op3 == ')')
        {
            this->real = real;
            this->imag = imag;
        }
        else {
            stream.setstate(std::ios::failbit);
        }
        return stream;
    }
    ostream & write(ostream & stream) const {
        return stream << '(' << real << ',' << imag << ')' << endl;
    }
};

int main()
{
    complex_t a,b,res;
    char op;
    
    if (a.read(cin) && (cin >> op) && b.read(cin)) {
        
        switch (op) {
            case '+':
                res  = a.add(b);
                res.write(cout);
                break;
            case '-':
                res = a.sub(b);
                res.write(cout);
                break;
            case '*':
                res = a.mult(b);
                res.write(cout);
                break;
            case '/':
                res = a.div(b);
                res.write(cout);
                break;
            default:
                cout << '\n' << "An error has occured while reading input data";
                break;
        }
    }
    else {
        cout << endl << "An error has occured while reading input data";
    }
    
    return 0;
}

