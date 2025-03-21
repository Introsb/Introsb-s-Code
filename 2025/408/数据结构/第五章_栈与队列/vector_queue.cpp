# include <iostream>
# include <vector>
# include <stdexcept>
# include <cstddef>
using namespace std;

template <typename T>
class VectorQueue
{
    private:
        vector<T> data;
        size_t front_index;
        size_t current_size;

        void resize(size_t new_capacity)
        {
            vector<T> new_data(new_capacity);
            for (size_t i = 0; i < current_size; ++i)
            {
                new_data[i] = data[(front_index + i) % data.capacity()];
            }
            data = move(new_data);
            front_index = 0;
        }
        
    public:
        VectorQueue() : front_index(0), current_size(0)
        {
            data.reserve(1);
        }

        void push(const T& value)
        {
            if (current_size == data.capacity())
            {
                size_t new_capacity = (data.capacity() == 0) ? 1 : data.capacity() * 2;
                resize(new_capacity);
            }
            size_t back_index = (front_index + current_size) % data.capacity();
            data[back_index] = value;
            ++current_size;
        }

        void pop()
        {
            if (empty())
            {
                throw runtime_error("pop from empty queue");
            }
            front_index = (front_index + 1) % data.capacity();
            --current_size;
        }

        T& front()
        {
            if (empty())
            {
                throw runtime_error("front from empty queue");
            }
            return data[front_index];
        }

        const T& front() const {
            if (empty()) {
                throw runtime_error("front from empty queue");
            }
            return data[front_index];
        }

        T& back()
        {
            if (empty())
            {
                throw runtime_error("back from empty queue");
            }
            size_t back_index = (front_index + current_size - 1) % data.capacity();
            return data[back_index];
        }

        const T& back() const {
            if (empty()) {
                throw runtime_error("back from empty queue");
            }
            size_t back_index = (front_index + current_size - 1) % data.capacity();
            return data[back_index];
        }
    
        bool empty() const {
            return current_size == 0;
        }
    
        size_t size() const {
            return current_size;
        }
    
        size_t capacity() const {
            return data.capacity();
        }
};