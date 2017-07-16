#include <stdlib.h>
#include <stdio.h>

typedef struct {
    unsigned long long number;
    unsigned long long divisors;
} Divs;

static const unsigned long long primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
static const unsigned long long primorials[] =
{ 2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870, 6469693230,
    200560490130, 7420738134810, 304250263527210, 13082761331670030,
    614889782588491410 };

static const unsigned num_primes = sizeof primorials / sizeof primorials[0];

Divs max_divisors(unsigned long long limit);
Divs best_with(unsigned long long limit, unsigned index, unsigned multiplicity);

int main() {
    unsigned long long limit;
    scanf("%lld", &limit);
    Divs best = max_divisors(limit);
    printf("%llu\n", best.number);
    return 0;
}

Divs max_divisors(unsigned long long limit) {
    Divs result;
    if (limit < 3) {
        result.number = limit;
        result.divisors = limit;
        return result;
    }
    unsigned idx = num_primes;
    Divs best = best_with(limit,0,1);
    for(idx = 1; idx < num_primes && primorials[idx] <= limit; ++idx) {
        unsigned long long test = limit, remaining = limit;
        unsigned multiplicity = 0;
        do {
            ++multiplicity;
            test /= primorials[idx];
            remaining /= primes[idx];
            result = best_with(remaining, idx-1, multiplicity);
            int i;
            for(i = 0; i < multiplicity; ++i) {
                result.number *= primes[idx];
            }
            result.divisors *= multiplicity + 1;
            if (result.divisors > best.divisors) {
                best = result;
            } else if (result.divisors == best.divisors && result.number < best.number) {
                best = result;
            }
        }while(test >= primorials[idx]);
    }
    return best;
}

Divs best_with(unsigned long long limit, unsigned index, unsigned multiplicity) {
    Divs result = {1, 1};
    if (index == 0) {
        while(limit > 1) {
            result.number *= 2;
            ++result.divisors;
            limit /= 2;
        }
        return result;
    }
    Divs best = {0,0};
    unsigned long long test = limit, remaining = limit;
    --multiplicity;
    int i;
    for(i = 0; i < multiplicity; ++i) {
        test /= primorials[index];
        remaining /= primes[index];
    }
    do {
        ++multiplicity;
        test /= primorials[index];
        remaining /= primes[index];
        result = best_with(remaining, index-1, multiplicity);
        int i;
        for(i = 0; i < multiplicity; ++i) {
            result.number *= primes[index];
        }
        result.divisors *= multiplicity + 1;
        if (result.divisors > best.divisors) {
            best = result;
        } else if (result.divisors == best.divisors && result.number < best.number) {
            best = result;
        }
    }while(test >= primorials[index]);
    return best;
}

