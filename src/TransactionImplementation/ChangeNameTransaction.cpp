#include "ChangeNameTransaction.h"
#include "Employee.h"

ChangeNameTransaction::ChangeNameTransaction(int id, const std::string &name)
    : ChangeEmployeeTransaction(id), m_newName(name)
{
}

void ChangeNameTransaction::Change(TEmployee e)
{
    e->setName(m_newName);
}
