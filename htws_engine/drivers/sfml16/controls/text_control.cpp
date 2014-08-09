#include "../../drivers_all.h"

TextControl::TextControl() :
		wrap(0)
{
	_font = &sf::Font::GetDefaultFont();
	textSprite.SetFont(*_font);
}

TextControl::~TextControl()
{
}

void TextControl::SetText(const string& text)
{
	textSprite.SetText(text);
	if (wrap)
	{
		Wrap();
	}
}

void TextControl::SetText(const char* text)
{
	textSprite.SetText(text);
	if (wrap)
	{
		Wrap();
	}
}

void TextControl::SetText(const wstring& text)
{
	textSprite.SetText(text);
	if (wrap)
	{
		Wrap();
	}
}

void TextControl::SetText(const wchar_t* text)
{
	textSprite.SetText(text);
	if (wrap)
	{
		Wrap();
	}
}

const wstring TextControl::GetText() const
{
	return textSprite.GetText();
}

void TextControl::SetFont(const IFont* font)
{
	//TODO set font
	//textSprite.SetFont()
}

void TextControl::SetFontSize(unsigned int size)
{
	textSprite.SetSize(size);
}

void TextControl::SetColor(const Color& color)
{
	textSprite.SetColor(SfmlConverter::GetSFColor(color));
}

void TextControl::Render(ICanvas* canvas)
{
	((sf::RenderTarget*) canvas->GetDriverSpecificRenderTarget())->Draw(
			textSprite);
}

NumVector<int> TextControl::GetPosition()
{
	return NumVector<int>(textSprite.GetPosition().x,
			textSprite.GetPosition().y);
}

NumVector<int> TextControl::GetSize()
{
	return NumVector<int>(textSprite.GetRect().GetWidth(),
			textSprite.GetRect().GetHeight());
}

int TextControl::GetLineCountIfWrapped(wstring& line)
{
	unsigned currentOffset = 0;
	int ret = 1;
	bool firstWord = true;
	std::size_t wordBegining = 0;
	wstring unwrappedstring = line;
	for (std::size_t pos(0); pos < unwrappedstring.size(); ++pos)
	{
		int currentChar = unwrappedstring[pos];
		if (currentChar == '\n')
		{
			currentOffset = 0;
			firstWord = true;
			if (pos != unwrappedstring.size() - 1)
			{
				++ret;
			}
			continue;
		}
		else if (currentChar == ' ')
		{
			wordBegining = pos;
			firstWord = false;
		}

		currentOffset += ceil(
				(_font->GetGlyph(currentChar).Advance * textSprite.GetSize())
						/ _font->GetCharacterSize());

		if (!firstWord && currentOffset > wrap)
		{
			pos = wordBegining;
			++ret;
			firstWord = true;
			currentOffset = 0;
		}
	}
	return ret;
}

void TextControl::Wrap()
{
	unsigned currentOffset = 0;
	bool firstWord = true;
	std::size_t wordBegining = 0;
	wstring unwrappedstring = this->textSprite.GetText();
	for (std::size_t pos(0); pos < unwrappedstring.size(); ++pos)
	{
		int currentChar = unwrappedstring[pos];
		if (currentChar == '\n')
		{
			currentOffset = 0;
			firstWord = true;
			continue;
		}
		else if (currentChar == ' ')
		{
			wordBegining = pos;
			firstWord = false;
		}

		currentOffset += ceil(
				(_font->GetGlyph(currentChar).Advance * textSprite.GetSize())
						/ _font->GetCharacterSize());

		if (!firstWord && currentOffset > wrap)
		{
			pos = wordBegining;
			unwrappedstring[pos] = L'\n';
			firstWord = true;
			currentOffset = 0;
		}
	}
	textSprite.SetText(unwrappedstring);
}
