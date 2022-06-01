#include <cstdlib>
#include "../defs/SegmentVol.h"
#include "../defs/SegmentSol.h"
#include <thread>
#include "../defs/Reboot.h"
#include "../defs/DetecteurParticules.h"
#include "../defs/PowerControler.h"
#include "../defs/pugixml.hpp"
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    list<string> appareils;
    SegmentVol* segmentVol = new SegmentVol();
    segmentVol->setIdentifiant(1);
    SegmentSol* monSeg = new SegmentSol(segmentVol);
    segmentVol->setSegmentSol(monSeg);
    thread t1 = monSeg->tActiverReception();
    pugi::xml_document doc;
    if (doc.load_file("../config/sample.xml")) {
        string res = "on";
        pugi::xpath_node Secu = doc.select_node("//SegmentVol/Securite");
        string secuRead = Secu.node().attribute("particules_energie").value();
        if (secuRead == res) {
            DetecteurParticules* detecteur = new DetecteurParticules(segmentVol);
            detecteur->start();
        }

        thread t2 = monSeg->tTraiter_cmd_queue();
        segmentVol->configurerRecupEtat(3, appareils);
        thread t3 = segmentVol->recupEtat();
        segmentVol->tlancement().join();
        t1.join();
        t2.join();
        t3.join();
        return 0;
    }
