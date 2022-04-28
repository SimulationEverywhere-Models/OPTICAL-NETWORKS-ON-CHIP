/*******************************************************************
*
*  DESCRIPTION: Atomic Model Laser
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
#include "Photodiode.h"  // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Photodiode
* Description: constructor
********************************************************************/
Photodiode::Photodiode( const string &name )
: Atomic( name )
, light( addInputPort( "light" ) )
, current( addOutputPort( "current" ) )
, processingTime (0,0,2,0)
{
	string time1( MainSimulator::Instance().getParameter( description(), "processingTime" ) ) ;

	if( time1 != "" )
		processingTime = time1 ;
	
}

/*******************************************************************
* Function Name: externalFunction
* Description: the Photodiode receives data
********************************************************************/
Model &Photodiode::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive)
  {
  
    if (msg.port() == light)
     {
      LIGHT = static_cast < int > (msg.value());//extract DATA from msg
      I = 1;     //set it to True
    
      holdIn(active, processingTime);
     }
    
	
  }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Photodiode::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Photodiode::outputFunction( const InternalMessage &msg )
{

      if ( I == 1 )
        {
         I = LIGHT / 30;
         sendOutput( msg.time(),current, I);
        }
         
      return *this;
}


