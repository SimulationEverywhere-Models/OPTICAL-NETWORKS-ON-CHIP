/*******************************************************************
*
*  DESCRIPTION: Atomic Model Driver
*
*  AUTHOR: Shafagh Jafer
*
*  EMAIL: sjafer@connect.carleton.ca
*
*
*  DATE: 30/10/2006
*
*******************************************************************/

/** include files **/
#include <math.h>            // fabs( ... )
#include <stdlib.h>
#include "Driver.h"  // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Driver
* Description: constructor
********************************************************************/
Driver::Driver( const string &name )
: Atomic( name )
, data( addInputPort( "data" ) )
, current( addOutputPort( "current" ) )
, processingTime (0,0,2,0)
{
	string time1( MainSimulator::Instance().getParameter( description(), "processingTime" ) ) ;

	if( time1 != "" )
		processingTime = time1 ;
	
}

/*******************************************************************
* Function Name: externalFunction
* Description: the Driver receives data
********************************************************************/
Model &Driver::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive)
  {
  
    if (msg.port() == data)
     {
      DATA = static_cast < int > (msg.value());//extract DATA from msg
      I = 1;     //set it to True
    
      holdIn(active, processingTime);
     }
    
	
  }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Driver::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Driver::outputFunction( const InternalMessage &msg )
{

      if ( I == 1 )
        {
         I = DATA * 60;
         sendOutput( msg.time(),current, I);
        }
         
      return *this;
}


