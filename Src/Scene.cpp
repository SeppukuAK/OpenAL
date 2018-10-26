#include "Scene.h"
#include "AudioManager.h"
#include "AudioSource.h"
#include <vector>
#include <conio.h>

Scene::Scene() {
	Init();
	Loop();
}

Scene::~Scene()
{

}
