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
#ifndef __TIA_H
#define __TIA_H

/** include files **/
#include "atomic.h"  // class Atomic


/** declarations **/
class TIA: public Atomic
{
public:
	TIA( const string &name = "TIA" ) ;	 // Default constructor

	

	virtual string className() const
		{return "TIA";}

protected:
	Model &initFunction()
		{   DATA = I = 0;
                      this -> passivate();
                      return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:

    const Port &current ;
	Port &data;
    Time processingTime;

    int   DATA, I;
	

    
};	// class TIA


#endif    //__TIA_H
