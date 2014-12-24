#ifndef G_CONSOLE_H_
#define G_CONSOLE_H_

class GConsole : public IWTextCommunicator, public WindowImpl
{
protected:
	string fontName;
	int fontSize;
	unsigned cachedLines;
	deque<wstring> lines;
	wstring userInput;
	bool useFormating;
	ProtEnums::Status status;
	TextControl* outputControl;
	TextControl* inputControl;
	wstring inputText;
	unsigned inputIndex;
	deque<wstring> unreadLines;
public:
	GConsole(string fontName, int fontSize, unsigned cachedLines = 100);
	void Write(const string& text);
	bool Write(const wstring& text);
	void Write(const char* text);
	void Write(const wchar_t* text);

	virtual bool hasInput();
	virtual bool hasOutput();
	virtual bool isBlocking();
	virtual void setAllowFormating(bool isAllowed);
	virtual bool setBlocking(bool value);
	virtual ProtEnums::Status getStatus();
	virtual int getLastError(string& text);
	virtual bool Open(const string& arg0, const string& arg1);
	virtual void Close();
	virtual bool Reinit();
	virtual int Read(wstring& str);;
	virtual bool GetLine(wstring& line);
	virtual void initEventHandling(ISystemEventHandler* eventHandler);
	virtual ~GConsole();
protected:
	virtual void _write(const wchar_t* text);
	virtual void _refreshLines();
	virtual int _getLineNumber();
	bool _textKeyPressed(const TextKeyEvent& event);
	bool _keyPressed(const KeyEvent& event);
	virtual void TextKeyEntered(wchar_t key);
	virtual void LineEntered(const wstring& text);
};

#endif /* G_CONSOLE_H_ */
