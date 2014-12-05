/* 
 * File:   PaymentClassification.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 19:36
 */

#ifndef PAYMENTCLASSIFICATION_H
#define	PAYMENTCLASSIFICATION_H

class Paycheck;

class PaymentClassification 
{
public:
    virtual ~PaymentClassification() {};
    virtual double CalculatePay( Paycheck *paycheck ) = 0;
};

#endif	/* PAYMENTCLASSIFICATION_H */

