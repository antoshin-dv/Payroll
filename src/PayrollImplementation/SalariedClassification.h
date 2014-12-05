/* 
 * File:   SalariedClassification.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 19:53
 */

#ifndef SALARIEDCLASSIFICATION_H
#define	SALARIEDCLASSIFICATION_H

#include "PaymentClassification.h"

class SalariedClassification : public PaymentClassification
{
public:
    SalariedClassification(double salary) : m_salary ( salary ) {};
    
    double getSalary() const { return m_salary; }
        
    double CalculatePay(Paycheck* paycheck) override { return m_salary; }
   
private:
    double m_salary;
};

#endif	/* SALARIEDCLASSIFICATION_H */
