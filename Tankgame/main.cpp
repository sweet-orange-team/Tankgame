#include"Console.h"
#include"Control.h"
#include"Map.h"
#include"Tank.h"
int main() {
	Control control;
    if (control.menu() == -1)return 0;
    else control.start();
	return 0;
}
