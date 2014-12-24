#include "../algorithm_all.h"

namespace petri
{

using namespace htws_math;

ModuloStateSpaceExplorer::ModuloStateSpaceExplorer() :logger(NULL), petrinet(NULL)
{
	// TODO Auto-generated constructor stub
}

void ModuloStateSpaceExplorer::UpdateGrowth(Node* marking)
{
	Node* parent = marking->parent;
	while(parent)
	{
		if (LessThanOrEqualTo<int>(parent->GetBasicMarking(),marking->GetBasicMarking()))
		{
			vector<int> newGrowth = SubtractVector(marking->GetBasicMarking(),parent->GetBasicMarking());
			if (HasGraterElementThan(newGrowth,0) && !marking->Combinable(newGrowth))
			{
				marking->AddGrowth(newGrowth);
			}
		}
		parent = parent->parent;
	}
}

vector<ModuloStateSpaceExplorer::Node*> ModuloStateSpaceExplorer::GetDescandants(Node* marking)
{
	vector<Node*> result;
	foreach_const(vector<Transition>, petrinet->GetTransitions(), itT)
	{
		if (itT->IsFirable(*marking))
		{
			vector<ExtModelMarking*> descandants = itT->FireTransition(*marking);
			foreach(vector<ExtModelMarking*>, descandants, itD)
			{
				Node* newNode = new Node(**itD);
				delete *itD;
				newNode->parent = marking;
				result.push_back(newNode);
			}
		}
	}
	return result;
}

void ModuloStateSpaceExplorer::Clear()
{
	foreach(vector<Node*>,markings,it)
	{
		delete *it;
	}
	markings.clear();
	foreach(deque<Node*>,newmarkings,it)
	{
		delete *it;
	}
	markings.clear();
}

ModuloStateSpaceExplorer::~ModuloStateSpaceExplorer()
{
	Clear();
}

void ModuloStateSpaceExplorer::ExaminePetriNet(const PetriNet& modell,
		int memoryLimit)
{
	ExaminePetriNet(modell, NULL, memoryLimit);
}

void ModuloStateSpaceExplorer::ExaminePetriNet(const PetriNet& modell,
		IWTextCommunicator* logger, int memoryLimit /* TODO implement */)
{
	Clear();
	petrinet = &modell;
	this->logger = logger;
	newmarkings.push_back(new Node(modell.GetInitialMarking()));
	while (newmarkings.size() > 0)
	{
		Node* currentNode = newmarkings.front();
		newmarkings.pop_front();
		UpdateGrowth(currentNode);
		if (!HasMarking(*currentNode))
		{
			markings.push_back(currentNode);
			if (markings.size() % 100 == 0) printf(" Marking count: %d\n", markings.size());
			vector<Node*> descandants = GetDescandants(currentNode);
			newmarkings.insert(newmarkings.end(),descandants.begin(),descandants.end());
		}
		else
		{
			delete currentNode;
		}
	}
}

void ModuloStateSpaceExplorer::PrintStatistic(
		const IWTextCommunicator& logger)
{
	//TODO implement
}

bool ModuloStateSpaceExplorer::HasMarking(const BasicModelMarking& marking)
{
	foreach(vector<Node*>,markings,it)
	{
		if ((*it)->Contains(ExtModelMarking(marking))) return true;
	}
	return false;
}

bool ModuloStateSpaceExplorer::HasMarking(const ExtModelMarking& marking)
{
	foreach(vector<Node*>,markings,it)
	{
		if ((*it)->Contains(marking)) return true;

	}
	return false;
}

} /* namespace petri */
