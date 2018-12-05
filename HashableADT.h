
/*
 * Simone Ray. Assignment5.
 * Abstract template class for Hashing. 
 */


#ifndef HASHABLE_H
#define HASHABLE_H

template <class T>
class HashableADT {
	public:
		virtual int hash()=0;			// hash function
		virtual bool operator==(T&)=0;		// equals method
};

#endif


