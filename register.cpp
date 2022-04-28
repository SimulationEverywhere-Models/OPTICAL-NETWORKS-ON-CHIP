/*******************************************************************
*
*  DESCRIPTION: Atomic Model User Interface
*
*  AUTHOR: Shafagh Jafer
*
*  EMAIL: sjafer@connect.carleton.ca
*
*
*  DATE: 8/06/2006
*
*******************************************************************/
#include "modeladm.h" 
#include "mainsimu.h"
#include "Driver.h"        // class Driver
#include "Laser.h"        // class Laser
#include "TIA.h"        // class TIA
#include "Photodiode.h"        // class Photodiode
#include "CommandModulation.h"        // class CommandModulation
#include "PolarizationCommand.h"        // class PolarizationCommand
#include "EmissionLaser.h"        // class EmissionLaser

void MainSimulator::registerNewAtomics()
{
 SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Driver>(), "Driver" ) ;   
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Laser>(), "Laser" ) ;    
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TIA>(), "TIA" ) ;    
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Photodiode>(), "Photodiode" ) ;    
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CommandModulation>(), "CommandModulation" ) ;    
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<PolarizationCommand>(), "PolarizationCommand" ) ;    
SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<EmissionLaser>(), "EmissionLaser" ) ;    
 
 
 
}