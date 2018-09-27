#ifndef stack_H
#define stack_H

#include <cassert> // because I am paranoid
#include <new> // std:: bad_alloc
// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom{

/************************************************
 * stack
 * A class that holds stuff
 ***********************************************/
template <class T>
class stack {
private:
    T* data;
    int numElements;
    int bufferSize = 0;

public:

    //Constructor with an initial capacity size
    stack(int initialBufferSize) throw(const char*)
    {
        assert(initialBufferSize >= 0);
        this->numElements = 0;

        if (initialBufferSize == 0) {
            this->bufferSize = 0;
            this->data = NULL;
            return;
        }
        this->numElements = initialBufferSize;

        // attempt to allocate
        try
        {
            data = new T[initialBufferSize];
        }

        catch (std::bad_alloc e)
        {
            throw "ERROR: Unable to allocate buffer";
        }

        this->bufferSize = initialBufferSize;
    }

    //Constructor to copy stacks
    stack(const stack& rhs) throw(const char*)
    {
        //assert(rhs.size() >= 0);

        if (rhs.size() == 0) {
            bufferSize = 0;
            data = NULL;
            return;
        }

        // attempt to allocate
        try
        {
            data = new T[rhs.size()];
        }
        catch (std::bad_alloc e)
        {
            throw "ERROR: Unable to allocate buffer";
        }

        // copy over the capacity
        bufferSize = rhs.size();

        // copy the items over one at a time using the assignment operator
        for (int i = 0; i < bufferSize; i++)
        {
            data[i] = rhs.data[i];
        }

        numElements = rhs.size();

    }

//Constructor - Defualt constructor with no elements.
   stack()
      {
         data = NULL;
         numElements = 0;
         bufferSize = 0;
      }


    //Deconstructor
    ~stack()
    {
        delete[] data;
    }






    bool empty() const
    {
      if (numElements == 0)
      {
         return true;
      }
      else
      {
        return false;
      }
    }

    int size() const
    {
       return numElements;
    }

    int capacity() const
    {
       return bufferSize;
    }

    void clear()
    {
       numElements = 0;
    }

   void push_back(T newItem)
   {
      if (bufferSize <= numElements)
      {

         bufferSize = bufferSize + 1;

         T* newBuffer = new T[bufferSize];
         for (int i = 0; i < numElements; ++i)
         {
           newBuffer[i] = data[i];
         }
         delete[] data;
         data = newBuffer;
      }
      data[numElements] = newItem;
      numElements++;

   }

   T top() throw(const char*)
   {
      if (numElements != 0)
      {
         return data[numElements -1]
      }
      else
      {
         throw "ERROR: Unable to allocate a new buffer for Stack";
      }
   }


   void pop()
   {
      delete[] data[numElements - 1]
      numElements--;
   }

   //Overload the "=" operator
   stack& operator=(const stack& rhs) throw(const char*)
   {
       numElements = 0;
       if (bufferSize <= rhs.size())
       {
         delete[] data;
         data = new T [rhs.size()];
       }

         numElements = rhs.size();

       for (int i = 0; i < numElements; i++)
           data[i] = rhs[i];

       return *this;
   }
};

#endif // stack_H

};
