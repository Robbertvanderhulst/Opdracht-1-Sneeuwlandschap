
/*
 * SneeuwVlok.cpp
 *  Gemaakt door Robbert van der Hulst, S1063848
 *
 */

#include "SneeuwVlok.hpp"

//Constructor van de klasse sneeuwvlok.
SneeuwVlok::SneeuwVlok(int positionX, int positionY) {
	this->positionX = positionX;
	this->positionY = positionY;

	//De boolean wordt op false gezet.
	this->dood = false;

	//De minimale en maximale grootte van de sneeuwvlok wordt vastgesteld.
	int mingrootte = 1;
	int maxgrootte = 7;

	//De grootte wordt bepaald door een random getal tussen de 1 en de 10.
	this->size = rand() % (maxgrootte-mingrootte) + maxgrootte;
}

// Methode teken sneeuwvlok, hierin worden de positie en kleur van de sneeuwvlok bepaald.
void SneeuwVlok::draw() {
	maSetColor( 0xffffff );
	maFillRect( this->positionX, this->positionY, this->size, this->size );
}

// De methode vallen zorgt ervoor dat de sneeuwvlokjes ook gaan vallen, in dit geval steeds met 3 pixels.

void SneeuwVlok::vallen( int Grond) {
	this->positionY = this->positionY + 3;

	//Als het sneeuwvlokje de grond heeft bereikt dan wordt de boolean op true gezet.
	if(this->positionY > Grond) {
		this->dood = true;
	}
}

// De boolean bepaald dan de status hiervan.
bool SneeuwVlok::isDood() {
	return this->dood;
}




