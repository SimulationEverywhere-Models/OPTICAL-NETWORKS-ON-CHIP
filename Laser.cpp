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
#include "Laser.h"  // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Laser
* Description: constructor
********************************************************************/
Laser::Laser( const string &name )
: Atomic( name )
, current( addInputPort( "current" ) )
, light( addOutputPort( "light" ) )
, processingTime (0,0,2,0)
{
	string time1( MainSimulator::Instance().getParameter( description(), "processingTime" ) ) ;

	if( time1 != "" )
		processingTime = time1 ;
	
}

/*******************************************************************
* Function Name: externalFunction
* Description: the Laser receives data
********************************************************************/
Model &Laser::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive)
  {
  
    if (msg.port() == current)
     {
      I = static_cast < int > (msg.value());//extract DATA from msg
      LIGHT = 1;     //set it to True
    
      holdIn(active, processingTime);
     }
    
	
  }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Laser::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Laser::outputFunction( const InternalMessage &msg )
{

      if ( LIGHT == 1 )
        {
         LIGHT = I * 30;
         sendOutput( msg.time(),light, LIGHT);
        }
         
      return *this;
}


