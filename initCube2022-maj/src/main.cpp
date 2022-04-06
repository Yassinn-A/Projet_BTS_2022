#include <cstdlib>
#include <ctime>
#include "../defs/SegmentVol.h"
#include "../defs/SegmentSol.h"
#include <thread>
#include "../defs/Reboot.h"
#include "../defs/DetecteurParticules.h"
#include "../defs/PowerControler.h"

using namespace std;

int main(int argc, char** argv) {
    DetecteurParticules* test = new DetecteurParticules();
    test->triggered(24);
}