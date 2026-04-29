#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

    template <typename T>
    
    class Array
    {
    private:
        T* data;
        unsigned int _size;

    public:

        Array()
        {
            data = NULL;
            _size = 0;
        }

        Array(unsigned int n)
        {
            _size = n;
            data = new T[n];
        }

        Array(const Array &other)
        {
            _size = other._size;
            data = new T[_size];

            unsigned int i = 0;
            while (i < _size)
            {
                data[i] = other.data[i];
                i++;
            }
        }

        Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                delete[] data;

                _size = other._size;
                data = new T[_size];

                unsigned int i = 0;
                while (i < _size)
                {
                    data[i] = other.data[i];
                    i++;
                }
            }
            return *this;
        }

        ~Array()
        {
            delete[] data;
        }

        T &operator[](unsigned int i)
        {
            if (i >= _size)
                throw std::exception();
            return data[i];
        }

        const T &operator[](unsigned int i) const
        {
            if (i >= _size)
                throw std::exception();
            return data[i];
        }

        unsigned int size() const
        {
            return _size;
        }
    };

#endif