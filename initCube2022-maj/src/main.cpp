#include <cstdlib>
#include <ctime>
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
    pugi::xml_document doc;
    if(doc.load_file("testxml.xml")){
        string res = "on";
        pugi::xpath_node Secu=doc.select_node("//SegmentVol/Securite");  
        string secuRead=Secu.node().attribute("particules_energie").value();
        if(secuRead==res){
            DetecteurParticules* test = new DetecteurParticules();
            test->start();
            sleep(100);
        }
    }
    return 0;
}