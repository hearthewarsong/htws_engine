#ifndef PERTI_FILE_HANDLER_H_
#define PERTI_FILE_HANDLER_H_

namespace petri
{

class PertiFileHandler
{
protected:
	bool GetNewString(FILE* f, string& s, char& c, const char* characters);
public:
	PertiFileHandler();
	OWNERSHIP PetriNet* LoadPetriNetFromFile(const FilePath& path);
	OWNERSHIP ReachibilityProblem* LoadReachibilityProblem(const FilePath& path);
	virtual ~PertiFileHandler();
};

} /* namespace petri */

#endif /* PERTI_FILE_HANDLER_H_ */
