#ifndef SNDHELP_H
#define SNDHELP_H

#include <AL/al.h>

#ifdef __cplusplus
extern "C" {
#endif

const char *FormatName(ALenum type);

int InitAL(char ***argv, int *argc);
void CloseAL(void);

int altime_get(void);
void al_nssleep(unsigned long nsec);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // SNDHELP_H
