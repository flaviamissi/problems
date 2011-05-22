#include <iostream>
#include <vector>

using namespace std;

bool is_prime(unsigned long long number){
    unsigned long long divisors = 2; //1 and the number itself

    if(number != 2 and number % 2 == 0)
        divisors++;

    for(unsigned long long i = 3; i < number; i += 2){
        if(number % i == 0)
            divisors++;
        if(divisors > 2)
            break;
    }

    if(divisors > 2)
        return false;
    return true;
}

bool is_factor(unsigned long long number, unsigned long long i){
    return number % i == 0;
}

vector<unsigned long long> get_factor_primes(unsigned long long number){
    vector<unsigned long long> primes;

    if(number % 2 == 0 and is_factor(number, 2))
        primes.push_back(2);

    for(int i = 3; i <= number; i += 2){
        if(is_factor(number, i) and is_prime(i)){
            primes.push_back(i);
        }
    }

    return primes;
}

int main(){
    vector<unsigned long long> primes = get_factor_primes(600851475143);
    for(int i = 0; i < primes.size(); i++){
        cout << primes[i] << endl;
    }
}
