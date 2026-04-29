#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;

    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int n);

        template <typename Iterator>
        void addRng(Iterator begin, Iterator end)
        {
            while (begin != end)
            {
                if (numbers.size() >= N)
                    throw std::runtime_error("Span is full");

                numbers.push_back(*begin);
                ++begin;
            }
        }

        int shortestSpan();
        int longestSpan();
    };

#endif