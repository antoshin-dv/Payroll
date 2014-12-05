#ifndef CHANGE_AFFILIATION_TRANSACTION_H
#define	CHANGE_AFFILIATION_TRANSACTION_H

#include "ChangeEmployeeTransaction.h"

class Affiliation;

class ChangeAffiliationTransaction : public ChangeEmployeeTransaction
{
public:
    ChangeAffiliationTransaction(int id);
    
protected:
	void Change(TEmployee e) override;
    
    virtual Affiliation *getAffiliation() = 0;
	virtual void RecordMembership(std::shared_ptr<Employee> e) = 0;
    
};

#endif	/* CHANGE_AFFILIATION_TRANSACTION_H */

