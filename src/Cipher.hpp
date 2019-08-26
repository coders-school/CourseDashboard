#include <vector>
#include <string>

class Cipher
{
public:
    Cipher();
    void encryption(std::string msg);
    void getEncrypted();
    void decryption();
    std::string getDecrypted();
private:
    void createPrimeNumbers(long int);
    void setPrimeNumberP();
    void setPrimeNumberQ();
    void getParameters();
    void setParameters();
    long int foundE(long int);
    long int foundD(long int, long int);
    long int gcd(long int, long int);
    long int encrypt(long int, long int, long int);
    long int decrypt(long int, long int, long int);
    bool isPrime(long int);
    long int generateNumber();
    const int maxPrime_ = 30;
    long int p, q, n, t, e, d;
    std::vector<long int> msgEncrypted;
    std::vector<long int> msgDecrypted;
    std::vector<int> primeVector_;
};

