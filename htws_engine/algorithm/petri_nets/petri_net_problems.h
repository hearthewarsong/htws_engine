/*
 * petri_net_problems.h
 *
 *  Created on: Aug 24, 2014
 *      Author: hearthewarsong
 */

#ifndef PETRI_NET_PROBLEMS_H_
#define PETRI_NET_PROBLEMS_H_

namespace petri
{

class ReachibilityProblem
{
	BasicModelMarking initial;
	BasicModelMarking final;
public:
	ReachibilityProblem(const vector<int>& initial, const vector<int>& final) :initial(initial), final(final) {}
	const BasicModelMarking& GetStartingMarking() { return initial; }
	const BasicModelMarking& GetEndMarking() { return final; }
	virtual ~ReachibilityProblem();
};

}
#endif /* PETRI_NET_PROBLEMS_H_ */
