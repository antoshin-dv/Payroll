/* 
 * File:   NoAffiliation.h
 * Author: denis
 *
 * Created on 23 октября 2014 г., 14:06
 */

#ifndef NOAFFILIATION_H
#define	NOAFFILIATION_H

#include "Affiliation.h"

class NoAffiliation : public Affiliation
{
public:
    double CalculateDeductions( Paycheck *paycheck ) const override { return 0.0; }
};

#endif	/* NOAFFILIATION_H */

