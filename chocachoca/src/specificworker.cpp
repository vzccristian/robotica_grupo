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
#include "specificworker.h"

/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(MapPrx& mprx) : GenericWorker(mprx)
{
  estado = IDLE;
}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{
	
}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{


	innermodel = new InnerModel("/home/robocomp/robocomp/files/innermodel/simpleworld.xml");

	timer.start(Period);
	return true;
}

void SpecificWorker::compute()
{
    //TOMAR DATOS DEL MUNDO (MUAHAHA)
    RoboCompDifferentialRobot::TBaseState bState;
    differentialrobot_proxy->getBaseState(bState);
    
    //ACTUALIZAR ARBOL
    innermodel->updateTransformValues("base", bState.x,0, bState.z,0,bState.alpha, 0 ); 
    
    //Tomar los datos del laser
    TLaserData data = laser_proxy->getLaserData(); 
    //Ordenamos el array de menor a mayor
    std::sort( data.begin()+25, data.end()-25, [](RoboCompLaser::TData a, RoboCompLaser::TData b){ return     a.dist < b.dist; }) ; 
    
    switch (estado)  
      {  
         case 'IDLE': 
	    idle();
            break; 
         case 'GOTO':  
	        if(!target.isEmpty()) { //EXISTE OBJETIVO
        if(!target.enObjetivo(bState.x,bState.z)){ //NO HEMOS LLEGADO AL OBJETIVO
	  //VARIABLES 
	  float dist,linealSpeed,rot,angleSpeed;
	  std::pair <std::pair <float,float>,std::pair <float,float>> coord = target.extract(); //Tomamos las coord del pick (target y robot)
	  QVec T = innermodel->transform("base",QVec::vec3(coord.first.first,0,coord.first.second),"world"); //Desplaza el eje de coord del mundo al robot
	  dist = T.norm2(); //Calculamos la distancia entre los puntos
	  rot=atan2(T.x(),T.z()); //Calculamos la rotacion con el arcotangente

	  //Calcular velocidad
	  linealSpeed = V_MAX * gauss(rot,0.3, 0.5) * sinusoide(dist); //CUANTA MENOS DISTANCIA MAS RECTA ES LA LINEA

	  if (rot>0.6)
            angleSpeed=0.6;
          else
	    angleSpeed=0.2;
	    
	  differentialrobot_proxy->setSpeedBase(linealSpeed, angleSpeed); //Movimiento
	} else{ //Objetivo
	    target.setEmpty(); 
            differentialrobot_proxy->setSpeedBase(0, 0); //Parar 
        } // FIN enObjetivo
    } // FIN isEmpty
            break;  
         default:  
	   
	   break;
      }  
    
    
    
    if(!target.isEmpty()) { //EXISTE OBJETIVO
        if(!target.enObjetivo(bState.x,bState.z)){ //NO HEMOS LLEGADO AL OBJETIVO
	  //VARIABLES 
	  float dist,linealSpeed,rot,angleSpeed;
	  std::pair <std::pair <float,float>,std::pair <float,float>> coord = target.extract(); //Tomamos las coord del pick (target y robot)
	  QVec T = innermodel->transform("base",QVec::vec3(coord.first.first,0,coord.first.second),"world"); //Desplaza el eje de coord del mundo al robot
	  dist = T.norm2(); //Calculamos la distancia entre los puntos
	  rot=atan2(T.x(),T.z()); //Calculamos la rotacion con el arcotangente

	  //Calcular velocidad
	  linealSpeed = V_MAX * gauss(rot,0.3, 0.5) * sinusoide(dist); //CUANTA MENOS DISTANCIA MAS RECTA ES LA LINEA

	  if (rot>0.6)
            angleSpeed=0.6;
          else
	    angleSpeed=0.2;
	    
	  differentialrobot_proxy->setSpeedBase(linealSpeed, angleSpeed); //Movimiento
	} else{ //Objetivo
	    target.setEmpty(); 
            differentialrobot_proxy->setSpeedBase(0, 0); //Parar 
        } // FIN enObjetivo
    } // FIN isEmpty
}

// --------- MAQUINA DE ESTADOS --------------
// IDLE
 void SpecificWorker::idle(){
   qDebug() << "Estado IDLE";
   if(!target.isEmpty())
     estado=GOTO;
 }
// ----------------------


// GAUSSIANA
// VROT = VELOCIDAD ROTACION
// VX = ANGULO DE ROTACION
// H = PARAMETRO DE CORTE EN FUNCION GAUSSIANA
 float SpecificWorker::gauss(float Vrot,float Vx, float h){
   float lambda = -(pow(Vx,2.0)/log(h));
   return exp(-(pow(Vrot,2.0)/lambda));
 }
 
 
// SINUSOIDE
 float SpecificWorker::sinusoide(float x){
    return (1/(1+exp(-x-0.5)));
 }
 
void SpecificWorker::setPick(const Pick &myPick)
{
  qDebug() << myPick.x << myPick.z ;
  
  //TOMAR DATOS DEL MUNDO (MUAHAHA)
  RoboCompDifferentialRobot::TBaseState bState;
  differentialrobot_proxy->getBaseState(bState);
  target.insert(myPick.x,myPick.z,bState.x,bState.z); 

}

//   float distumbral = 300;
//   float angleumbral = 0.79;
//   float rotacion=0.6;
//   bool valido=false;
//   
//   //Tomar los datos del laser
//   TLaserData data = laser_proxy->getLaserData(); 
//   //Ordenamos el array de menor a mayor
//   std::sort( data.begin()+25, data.end()-25, [](RoboCompLaser::TData a, RoboCompLaser::TData b){ return     a.dist < b.dist; }) ; 
//   
//   for(auto h: data)
//     qDebug() << h.angle << h.dist;
//   
//     if (data[25].dist < distumbral) {
//       qDebug()<< "Valido: "<<data[25].dist<<data[25].angle;
//       if ( (rand()%(10)) % 2 != 0)
//         rotacion=rotacion*(-1);
//         differentialrobot_proxy->setSpeedBase(5, rotacion);
//       usleep(rand()%(1500000-100000 + 1) + 100000);
//     } else  {
//     differentialrobot_proxy->setSpeedBase(1500, 0);
//  }
