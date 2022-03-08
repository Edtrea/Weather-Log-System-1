/**
 * @file VECTOR.H
 * @author Lim Wen Chao
 * @brief A template class of dyanaic array
 * @version 0.1
 * @date 2022-02-21
 * 
 * @version 0.2
 * @date 2022-02-26
 * Updated Clear() to not delete elements
 * 
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

template<class T>
class Vector
{
    public:
            /**
             * @brief Construct a new Vector object
             * 
             */
        Vector();
            /**
             * @brief Construct a new Vector object and deep copies the elements of another Vector object into the new Vector
             * 
             * @param other - Another Vector Object
             */
        Vector( Vector& other);
            /**
             * @brief Destroy the Vector object
             * 
             */
        ~Vector();

            /**
             * @brief Get m_size
             * 
             * @return unsigned int - The current size of the Vector
             */
        unsigned int Size() const 
        {
            return m_size;
        }
            /**
             * @brief Get m_capasity
             * 
             * @return unsigned int - The current capacity of the Vector
             */
        unsigned int Capacity() const 
        {
            return m_capacity;
        }
        
            /**
             * @brief Deep copies another vector's elements into a existing Vector
             * 
             * @param other - Another Vector Object
             * 
             */
        void operator=(Vector& other);
            /**
             * @brief Retrives an element from a given index position
             * 
             * @param index - The index position of the element to be retrieved
             * @return const T& - The element data passed by reference
             */
        const T& operator[](const unsigned int& index) const;

            /**
             * @brief Change the size of the vector to match the given size
             * 
             * @param newsize - The Vector size to change the Vector to
             */
        void Resize(const unsigned int& newsize);
            /**
             * @brief Removes an element from an index position and moves all elements on the right to the left to fill in the removed element's position
             * 
             * @param index - the index of the element to be removed
             */
        void Erase(const unsigned int& index);
            /**
             * @brief Inserts an element at the given index position and move all elements from the index to the right to make space for the element to be inserted
             * 
             * @param pos - index position of the element to be inserted
             * @param val - data value of the element
             */
        void Insert(const unsigned int& pos, const T& val);
            /**
             * @brief Sets m_size to 0. Make the Vector empty
             * 
             */
        void Clear();

    private:
            //The pointer of the Vector
        T* m_pointer;
            //The number of elements in the Vector
        unsigned int m_size;
            //The max number of element the Vector is expected to hold
        unsigned int m_capacity;

            /**
             * @brief Increase the m_capasity of Vector by 2 times if capacity is maxed
             * 
             * @param newcapacity - The current capasity of the Vector
             */
        void Reserve(unsigned int newcapacity);
            /**
             * @brief Multiply a int by 2
             * 
             * @param size - The current capacity
             * @return unsigned int - The multiplied capasity
             */
        unsigned int MultiplyBy2(const unsigned int& size)
        {
            return m_size * 2;
        }
            /**
             * @brief Deep copies a Vector into result given the first element and the last element memory position
             * 
             * @param first - The pointer of the first element of a Vector being copied
             * @param last - The pointer of the last element of a Vector being copied
             * @param result - The pointer of the Vector being copied to
             * @return T* - Returns result
             */
        T* DeepCopy(T* first, T* last, T* result);
};

template<class T>
Vector<T>::Vector()
: m_pointer(NULL), m_size(0), m_capacity(0)
{}

template<class T>
Vector<T>::Vector(Vector& other) 
{
        //Creates a Vector in the other Vector's capasity
    m_pointer=new T[other.Capacity()];
    DeepCopy(other.m_pointer,other.m_pointer+other.Size(),m_pointer);
        //Sets this Vector to the other vector's size and capasity
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

template<class T>
Vector<T>::~Vector() 
{
        //If Vector pointer is not null then delete it and set to null
    if(m_pointer != nullptr)
    {
        delete[] m_pointer;
        m_pointer = nullptr;
    }
        //Set size and capasity of this vector to 0
    m_size = 0;
    m_capacity = 0;
}

template<class T>
void Vector<T>::operator=(Vector& other)  // Assignment operator
{
        //Increase this vector's capasity to to capable to holding the other vector's element
    m_pointer=new T[other.Capacity()];
    DeepCopy(other.m_pointer,other.m_pointer+other.Size(),m_pointer);
        //Sets this vector's size to be the same 
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

template<class T>
const T& Vector<T>::operator[](const unsigned int& index) const 
{
        //Checks if index is greater than or equal to the size of vector
    if(index >= m_size)
        throw out_of_range("");
    else
        return m_pointer[index];
}

template<class T>
void Vector<T>::Resize(const unsigned int& newsize)
{
        //Checks if newsize is greater than the capasity of Vector before trying to reserve more capasity
    if(newsize > m_capacity)
        {
            Reserve(newsize);
        }
        //Sets vector size to be the newsize
    m_size=newsize;   
}

template<class T>
void Vector<T>::Erase(const unsigned int& index) 
{
        //Checks if index is valid for the Vector
    if (index < 0 || index > m_size)
    {
        cout << "The location of the item to be removed is out of range." << endl;
    }
    else
    {
            //  Shift all the elements one step left, beginning from "index+1"
        for(unsigned int i = index; i < m_size-1; i++)
        {
            m_pointer[i] = m_pointer[i+1];   
        }

        --m_size;
    }
}

template<class T>
void Vector<T>::Insert(const unsigned int& index, const T& val) 
{
        // Create some space if it doesn't have enough to take another element
    if(m_capacity <= m_size)  
    {
        Reserve(m_size);
    }
    m_size++;
        //  Shift all the elements one step towards right, beginning from "index"+1..
    for(unsigned int i = m_size-1; i > index; i--)  
    {
        m_pointer[i] = m_pointer[i-1];
    }
    m_pointer[index] = val;
}

template<class T>
void Vector<T>::Clear() 
{
    m_size=0;
}

template<class T>
void Vector<T>::Reserve(unsigned int newcapacity) 
{
    if( newcapacity == 0)
    {
        newcapacity = 1;
    }
    else
    {
            // Keep the capacity of the vector as a power of 2 to avoid space wastage
        newcapacity = MultiplyBy2(newcapacity);  
    }
    if(newcapacity > m_capacity)
    {
        T* temp=new T[newcapacity];
        DeepCopy(m_pointer,m_pointer+m_capacity,temp);
        delete[] m_pointer;
        m_pointer=temp;
        m_capacity=newcapacity;
    }
}

template<class T>
T* Vector<T>::DeepCopy(T* first, T* last, T* result)
{
        //For the range from first to last copy to result
    while (first != last) 
    {
        *result = *first;
        ++result;
        ++first;
    }
    return result;
}

#endif