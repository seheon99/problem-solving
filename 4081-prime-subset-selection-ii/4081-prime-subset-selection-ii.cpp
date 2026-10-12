using intpair = std::pair<int, int>;

class Solution {
    std::vector<int> primes;
    std::vector<std::vector<intpair>> cache;
    std::vector<std::vector<bool>> shouldTakePrime;

    intpair dp(int primeIndex, int remainingSum) {
        if (primeIndex >= primes.size()) {
            return {0, 0};
        }
    
        if (cache[primeIndex][remainingSum].first != -1) {
            return cache[primeIndex][remainingSum];
        }
    
        int currentPrime = primes[primeIndex];
    
        if (currentPrime > remainingSum) {
            return cache[primeIndex][remainingSum] = {0, 0};
        }

        intpair bestWithout = dp(primeIndex + 1, remainingSum);
        intpair bestWith = dp(primeIndex + 1, remainingSum - currentPrime);
        bestWith.first += currentPrime;
        bestWith.second++;
        if (
            bestWith.first > bestWithout.first ||
            (bestWith.first == bestWithout.first && bestWith.second <= bestWithout.second)
        ) {
            shouldTakePrime[primeIndex][remainingSum] = true;
            cache[primeIndex][remainingSum] = bestWith;
        } else {
            cache[primeIndex][remainingSum] = bestWithout;
        }
        return cache[primeIndex][remainingSum];
    }

public:
    std::vector<int> maxPrimeSubset(int primeLimit, int sumLimit) {
        std::vector<bool> isPrimeNumber(primeLimit + 1, true);
        isPrimeNumber[0] = isPrimeNumber[1] = false;

        for (int divisor = 2; divisor * divisor <= primeLimit; divisor++) {
            if (isPrimeNumber[divisor]) {
                for (int multiple = divisor * divisor;
                     multiple <= primeLimit;
                     multiple += divisor) {
                    isPrimeNumber[multiple] = false;
                }
            }
        }

        primes.clear();

        for (int number = 2; number <= primeLimit; number++) {
            if (isPrimeNumber[number]) {
                primes.push_back(number);
            }
        }

        int primeCount = primes.size();

        cache.assign(
            primeCount,
            std::vector<intpair>(sumLimit + 1, {-1, -1})
        );

        shouldTakePrime.assign(
            primeCount,
            std::vector<bool>(sumLimit + 1, false)
        );

        dp(0, sumLimit);

        std::vector<int> selectedPrimes;
        int remainingSum = sumLimit;

        for (int primeIndex = 0; primeIndex < primeCount; primeIndex++) {
            if (shouldTakePrime[primeIndex][remainingSum]) {
                selectedPrimes.push_back(primes[primeIndex]);
                remainingSum -= primes[primeIndex];
            }
        }

        return selectedPrimes;
    }
};