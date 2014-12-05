#include "ChangeUnaffiliatedTransaction.h"
#include "NoAffiliation.h"
#include "UnionAffiliation.h"
#include "PayrollDatabase.h"

ChangeUnaffiliatedTransaction::ChangeUnaffiliatedTransaction(int id) : ChangeAffiliationTransaction(id)
{}

Affiliation *ChangeUnaffiliatedTransaction::getAffiliation()
{
    return new NoAffiliation;
}

void ChangeUnaffiliatedTransaction::RecordMembership(std::shared_ptr<Employee> e)
{
    UnionAffiliation *aff = dynamic_cast<UnionAffiliation*>(e->getAffiliation());
    if (aff)
    {
        int memberId = aff->getMemberId();
        PayrollDatabase::instance().RemoveUnionMember(memberId);
    }
    
}
