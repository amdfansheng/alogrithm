#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <utility>
#include <cstddef>              // ptrdiff_t
#include <iterator>             // std::input_iterator_tag

template <typename T>
struct HengList {
    struct Node {
        T val;
        Node *prev;
        Node *next;
    };
    typedef Node *nPtr;
    struct iterator {
        friend struct HengList<T>;
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const value_type *pointer;
        typedef const value_type &reference;
        typedef std::bidirectional_iterator_tag  iterator_category;

        iterator() noexcept : np_(nullptr) {}
        explicit iterator(nPtr np) noexcept : np_(np) {}

        reference operator*() const noexcept { return np_->val; }
        pointer operator->() const noexcept { return &np_->val; }

        iterator &operator++()
        {
            np_ = np_->next;
            return *this;
        }
        iterator operator++(int)
        { // postfix
            iterator temp(*this);
            ++*this;
            return temp;
        }
        iterator &operator--()
        {
            np_ = np_->prev;
            return *this;
        }
        iterator operator--(int)
        { // postfix
            iterator temp(*this);
            --*this;
            return temp;
        }
        bool operator==(const iterator &rhs) const noexcept
        {
            return np_ == rhs.np_;
        }
        bool operator!=(const iterator &rhs) const noexcept
        {
            return !operator==(rhs);
        }
    private:
        nPtr get() { return np_; }
        nPtr np_;
    };

    HengList() = default;
    HengList(std::initializer_list<T> il);
    HengList(const HengList &) = delete;
    HengList &operator=(const HengList &) = delete;
    ~HengList() { clearup(); }

    void push_back(const T &val);
    void push_front(const T &val);

    void pop_back();
    void pop_front();

    iterator find(const T &val);
    iterator insert(iterator position, const T &val);

    void remove(const T &val);
    iterator erase(iterator position);

    iterator begin() { return iterator(head_); }
    iterator end() { return iterator(); }

    size_t size() { return length_; }

private:
    void clearup();

    size_t length_ = 0;
    nPtr head_ = nullptr;
    nPtr tail_ = nullptr;
};

template<typename T>
void HengList<T>::clearup()
{
    for (auto it = begin(), tmp = it; it != end(); tmp = it) {
        ++it;
        free(tmp.get());
    }
}

template<typename T> HengList<T>::HengList(std::initializer_list<T> il)
{
    for (auto it = il.begin(); it != il.end(); ++it) {
        push_back(*it);
    }
}

template<typename T>
void HengList<T>::push_back(const T &val)
{
    nPtr raw = static_cast<nPtr>(calloc(1, sizeof(Node)));
    assert(raw);
    ++length_;
    raw->val = val;
    raw->prev = tail_;
    if (tail_) {
        tail_->next = raw;
    }
    if (!head_) {
        head_ = raw;
    }
    tail_ = raw;
    return;
}

template<typename T>
void HengList<T>::push_front(const T &val)
{
    nPtr raw = static_cast<nPtr>(calloc(1, sizeof(Node)));
    assert(raw);
    ++length_;
    raw->val = val;
    raw->next = head_;
    if (head_) {
        head_->prev = raw;
    }
    if (!tail_) {
        tail_ = raw;
    }
    head_ = raw;
    return;
}

template<typename T>
void HengList<T>::pop_back()
{
    if (!tail_) { return; }
    nPtr prev = tail_->prev;
    free(tail_);
    if (prev) {
        prev->next = nullptr;
    } else {
        head_ = nullptr;
    }
    tail_ = prev;
    --length_;
}

template<typename T>
void HengList<T>::pop_front()
{
    if (!head_) { return; }
    nPtr next = head_->next;
    free(head_);
    if (next) {
        next->prev = nullptr;
    } else {
        tail_ = nullptr;
    }
    head_ = next;
    --length_;
}


template<typename T>
typename HengList<T>::iterator HengList<T>::find(const T &val)
{
    for (auto it = begin(); it != end(); ++it) {
        if (*it == val) { return it; }
    }
    return end();
}

template<typename T>
typename HengList<T>::iterator HengList<T>::insert(iterator position, const T &val)
{
    nPtr curr = position.get();
    if (!curr) {
        push_back(val);
        return iterator(tail_);
    }
    nPtr prev = curr->prev;
    if (!prev) {
        push_front(val);
        return begin();
    }

    nPtr raw = static_cast<nPtr>(calloc(1, sizeof(Node)));
    assert(raw);
    ++length_;
    raw->val = val;

    raw->next = curr;
    curr->prev = raw;

    prev->next = raw;
    raw->prev = prev;
    return iterator(raw);
}

template<typename T>
void HengList<T>::remove(const T &val)
{
    for (auto it = begin(); it != end(); ++it) {
        if (*it == val) { erase(it); }
    }
}

template<typename T>
typename HengList<T>::iterator HengList<T>::erase(iterator position)
{
    nPtr curr = position.get();
    if (!curr) { return end(); }
    if (curr == head_) {
        pop_front();
        return begin();
    }
    if (curr == tail_) {
        pop_back();
        return end();
    }

    nPtr next = curr->next;
    curr->prev->next = next;
    next->prev = curr->prev;
    free(curr);
    --length_;
    return iterator(next);
}
