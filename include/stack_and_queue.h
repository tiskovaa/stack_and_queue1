#pragma once

#include <iostream>
using namespace std;

template<typename T>
class mVector
{
protected:
	size_t sz;
	size_t capacity;
	T* pMem;
public:
	mVector(size_t size = 0) : sz(size), capacity(sz * 2 + 2)
	{
		pMem = new T[capacity];
		if (pMem == nullptr)
			throw bad_alloc();
	}
	mVector(T* arr, size_t size) : sz(size), capacity(sz * 2 + 2)
	{
		if (arr == nullptr)
			throw logic_error("mVector requires non - nullptr arg");
		pMem = new T[capacity];
		if (pMem == nullptr)
			throw bad_alloc();
		copy(arr, arr + sz, pMem);
	}
	mVector(const mVector& v) : sz(v.sz), capacity(v.capacity)
	{
		pMem = new T[capacity];
		if (pMem == nullptr)
			throw bad_alloc();
		copy(v.pMem, v.pMem + sz, pMem);
	}
	mVector(mVector&& v) noexcept
	{
		sz = 0;
		capacity = 0;
		pMem = nullptr;
		swap(*this, v);
	}
	~mVector()
	{
		delete[] pMem;
		pMem = nullptr;
	}

	// операторы

	mVector& operator=(const mVector& v)
	{
		if (this != &v)
		{
			if (sz != v.sz)
			{
				sz = v.sz;
				capacity = v.capacity;
				delete[] pMem;
				T* p = new T[capacity];
				if (p == nullptr)
					throw bad_alloc();
				pMem = p;
			}
			copy(v.pMem, v.pMem + sz, pMem);
		}
		return (*this);
	}
	mVector& operator=(mVector&& v) noexcept
	{
		sz = 0;
		capacity = 0;
		delete[] pMem;
		pMem = nullptr;
		swap(*this, v);
		return (*this);
	}
	friend void swap(mVector& lhs, mVector& rhs)
	{
		swap(lhs.size, rhs.size);
		swap(lhs.capacity, rhs.capacity);
		swap(lhs.data, rhs.data);
	}
	size_t size() const noexcept { return sz; }
	size_t getcapacity() const noexcept { return capacity; }
	bool isFull() const noexcept { return (sz == capacity); }
	bool isEmpty() const noexcept { return (sz == 0); }

	// индексация
	T& operator[](size_t ind)
	{
		return pMem[ind];
	}
	const T& operator[](size_t ind) const
	{
		return pMem[ind];
	}

	// сравнение
	bool operator==(const mVector& v) const noexcept
	{
		if (sz != v.sz)
			return 0;
		else
			for (size_t i = 0; i < sz; i++)
				if (pMem[i] != v.pMem[i])
					return 0;
		return 1;
	}
	bool operator!=(const mVector& v) const noexcept
	{
		return !(*this == v);
	}
	void resize(size_t newsize)
	{
		T* p = new T[newsize * 2 + 2];
		if (p == nullptr)
			throw bad_alloc();
		copy(pMem, pMem + sz, p);
		pMem = p;
		p = nullptr;
		capacity = newsize * 2 + 2;
	}
	void push_back(T elem)
	{
		if (isFull())
			resize(sz + 1);
		pMem[sz++] = elem;
	}
	void pop_back()
	{
		if (isEmpty())
			throw logic_error("Vector is empty");
		else sz--;
	}
	void push_front(T elem)
	{
		insert(elem, 0);
	}
	void pop_front()
	{
		erase(0);
	}
	void insert(T elem, size_t ind)
	{
		if (ind < 0 || ind >= capacity)
			throw out_of_range("Index should be greater than zero and less than vector size");
		if (sz == capacity)
			resize(sz + 1);
		for (size_t i = sz; i > ind; i--)
			pMem[i] = pMem[i - 1];
		pMem[ind] = elem;
		sz++;
	}
	void erase(size_t ind)
	{
		if (ind < 0 || ind >= capacity)
			throw out_of_range("Index should be greater than zero and less than vector size");
		if (sz == 0)
			throw logic_error("Vector is empty");
		for (size_t i = ind; i < sz; i++)
			pMem[i] = pMem[i + 1];
		sz--;
	}
};

// стек
template<typename T>
class mStack : private mVector<T>
{
	using mVector<T>::sz;
	using mVector<T>::capacity;
	using mVector<T>::pMem;
	using mVector<T>::push_back;
	using mVector<T>::pop_back;
	using mVector<T>::resize;
public:
	using mVector<T>::isFull;
	using mVector<T>::isEmpty;
	using mVector<T>::size;

	size_t getcapacity() const noexcept { return capacity; }
	mStack() : mVector<T>(0) { };
	void push(T elem)
	{
		push_back(elem);
	}
	void pop()
	{
		pop_back();
	}
	T top()
	{
		if (isEmpty())
			throw logic_error("Stack is empty");
		return pMem[sz - 1];
	}
};

// очередь
template<typename T>
class mQueue : private mVector<T>
{
	using mVector<T>::sz;
	using mVector<T>::capacity;
	using mVector<T>::pMem;
	size_t front;
	size_t back;
	using mVector<T>::push_back;
	using mVector<T>::resize;
public:

	using mVector<T>::isFull;
	using mVector<T>::isEmpty;
	using mVector<T>::size;
	using mVector<T>::getcapacity;
	mQueue() : mVector<T>(0), front(0), back(0) { }
	void push(T elem)
	{
		push_back(elem);
		if (back == capacity)
			back = 0;
		else
			back++;
	}
	void pop()
	{
		if (isEmpty())
			throw logic_error("Queue is empty");
		if (front == capacity)
			front = 0;
		else
			front++;
		sz--;
	}
	T getFront() const noexcept {
		return pMem[front];
	}
	T getBack() const noexcept {
		if (back == 0)
			return pMem[capacity - 1];
		return pMem[back - 1];
	}
	size_t getBackIndex() const noexcept { return back; }
};

// очередь двa стека
template<typename T>
class Queue2Stacks : private mVector<mStack<T>>
{
	using mVector<mStack<T>>::pMem;
	size_t sz;
	size_t capacity;
public:
	Queue2Stacks() : mVector<mStack<T>>(0), sz(pMem[0].size() + pMem[1].size()), capacity(pMem[0].getcapacity() + pMem[1].getcapacity()) { }
	size_t size() const noexcept { return sz; }
	size_t getcapacity() const noexcept { return capacity; }
	bool isFull() const noexcept { return (pMem[0].isFull() && pMem[1].isFull()); }
	bool isEmpty() const noexcept { return (pMem[0].isEmpty() && pMem[1].isEmpty()); }
	void push(T elem)
	{
		pMem[1].push(elem);
		sz++;
	}
	void pop()
	{
		if (pMem[0].isEmpty())
		{
			while (!pMem[1].isEmpty())
			{
				T tmp = pMem[1].top();
				pMem[0].push(tmp);
				pMem[1].pop();
			}
			pMem[0].pop();
		}
		else
			pMem[0].pop();
		sz--;
	}
	T front()
	{
		if (!pMem[1].isEmpty())
		{
			T tmp{ };
			while (!pMem[1].isEmpty())
			{
				tmp = pMem[1].top();
				pMem[1].pop();
			}
			return tmp;
		}
		if (!pMem[0].isEmpty())
			return pMem[0].top();
		return 0;
	}
	T back()
	{
		if (!pMem[0].isEmpty())
		{
			T tmp{ };
			while (!pMem[0].isEmpty())
			{
				tmp = pMem[0].top();
				pMem[0].pop();
			}
			return tmp;
		}
		if (!pMem[1].isEmpty())
			return pMem[1].top();
		return 0;
	}
};