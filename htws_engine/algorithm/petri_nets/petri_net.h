#ifndef PETRI_NET_H_
#define PETRI_NET_H_

namespace petri {


struct ExtPlaceState
{
public:
	ExtPlaceState() :value(0) {}
	int value;
	vector<int> growth;
};

class BasicModelMarking
{
protected:
	vector<int> places;
public:
	BasicModelMarking(int placeCount);
	BasicModelMarking(const vector<int>& places);
	int& operator[](int index) { return places[index]; }
	const int& operator[](int index) const { return places[index]; }
	unsigned GetPlaceCount() const { return places.size(); }
	const BasicModelMarking& operator=(const BasicModelMarking& bmm);
	unsigned size() const { return places.size(); }
	const vector<int>& GetMarking() const { return places; }
};

class ExtModelMarking
{
protected:
	vector<ExtPlaceState> places;
	map<vector<int>,bool> recursiveCombinableCache;
	bool recursiveCombinable(vector<int>& reguiredGrowth);
public:
	ExtModelMarking(int placeCount);
	ExtModelMarking(const ExtModelMarking& other);
	ExtModelMarking(const BasicModelMarking& other);
	ExtPlaceState& operator[](int index) { return places[index]; }
	const ExtPlaceState& operator[](int index) const { return places[index]; }
	unsigned size() const { return places.size(); }
	unsigned GetPlaceCount() const { return places.size(); }
	bool Contains(const ExtModelMarking& marking);
	unsigned GetGrowthCount() const { return places.size() != 0 ? places[0].growth.size(): 0; }
	vector<int> GetBasicMarking() const;
	void SetBasicMarking(const vector<int>& marking);
	vector<int> GetGrowth(int index) const;
	void AddGrowth(const vector<int> growth);
	bool Combinable(vector<int> reguiredGrowth);
	virtual ~ExtModelMarking() {}
};

class Transition
{
protected:
	vector<int> inputEdges;
	vector<int> outputEdges;
	wstring name;
	static unsigned transitionNumber;
public:
	Transition(vector<int> inputEdges,vector<int> outputEdges, const wstring& name = wstring());
	const vector<int>& GetInputEdges() const { return inputEdges; }
	const vector<int>& GetOutputEdges() const { return outputEdges; }
	const wstring& GetName() const { return name; }
	bool IsFirable(const BasicModelMarking& marking) const;
	bool IsFirable(const ExtModelMarking& marking) const;
	OWNERSHIP BasicModelMarking* FireTransition(const BasicModelMarking& marking) const;
	OWNERSHIP vector<ExtModelMarking*> FireTransition(const ExtModelMarking& marking) const;
	friend class PertiFileHandler;
};

class Place
{

};

class PetriNet
{
protected:
	vector<Place> places;
	vector<Transition> transitions;
	IntMatrix matrix;
	BasicModelMarking initialMarking;
public:
	PetriNet();
	const BasicModelMarking& GetInitialMarking() const;
	void SetInitialMarking(const BasicModelMarking& initialMarking);
	const vector<Transition>& GetTransitions() const { return transitions; }
	void AddTransition(const Transition& t) { transitions.push_back(t); }
	void AddPlace(const Place& p) { places.push_back(p); }
	vector<Place>& GetPlaces() { return places; }
	void CalculateMatrix();
	const IntMatrix& GetMatrix() { return matrix; }

	virtual ~PetriNet();
};

}

#endif /* PETRI_NET_H_ */
