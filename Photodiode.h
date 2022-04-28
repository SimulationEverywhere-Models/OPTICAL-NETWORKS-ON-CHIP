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
#ifndef __Photodiode_H
#define __Photodiode_H

/** include files **/
#include "atomic.h"  // class Atomic


/** declarations **/
class Photodiode: public Atomic
{
public:
	Photodiode( const string &name = "Photodiode" ) ;	 // Default constructor

	

	virtual string className() const
		{return "Photodiode";}

protected:
	Model &initFunction()
		{   LIGHT = I = 0;
                      this -> passivate();
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:

    const Port &light ;
	Port &current;
    Time processingTime;

    int   LIGHT, I;
	

    
};	// class Photodiode


#endif    //__Photodiode_H
