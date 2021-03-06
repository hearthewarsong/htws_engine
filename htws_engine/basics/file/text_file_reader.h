#ifndef TEXT_FILE_READER_H_
#define TEXT_FILE_READER_H_

class TextFileReader
{
protected:
	string fileName;
	bool trim;
	bool skipComments;
	bool considerQuotationMarks;
	string path;
public:
	TextFileReader(const string& fileName, bool skipComments = true,
			bool trim = true, bool considerQuotationMarks = true);
	virtual ~TextFileReader();
	void SetPath(string Path);
	bool GetContent(vector<string>& lines);
	bool GetContent(vector<wstring>& lines);
	bool GetContent(map<string, string>& dictionary);
	bool GetContent(map<wstring, wstring>& dictionary);
};

#endif /* TEXT_FILE_READER_H_ */
