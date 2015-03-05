#include "dynamicArray.h"
#include <iostream>TAB
using namespace std;


DynamicArray::DynamicArray(const DynamicArray &_source){
	capacite = _source.capacite;

	tabElement = new int[capacite];

	for (int i = 0; i < capacite; i++){
		tabElement[i] = _source.tabElement[i];
	}
}


DynamicArray::DynamicArray(int _capacite){

	if (_capacite > 0){
		capacite = _capacite;
		tabElement = new int[capacite];
		for (int i = 0; i < capacite; i++){
			tabElement[i] = 0;
		}
	}
	else{
		throw invalid_argument("La capacité doit être supérieure à 0");
	}
}


DynamicArray::~DynamicArray(){
	delete[] tabElement;
}

DynamicArray& DynamicArray::operator=(const DynamicArray &_source){
	if (&_source != this){
		capacite = _source.capacite;
		tabElement = new int[capacite];

		for (int i = 0; i < capacite; i++){
			tabElement[i] = _source.tabElement[i];
		}
	}
	return *this;
}

bool DynamicArray::operator==(const DynamicArray &_source) const{
	bool estEgal = true;
	int i = 0;

	if (&_source != this){
		if (capacite == _source.capacite){
			while (i < capacite && estEgal == true){
				if (tabElement[i] != _source.tabElement[i]){
					estEgal = false;
				}
				i++;
			}
		}
		else{
			estEgal = false;
		}
	}


	return estEgal;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& _source){

	int ancienneCapacite = capacite;
	setCapacite(capacite + _source.capacite);

	int j = 0;
	for (int i = ancienneCapacite; i < capacite; i++){
		tabElement[i] = _source.tabElement[j];
		j++;
	}
	return *this;
}

int DynamicArray::getCapacite() const{
	return capacite;
}


int DynamicArray::getElement(int _index) const{

	if (_index >= 0 && _index < capacite){
		return tabElement[_index];
	}
	else{
		throw out_of_range("L'index demandé n'est pas dans les valeurs existantes du tableau");
	}

}

void DynamicArray::setElement(int _index, int _valeur){
	if (_index >= capacite){
		setCapacite(_index + 1);
		tabElement[_index] = _valeur;
	}
	tabElement[_index] = _valeur;
}

void DynamicArray::setCapacite(int _nouvelleCapacite){

	if (_nouvelleCapacite > 0){
		int* nouveauTabElement = new int[_nouvelleCapacite];

		if (_nouvelleCapacite > capacite){

			for (int i = 0; i < capacite; i++){
				nouveauTabElement[i] = tabElement[i];
			}
			for (int i = capacite; i < _nouvelleCapacite; i++){
				nouveauTabElement[i] = 0;
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