#include "modules.hpp"

CModules::CModules(void)
{

}

CModules::~CModules(void)
{
}

bool CModules::Init()
{
	u8 ret;
	SifInitRpc(0);

	printf("sample: kicking IRXs\n");
	ret=SifLoadModule("rom0:LIBSD", 0, NULL);
	printf("libsd loadmodule %d\n", ret);

	printf("sample: loading audsrv\n");
	ret=SifLoadModule("host:audsrv.irx", 0, NULL);
	printf("audsrv loadmodule %d\n", ret);
/*
	ret=audsrv_init();
	if(ret!=0)
	{
		printf("sample: failed to initialize audsrv\n");
		printf("audsrv returned error string: %s\n", audsrv_get_error_string());
		return(false);
	}*/
	return(true);
}
