/* 
 * File:   CommissionedClassification.h
 * Author: denis
 *
 * Created on 21 октября 2014 г., 21:53
 */

#ifndef COMMISSIONEDCLASSIFICATION_H
#define	COMMISSIONEDCLASSIFICATION_H

#include "PaymentClassification.h"
#include "SalesReceipt.h"
#include <map>

class CommissionedClassification : public PaymentClassification
{
public:
    CommissionedClassification(double baseRate, double commissionRate);
    ~CommissionedClassification();
    
    double getBaseRate() const { return m_baseRate; }
    double getCommissionRate() const { return m_commissionRate; }
    
    void AddSalesReceipt(SalesReceipt *sales);
    SalesReceipt* GetSalesReceipt(const Date& date);

    double CalculatePay(Paycheck* paycheck) override;


private:
    double m_baseRate;
    double m_commissionRate;
    std::map<Date, SalesReceipt*> m_salesReceipts;
};

#endif	/* COMMISSIONEDCLASSIFICATION_H */

