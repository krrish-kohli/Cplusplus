// Name: Krrish Kohli
// Class CECS 325-01
// Project Name: Prog 6 - BigInt
// Due Date: 07/04/2025 

// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program

#include <iostream>
#include <vector> 
#include <string> 
#include<climits>
#include<iomanip>

using namespace std;


class BigInt
{
private:
    vector<char> v;
    BigInt fibo(BigInt n, BigInt a, BigInt b);
    BigInt fact(BigInt n, BigInt result) const;

public:
    BigInt(string);
    BigInt(int); 
    BigInt();
    BigInt operator/ (const BigInt &) const;
    BigInt operator% (const BigInt &) const;
    BigInt operator++(int);
    BigInt operator++( );
    BigInt operator[](int);
    BigInt operator+ (const BigInt &) const;
    BigInt operator- (const BigInt &) const;
    BigInt operator- (int);
    BigInt operator* (const BigInt &) const;

    void print();
    int size();
    BigInt fibo(BigInt);
    BigInt fact(BigInt) const;
    
    friend ostream& operator<<(ostream&, const BigInt&); 
    friend BigInt operator+ (int,const BigInt&);

    bool operator==(const BigInt&) const; 
	bool operator!=(const BigInt&) const;
	bool operator<=(const BigInt&) const;
    bool operator>=(const BigInt&) const; 
	bool operator< (const BigInt&) const; 
	bool operator> (const BigInt&) const;
    BigInt fibo();
    BigInt fact();
};
BigInt:: BigInt(string str) { 
    int i = str.size() -1;
    while (i>=0)
    {
        v.push_back(str[i] - '0');
        --i;
    }    
} 
BigInt::BigInt(int n) {
    char digit;
    do {
        digit = n % 10;
        v.push_back (digit);
        n/=10;
    } 
    while (n > 0);
}

BigInt::BigInt() {} 


BigInt BigInt::operator/(const BigInt& divisor) const{
    BigInt quotient;
    BigInt remainder = *this; 

    while (remainder >= divisor) 
    {
        BigInt subs(1);
        BigInt temp = divisor;
        while (remainder >= BigInt(5) * temp){
            temp = BigInt(5) * temp;
            subs = BigInt(5) * subs;
                
        }
        if (divisor == BigInt(0)) 
        { 
            throw std::runtime_error("Division by zero error");
        }
        remainder = remainder - temp;
        quotient = quotient + subs; 

        while (remainder >= temp){
            remainder = remainder - divisor;
            quotient = quotient + BigInt(1);    
    }
    
}
return quotient;
}
BigInt BigInt:: operator% (const BigInt& divisor) const{

    BigInt remainder = *this; 

    while (remainder >= divisor) 
    {
        BigInt subs = 1;
        
        while (remainder >= BigInt(2) * divisor){
            remainder = remainder - BigInt(2)* divisor;
        }
            while (remainder >= divisor){
            remainder = remainder - divisor;
            }
           
    }
    return remainder;

}


 BigInt BigInt::operator++(int)
{
    BigInt dummy(*this);
    *this = *this + 1; 
    return dummy;

}
BigInt BigInt::operator++()
{
    *this = *this + BigInt(1);
    return *this;
} 

BigInt BigInt:: operator[](int index)
{
 if (index < 0 || index >= v.size()) 
 {
    throw string("Index is not in range");
 }
 return BigInt(v[index]+'0');
}

BigInt BigInt::operator+(const BigInt& other) const{

	BigInt addition;
	int carry = 0;
	int length = max(v.size(), other.v.size());
		
	for (int i = 0; i < length || carry; ++i) {
		if (i == addition.v.size()) 
        {
            addition.v.push_back(0);
        }

		int sum = carry;
        if (i < v.size()) sum += v[i];
        if (i < other.v.size()) sum += other.v[i];
        
        addition.v[i] = sum % 10;
        carry = sum / 10;
	}
	return addition;
}
BigInt BigInt::operator-(const BigInt& other) const{

	BigInt sub = *this;
	int borrow = 0;
	
	for (int i = 0; i < other.v.size() || borrow; ++i) {
	     sub.v[i] -= borrow + (i < other.v.size() ? other.v[i] : 0);
	     borrow = sub.v[i] < 0; 
	     if (borrow)
         {
            sub.v[i] += 10;
         }
	}
	
	    while (sub.v.size() > 1 && sub.v.back() == 0) {
	        sub.v.pop_back();
	   }
	return sub;
	    
}




BigInt BigInt:: operator- (int num){
    BigInt sub(num);
    return *this - sub;
}
BigInt BigInt::operator*(const BigInt& other) const{

	BigInt product;
    product.v.resize(v.size() + other.v.size());

    for (int i = 0; i < v.size(); ++i) {
        int carry = 0;
        for (int j = 0; j < other.v.size() || carry; ++j) {
            int temp = product.v[i + j] + v[i] * (j < other.v.size() ? other.v[j] : 0) + carry;
            product.v[i + j] = temp % 10;
            carry = temp / 10;
        }
    }

   while (product.v.size() > 1 && product.v.back() == 0) {
      product.v.pop_back();
   }
   return product;
}


void BigInt::print()
{
    for (int i = v.size()-1; i>=0; --i)
    {
        cout << static_cast<int>(v[i]);
    }
}
int BigInt::size()
{
    return v.size();
}


BigInt BigInt::fibo(BigInt n, BigInt a, BigInt b) {
    if (n == BigInt(0)){
        return a;
    }
    return fibo(n - BigInt(1), b, a + b);
}

BigInt BigInt::fibo() {
    return fibo(*this);
}


BigInt BigInt::fact(BigInt n, BigInt result) const {
    if (n == BigInt(0)){
        return result;
    }
    return fact(n - BigInt(1), result * n);
}

BigInt BigInt::fact() {
    return fact(*this);
}

BigInt BigInt::fibo(BigInt n) {
    return fibo(n, BigInt(0), BigInt(1));
}

BigInt BigInt::fact(BigInt n) const {
    return fact(n, BigInt(1));
}


ostream& operator<<(ostream& os, const BigInt& num) {

    if (num.v.size() <= 12) {
        for (int i = num.v.size() - 1; i >= 0; --i) {
            os << static_cast<int>(num.v[i]);
        }
    } else {
        os << fixed << setprecision(7) << scientific;
        os << static_cast<int>(num.v.back()) << ".";
        for (int i = num.v.size() - 2; i > num.v.size() - 8; --i) {
            os << static_cast<int>(num.v[i]);
        }
        os << "e" << (num.v.size() - 1);
    }
    return os;
}

    BigInt operator+ (int i, const BigInt& b) 
    {
        return BigInt(i) + b;
    }

    bool BigInt::operator>= (const BigInt& other) const
    {
        return !(*this < other);
    }
    bool BigInt::operator<(BigInt const& other) const
    {
        if (v.size() != other.v.size()) 
        {
            bool y = v.size() < other.v.size();
            return y;
        }
        for (int i = v.size() - 1; i>= 0; --i)
        {
            if ((v[i] != other.v[i])) 
            {
               bool l = v[i] < other.v[i]; 
               return l;
            }
        }
        return false;
    }

    bool BigInt::operator!=(const BigInt& other) const {
        return !(*this == other);
    }

bool BigInt::operator==(const BigInt& other) const{
	 return v == other.v;
}

bool BigInt::operator>(const BigInt& other) const{
    return !(*this <= other);
} 

bool BigInt::operator<=(const BigInt& other) const{
    return (*this < other) || (*this == other);
}



void testUnit()
{
int space = 10;
cout << "\a\nTestUnit:\n"<<flush;
system("whoami");
system("date");
// initialize variables
BigInt n1(25);
BigInt s1("25");
BigInt n2(1234);
BigInt s2("1234");
BigInt n3(n2);
BigInt fibo(12345);
BigInt fact(50);
BigInt imax = INT_MAX;
BigInt big("9223372036854775807");
// display variables
cout << "n1(int) :"<<setw(space)<<n1<<endl;
cout << "s1(str) :"<<setw(space)<<s1<<endl;
cout << "n2(int) :"<<setw(space)<<n2<<endl;
cout << "s2(str) :"<<setw(space)<<s2<<endl;
cout << "n3(n2) :"<<setw(space)<<n3<<endl;
cout << "fibo(12345):"<<setw(space)<<fibo<<endl;
cout << "fact(50) :"<<setw(space)<<fact<<endl;
cout << "imax :"<<setw(space)<<imax<<endl;
cout << "big :"<<setw(space)<<big<<endl;
cout << "big.print(): "; big.print(); cout << endl;
cout << n2 << "/"<< n1<< " = "<< n2/n1 <<" rem "<<n2%n1<<endl;
cout << "fibo("<<fibo<<") = "<<fibo.fibo() << endl;
cout << "fact("<<fact<<") = "<<fact.fact() << endl;
cout << "10 + n1 = " << 10+n1 << endl;
cout << "n1 + 10 = " << n1+10 << endl;
cout << "(n1 == s1)? --> "<<((n1==s1)?"true":"false")<<endl;
cout << "n1++ = ? --> before:"<<n1++<<" after:"<<n1<<endl;
cout << "++s1 = ? --> before:"<<++s1<<" after:"<<s1<<endl;
cout << "s2 * big = ? --> "<< s2 * big<<endl;
cout << "big * s2 = ? --> "<< big * s2<<endl;
} 

int main()
{
    testUnit();

    return 0;
}

