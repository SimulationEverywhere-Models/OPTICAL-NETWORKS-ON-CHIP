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
#include "TIA.h"  // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: TIA
* Description: constructor
********************************************************************/
TIA::TIA( const string &name )
: Atomic( name )
, data( addOutputPort( "data" ) )
, current( addInputPort( "current" ) )
, processingTime (0,0,2,0)
{
	string time1( MainSimulator::Instance().getParameter( description(), "processingTime" ) ) ;

	if( time1 != "" )
		processingTime = time1 ;
	
}

/*******************************************************************
* Function Name: externalFunction
* Description: the TIA receives data
********************************************************************/
Model &TIA::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive)
  {
  
    if (msg.port() == current)
     {
      I = static_cast < int > (msg.value());//extract DATA from msg
      DATA = 1;     //set it to True
    
      holdIn(active, processingTime);
     }
    
	
  }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &TIA::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &TIA::outputFunction( const InternalMessage &msg )
{

      if ( DATA == 1 )
        {
         DATA = I / 60;
         sendOutput( msg.time(),data, DATA);
        }
         
      return *this;
}


