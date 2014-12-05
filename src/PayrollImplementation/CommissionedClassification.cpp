/* 
 * File:   CommissionedClassification.cpp
 * Author: denis
 * 
 * Created on 21 октября 2014 г., 21:53
 */

#include "CommissionedClassification.h"
#include "Paycheck.h"

CommissionedClassification::CommissionedClassification( double baseRate, double commissionRate )
    : m_baseRate( baseRate ), m_commissionRate( commissionRate )
{
}

CommissionedClassification::~CommissionedClassification()
{
    for( auto it = m_salesReceipts.begin(); it != m_salesReceipts.end(); ++it )
        delete (*it).second;
}

void CommissionedClassification::AddSalesReceipt(SalesReceipt *sales)
{
    m_salesReceipts[sales->getDate()] = sales;
}

SalesReceipt* CommissionedClassification::GetSalesReceipt(const Date& date)
{
    return m_salesReceipts[date];
}

double CommissionedClassification::CalculatePay(Paycheck* paycheck)
{
    double total = 0;
    for(auto it = m_salesReceipts.begin(); it != m_salesReceipts.end(); ++it)
    {
        Date date = it->first;
        SalesReceipt *sales = it->second;
        if(date.isInPeriod(paycheck->PayPeriodStartDate(), paycheck->PayPeriodEndDate()))
            total += sales->getAmount();
    }
    return m_baseRate + (total * m_commissionRate * 0.01);
}
