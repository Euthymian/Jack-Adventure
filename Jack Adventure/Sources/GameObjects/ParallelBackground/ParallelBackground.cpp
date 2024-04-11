#include "ParallelBackground.h"

void ParallelBackground::pbInit()
{
	Layer* layer;
	std::string path = "Background/";

	// Layer 1
	layer = new Layer();
	layer->layerInit(path + "Layer_0011_0", -30);
	m_Background.push_back(layer);

	// Layer 2
	layer = new Layer();
	layer->layerInit(path + "Layer_0010_1", -45);
	m_Background.push_back(layer);

	// Layer 3
	layer = new Layer();
	layer->layerInit(path + "Layer_0009_2", -60);
	m_Background.push_back(layer);

	// Layer 4
	layer = new Layer();
	layer->layerInit(path + "Layer_0008_3", -75);
	m_Background.push_back(layer);

	// Layer 5
	layer = new Layer();
	layer->layerInit(path + "Layer_0007_Lights", -90);
	m_Background.push_back(layer);

	// Layer 6
	layer = new Layer();
	layer->layerInit(path + "Layer_0006_4", -105);
	m_Background.push_back(layer);

	// Layer 7
	layer = new Layer();
	layer->layerInit(path + "Layer_0005_5", -120);
	m_Background.push_back(layer);

	// Layer 8
	layer = new Layer();
	layer->layerInit(path + "Layer_0004_Lights", -135);
	m_Background.push_back(layer);

	// Layer 9
	layer = new Layer();
	layer->layerInit(path + "Layer_0003_6", -150);
	m_Background.push_back(layer);

	// Layer 10
	layer = new Layer();
	layer->layerInit(path + "Layer_0002_7", -165);
	m_Background.push_back(layer);

	// Layer 11
	layer = new Layer();
	layer->layerInit(path + "Layer_0001_8", -180);
	m_Background.push_back(layer);

	// Layer 12
	layer = new Layer();
	layer->layerInit(path + "Layer_0000_9", -195);
	m_Background.push_back(layer);
}

void ParallelBackground::pbUpdate(float deltaTime)
{
	for (Layer* each : m_Background) {
		each->layerUpdate(deltaTime);
	}
}

void ParallelBackground::pbRender(sf::RenderWindow* window)
{
	for (Layer* each : m_Background) {
		each->layerRender(window);
	}
}
