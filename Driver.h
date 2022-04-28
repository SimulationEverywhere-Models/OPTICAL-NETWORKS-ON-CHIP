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
#ifndef __Driver_H
#define __Driver_H

/** include files **/
#include "atomic.h"  // class Atomic


/** declarations **/
class Driver: public Atomic
{
public:
	Driver( const string &name = "Driver" ) ;	 // Default constructor

	

	virtual string className() const
		{return "Driver";}

protected:
	Model &initFunction()
		{   DATA = I = 0;
                      this -> passivate();
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:

    const Port &data ;
	Port &current;
    Time processingTime;

    int   DATA, I;
	

    
};	// class Driver


#endif    //__Driver_H
