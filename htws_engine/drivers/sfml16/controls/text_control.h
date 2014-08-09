#ifndef TEXT_CONTROL_H_
#define TEXT_CONTROL_H_

#include <SFML/Graphics/String.hpp>
#include <string>

#include "../../../basics/templates/math_classes.hpp"
#include "../../../basics/templates/scontainer.hpp"

class Color;
class ICanvas;
class IFont;

class TextControl: public SContainer<IDrawable2D>
{
protected:
	sf::String textSprite;
	const sf::Font* _font;
	unsigned int wrap;
	void Wrap();
public:
	TextControl();
	void SetText(const string& text);
	void SetText(const char* text);
	void SetText(const wstring& text);
	void SetText(const wchar_t* text);
	const wstring GetText() const;
	void SetFont(const IFont* font);
	void SetFontSize(unsigned int size);
	void SetColor(const Color& color);
	void SetWordWrap(unsigned wrap) { this->wrap = wrap; }
	int GetLineCountIfWrapped(wstring& line);
	virtual bool CanHaveChildren() { return false; }
	virtual void Render(ICanvas * canvas);
	virtual NumVector<int> GetPosition();
	virtual NumVector<int> GetSize();
	virtual ~TextControl();
};

#endif /* TEXT_CONTROL_H_ */
