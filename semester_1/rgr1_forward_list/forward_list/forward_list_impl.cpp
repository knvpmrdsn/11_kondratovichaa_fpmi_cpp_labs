#include "forward_list_impl.h"

ForwardList::ForwardList() : head_(nullptr), size_(0) {}

ForwardList::ForwardList(const ForwardList& rhs) 
{
    if (rhs.head_ == nullptr) 
    {
        head_ = nullptr;
        size_ = 0;
        return;
    }

    head_ = new Node(rhs.head_->value_);
    Node* current = head_;
    Node* rhs_node = rhs.head_->next_;

    size_ = 1;

    while (rhs_node != nullptr) 
    {
        current->next_ = new Node(rhs_node->value_);
        current = current->next_;
        rhs_node = rhs_node->next_;
        ++size_;
    }
}

ForwardList::ForwardList(size_t count, int32_t value) 
{
    for (size_t i = 0; i < count; i++) 
    {
        PushFront(value);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init) 
{
    head_ = nullptr;
    size_ = 0;
    Node* tail = nullptr;

    for (int32_t value : init) {
        Node* node = new Node(value);
        if (!head_) 
        {
            head_ = node;
            tail = node;
        } 
        
        else 
        {
            tail->next_ = node;
            tail = node;
        }
        ++size_;
    }
}

ForwardList& ForwardList::operator=(const ForwardList& rhs) 
{
    if (this == &rhs)
        return *this;

    Clear();

    if (rhs.head_ == nullptr) 
    {
        head_ = nullptr;
        size_ = 0;
        return *this;
    }

    head_ = new Node(rhs.head_->value_);
    size_ = 1;
    Node* current = head_;
    Node* rhs_node = rhs.head_->next_;

    while (rhs_node != nullptr) 
    {
        current->next_ = new Node(rhs_node->value_);
        rhs_node = rhs_node->next_;
        current = current->next_;
        ++size_;
    }

    return *this;
}

ForwardList::~ForwardList() 
{
    Clear();
}

void ForwardList::PushFront(int32_t value) 
{
    Node* node = new Node(value);
    node->next_ = head_;
    head_ = node;
    ++size_;
}

void ForwardList::PopFront() 
{
    if (head_ == nullptr)
        throw std::out_of_range("PopFront on empty list");

    Node* tmp = head_;
    head_ = head_->next_;
    delete tmp;
    --size_;
}

void ForwardList::Remove(int32_t value) 
{
    while (head_ != nullptr && head_->value_ == value) 
    {
        Node* tmp = head_;
        head_ = head_->next_;
        delete tmp;
        --size_;
    }

    if (head_ == nullptr)
        return;

    Node* prev = head_;
    Node* current = prev->next_;
    while (current != nullptr) 
    {
        if (current->value_ == value) 
        {
            prev->next_ = current->next_;
            delete current;
            current = prev->next_;
            --size_;
        } 

        else 
        {
            prev = current;
            current = current->next_;
        }
    }
}

void ForwardList::Clear() 
{
    Node* current = head_;
    while (current != nullptr) 
    {
        Node* next = current->next_;
        delete current;
        current = next;
    }
    size_ = 0;
    head_ = nullptr;
}

bool ForwardList::FindByValue(int32_t value) 
{
    Node* current = head_;
    while (current != nullptr) 
    {
        if (current->value_ == value)
            return true;
        current = current->next_;
    }
    return false;
}

void ForwardList::Print(std::ostream& out) 
{
    Node* current = head_;
    while (current != nullptr) 
    {
        out << current->value_;
        if (current->next_ != nullptr)
            out << ' ';
        current = current->next_;
    }
}

int32_t ForwardList::Front() const 
{
    if (head_ == nullptr) throw std::out_of_range("Front on empty list");
    return head_->value_;
}

size_t ForwardList::Size() const 
{
    return size_;
}