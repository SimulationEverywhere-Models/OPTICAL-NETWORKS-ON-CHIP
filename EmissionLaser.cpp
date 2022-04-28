/*******************************************************************
*
*  DESCRIPTION: Atomic Model EmissionLaser
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
#include "EmissionLaser.h"  // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: EmissionLaser
* Description: constructor
********************************************************************/
EmissionLaser::EmissionLaser( const string &name )
: Atomic( name )
, in1( addInputPort( "in1" ) )
, in2( addInputPort( "in2" ) )
, out1( addOutputPort( "out1" ) )
, processingTime (0,0,2,0)
{
	string time1( MainSimulator::Instance().getParameter( description(), "processingTime" ) ) ;

	if( time1 != "" )
		processingTime = time1 ;
	
}

/*******************************************************************
* Function Name: externalFunction
* Description: the EmissionLaser receives data
********************************************************************/
Model &EmissionLaser::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive)
  {
  
    if (msg.port() == in1)
     {
      IN1 = static_cast < int > (msg.value());//extract DATA from msg
      if (IN2 > 0){
      	OUT1 = 1;
      	holdIn(active, processingTime);
      }
     }
    
    if (msg.port() == in2)
     {
      IN2 = static_cast < int > (msg.value());//extract DATA from msg
	  
      if (IN1 > 0){
      	OUT1 = 1;
	    holdIn(active, processingTime);
      }
     }
	

  }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &EmissionLaser::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &EmissionLaser::outputFunction( const InternalMessage &msg )
{

      if ( OUT1 == 1 )
        {
         OUT1 = IN1 + IN2;
         sendOutput( msg.time(),out1, OUT1);
        }
         
      return *this;
}


