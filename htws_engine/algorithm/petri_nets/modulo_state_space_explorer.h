#ifndef MODULO_STATE_SPACE_EXPLORER_H_
#define MODULO_STATE_SPACE_EXPLORER_H_

namespace petri
{

class ModuloStateSpaceExplorer
{
protected:
	class Node : public ExtModelMarking
	{
	public:
		Node* parent;
		Node(const ExtModelMarking& other) :ExtModelMarking(other), parent(NULL) {}
		Node(const BasicModelMarking& other) :ExtModelMarking(other), parent(NULL) {}
		operator ExtModelMarking() { return *(ExtModelMarking*)this; }
	};
	vector<Node*> markings;
	deque<Node*> newmarkings;
	IWTextCommunicator* logger;
	const PetriNet* petrinet;
	void UpdateGrowth(Node* marking);
	vector<Node*> GetDescandants(Node* marking);
	void Clear();
public:
	ModuloStateSpaceExplorer();
	void ExaminePetriNet(const PetriNet& modell, int memoryLimit = 0);
	void ExaminePetriNet(const PetriNet& modell, IWTextCommunicator* logger, int memoryLimit = 0);
	void PrintStatistic( const IWTextCommunicator& logger);
	bool HasMarking(const BasicModelMarking& marking);
	bool HasMarking(const ExtModelMarking& marking);
	unsigned GetGraphSize() const { return markings.size(); }
	virtual ~ModuloStateSpaceExplorer();
};

} /* namespace petri */

#endif /* MODULO_STATE_SPACE_EXPLORER_H_ */
