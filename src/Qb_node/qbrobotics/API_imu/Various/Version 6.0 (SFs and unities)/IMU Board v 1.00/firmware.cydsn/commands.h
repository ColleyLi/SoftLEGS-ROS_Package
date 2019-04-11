// Copyright (c) 2012, qbrobotics.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// - Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
// - Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

/**
 *  \file       commands.h
 *
 *  \brief      Definitions for QB Move commands, parameters and packages.
 *
 *  \details
 *  This file is included in the QB Move firmware, in its libraries and
 *  applications. It contains all definitions that are necessary for the
 *  contruction of communication packages.
 *
 *  It includes definitions for all of the device commands, parameters and also
 *  the size of answer packages.
 *
**/

#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED


//==============================================================================
//                                                                      COMMANDS
//==============================================================================


/** \name QB Move Commands
 * \{
**/

enum qbmove_command
{

//=========================================================     general commands

    CMD_PING                    = 0,    ///< Asks for a ping message
    CMD_SET_ZEROS               = 1,    ///< Command for setting the encoders zero position
    CMD_STORE_PARAMS            = 3,    ///< Stores all parameters in memory and
                                        ///  loads them
    CMD_STORE_DEFAULT_PARAMS    = 4,    ///< Store current parameters as factory parameters
    CMD_RESTORE_PARAMS          = 5,    ///< Restore default factory parameters
    CMD_GET_INFO                = 6,    ///< Asks for a string of information about

    CMD_SET_VALUE               = 7,    ///< Not Used
    CMD_GET_VALUE               = 8,    ///< Not Used

    CMD_BOOTLOADER              = 9,    ///< Sets the bootloader modality to update the
                                        ///  firmware
    CMD_INIT_MEM                = 10,   ///< Initialize the memory with the defalut values
    CMD_CALIBRATE               = 11,   ///< Starts the stiffness calibration of the qbMove
                                        ///  or the hand closure and opening calibration
    CMD_GET_PARAM_LIST          = 12,   ///< Command to get the parameters list or to set
                                        ///  a defined value chosen by the use
    CMD_HAND_CALIBRATE          = 13,   ///< Starts a series of opening and closures of the hand


//=========================================================     QB Move commands

    CMD_ACTIVATE            = 128,  ///< Command for activating/deactivating
                                    ///  the device
    CMD_GET_ACTIVATE        = 129,  ///< Command for getting device activation
                                    ///  state
    CMD_SET_INPUTS          = 130,  ///< Command for setting reference inputs
    CMD_GET_INPUTS          = 131,  ///< Command for getting reference inputs
    CMD_GET_MEASUREMENTS    = 132,  ///< Command for asking device's
                                    ///  position measurements
    CMD_GET_CURRENTS        = 133,  ///< Command for asking device's
                                    ///  current measurements
    CMD_GET_CURR_AND_MEAS   = 134,  ///< Command for asking device's
                                    ///  measurements and currents
    CMD_SET_POS_STIFF       = 135,

    CMD_GET_EMG             = 136,
    CMD_SET_WATCHDOG        = 138,  ///< Command for setting watchdog timer
                                    ///  or disable it
    CMD_SET_BAUDRATE        = 139,   ///< Command for setting baudrate
                                    ///  of communication
    
    CMD_GET_N_IMU           = 147,  // Get number of IMUs connected to board
    CMD_GET_MAG_PARAM       = 148,  // Retrieve magnetometer parameters from IMUs
    CMD_GET_IMU_READINGS    = 149,  // Retrieve accelerometers, gyroscopes and magnetometers readings
    CMD_SET_IMU_MODE        = 150,  // Set sensors to read for each IMU
    CMD_GET_IMUS_MODE       = 151,  // Retrieve a summary of what we are reading from all imus
    CMD_GET_IMUS_SFS         = 152   // Retrieve a summary of ACC, GYRO and MAG scale factors and unities
};

/** \} */
//==============================================================================
//                                                                    PARAMETERS
//==============================================================================
/** \name QB Move Parameters */
/** \{ */

enum qbmove_parameter
{

    PARAM_ID                     = 0   ///< Device's ID number
    
};


//===================================================     resolution definitions

enum qbmove_resolution
{
    RESOLUTION_360      = 0,
    RESOLUTION_720      = 1,
    RESOLUTION_1440     = 2,
    RESOLUTION_2880     = 3,
    RESOLUTION_5760     = 4,
    RESOLUTION_11520    = 5,
    RESOLUTION_23040    = 6,
    RESOLUTION_46080    = 7,
    RESOLUTION_92160    = 8
};

//==============================================================     input modes

enum qbmove_input_mode
{
    INPUT_MODE_EXTERNAL         = 0,    ///< References through external
                                        ///  commands (default)
    INPUT_MODE_ENCODER3         = 1,    ///< Encoder 3 drives all inputs
    INPUT_MODE_EMG_PROPORTIONAL = 2,    ///< Use EMG measure to proportionally
                                        ///  drive the position of the motor 1
    INPUT_MODE_EMG_INTEGRAL     = 3,    ///< Use 2 EMG signals to drive motor
                                        ///  position
    INPUT_MODE_EMG_FCFS         = 4,    ///< Use 2 EMG. First reaching threshold
                                        ///  wins and its value defines hand closure
    INPUT_MODE_EMG_FCFS_ADV     = 5     ///< Use 2 EMG. First reaching threshold
                                        ///  wins and its value defines hand closure
                                        ///  Wait for both EMG to lower under threshold
};

//============================================================     control modes

enum qbmove_control_mode {

    CONTROL_ANGLE           = 0,        ///< Classic position control
    CONTROL_PWM             = 1,        ///< Direct PWM value
    CONTROL_CURRENT         = 2,        ///< Current control (beta)
    CURR_AND_POS_CONTROL    = 3         ///< Current control (beta)

};

//======================================================== motor supply voltage values

enum motor_supply_tipe {
    MAXON_24V               = 0,
    MAXON_12V               = 1
};

enum acknowledgment_values
{
    ACK_ERROR           = 0,
    ACK_OK              = 1
};

//==============================================    data types enumeration

enum data_types {
    TYPE_FLAG    = 0,
    TYPE_INT8    = 1,
    TYPE_UINT8   = 2,
    TYPE_INT16   = 3,
    TYPE_UINT16  = 4,
    TYPE_INT32   = 5,
    TYPE_UINT32  = 6,
    TYPE_FLOAT   = 7,
    TYPE_DOUBLE  = 8
};

#define PARAM_BYTE_SLOT     50      //Number of bytes reserved to a param information
#define PARAM_MENU_SLOT     150     //Number of bytes reserved to a param menu


/** \} */

//==============================================================================
//                                                                   INFORMATION
//==============================================================================
/** \name QB Move Information Strings */
/** \{ */
#define INFO_ALL        0 ///< All system information.

/** \} */

// ----------------------------------------------------------------------------
#endif
/* [] END OF FILE */