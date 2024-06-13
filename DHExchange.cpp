//Create a C++ program that implements the Diffie Hellman Exchange by:
//Following the steps needed for a key exchange via the Diffie Hellman Exchange:
//-Establish 2 users; Alice and Bob 
//-Have Alice and Bob establish 2 values, p (prime number) and q (elements of this prime number never equal to p).
//-Both Alice and Bob choose private keys kA and kB (whole numbers)
//-Alice computes a public key: pkA: q^kA mod p
//-Bob computes b public key: pkB: q^kB mod p
//-create a shared value, s, using the public keys for Alice and Bob
//-Alice creates shared value, sA: pkB^kA mod p
//-Bob creates shares value, sB: pkA^kB mod p
//-shared values sA and sB should be the same between Alice and Bob, showing a working demonstration of the Diffie Hellman exchange.
// Ask the user of the program for inputs for Alice and Bob throughout, 
// use the program to calculate the required values and determine their outputs and if they are equal. Ensure the user inputs valid values for p, q, kA, and kB.

#include <cmath>  
#include <iostream>  
using namespace std;  

// function for finding the values with modular math.
// due to inherent limits within C, long long must be used as the int type
// in order to ensure that exponentiation doesn't overflow with values too high.
// Despite this, there is still a limit within this program, so small numbers 
// should be used for private keys kA and kB, pubkA and pubkB.

long long int modmath(long long int x, long long int y, long long int p1)
{
    if (y == 1)
        return x;
    else
        return (((long long int)pow(x, y)) % p1);
}

// Function for checking the status of numbers entered to see if they're prime.
// The variable "p" needs to be prime for Diffie Hellman exchange.
// The function works well and is an easy addition to the program to ensure 
// that no improper inputs are given
bool PrimeCheck(int a)
{
    if (a<= 1)
        return false;
    for (int i =2; i <= a / 2; i++)
        if (a % i == 0)
            return false;
    return true;
}

// Main function

int main()
{
    long long  int p, q, x, y, p1;
    long long  int kA, kB, pubkA, pubkB;
    long long  int sA; int sB;

    cout << "Please enter shared values, p and q, required for the Diffie Hellman Exchange" << "\n";
    cout << "Separate by space. 'p' should be a prime number, q should be a primitive root of p" << endl;
    cin >> p >> q;

    // check for prime numbers using primecheck function
    if (PrimeCheck(p) == false){
        cout << "p needs to be a PRIME number. \nPlease enter a prime number p" << endl;
        cin >> p;
    } 

    cout << "You've selected the values " << p << " for p, and " << q << " for q." << endl;
    
    // ask Alice and Bob for their private keys, pkA and pkB, which are to be whole numbers.
    cout << "Choose a private key for Alice" << "\n" << "This number needs to be a whole number" << endl;
    cin >> kA;
    cout << "Choose a private key for Bob (this needs to be a whole number)" << "\n";
    cin >> kB;
    cout << "Awesome. Alice's private key is " << kA << " and Bob's private key is " << kB << endl;

    // calculate pubkA and pubkB using modmath function and values inputted from the user

    pubkA = modmath(q, kA, p);
    pubkB = modmath(q, kB, p);
    cout << "Alice's public key : " << pubkA << "\n" << "Bob's public key: " << pubkB << endl;
    
    // calculate sA and sB, the values that Alice and Bob ultimately get.
    // These 2 values should be the same 
    sA = modmath(pubkB, kA, p); // something wrong with the math here
    sB = modmath(pubkA, kB, p);

    // debugging to check math :::: cout << sA << "\n" << sB << endl;

    //
    if (sA == sB){
        cout << "shared value sA for Alice is " << sA << " and the value sB for Bob is " << sB << "\nsA is equal to sB,";
        cout << "the Diffie Hellman Exchange was successful" << endl;
    } else{
        cout << "Something went wrong. p or q were either too large\n or " << q << " is likely not a primitive root of " << p << endl;
    }
    
    return 0;
}
