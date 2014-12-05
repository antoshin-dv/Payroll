#include "ChangeMemberTransaction.h"
#include "UnionAffiliation.h"
#include "PayrollDatabase.h"

ChangeMemberTransaction::ChangeMemberTransaction(int empId, int memberId, double dues)
    : ChangeAffiliationTransaction(empId), m_memberId(memberId), m_dues(dues)
{}

Affiliation *ChangeMemberTransaction::getAffiliation()
{
    return new UnionAffiliation(m_memberId, m_dues);
}

void ChangeMemberTransaction::RecordMembership(std::shared_ptr<Employee> e)
{
    PayrollDatabase::instance().AddUnionMember(m_memberId, e);
}
