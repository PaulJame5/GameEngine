#include "../../Include/Systems/RenderingSystem.h"
#include <mutex>
std::mutex mu;
RenderingSystem::RenderingSystem()
{
}

RenderingSystem::~RenderingSystem()
{
}

void RenderingSystem::update(sf::RenderWindow& rend)
{

//#if _DEBUG
	TestBeginTime();
//#endif
	sf::RenderWindow* win = &rend;
	drawSprites(win);
//#if _DEBUG
	TestEndTime();
//#endif

}

//#if _DEBUG
inline void RenderingSystem::TestBeginTime()
{

	now = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
		);
}


inline void RenderingSystem::TestEndTime()
{

	std::chrono::milliseconds after = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch());

	std::chrono::milliseconds diff = after - now;
	std::cout << "Rendering all components took: " << " " << diff.count() << "ns" << std::endl;
}

void RenderingSystem::drawSprites(sf::RenderWindow* rend)
{

	std::map<int, std::vector<SpriteComponent> >::iterator it = SpriteSystem::getEntities().begin();

	sf::VertexArray circleArray;
	for (; it != SpriteSystem::getEntities().end(); ++it)
	{
		int numberOfComponents = it->second.size();

		for (int i = 0; i < numberOfComponents; i++)
		{
			rend->draw(it->second.at(i));
		}

	}
}
//#endif


