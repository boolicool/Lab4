#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

using namespace std;

template <class T>
class DynamicArray
{

public:
	DynamicArray(int _capacite = 100);
	~DynamicArray();

	int getCapacite() const;
	T getElement(int _index) const;
	void setElement(int _index, T _valeur);
	void setCapacite(int _nouvelleCapacite);

private:
	T* tabElement;
	int capacite;

	DynamicArray(T & _source);
	DynamicArray<T>& operator=(const DynamicArray<T> & _source);
};

#include "dynamicArray.hpp"
#endif //DYNAMICARRAY_H_
