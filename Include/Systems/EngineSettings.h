#pragma once

#define SFML 
// Swap SFML for SDL if you wish to use the SDL Library
#define _SFML 

#ifdef _SFML


#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-s-d.lib") 
#pragma comment(lib,"sfml-audio-s-d.lib") 
#pragma comment(lib,"sfml-system-s-d.lib") 
#pragma comment(lib,"sfml-window-s-d.lib") 
#pragma comment(lib,"sfml-network-s-d.lib") 
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")

#else 
#pragma comment(lib,"sfml-graphics-s.lib") 
#pragma comment(lib,"sfml-audio-s.lib") 
#pragma comment(lib,"sfml-system-s.lib") 
#pragma comment(lib,"sfml-window-s.lib") 
#pragma comment(lib,"sfml-network-s.lib") 
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")
#endif 

#endif // SFML