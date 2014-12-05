/* 
 * File:   Affiliation.h
 * Author: denis
 *
 * Created on 23 октября 2014 г., 13:15
 */

#ifndef AFFILIATION_H
#define	AFFILIATION_H

class Paycheck;

class Affiliation {
public:
    virtual ~Affiliation() {};
    virtual double CalculateDeductions( Paycheck *paycheck ) const = 0;
};

#endif	/* AFFILIATION_H */

