/*
 * Number.h
 *
 *  Created on: Apr 8, 2014
 *      Author: kyle
 *      Note: it might be necessary to include template<> stuff, since it should be agnostic to types of subclasses...?
 */

#ifndef NUMBER_H_
#define NUMBER_H_

using namespace std;


class Number {
	public:
		Number(); // Not sure if we need
		virtual ~Number();
		virtual void Add() = 0; // void since actual returns should be subclasses
		virtual void Subtract() = 0;
		virtual void Multiply() = 0;
		virtual void Divide() = 0;
}

#endif /* NUMBER_H_ */
