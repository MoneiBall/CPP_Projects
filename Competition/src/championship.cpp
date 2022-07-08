#include "championship.h"
using namespace std;

void ChampEnor::next()
{
    string line;
    getline(_f , line);
    if( !(_end = _f.fail()) ){
        istringstream is(line);
        is >> _cur.angler >> _cur.championship;
        string fish;
        int size;
        _cur.exist = false;

        while(!is.fail() && !_cur.exist && is>>fish>>size) {
            _cur.exist = (fish == "tuna");
        }
    }
}
