
/*
 * SneeuwLandschap.hpp
 *  Gemaakt door Robbert van der Hulst, S1063848
 *
 */

#ifndef SNEEUWVLOK_HPP_
#define SNEEUWVLOK_HPP_


//deze header hebben we nodig voor de functie rand()
#include <mastdlib.h>
#include <ma.h>


//maak een klasse SneeuwVlok
class SneeuwVlok
{
private:
	int positionX;	//sneeuwvlok heeft x positie
	int positionY;	//sneeuwvlok heeft y positie
	int size;		//sneeuwvlok heeft (een willekeurige) grootte
	bool dood;		//als dead == true, wordt de sneeuwvlok verwijdert

public:
	SneeuwVlok( int positionX, int positionY );	//constructor
	void draw();								//teken functie die een sneeuwvlok tekent
	void vallen( int Grond );					//functie die de y positie verandert
	bool isDood();								//functie die de sneeuwvlok dead status teruggeeft
};



#endif /* SNEEUWVLOK_HPP_ */
