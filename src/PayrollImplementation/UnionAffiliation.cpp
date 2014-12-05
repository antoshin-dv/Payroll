/* 
 * File:   UnionAffiliation.cpp
 * Author: denis
 * 
 * Created on 23 октября 2014 г., 10:37
 */

#include "UnionAffiliation.h"
#include "Paycheck.h"
#include "ServiceCharge.h"

UnionAffiliation::UnionAffiliation( int id, double dues )
    : m_memberId( id ), m_dues( dues )
{
}

void UnionAffiliation::AddServiceCharge(ServiceCharge *sc) {
	m_charges[sc->getDate()] = TServiceCharge(sc);
}

double UnionAffiliation::CalculateDeductions(Paycheck *paycheck) const 
{
    double totalDues = 0.0;
    int fridays = NumberOfFridaysInPayPeriod(paycheck->PayPeriodStartDate(), paycheck->PayPeriodEndDate());
    totalDues = m_dues * fridays;
    
    for( auto it = m_charges.begin(); it != m_charges.end(); ++it )
    {
		TServiceCharge charge = it->second;
        Date date = it->first;
        if ( date.isInPeriod( paycheck->PayPeriodStartDate(), paycheck->PayPeriodEndDate() ) )
            totalDues += charge->getAmount();
    }
    
    return totalDues;
}

int UnionAffiliation::NumberOfFridaysInPayPeriod(const Date &payPeriodStart, const Date &payPeriodEnd) const
{
    int fridays = 0;
    for ( Date d = payPeriodStart; d <= payPeriodEnd; ++d )
        if( d.DayOfWeek() == 5 )
            fridays++;
    return fridays;
}

const ServiceCharge* UnionAffiliation::getServiceCharge(const Date &date) const
{
	auto it = m_charges.find(date);
	if (it == m_charges.cend())
		return nullptr;

	return (it->second).get();
}
