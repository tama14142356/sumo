#!/usr/bin/env python
# Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
# Copyright (C) 2009-2018 German Aerospace Center (DLR) and others.
# This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v2.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/epl-v20.html
# SPDX-License-Identifier: EPL-2.0

# @file    test.py
# @author  Pablo Alvarez Lopez
# @date    2016-11-25
# @version $Id$

# import common functions for netedit tests
import os
import sys

testRoot = os.path.join(os.environ.get('SUMO_HOME', '.'), 'tests')
neteditTestRoot = os.path.join(
    os.environ.get('TEXTTEST_HOME', testRoot), 'netedit')
sys.path.append(neteditTestRoot)
import neteditTestFunctions as netedit  # noqa

# Open netedit
neteditProcess, match = netedit.setupAndStart(neteditTestRoot, ['--gui-testing-debug-gl'])

# go to select mode
netedit.selectMode()

# select first POILane
netedit.leftClick(match, 140, 215)

# select second POILane
netedit.leftClick(match, 200, 215)

# go to inspect mode
netedit.inspectMode()

# inspect first POILane
netedit.leftClick(match, 140, 215)

# Change parameter 4 with a non valid value (dummy)
netedit.modifyAttribute(2, "dummyColor")

# Change parameter 4 with a non valid value (invalid format)
netedit.modifyAttribute(2, "255,255,500")

# Change parameter 4 with a valid value (valid format)
netedit.modifyAttribute(2, "blue")

# Change parameter 4 with a valid value (valid format)
netedit.modifyAttribute(2, "125,60,200")

# Check undos and redos
netedit.undo(match, 3)
netedit.redo(match, 3)

# save shapes
netedit.saveShapes()

# save network
netedit.saveNetwork()

# quit netedit
netedit.quit(neteditProcess)
