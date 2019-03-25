#ifndef __27782DC35A43B672D34639__TEXT__HPP__
#define __27782DC35A43B672D34639__TEXT__HPP__

#include <Ito.h>
#include <string.h>

class CText
{
public:
	static const u8 LARGE_FONT=1;
	static const u8 SMALL_FONT=2;

	static const u8 ALIGN_CENTER=10;
	static const u8 ALIGN_LEFT=11;
	static const u8 ALIGN_RIGHT=12;

	CText(void);
	~CText(void);

	void PrintText(const char* text, u16 x, u16 y, u32 color, Ito::GifPipe *gif, u8 font=LARGE_FONT, u8 align=ALIGN_LEFT);
	void PrintChar(const char ch, u16 x, u16 y, u32 color, Ito::GifPipe *gif, u8 font=LARGE_FONT);
};

#endif // __27782DC35A43B672D34639__TEXT__HPP__
