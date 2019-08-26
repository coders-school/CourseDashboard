#include "Cipher.hpp"
#include <iostream>
#include <random>
#include <chrono>
#include <string>

Cipher::Cipher()
{
    createPrimeNumbers(maxPrime_);
    setPrimeNumberP();
    setPrimeNumberQ();
    setParameters();
}

void Cipher::getEncrypted()
{
    for (auto el : msgEncrypted)
    {
        std::cout << el;
    }
    std::cout << std::endl;
}

std::string Cipher::getDecrypted()
{
    std::string decryptedText = "";
    for (auto el : msgDecrypted)
    {
        decryptedText += static_cast<char>(el);
    }
    return decryptedText;
}

long int Cipher::encrypt(long int i, long int e, long int n)
{
    long int current, result;
    current = i - 97;
    result = 1;
    for (long int i = 0; i < e; i++)
    {
        result = result * current;
        result = result % n;
    }
    return result;
}

long int Cipher::decrypt(long int i, long int d, long int n)
{
    long int current, result;
    current = i;
    result = 1;
    for (long int i = 0; i < d; i++)
    {
        result *= current;
        result %=  n;
    }
    return result + 97;
}

void Cipher::encryption(std::string msg)
{   
    for (int i=0; i < msg.size(); i++)
    {
        msgEncrypted.push_back(encrypt(static_cast<long int>(msg[i]), e, n));
    }
    std::cout<< std::endl;
}

void Cipher::decryption()
{
    for (int i=0; i < msgEncrypted.size(); i++)
    {
        msgDecrypted.push_back(decrypt(msgEncrypted[i], d, n));
    }
}

long int Cipher::foundD(long int e, long int t)
{
    long int d =0;
    long int k =1;

    while(1)
    {
        k = k + t;
        if (k % e == 0)
        {
            d = (k / e);
            return d;
        }
    }
}

long int Cipher::gcd(long int e, long int t)
{
    while (e > 0)
    {
        long int temp;
        temp = e;
        e = t % e;
        t = temp;
    }
    return t;
}

long int Cipher::foundE(long int t)
{
    for (long int e = 2; e < t; e++)
    {
        if (gcd(e,t) == 1) return e;
    }
}

void Cipher::setParameters()
{
    n = this->p * this->q;
    t = ((this->p)-1) * ((this->q)-1);
    e = foundE(t);
    d = foundD(e, t);
}

void Cipher::getParameters()
{
    std::cout<< "p = "<< this->p << std::endl;
    std::cout<< "q = "<< this->q << std::endl;
    std::cout<< "n = "<< this->n << std::endl;
    std::cout<< "t = "<< this->t << std::endl;
    std::cout<< "e = "<< this->e << std::endl;
    std::cout<< "d = "<< this->d << std::endl;
    std::cout<< "Public key (n,e) = ("<< this->n << "," << this->e << ")"<< std::endl;
    std::cout<< "Private key (n,d) = ("<< this->n << "," << this->d << ")" <<std::endl;
}

void Cipher::setPrimeNumberP()
{
    int temp =0;
    do
    {
        temp = this->generateNumber();
    }
    while (temp == 0);
    this->p = temp;
}

void Cipher::setPrimeNumberQ()
{
    long int temp=0;
    do
    {
        temp = generateNumber();
    }
    while (p == temp || temp == 0);
    this->q = temp;
}

long int Cipher::generateNumber()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(2, primeVector_.size());

    return primeVector_[distribution(generator)];
}

bool Cipher::isPrime(long int n)
{
    long int tempN = n;
    while (tempN > 2)
    {
        tempN--;
        if (n%tempN == 0)
        {
            return false;
        }
    }
    return true;
}

void Cipher::createPrimeNumbers(long int max)
{
    for (int i = 2; i < max; i++)
    {
        if (isPrime(i))
        {
             this->primeVector_.push_back(i);
        }
    }
}

