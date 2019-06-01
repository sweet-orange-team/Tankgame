#include"Console.h"
#include"Control.h"
#include"Map.h"
#include"Tank.h"
int main() {
	Control control;
    control.animation();
    //if (control.menu() == -1)return 0;
    //else if (control.menu() == 2)control.instruction();
    if (control.init() == 0)return 0;
    else control.start();
	return 0;
}
