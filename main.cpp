#include <iostream>

using namespace std;
class Bits{
    bool binary[8]{};
    Bits() =default;
public:
    static Bits& instantiate( );
    Bits( const Bits& ) = delete;
    Bits& operator=( const Bits& ) = delete;
    Bits& operator<<(unsigned char c);
    friend ostream& operator<<(ostream& os, const Bits& b);
};
ostream& operator<<(ostream& os, const Bits& b){
    for (unsigned int i : b.binary) {
        os << i;
    }
    return os;
}
ostream& operator<<(const Bits& b, unsigned char ch){

    return cout << b;
}


Bits& bits = Bits::instantiate( );
Bits& Bits::instantiate( ) {
    static Bits b;
    return b;
}

Bits& Bits::operator<<(unsigned char c){
    unsigned char m = 0x80;
    for (bool & i : binary) {
        if ( c & m ) {
            i = 1;
        }
        else {
            i = 0;
        }
        m = m >> 1;
    }
    return *this;
}


int main() {
    unsigned char x = 4;
    bits << x;
    cout << bits << endl;
    return 0;
}
