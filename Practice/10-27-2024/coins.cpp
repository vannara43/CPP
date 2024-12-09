#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int factorial(int n)
{
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int binomialCoeff(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

double binomialProbability(int n, int k, double p)
{
    return binomialCoeff(n, k) * pow(p, k) * pow(1 - p, n - k);
}

int main()
{
    // Part A and C1
    double p_heads_fair = 0.5;
    double p_heads_biased = 0.6;
    int flips = 4, heads_count = 3;

    double probability_fair = binomialProbability(flips, heads_count, p_heads_fair);
    double probability_biased = binomialProbability(flips, heads_count, p_heads_biased);

    cout << "Theoretical probability of 3 heads and 1 tail in 4 flips (fair coin): "
         << probability_fair * 100 << "%" << endl;
    cout << "Theoretical probability of 3 heads and 1 tail in 4 flips (biased coin): "
         << probability_biased * 100 << "%" << endl;

    // Part B and C2
    srand(static_cast<unsigned>(time(nullptr)));
    int trials = 10000;
    int success_count_fair = 0, success_count_biased = 0;

    for (int i = 0; i < trials; ++i)
    {
        int heads_fair = 0, heads_biased = 0;

        for (int j = 0; j < 4; ++j)
        {
            if ((rand() / static_cast<double>(RAND_MAX)) < p_heads_fair)
                ++heads_fair;
            if ((rand() / static_cast<double>(RAND_MAX)) < p_heads_biased)
                ++heads_biased;
        }

        if (heads_fair == 3)
            ++success_count_fair;
        if (heads_biased == 3)
            ++success_count_biased;
    }

    double empirical_prob_fair = static_cast<double>(success_count_fair) / trials;
    double empirical_prob_biased = static_cast<double>(success_count_biased) / trials;

    cout << "Empirical probability of 3 heads and 1 tail in 4 flips (fair coin): "
         << empirical_prob_fair * 100 << "%" << endl;
    cout << "Empirical probability of 3 heads and 1 tail in 4 flips (biased coin): "
         << empirical_prob_biased * 100 << "%" << endl;

    return 0;
}
