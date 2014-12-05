/* 
 * File:   PaymentMethod.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 19:36
 */

#ifndef PAYMENTMETHOD_H
#define	PAYMENTMETHOD_H

class Paycheck;

class PaymentMethod {
public:
    virtual ~PaymentMethod() {};
    virtual void Pay( Paycheck *paycheck ) = 0;
};

#endif	/* PAYMENTMETHOD_H */

