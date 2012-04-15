
/*
 * SneeuwLandschap.cpp
 *  Gemaakt door Robbert van der Hulst, S1063848
 *
 */

#include "SneeuwLandschap.hpp"


//globale variabelen voor breedte en hoogte van het scherm
int screenWidth;
int screenHeight;


//constructor
SneeuwLandschap::SneeuwLandschap()
{
	//sla schermgrootte op in globale variabelen
	MAExtent screenSize = maGetScrSize();
	screenWidth = EXTENT_X( screenSize );
	screenHeight = EXTENT_Y( screenSize );

	//stel sneeuwhoogte in (vanaf bodem)
	this->sneeuwHoogte = 30;

	//stel in waar de grond is
	this->grond = screenHeight - this->sneeuwHoogte;

	//maak een nieuwe sneeuwman
	this->sneeuwMan = new SneeuwMan( screenWidth / 2, screenHeight - this->sneeuwHoogte );
}


//wordt aangeroepen als er input is (druk op de toets, touch van scherm)
void SneeuwLandschap::run( MAEvent event )
{
	//als er een key is ingetoetst
	if( event.type == EVENT_TYPE_KEY_PRESSED )
	{
		//pak de key code
		int key = maGetKeys();

		//kijk voor linkertoets
		if( key == MAKB_LEFT )
			this->sneeuwMan->move( -6 );	//beweeg sneeuwman -6 pixels

		//kijk voor rechtertoets
		if( key == MAKB_RIGHT )
			this->sneeuwMan->move( 6 );		//beweeg sneeuwman 6 pixels
	}

	//voeg een sneeuwvlok toe

	//er wordt een xpositie random gegenereert.
	int xpositie = rand()  % (screenWidth);

	//De sneewvlok wordt aangemaakt op de random gegenereerde waarde en begint bovenaan, en wacht steeds 40 miliseconde.
	maWait(40);
	SneeuwVlok* sneeuwvlok= new SneeuwVlok(xpositie, 0);

	//De sneeuwvlok wordt aan de arraylist toegevoegd.
	sneeuwvlokkenArray.add(sneeuwvlok);

	//laat alle sneeuwvlokken vallen.

	//De hele array wordt doorlopen en roept voor elke sneeuwvlok de functie vallen aan.
	for(int i = 0; i < sneeuwvlokkenArray.size(); i++) {
		sneeuwvlokkenArray[i]->vallen(this->grond);

		//Als de sneeuwvlok de boolean krijgt dat die dood is wordt hij verwijderd.
		if(sneeuwvlokkenArray[i]->isDood()) {
			SneeuwVlok* verwijder = sneeuwvlokkenArray[i];
			delete verwijder;

			//De sneeuwvlok wordt ook uit de lijst verwijderd.
			sneeuwvlokkenArray.remove(i);
		}
	}
}

//wordt elke "tick" aangeroepen om het winterlandschap, sneeuwman en sneeuwvlokken te tekenen
void SneeuwLandschap::draw()
{
	//kleur de lucht blauw
	maSetColor( 0x0055ff );
	maFillRect( 0, 0, screenWidth, screenHeight );

	//maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	//teken de sneeuwman
	this->sneeuwMan->draw();

	//teken alle sneeuwvlokken
	for(int i = 0; i < sneeuwvlokkenArray.size(); i++) {
		sneeuwvlokkenArray[i]->draw();
	}
}


