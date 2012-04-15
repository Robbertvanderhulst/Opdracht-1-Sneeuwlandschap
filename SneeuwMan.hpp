
/*
 * SneeuwMan.hpp
 *  Gemaakt door Robbert van der Hulst, S1063848
 *
 */

#ifndef SNEEUWMAN_HPP_
#define SNEEUWMAN_HPP_


//bevat teken functies
#include <ma.h>


//de klasse SneeuwMan
class SneeuwMan
{
private:
	int positionX;	//x positie van sneeuwman
	int positionY;	//y positie van sneeuwman

public:
	//constructor
	SneeuwMan( int positionX, int positionY );

	//beweeg de sneeuwman in de richting "direcion", negatief getal is links, positief is rechts
	void move( int direction );

	//tekent een sneeuwman
	void draw();
};


#endif /* SNEEUWMAN_HPP_ */
