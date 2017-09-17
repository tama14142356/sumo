/****************************************************************************/
/// @file    GNECalibratorLane.h
/// @author  Pablo Alvarez Lopez
/// @date    Sep 2017
/// @version $Id: GNECalibratorLane.h 25918 2017-09-07 19:38:16Z behrisch $
///
//
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
// Copyright (C) 2001-2017 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef GNECalibratorLane_h
#define GNECalibratorLane_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include "GNECalibrator.h"


// ===========================================================================
// class definitions
// ===========================================================================
/**
* @class GNECalibratorLane
* class for represent Calibratos in netedit
*/
class GNECalibratorLane : public GNECalibrator {
public:

    /**@brief Constructor
    * @param[in] id The storage of gl-ids to get the one for this lane representation from
    * @param[in] lane Lane of this calibrator belongs
    * @param[in] viewNet pointer to GNEViewNet of this additional element belongs
    * @param[in] pos position of the calibrator on the edge (Currently not used)
    * @param[in] frequency the aggregation interval in which to calibrate the flows
    * @param[in] output The output file for writing calibrator information
    * @param[in] calibratorRoutes vector with the calibratorRoutes of calibrator
    * @param[in] calibratorFlows vector with the calibratorFlows of calibrator
    * @param[in] calibratorVehicleTypes vector with the CalibratorVehicleType of calibrator
    */
    GNECalibratorLane(const std::string& id, GNELane* lane, GNEViewNet* viewNet, double pos, double frequency, const std::string& output,
        const std::vector<GNECalibratorRoute>& calibratorRoutes, const std::vector<GNECalibratorFlow>& calibratorFlows,
        const std::vector<GNECalibratorVehicleType>& calibratorVehicleTypes);

    /// @brief Destructor
    ~GNECalibratorLane();

    /// @name inherited from GNEAttributeCarrier
    /// @{
    /* @brief method for getting the Attribute of an XML key
    * @param[in] key The attribute key
    * @return string with the value associated to key
    */
    std::string getAttribute(SumoXMLAttr key) const;

    /* @brief method for setting the attribute and letting the object perform additional changes
    * @param[in] key The attribute key
    * @param[in] value The new value
    * @param[in] undoList The undoList on which to register changes
    */
    void setAttribute(SumoXMLAttr key, const std::string& value, GNEUndoList* undoList);

    /* @brief method for checking if the key and their correspond attribute are valids
    * @param[in] key The attribute key
    * @param[in] value The value asociated to key key
    * @return true if the value is valid, false in other case
    */
    bool isValid(SumoXMLAttr key, const std::string& value);
    /// @}

private:
    /// @brief set attribute after validation
    void setAttribute(SumoXMLAttr key, const std::string& value);

    /// @brief Invalidated copy constructor.
    GNECalibratorLane(const GNECalibratorLane&) = delete;

    /// @brief Invalidated assignment operator.
    GNECalibratorLane& operator=(const GNECalibratorLane&) = delete;
};

#endif
/****************************************************************************/
