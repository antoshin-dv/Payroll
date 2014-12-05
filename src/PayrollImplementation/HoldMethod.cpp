/* 
 * File:   HoldMethod.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 20:02
 */

#include "HoldMethod.h"
#include "Paycheck.h"

HoldMethod::HoldMethod() {
}

void HoldMethod::Pay( Paycheck *paycheck )
{
    paycheck->setField( "Disposition", "Hold" );
}


