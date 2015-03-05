#include "dynamicArray.h"
#include <iostream>
using namespace std;


template <class T>
DynamicArray<T>::DynamicArray(int _capacite){

	if (_capacite > 0){
		capacite = _capacite;
		tabElement = new T[capacite];
		for (int i = 0; i < capacite; i++){
			tabElement[i] = T();
		}
	}
	else{
		throw invalid_argument("La capacité doit être supérieure à 0");
	}
}

template <class T>
DynamicArray<T>::~DynamicArray(){
	delete[] tabElement;
}

template <class T>
int DynamicArray<T>::getCapacite() const{
	return capacite;
}

template <class T>
T DynamicArray<T>::getElement(int _index) const{

	if (_index >= 0 && _index < capacite){
		return tabElement[_index];
	}
	else{
		throw out_of_range("L'index demandé n'est pas dans les valeurs existantes du tableau");
	}

}

template <class T>
void DynamicArray<T>::setElement(int _index, T _valeur){
	if (_index >= capacite){
		setCapacite(_index + 1);
		tabElement[_index] = _valeur;
	}
	tabElement[_index] = _valeur;
}

template <class T>
void DynamicArray<T>::setCapacite(int _nouvelleCapacite){

	if (_nouvelleCapacite > 0){
		T* nouveauTabElement = new T[_nouvelleCapacite];

		if (_nouvelleCapacite > capacite){

			for (int i = 0; i < capacite; i++){
				nouveauTabElement[i] = tabElement[i];
			}
			for (int i = capacite; i < _nouvelleCapacite; i++){
				nouveauTabElement[i] = T();
			}
		}
		else{

			for (int i = 0; i < _nouvelleCapacite; i++){
				nouveauTabElement[i] = tabElement[i];
			}
		}

		delete[] tabElement;
		tabElement = nouveauTabElement;
		capacite = _nouvelleCapacite;

	}
	else{
		throw invalid_argument("La capacité du nouveau tableau ne peut pas être inférieure à 1");
	}
}