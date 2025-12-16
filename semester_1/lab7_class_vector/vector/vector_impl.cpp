#include "vector_impl.h"

Vector::Vector() : data_(nullptr), size_(0), capacity_(0) {}

Vector::Vector(size_t size) : size_(size < 0 ? 0 : size), capacity_(size_) {
    data_ = new int[capacity_];
    for(size_t i = 0; i < size; i++)
    {
        data_[i] = 0;
    }
}

Vector::Vector(std::initializer_list<int> list) : size_(list.size()), capacity_(list.size()) {
    data_ = new int[capacity_];
    std::copy(list.begin(), list.end(), data_);
}

Vector::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    data_ = new int[capacity_];
    std::copy(other.data_, other.data_ + size_, data_);
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        Vector temp(other);
        Swap(temp);
    }
    return *this;
}

Vector::~Vector() {
    delete[] data_;
}

void Vector::Swap(Vector& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

int& Vector::operator[](size_t index) {
    return data_[index];
}

const int& Vector::operator[](size_t index) const {
    return data_[index];
}

int& Vector::At(size_t index) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

const int& Vector::At(size_t index) const {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

size_t Vector::Size() const {
    return size_;
}

size_t Vector::Capacity() const {
    return capacity_;
}

void Vector::PushBack(int value) {
    if (size_ == capacity_) {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        Reserve(new_capacity);
    }
    data_[size_++] = value;
}

void Vector::PopBack() {
    if (size_ > 0) {
        --size_;
    }
}

void Vector::Clear() {
    size_ = 0;
}

void Vector::Reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
        int* new_data = new int[new_capacity];
        std::copy(data_, data_ + size_, new_data);
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[";
    for (size_t i = 0; i < vec.Size(); ++i) {
        os << vec[i];
        if (i != vec.Size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
