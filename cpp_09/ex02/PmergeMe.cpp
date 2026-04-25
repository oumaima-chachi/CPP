#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVec(0), _timeDeq(0), _vec(), _deq() 
{}
PmergeMe::PmergeMe(const PmergeMe &o) : _timeVec(o._timeVec), _timeDeq(o._timeDeq), _vec(o._vec), _deq(o._deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &o) 
{
    if (this != &o) { _vec = o._vec; _deq = o._deq; }
    return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::parse(int argc, char **argv) 
{
    for (int i = 1; i < argc; i++) 
    {
        std::istringstream ss(argv[i]);
        int n;
        char leftover;
        if (!(ss >> n) || ss >> leftover || n < 0)
            throw std::runtime_error("Error");
        if (std::find(_vec.begin(), _vec.end(), n) != _vec.end())
            continue;
        _vec.push_back(n);
        _deq.push_back(n);
    }
}

// static std::vector<int> jacobsthalOrder(int n)
// {
//     std::vector<int> jacob;
//     jacob.push_back(1);
//     jacob.push_back(3);
//     while (jacob.back() < n)
//     {
//         int size = jacob.size();
//         int next = jacob[size - 1] + 2 * jacob[size - 2];
//         jacob.push_back(next);
//     }
//     std::vector<int> order;
//     int prev = 1;
//     for (int i = 1; i < (int)jacob.size(); i++)
//     {
//         int curr = jacob[i];
//         for (int j = curr; j > prev; j--)
//         {
//             if (j <= n)
//                 order.push_back(j);
//         }
//         prev = curr;
//     }
//     // order.push_back(0);
//     return order;
// }


static std::vector<int> jacobsthalOrder(int n)
{
    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(1);
    while (jacob.back() < n)
    {
        int sz = jacob.size();
        jacob.push_back(jacob[sz - 1] + 2 * jacob[sz - 2]);
    }
    std::vector<int> order;
    int prev = 1;
    for (size_t i = 2; i < jacob.size(); ++i)
    {
        int curr = jacob[i];

        for (int j = std::min(curr, n); j > prev; --j)
        {
            order.push_back(j - 1);
        }
        prev = curr;
    }
    return order;
}

static void mergeInsertVec(std::vector<int> &v)
{
    if (v.size() <= 1)
        return;
    std::vector<std::pair<int, int> > pairs;
    int i = 0;
    
    while (i + 1 < (int)v.size())
    {
        int a = v[i];
        int b = v[i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(b, a));
        i += 2;
    }

    bool hasOdd = v.size() % 2 != 0;
    int  odd    = 0;
    if (hasOdd)
        odd = v.back();
    
    std::vector<int> big;
    for (int j = 0; j < (int)pairs.size(); j++)
    {
        big.push_back(pairs[j].second);
    }

    mergeInsertVec(big);
    
    std::vector<std::pair<int, int> > result;
    for (std::vector<int>::iterator at = big.begin(); at != big.end(); ++at)
    {
          for (size_t i = 0; i < pairs.size(); i++)
        {
            if (*at == pairs[i].second)
            {
                result.push_back(pairs[i]);
                break;
            }
        }
    }

    if (!result.empty())
    big.insert(big.begin(), result[0].first);
    std::vector<int> order = jacobsthalOrder(pairs.size());
    for (int j = 0; j < (int)order.size(); j++)
    {
        int idx = order[j];
        if (idx >= (int)pairs.size())
            continue;

        int smallVal = result[idx].first;
        int bigVal   = result[idx].second;

        std::vector<int>::iterator bound = std::find(big.begin(), big.end(), bigVal);
        std::vector<int>::iterator  pos   = std::lower_bound(big.begin(), bound, smallVal);
        big.insert(pos, smallVal);
    }
    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(big.begin(), big.end(), odd);
        big.insert(pos, odd);
    }
    v = big;
}

static void mergeInsertDec(std::deque<int> &v)
{
    if (v.size() <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
    int i = 0;

    while (i + 1 < (int)v.size())
    {
        int a = v[i];
        int b = v[i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(b, a));
        i += 2;
    }

    bool hasOdd = v.size() % 2 != 0;
    int odd = hasOdd ? v.back() : 0;

    std::deque<int> big;
    for (int j = 0; j < (int)pairs.size(); j++)
        big.push_back(pairs[j].second);

    mergeInsertDec(big);

    std::vector<std::pair<int, int> > result;

    for (std::deque<int>::iterator at = big.begin(); at != big.end(); ++at)
    {
        for (size_t i = 0; i < pairs.size(); i++)
        {
            if (*at == pairs[i].second)
            {
                result.push_back(pairs[i]);
                break;
            }
        }
    }

    if (!result.empty())
    {
        std::deque<int>::iterator pos =
            std::lower_bound(big.begin(), big.end(), result[0].first);
        big.insert(pos, result[0].first);
    }

    std::vector<int> order = jacobsthalOrder(pairs.size());

    for (int j = 0; j < (int)order.size(); j++)
    {
        int idx = order[j];
        if (idx >= (int)pairs.size())
            continue;

        int smallVal = result[idx].first;
        int bigVal   = result[idx].second;

        std::deque<int>::iterator bound = std::find(big.begin(), big.end(), bigVal);
        std::deque<int>::iterator pos   = std::lower_bound(big.begin(), bound, smallVal);
        big.insert(pos, smallVal);
    }

    if (hasOdd)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(big.begin(), big.end(), odd);
        big.insert(pos, odd);
    }

    v = big;
}


void PmergeMe::sort() 
{
    std::clock_t s = std::clock();
    mergeInsertVec(_vec);
    _timeVec = (double)(std::clock() - s) / CLOCKS_PER_SEC * 1e6;

    s = std::clock();
    mergeInsertDec(_deq);
    _timeDeq = (double)(std::clock() - s) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::print(const char *label) const 
{
    std::cout << label;
    for (int i = 0; i < (int)_vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << "\n";
}