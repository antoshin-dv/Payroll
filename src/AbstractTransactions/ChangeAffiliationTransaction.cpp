#include "ChangeAffiliationTransaction.h"
#include "Employee.h"

ChangeAffiliationTransaction::ChangeAffiliationTransaction(int id) : ChangeEmployeeTransaction(id)
{}

void ChangeAffiliationTransaction::Change(TEmployee e)
{
    RecordMembership(e);
    e->setAffiliation( getAffiliation() );
}
