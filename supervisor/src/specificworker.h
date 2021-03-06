/*
 *    Copyright (C) 2017 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
       \brief
       @author authorname
*/


#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
#include <innermodel/innermodel.h>
#include <mutex>          // std::mutex
#include "Chocachoca.h"
#include <stdlib.h>
#include <ctime>

using namespace std;
enum states {SEARCH, WAIT, SENDGOTO, SENDPICKBOX, SENDRELEASEBOX};

const int MAXBOXES=10;
const int MAXDUMPS=4;
const int MAXDIST=300;
const float MAXSEARCHBOX=999999.0;

class SpecificWorker : public GenericWorker
{
    Q_OBJECT
public:
    SpecificWorker(MapPrx& mprx);
    ~SpecificWorker();
    bool setParams(RoboCompCommonBehavior::ParameterList params);

    void search();
    void sendGoto();
    void wait();
    void sendPickBox();
    void sendReleaseBox();

public slots:
    void compute();

private:
    InnerModel *innermodel;

    std::mutex mtx;

    clock_t begin_time;

    states state;

    //TAGS
    void newAprilTag(const RoboCompGetAprilTags::listaMarcas &tags);
    int dump;
    std::pair<int,int> coorsDump;
    void searchDump(const RoboCompGetAprilTags::listaMarcas &tags);

    //BOX
    int movedBoxes[MAXBOXES];
    float coorsBox[3];
    void searchBoxes(const RoboCompGetAprilTags::listaMarcas &tags);
    bool boxIsMoved(int id);
    void addToMovedBoxes(int id);

    //FLAG
    int waitingFor; /* 1 - waiting for arrive to box. 2 - waiting for picking box. 3 - waiting for arrive to dump. 4 - waiting for releasing box. */
};

#endif
