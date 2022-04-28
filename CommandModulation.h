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
#ifndef __CommandModulation_H
#define __CommandModulation_H

/** include files **/
#include "atomic.h"  // class Atomic


/** declarations **/
class CommandModulation: public Atomic
{
public:
	CommandModulation( const string &name = "CommandModulation" ) ;	 // Default constructor

	

	virtual string className() const
		{return "CommandModulation";}

protected:
	Model &initFunction()
		{   IN1 = IN2 = OUT1 = 0;
                      this -> passivate();
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:

    const Port &in1 ;
    const Port &in2 ;    
	Port &out1;
    Time processingTime;

    int   IN1, IN2, OUT1;
	

    
};	// class CommandModulation


#endif    //__CommandModulation_H
