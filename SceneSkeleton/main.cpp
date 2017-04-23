#include "SceneSkeletonApp.h"
#include "Settings.h"

int main() {
	
	auto app = new SceneSkeletonApp();
	app->run("AIE", SCREENWIDTH, SCREENHEIGHT, false);
	delete app;

	return 0;
}