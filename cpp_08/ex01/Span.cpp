#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (numbers.size() >= N)
        throw std::runtime_error("Span is full");
    numbers.push_back(n);
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> tmp = numbers;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];

    size_t i = 1;
    while (i < tmp.size())
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
        i++;
    }

    return minSpan;
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());

    return max - min;
}


