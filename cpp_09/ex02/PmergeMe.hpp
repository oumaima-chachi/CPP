#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <stdexcept>

class PmergeMe 
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &o);
        PmergeMe &operator=(const PmergeMe &o);
        ~PmergeMe();

        void   parse(int argc, char **argv);
        void   sort();
        void   print(const char *label) const;

        double getTimeVec() const { return _timeVec; }
        double getTimeDeq() const { return _timeDeq; }
        size_t size()       const { return _vec.size(); }

    private:
        double           _timeVec;
        double           _timeDeq;
        std::vector<int> _vec;
        std::deque<int>  _deq;
};

#endif