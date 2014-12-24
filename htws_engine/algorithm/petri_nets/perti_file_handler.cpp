
#include "../algorithm_all.h"

namespace petri
{
class PetriNet;
class ReachibilityProblem;
} /* namespace petri */

namespace petri
{

PertiFileHandler::PertiFileHandler()
{
	// TODO Auto-generated constructor stub

}

PertiFileHandler::~PertiFileHandler()
{
	// TODO Auto-generated destructor stub
}

PetriNet* PertiFileHandler::LoadPetriNetFromFile(const FilePath& path)
{
	FILE * f = path.FOpen();
	if (!f)
	{
		LLF("petri",Format("Unable to open file: %s", path.GetPath()));
		return NULL;
	}
	vector<string> places;
	vector<Transition> transitions;
	string s;
	char c;
	if ( !GetNewString(f,s,c,":") || s != "Places" || c != ':')
	{
		LL1("petri","Invalid petri net file format");
		return NULL;
	}
	while(GetNewString(f,s,c,",;"))
	{
		places.push_back(s);
		if (c == ';')
		{
			break;
		}
		if (c != ',')
		{
			LL1("petri","error loading places");
			return NULL;
		}
	}
	if ( !GetNewString(f,s,c,":") || s != "Transitions" || c != ':')
	{
		LL1("petri","Invalid petri net file format");
		return NULL;
	}
	while(GetNewString(f,s,c,",;"))
	{
		transitions.push_back(Transition(vector<int>(places.size(),0),vector<int>(places.size(),0),StringHelper::UTF8to16(s.c_str())));
		if (c == ';')
		{
			break;
		}
		if (c != ',')
		{
			LL1("petri","error loading transitions");
			return NULL;
		}

	}
	if ( !GetNewString(f,s,c,":") || s != "Edges" || c != ':')
	{
		LL1("petri","Invalid petri net file format");
		return NULL;
	}
	while(GetNewString(f,s,c,",;"))
	{
		if (s.find(":") == s.rfind(":"))
		{
			LL1("petri",Format("error loading edges, invalid edge: %s", s));
		}
		string name1 = s.substr(0,s.find(":"));
		string name2 = s.substr(s.find(":")+1,s.rfind(":") - s.find(":") - 1);
		string placeName;
		wstring transitionName;
		int weight = atoi(s.substr(s.rfind(":") +1, string::npos).c_str());
		vector<Transition>::iterator itTran;
		bool isInputEdge;
		if ( std::find(places.begin(), places.end(), name1) != places.end())
		{
			placeName = name1;
			transitionName = StringHelper::UTF8to16(name2.c_str());
			isInputEdge = true;
		}
		else if (std::find(places.begin(), places.end(), name2) != places.end())
		{
			placeName = name2;
			transitionName = StringHelper::UTF8to16(name1.c_str());
			isInputEdge = false;
		}
		else
		{
			LL1("petri",Format("error loading edges, place not found for edge: %s", s));
			return NULL;
		}
		itTran = std::find_if(transitions.begin(), transitions.end(), [&transitionName] (const Transition& t) { return t.GetName() == transitionName; });
		if (itTran == transitions.end())
		{
			LL1("petri",Format("error loading edges, transition not found for edge: %s", s));
			return NULL;
		}
		int placeIndex = -1;
		for (int i = 0; i< places.size(); ++ i)
		{
			if (places[i] == placeName)
			{
				placeIndex = i;
			}
		}
		if (isInputEdge)
		{
			itTran->inputEdges[placeIndex] = weight;
		}
		else
		{
			itTran->outputEdges[placeIndex] = weight;
		}
		if (c == ';')
		{
			break;
		}
		if (c != ',')
		{
			LL1("petri","error loading transitions");
			return NULL;
		}

	}
	PetriNet* net = new PetriNet();
	for(unsigned i = 0; i< transitions.size(); ++i)
	{
		net->AddTransition(transitions[i]);
	}
	return net;
}

ReachibilityProblem* PertiFileHandler::LoadReachibilityProblem(
		const FilePath& path)
{
	FILE * f = path.FOpen();
	if (!f)
	{
		LLF("petri",Format("Unable to open file: %s", path.GetPath()));
		return NULL;
	}
	vector<int> initialMarking;
	vector<int> endMarking;
	string s;
	char c;
	if ( !GetNewString(f,s,c,":") || s != "Initial" || c != ':')
	{
		LL1("petri","Invalid reachibility problem file format");
		return NULL;
	}
	while(GetNewString(f,s,c,",;"))
	{
		initialMarking.push_back(atoi(s.c_str()));
		if (c == ';')
		{
			break;
		}
		if (c != ',')
		{
			LL1("petri","error loading initial marking");
			return NULL;
		}
	}
	if ( !GetNewString(f,s,c,":") || s != "Final" || c != ':')
	{
		LL1("petri","Invalid reachibility problem file format");
		return NULL;
	}
	while(GetNewString(f,s,c,",;"))
	{
		endMarking.push_back(atoi(s.c_str()));
		if (c == ';')
		{
			break;
		}
		if (c != ',')
		{
			LL1("petri","error loading initial marking");
			return NULL;
		}
	}
	ReachibilityProblem* ret = new ReachibilityProblem(initialMarking,endMarking);
	return ret;
}

bool PertiFileHandler::GetNewString(FILE* f, string& s, char& c, const char* characters)
{
	char buffer[10000];
	string formats = "%[";
	while(*characters)
	{
		formats += "^";
		formats += *characters;
		++characters;
	}
	formats += "]";
	if (fscanf(f,formats.c_str(),buffer) == 1 && fscanf(f,"%c",&c) == 1)
	{
		s = buffer;
		s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
		StringHelper::trim(s);
		return true;
	}
	return false;
}

} /* namespace petri */


