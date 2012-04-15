
/*
 * SneeuwLandschap.hpp
 *  Gemaakt door Robbert van der Hulst, S1063848
 *
 */

#ifndef SNEEUWLANDSCHAP_HPP_
#define SNEEUWLANDSCHAP_HPP_

//Onderstaande is nodig om de sneeuwvlokken in een lijst op te kunnen slaan.

#include <ma.h>
#include <mastdlib.h>
#include <MAUtil/Vector.h>
#include "SneeuwMan.hpp"
#include "SneeuwVlok.hpp"



class SneeuwLandschap
{
private:
	int sneeuwHoogte; //Waarde van de hoogte van de sneeuw.
	SneeuwMan* sneeuwMan; //Waardes van de sneeuwman.
	int grond; //Waarde waar de grond is.

	MAUtil::Vector<SneeuwVlok*> sneeuwvlokkenArray;

public:
	SneeuwLandschap();
	void draw();
	void run( MAEvent event );
};


#endif /* SNEEUWLANDSCHAP_HPP_ */
