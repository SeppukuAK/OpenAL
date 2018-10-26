#ifndef __AudioSource_h_
#define __AudioSource_h_

#include "al.h"

class AudioSource
{
public:
	AudioSource();
	~AudioSource();

	void SetAudioClip(ALint buffer);

	//Métodos que modifican los atributos del Source
	void SetSourcePos(ALfloat * sourcePos);
	void SetSourceVel(ALfloat * sourceVel);
	void SetSourcePitch(ALfloat  sourcePitch);
	void SetSourceGain(ALfloat  sourceGain);
	void SetSourceLoop(bool loop);

	//Métodos para la reproducción del audio
	void Play();
	void Stop();
	void Pause();

private:
	ALuint source;
};
#endif // #ifndef __AudioSource_h_

