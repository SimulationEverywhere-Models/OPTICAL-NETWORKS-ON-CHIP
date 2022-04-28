/*******************************************************************
*
*  DESCRIPTION: Atomic Model ReceiverMobile
*
*  AUTHOR: Shafagh Jafer
*
*  EMAIL: sjafer@connect.carleton.ca
*
*
*  DATE: 30/10/2007
*
*******************************************************************/
#ifndef __Laser_H
#define __Laser_H

/** include files **/
#include "atomic.h"  // class Atomic


/** declarations **/
class Laser: public Atomic
{
public:
	Laser( const string &name = "Laser" ) ;	 // Default constructor

	

	virtual string className() const
		{return "Laser";}

protected:
	Model &initFunction()
		{   LIGHT = I = 0;
                      this -> passivate();
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:

    const Port &current ;
	Port &light;
    Time processingTime;

    int   LIGHT, I;
	

    
};	// class Laser


#endif    //__Laser_H
