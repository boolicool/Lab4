template <typename TYPE>
TYPE TrouverMax(TYPE _tabValeur[], int _taille){
	TYPE maximum = _tabValeur[0];
	for (int i = 0; i < _taille; i++){
		if (_tabValeur[i] > maximum){
			maximum = _tabValeur[i];
		}
	}
	return maximum;
}

template <typename TYPE>
TYPE CalculerSomme(TYPE _tabValeur[], int _taille){
	TYPE resultat = _tabValeur[0];

	for (int i = 1; i < _taille; i++){
		resultat += _tabValeur[i];
	}
	return resultat;
}


template <typename TYPE>
unsigned int CompterElement(TYPE _element, TYPE _tabValeur[], int _taille){
	unsigned int occurence = 0;

	for (int i = 0; i < _taille; i++){
		if (_tabValeur[i] == _element){
			occurence++;
		}
	}
	return occurence;
}