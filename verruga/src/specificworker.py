#
# Copyright (C) 2017 by YOUR NAME HERE
#
#    This file is part of RoboComp
#
#    RoboComp is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    RoboComp is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
#


#

import sys
import os
import traceback
import time

from PySide import QtGui, QtCore
from genericworker import *

# If RoboComp was compiled with Python bindings you can use InnerModel in Python
# sys.path.append('/opt/robocomp/lib')
# import librobocomp_qmat
# import librobocomp_osgviewer
# import librobocomp_innermodel


class SpecificWorker(GenericWorker):
	def __init__(self, proxy_map):
		super(SpecificWorker, self).__init__(proxy_map)
		self.timer.timeout.connect(self.compute)
		self.Period = 300
		self.timer.start(self.Period)

	def setParams(self, params):
		# try:
		#	self.innermodel = InnerModel(params["InnerModelPath"])
		# except:
		#	traceback.print_exc()
		#	print "Error reading config params"
		self.listState = ["PICK", "RELEASE"]
		self.state = self.listState[0]
		self.listaBoxes = ["C10", "C11", "C12"]
		self.currentBox = None
		return True

	@QtCore.Slot()
	def compute(self):
		print "State:",self.state
		# State machine
		if (self.state.find(self.listState[0]) > -1):
			self.detectPick()
		elif (self.state.find(self.listState[1]) > -1):
			self.detectRelease()
		return True

	def detectPick(self):
		for box in self.listaBoxes:
			for car in range(1, 6):
				boxname = box + "_" + str(car)
				try:
					if self.innermodelmanager_proxy.collide("finger_right_2_mesh3", boxname):
						self.innermodelmanager_proxy.moveNode(box, "cameraHand")  # IF MOVING TO A MESH PETA
						pose = Pose3D()
						pose.x=0
						pose.y=-50
						pose.z=50
						pose.rx=0
						pose.ry=0
						pose.rz=0
						self.innermodelmanager_proxy.setPoseFromParent(box, pose)
						print "Detecting collision finger_right_2_mesh3 with ",boxname, "and sending to -> cameraHand"
						time.sleep(5)
						self.state = self.listState[1]
						self.currentBox = box
				except Ice.Exception, e:
					traceback.print_exc()
					print e
					sys.exit()
		if (self.state.find(self.listState[0]) > -1):
			self.currentBox = None

	def detectRelease(self):
		for car in range(1, 6):
			boxname = self.currentBox + "_" + str(car)
			print "Compruebo caja:",self.currentBox
			try:
				if self.innermodelmanager_proxy.collide(boxname, "ddG"):
					self.initial_pose = None
					if (self.innermodelmanager_proxy.getPoseFromParent(self.currentBox,self.initial_pose)):
						print self.initial_pose
					self.innermodelmanager_proxy.moveNode(self.currentBox, "world")  # IF MOVING TO A MESH PETA
					pose = Pose3D()
					pose.x=0
					pose.y=5
					pose.z=0
					pose.rx=0
					pose.ry=0
					pose.rz=0
					self.innermodelmanager_proxy.setPoseFromParent(self.currentBox, pose)
					print "SETPOSE FUNCIONA SOCIO"
					time.sleep(5)
					self.state = self.listState[0]
			except Ice.Exception, e:
				traceback.print_exc()
				print e
				sys.exit()

# The API of python-innermodel is not exactly the same as the C++ version
# self.innermodel.updateTransformValues("head_rot_tilt_pose", 0, 0, 0, 1.3, 0, 0)
# z = librobocomp_qmat.QVec(3,0)
# r = self.innermodel.transform("rgbd", z, "laser")
# r.printvector("d")
# print r[0], r[1], r[2]