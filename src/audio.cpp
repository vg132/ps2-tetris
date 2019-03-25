#include "audio.hpp"

CAudio::CAudio(void)
{
}

CAudio::~CAudio(void)
{
}

void CAudio::Play(const char *filename)
{
	u16 played, ret;
	char chunk[2048];
	FILE *wav;

	audsrv_init();

	struct audsrv_fmt_t format;
	format.bits=16;
	format.freq=22050;
	format.channels=2;
	audsrv_set_format(&format);
	audsrv_set_volume(MAX_VOLUME);

	wav=fopen(filename, "rb");
	if(wav==NULL)
	{
		printf("failed to open wav file\n");
		return;
	}
	fseek(wav, 0x30, SEEK_SET);
	played=0;
	while(1)
	{
		ret=fread(chunk,1,sizeof(chunk),wav);
		if(ret>0)
		{
			audsrv_wait_audio(ret);
			audsrv_play_audio(chunk, ret);
		}
		if(ret<sizeof(chunk))
		{
			break;
		}
		played++;
		if(played % 8==0)
		{
			printf(".");
		}
		if(played==512)
			break;
	}
	fclose(wav);
	audsrv_quit();
	printf("sample: ended\n");
}
