#ifndef __E1D0643E8B69E76F6966B__AUDIO__HPP__
#define __E1D0643E8B69E76F6966B__AUDIO__HPP__

#include <stdio.h>
#include <string.h>
#include <kernel.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <tamtypes.h>
#include <audsrv.h>

class CAudio
{
private:
public:
	void Play(const char *filename);
	CAudio(void);
	~CAudio(void);
};

#endif // __E1D0643E8B69E76F6966B__AUDIO__HPP__
