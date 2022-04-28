/*******************************************************************
*
*  DESCRIPTION: Atomic Model PolarizationCommand
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
#include "PolarizationCommand.h"  // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: PolarizationCommand
* Description: constructor
********************************************************************/
PolarizationCommand::PolarizationCommand( const string &name )
: Atomic( name )
, in1( addInputPort( "in1" ) )
, out1( addOutputPort( "out1" ) )
, out2( addOutputPort( "out2" ) )
, processingTime (0,0,0,0)
{
	string time( MainSimulator::Instance().getParameter( description(), "processingTime" ) ) ;

	if( time != "" )
		processingTime = time;

	
}

/*******************************************************************
* Function Name: externalFunction
* Description: the PolarizationCommand receives data
********************************************************************/
Model &PolarizationCommand::externalFunction( const ExternalMessage &msg )
{
  if ( this->state() == passive)
  {
  
       
    if (msg.port() == in1)
     {
      IN1 = static_cast < int > (msg.value());//extract DATA from msg
	  OUT1 = 1;     //set it to True
      holdIn(active, processingTime);
     }
	

  }
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &PolarizationCommand::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &PolarizationCommand::outputFunction( const InternalMessage &msg )
{

      if ( OUT1 == 1 )
        {
         OUT1 = IN1;
         OUT2 = IN1;
         sendOutput( msg.time(),out1, OUT1);
         sendOutput( msg.time(),out2, OUT2);
        }
         
      return *this;
}


