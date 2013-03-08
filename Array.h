/*
	A generic vector implementation, 
	with the ability to increase in size,
	and to find/remove specific objects

	Author: Mikael Hallgren 2013
*/

#ifndef ARRAY_H
#define ARRAY_H

namespace Engine
{
	template <class T>	// The generic identifier
	class Array
	{
	private:
		T ** m_baseArray;				// The array of pointers to T objects
		int m_numberOfElement;	// Keeps track on the number of elements stored in m_baseArray
		int m_baseArraySize;		// Holds the current size of m_baseArray

	public:
		Array();
		Array(int in_ArraySize);
		~Array();								// Removes all objects in the array, cleanup

		void Add(T * obj);			// Add object in m_baseArray
		void Remove(T * obj);		// Searches list for object and removes it
		void Remove(int index);	// Removes object at given index

		int Size(){ return this->m_numberOfElement;}		// Returns m_numberOfElement
		T* Get(int pos){return this->m_baseArray[pos];}	// Returns T object at index
	};



	// Constuctor that initiates m_baseArray with 50 free free slots
	template <class T> Array<T>::Array()
	{
		this->m_baseArraySize = 50;
		this->m_numberOfElement = 0;
		this->m_baseArray = new T*[this->m_baseArraySize];
	}

	// Constructor that initiates m_baseArray based on parameter input
	template <class T> Array<T>::Array(int inSize)
	{
		this->m_baseArraySize = inSize;
		this->m_numberOfElement = 0;
		this->m_baseArray = new T*[this->m_baseArraySize];
	}

	// Deconstructor that removes all T-pointers from m_baseArray
	template <class T> Array<T>::~Array()
	{
		// Copy objects to new array
		for(int i=0; i < this->m_numberOfElement-1; i++){
				delete this->m_baseArray[i];		// Removing object
		}

		delete [] this->m_baseArray;
	}

	// Adding T-pointer to m_baseArray
	template <class T> void Array<T>::Add(T*newVal)
	{
		// If the number of stored elements is less than the number of positions in m_baseArray
		if(this->m_numberOfElement < this->m_baseArraySize)
		{
			// Add to m_baseArray and increase the number of elements stored in list
			this->m_baseArray[this->m_numberOfElement++] = newVal;
		}

		// There is equaly many stored objects as the size of m_baseArray
		// Resulting in creating a new array with more slots
		else
		{

			this->m_baseArraySize = this->m_baseArraySize * 2 + 1;	// Set the new size of new array, in this case Doubble as big
			T ** tmp_vector = new T*[this->m_baseArraySize];				// Create a new array in the heap with this size

			// Copys T-objects to new array
			for(int i = 0; i <= this->m_numberOfElement; i++)
			{
				tmp_vector[i] = this->m_baseArray[i];
			}

			delete [] this->m_baseArray;		// Delete old array
			this->m_baseArray = tmp_vector;	// Repoint pointer to new array

			this->m_baseArray[this->m_numberOfElement++] = newVal;	// Add the new walue to m_baseArray
		}
	}

	// Removing the object that is given by prameter
	template <class T> void Array<T>::Remove(T * newVal)
	{
		int tmp_index = 0;	// Holds the new array positioning
		T ** tmp_vector = new T*[this->m_baseArraySize--];	// The new array with one position less

		// Copy objects to new array
		for(int i=0; i <= this->m_numberOfElement; i++)
		{
			// Copy all objects that doesnt match the paramter object
			if(newVal != this->m_baseArray[i])
				tmp_vector[tmp_index++] = this->m_baseArray[i];	// Using tmp_index so there wont be a gap in the array
			else
			{
				delete this->m_baseArray[i];		// Removing object that is found
				this->m_numberOfElement--;			// if found, decrease the number of stored objects in m_baseArray
			}
		}
		
		delete [] this->m_baseArray;		// Delete old array
		this->m_baseArray = tmp_vector;	// Repoint pointer to new array
		
	};

	// Removing the object at given index
	template <class T> void Array<T>::Remove(int index){
		int tmp_index = 0;	// Holds the new array positioning
		T ** tmp_vector = new T*[this->m_baseArraySize--];	// The new array with one position less

		// Copy objects to new array
		for(int i=0; i <= this->m_numberOfElement; i++){
			if(i != index)
				tmp_vector[tmp_index++] = this->m_baseArray[i];// Using tmp_index so there wont be a gap in the array
			else
			{
				delete this->m_baseArray[i];		// Removing object that is found
				this->m_numberOfElement--;			// if found, decrease the number of stored objects in m_baseArray
			}
		}

		delete [] this->m_baseArray;		// Delete old array
		this->m_baseArray = tmp_vector;	// Repoint pointer to new array
		
	};
}

#endif