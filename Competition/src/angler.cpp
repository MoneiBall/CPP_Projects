#include "angler.h"

void AnglerEnor::next()
{
    if( !(_end = _tt.end()) ){
        _cur.name = _tt.current().angler; //idendity comparison
        _cur.contest_cnt = 0;

        for( ; !_tt.end() && _tt.current().angler == _cur.name; _tt.next() ){
            if(_tt.current().exist) {
                _cur.contest_cnt ++;
            }
        }

    }
}
