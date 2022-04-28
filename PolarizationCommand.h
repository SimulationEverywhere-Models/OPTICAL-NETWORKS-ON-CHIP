/*******************************************************************
*
*  DESCRIPTION: Atomic Model PolarizationCommand
*
*  AUTHOR: Shafagh Jafer
*
*  EMAIL: sjafer@connect.carleton.ca
*
*
*  DATE: 30/10/2007
*
*******************************************************************/
#ifndef __PolarizationCommand_H
#define __PolarizationCommand_H

/** include files **/
#include "atomic.h"  // class Atomic


/** declarations **/
class PolarizationCommand: public Atomic
{
public:
	PolarizationCommand( const string &name = "PolarizationCommand" ) ;	 // Default constructor

	

	virtual string className() const
		{return "PolarizationCommand";}

protected:
	Model &initFunction()
		{   IN1 = OUT2 = OUT1 = 0;
                      this -> passivate();
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:

    const Port &in1 ;
    Port &out1;    
	Port &out2;
    Time processingTime;


    int   IN1, OUT1, OUT2;
	

    
};	// class PolarizationCommand


#endif    //__PolarizationCommand_H
