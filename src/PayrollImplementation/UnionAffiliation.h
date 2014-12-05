/* 
 * File:   UnionAffiliation.h
 * Author: denis
 *
 * Created on 23 октября 2014 г., 10:37
 */

#ifndef UNIONAFFILIATION_H
#define	UNIONAFFILIATION_H

#include "Affiliation.h"
#include "Date.h"
#include <map>
#include <memory>

class ServiceCharge;

class UnionAffiliation : public Affiliation
{
private:
	typedef std::shared_ptr<ServiceCharge> TServiceCharge;

public:
    UnionAffiliation( int id, double dues );
    
    int getMemberId() const { return m_memberId; }
    double getDues() const { return m_dues; }
    
    void AddServiceCharge(ServiceCharge *sc);
	const ServiceCharge *getServiceCharge(const Date &date) const;// { return m_charges[date].get(); }
    
    double CalculateDeductions(Paycheck *paycheck) const override;

private:
    int NumberOfFridaysInPayPeriod(const Date &payPeriodStart, const Date &payPeriodEnd) const;
    int m_memberId;
    double m_dues;
	std::map<Date, TServiceCharge> m_charges;
};

#endif	/* UNIONAFFILIATION_H */

