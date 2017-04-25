#include "MatrixHierarchyDemo_3DSpherePlatformerApp.h"

int main() {
	
	auto app = new MatrixHierarchyDemo_3DSpherePlatformerApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}