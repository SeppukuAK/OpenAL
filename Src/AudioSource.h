#ifndef __AudioSource_h_
#define __AudioSource_h_

#include "al.h"

class AudioSource
{
public:
	AudioSource();
	~AudioSource();

	void SetAudioClip(ALint buffer);

	//M�todos que modifican los atributos del Source
	void SetSourcePos(ALfloat * sourcePos);
	void SetSourceVel(ALfloat * sourceVel);
	void SetSourcePitch(ALfloat  sourcePitch);
	void SetSourceGain(ALfloat  sourceGain);
	void SetSourceLoop(bool loop);

	//M�todos para la reproducci�n del audio
	void Play();
	void Stop();
	void Pause();

private:
	ALuint source;
};
#endif // #ifndef __AudioSource_h_

