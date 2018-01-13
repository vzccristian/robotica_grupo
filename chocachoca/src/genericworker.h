/*
 *    Copyright (C) 2018 by YOUR NAME HERE
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
#ifndef GENERICWORKER_H
#define GENERICWORKER_H

#include "config.h"
#include <QtGui>
#include <stdint.h>
#include <qlog/qlog.h>

#include <ui_mainUI.h>

#include <CommonBehavior.h>
#include <DifferentialRobot.h>
#include <GetAprilTags.h>
#include <InnerModelManager.h>
#include <Chocachoca.h>
#include <JointMotor.h>
#include <Laser.h>
#include <RCISMousePicker.h>

#include <IceStorm/IceStorm.h>


#define CHECK_PERIOD 5000
#define BASIC_PERIOD 100

typedef map <string,::IceProxy::Ice::Object*> MapPrx;

using namespace std;

using namespace RoboCompDifferentialRobot;
using namespace RoboCompGetAprilTags;
using namespace RoboCompInnerModelManager;
using namespace RoboCompChocachoca;
using namespace RoboCompJointMotor;
using namespace RoboCompLaser;
using namespace RoboCompRCISMousePicker;




class GenericWorker : 
#ifdef USE_QTGUI
public QWidget, public Ui_guiDlg
#else
public QObject
#endif
{
Q_OBJECT
public:
	GenericWorker(MapPrx& mprx);
	virtual ~GenericWorker();
	virtual void killYourSelf();
	virtual void setPeriod(int p);
	
	virtual bool setParams(RoboCompCommonBehavior::ParameterList params) = 0;
	QMutex *mutex;
	

	InnerModelManagerPrx innermodelmanager_proxy;
	GetAprilTagsPrx getapriltags_proxy;
	LaserPrx laser_proxy;
	JointMotorPrx jointmotor_proxy;
	DifferentialRobotPrx differentialrobot_proxy;
	IceStorm::TopicManagerPrx topicmanager_proxy;

	virtual bool pickingBox() = 0;
	virtual string getState() = 0;
	virtual void stop() = 0;
	virtual void turn(const float speed) = 0;
	virtual void go(const float x, const float z) = 0;
	virtual bool releasingBox() = 0;
	virtual void setPick(const Pick &myPick) = 0;


protected:
	QTimer timer;
	int Period;


public slots:
	virtual void compute() = 0;


signals:
	void kill();
};

#endif
