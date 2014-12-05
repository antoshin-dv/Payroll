#ifndef CHANGE_UNAFFILIATED_TRANSACTION_H
#define	CHANGE_UNAFFILIATED_TRANSACTION_H

#include "ChangeAffiliationTransaction.h"

class Employee;

class ChangeUnaffiliatedTransaction : public ChangeAffiliationTransaction
{
public:
    ChangeUnaffiliatedTransaction( int id );
    
protected:
    Affiliation *getAffiliation() override;
	void RecordMembership(std::shared_ptr<Employee> e) override;

};

#endif	/* CHANGE_UNAFFILIATED_TRANSACTION_H */

