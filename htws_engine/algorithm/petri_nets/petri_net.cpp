#include "../algorithm_all.h"

namespace petri {

using namespace htws_math;

PetriNet::PetriNet() :matrix(0,0), initialMarking(0)
{
	// TODO Auto-generated constructor stub
}

const BasicModelMarking& PetriNet::GetInitialMarking() const
{
	if (initialMarking.size() == 0)
	{
		//LLF("PETRI",);
	}
	return initialMarking;
}

void PetriNet::SetInitialMarking(const BasicModelMarking& initialMarking)
{
	this->initialMarking = initialMarking;
}

void PetriNet::CalculateMatrix()
{
	//TODO implement
}

PetriNet::~PetriNet()
{
	// TODO Auto-generated destructor stub
}

BasicModelMarking::BasicModelMarking(int placeCount) :places(placeCount,0)
{
}

BasicModelMarking::BasicModelMarking(const vector<int>& places) :places(places)
{
}

ExtModelMarking::ExtModelMarking(int placeCount) :places(placeCount)
{
}

const BasicModelMarking& BasicModelMarking::operator=(const BasicModelMarking& bmm)
{
	this->places = bmm.places;
	return *this;
}

ExtModelMarking::ExtModelMarking(const ExtModelMarking& other)
{
	this->places = other.places;
}

ExtModelMarking::ExtModelMarking(const BasicModelMarking& other) :places(other.size())
{
	for(unsigned i=0; i< size(); ++i)
	{
		places[i].value = other[i];
	}
}

bool ExtModelMarking::Contains(const ExtModelMarking& marking)
{
	vector<int> temp;
	if (!Combinable(SubtractVector<int>(marking.GetBasicMarking(),GetBasicMarking())))
	{
		return false;
	}
	for(unsigned i = 0; i<marking.GetGrowthCount(); ++i)
	{
		if (!Combinable(marking.GetGrowth(i)))
		{
			return false;
		}
	}
	return true;
}


bool ExtModelMarking::Combinable(vector<int> requiredGrowth)
{
	if (places.size() != requiredGrowth.size() || places.size() == 0)
	{
		LLF("petri",Format("%s was called with requiredGrowth.size()=%d and places.size()=%d", __FUNCTION__ % requiredGrowth.size() % places.size() ));
		return false;
	}
	recursiveCombinableCache.clear();
	return recursiveCombinable(requiredGrowth);
}

bool ExtModelMarking::recursiveCombinable(
		vector<int>& requiredGrowth)
{
	if (htws_math::HasSmallerElementThan<int>(requiredGrowth,0))
	{
		return 0;
	}
	if (recursiveCombinableCache.find(requiredGrowth) != recursiveCombinableCache.end())
	{
		return recursiveCombinableCache[requiredGrowth];
	}
	if(htws_math::allElementsEqualTo<int>(requiredGrowth,0))
	{
		return true;
	}
	for (unsigned i = 0; i<places[0].growth.size(); ++i)
	{
		vector<int> newStep = requiredGrowth;
		for(unsigned j = 0; j<places.size(); ++j)
		{
			newStep[j] -= places[j].growth[i];
		}
		if (recursiveCombinable(newStep)) return true;
	}
	return false;
}

vector<int> ExtModelMarking::GetBasicMarking() const
{
	vector<int> result;
	for(unsigned i = 0; i<places.size(); ++i)
	{
		result.push_back(places[i].value);
	}
	return result;
}

vector<int> ExtModelMarking::GetGrowth(int index) const
{
	vector<int> result;
	for(unsigned i = 0; i<places.size(); ++i)
	{
		result.push_back(places[i].growth[index]);
	}
	return result;
}


unsigned Transition::transitionNumber = 0;

Transition::Transition(vector<int> inputEdges, vector<int> outputEdges,
		const wstring& name) :inputEdges(inputEdges), outputEdges(outputEdges), name(name)
{
	if (name==L"")
	{
		this->name = FormatW(L"T_%d",transitionNumber);
	}
}

bool Transition::IsFirable(const BasicModelMarking& marking) const
{
	return LessThanOrEqualTo<int>(inputEdges,marking.GetMarking());
}

bool Transition::IsFirable(const ExtModelMarking& marking) const
{
	for (unsigned i = 0; i<inputEdges.size(); ++i)
	{
		if (inputEdges[i] > marking[i].value)
		{
			bool canAdd = false;
			foreach_const(vector<int>,marking[i].growth,it)
			{
				if (*it > 0)
				{
					canAdd = true;
					break;
				}
			}
			if (!canAdd) return false;
		}
	}
	return true;
}

BasicModelMarking* Transition::FireTransition(
		const BasicModelMarking& marking) const
{
	if (!IsFirable(marking))
	{
		return NULL;
	}
	BasicModelMarking* ret = new BasicModelMarking(marking);
	for(unsigned i = 0; i<marking.GetPlaceCount(); ++i)
	{
		(*ret)[i]-=this->inputEdges[i];
		(*ret)[i]+=this->outputEdges[i];
	}
	return ret;
}

vector<ExtModelMarking*> Transition::FireTransition(
		const ExtModelMarking& marking) const
{
	vector<ExtModelMarking*> result;
	if (!IsFirable(marking))
	{
		return vector<ExtModelMarking*>();
	}
	deque<BasicModelMarking*> breadthFirstStack;
	breadthFirstStack.push_back(new BasicModelMarking(marking.GetBasicMarking()));
	while(breadthFirstStack.size() > 0)
	{
		BasicModelMarking* current = breadthFirstStack.front();
		breadthFirstStack.pop_front();
		if (IsFirable(*current))
		{
			BasicModelMarking* newBasicMarking = FireTransition(*current);
			ExtModelMarking * newMarking = new ExtModelMarking(marking);
			newMarking->SetBasicMarking(newBasicMarking->GetMarking());
			delete newBasicMarking;
			result.push_back(newMarking);
		}
		else
		{
			for(unsigned i = 0; i<marking.GetGrowthCount(); ++i)
			{
				for (unsigned j = 0; j<marking.GetPlaceCount(); ++j)
				{
					if ((*current)[j] < inputEdges[j] && marking[j].growth[i] > 0)
					{
						breadthFirstStack.push_back(new BasicModelMarking(AddVector<int>(current->GetMarking(),marking.GetGrowth(i))));
						break;
					}
				}
			}
		}
		delete current;
	}
	return result;
}

void ExtModelMarking::SetBasicMarking(const vector<int>& marking)
{
	for(unsigned i = 0; i < places.size(); ++i)
	{
		places[i].value=marking[i];
	}
}

void ExtModelMarking::AddGrowth(const vector<int> growth)
{
	for(unsigned i = 0; i<growth.size(); ++i)
	{
		places[i].growth.push_back(growth[i]);
	}
}

}

