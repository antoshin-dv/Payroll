#ifndef CHANGE_MEMBER_TRANSACTION_H
#define	CHANGE_MEMBER_TRANSACTION_H

#include "ChangeAffiliationTransaction.h"

class Employee;

class ChangeMemberTransaction : public ChangeAffiliationTransaction
{
public:
    ChangeMemberTransaction(int empId, int memberId, double dues);
    
protected:
    Affiliation *getAffiliation() override;
    
    void RecordMembership(std::shared_ptr<Employee> e) override;
    
private:
    const int m_memberId;
    const double m_dues;
};

#endif	/* CHANGE_MEMBER_TRANSACTION_H */

