/* 
 * File:   HoldMethod.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 20:02
 */

#ifndef HOLDMETHOD_H
#define	HOLDMETHOD_H

#include "PaymentMethod.h"

class HoldMethod : public PaymentMethod
{
public:
    HoldMethod();
    
    void Pay( Paycheck* paycheck );
};

#endif	/* HOLDMETHOD_H */

