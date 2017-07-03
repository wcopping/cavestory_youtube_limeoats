# cavestory_youtube_limeoats
Following LimeOats' YouTube guide on recreating cavestory using C++
currently on hiatus to learn more about working with ubuntu and gcc, libpng, sdl2_image, etc.
Current problem is SDL_QueryTexture pulls 0 for tilesetWidth and tilesetHeight in level.cpp for
constructing the map from the tileset png included in /content/tilesets. I believe the proper tileset is loaded
into the texture but there is a problem with SDL2_Image being built with libpngxx but running with
libpngyy I THINK.
