
/*
 * SneeuwMan.cpp
 *  Gemaakt door Robbert van der Hulst, S1063848
 *
 */

#include "SneeuwMan.hpp"


//De sneeuwman wordt gedefinierd.
SneeuwMan::SneeuwMan(int positionX, int positionY) {
	this->positionX = positionX;
	this->positionY = positionY;
}


//De methode beweeg zorgt ervoor dat de sneeuwman links en rechts kan bewegen.
void SneeuwMan::move(int direction) {
	this->positionX = this->positionX+direction;
}

//De teken methode zorgt ervoor dat de sneeuwman ook daadwerkelijk getekend word.
void SneeuwMan::draw() {

	//Kleur wordt op lichtgrijs gezet.
	maSetColor(0xC0C0C0);

	//De 2 grijze vlakken worden getekend.

		maFillRect( this->positionX, this->positionY -40, 50, 40);
		maFillRect( this->positionX + 10, this->positionY - 70 , 30, 30);

	//De kleur wordt op zwart gezet.
		maSetColor(0x000000);

	//Zijn ogen, mond, ogen, en knoopjes worden getekend.

		maFillRect( this->positionX, this->positionY - 105, 50, 35);
		maFillRect( this->positionX + 20, this->positionY -40, 7, 7);
		maFillRect( this->positionX + 20, this->positionY -25, 7, 7);
		maFillRect( this->positionX + 20, this->positionY -10, 7, 7);
		maFillRect( this->positionX + 15, this->positionY -65, 5, 5);
		maFillRect( this->positionX + 30, this->positionY -65, 5, 5);
		maFillRect( this->positionX + 22, this->positionY -55, 5, 5);
}





