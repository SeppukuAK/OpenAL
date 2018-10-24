#include <stdlib.h>
#include <al.h>
#include <alut.h>
#include <alc.h>

int main() {
	// inicializamos
	alutInit(0, NULL);
	alGetError(); //limpiamos el bit de error
				  // creamos buffer
	//ALuint Buffer = alutCreateBufferFromFile("../wavdata/holaMundo.wav");
	ALuint Buffer = alutCreateBufferFromFile("../../Media/batalla/Battle.wav");

	if (alGetError() != AL_NO_ERROR) exit(-1);
	// creamos source
	ALuint Source;
	alGenSources(1, &Source);
	// enganchamos source al buffer
	alSourcei(Source, AL_BUFFER, Buffer);
	// reproducimos
	alSourcePlay(Source);
	// pausa para escuchar, liberacion de recursos y salida
	alutSleep(3);
	alutExit();
	return EXIT_SUCCESS;
}