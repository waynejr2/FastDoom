#ifndef __GUSWAVE_H
#define __GUSWAVE_H

#define GUSWAVE_MinVoiceHandle 1

enum GUSWAVE_Errors
{
    GUSWAVE_Warning = -2,
    GUSWAVE_Error = -1,
    GUSWAVE_Ok = 0,
    GUSWAVE_GUSError,
    GUSWAVE_NotInstalled,
    GUSWAVE_NoVoices,
    GUSWAVE_UltraNoMem,
    GUSWAVE_UltraNoMemMIDI,
    GUSWAVE_VoiceNotFound,
    GUSWAVE_InvalidVOCFile,
    GUSWAVE_InvalidWAVFile
};

int GUSWAVE_VoicePlaying(int handle);
int GUSWAVE_VoicesPlaying(void);
int GUSWAVE_Kill(int handle);
int GUSWAVE_KillAllVoices(void);
void GUSWAVE_SetVolume(int volume);
int GUSWAVE_StartDemandFeedPlayback(void (*function)(char **ptr, unsigned long *length), int bits, int rate, int angle);
void GUSWAVE_SetReverseStereo(int setting);
int GUSWAVE_Init(int numvoices);
void GUSWAVE_Shutdown(void);
#pragma aux GUSWAVE_Shutdown frame;

#endif
