#include "AudioSource.h"
#include "AudioManager.h"


AudioSource::AudioSource()
{
	//Creación source
	alGenSources(1, &source);	//Número de sources, puntero a ellas
}


AudioSource::~AudioSource()
{
	alDeleteSources(1, &source);
}

void AudioSource::SetAudioClip(ALint buffer)
{
	//Enganchar buffer a source
	alSourcei(source, AL_BUFFER, buffer);
}

void AudioSource::SetSourcePos(ALfloat * sourcePos) {
	alSourcefv(source, AL_POSITION, sourcePos);
}

void AudioSource::SetSourceVel(ALfloat * sourceVel) {
	alSourcefv(source, AL_VELOCITY, sourceVel);
}

void AudioSource::SetSourcePitch(ALfloat sourcePitch) {
	alSourcef(source, AL_PITCH, sourcePitch); // frec de reproduccion
}

void AudioSource::SetSourceGain(ALfloat sourceGain) {
	alSourcef(source, AL_GAIN, sourceGain); // ganancia de la fuente
}

void AudioSource::SetSourceLoop(bool loop) {
	alSourcei(source, AL_LOOPING, loop); // para repr. ciclica
}

void AudioSource::Play() {
	alSourcePlay(source);
}

void AudioSource::Stop() {
	alSourceStop(source);
}

void AudioSource::Pause() {
	alSourcePause(source);
}
