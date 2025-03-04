Texas Instruments, Inc.

CC2540/41 Bluetooth® Low Energy Software Development Kit
Release Notes
BLE-Stack Version 1.5.1
January 30th, 2020
Texas Instruments, Inc.

Notices:

- This version of the Texas Instruments Bluetooth Low Energy software protocol stack (BLE-Stack) is a maintenance update to the v1.5.0 release and contains 2 bug fixes.

- For BEM, EBL and SimpleBLEPeripheral projects, refer to the porting guide section of the included Software Developers Guide (SWRU271) for details on how to update to this release.

Bug fixes included in this release:

- Fixed an issue where the AES-CTR counter value was reset after every 64 byte block in the BEM and EBL projects (BLESTACK-5116).

- Update the MAC verification to use a constant time function in the BEM project (BLESTACK-5117).

- Updated simple peripheral application to re-initiate advertising upon a connection fail event caused by invalid connection PDU parameters (BLESTACK-5258).

Known Issues / Limitations:

- HCI packet size of 128 bytes or more will be disregarded by the stack, and as 
  such, no HCI event will be returned.

- The configuration of the PICTL register by HalKeyConfig in Components\hal\target\CC2540USB\hal_key.c is incorrect. 
  Change the following within HalKeyConfig:
    PICTL |= 0x01;                 // P1ICONL: Falling edge ints on pins 0-3.
  to
    PICTL |= 0x02;                 // P1ICONL: Falling edge ints on pins 0-3.

- The CC254X OAD SW does not support downgrade attack protection, and the user applications should ensure downgrade or rollback attack protection applied at the application level (e.g. by making the SW security version part of the SW image).

For technical support please visit the Texas Instruments Bluetooth E2E Forum:

  http://www.ti.com/ble-forum
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Texas Instruments, Inc.

CC2540/41 Bluetooth® Low Energy Software Development Kit
Release Notes
BLE-Stack Version 1.5.0
April 18th, 2019
Texas Instruments, Inc.

Notices:

- This version of the Texas Instruments Bluetooth Low Energy software protocol stack (BLE-Stack) is a maintenance update to the v1.4.2 release and contains several bug fixes.

- For applications running v1.4.1 or later, most applications do not require porting since most changes are in protocol stack libraries. Refer to the porting guide section of the included Software Developers Guide (SWRU271H) for specific details on how to port to this release.

Bug fixes included in this release:

- Update the controller to enforce the rule that no data packet should be exchanged during the encryption procedure. (BLESTACK-4080).

- Update the controller to avoid deadlock when control procedure was happening at the same time as an encryption request. (BLESTACK-2273).

- Update the bond manager to avoid disconnection when the non-volatile memory is full. (BLESTACK-908, BLESTACK-4103).

- Fixed an issue that prevented establishing a connection with certain parameters. (BLESTACK-953).

- Fixed an issue that prevented the slave latency value to be taken into account during a specific parameter update. (BLESTACK-957).

- Fixed an issue where sending HCI_RESET after creating a connection was causing the device to become unresponsive. (BLESTACK-894).

- Fixed an issue where RFU header bits were not masked out. (BLESTACK-4045).

- Fixed an issue where the device can hang if a termination indication (unencrypted) is sent right after an encryption procedure has started. (BLESTACK-4421).

- Fixed an issue where the slave could not request a connection parameter update with a new connection interval not a multiple of the current connection interval. (BLESTACK-1612).

- Fixed an issue where the BIM could have a corrupted DMA structure. (BLESTACK-524).

- in GATT, the authorization check was not returning the correct status in case of failure. (BLESTACK-4353).

- in the thermometer service, the check on the temperature range was excluding the boundary value, where it should not. (BLESTACK-4354).

- in the thermometer service, fix an issue where the notification was not sent if the measurement interval characteristic value was greater than 0. (BLESTACK-4355).

- in the cycling service, fix a case where the notification was not always disabled. (BLESTACK-4358).

- Fixed a race condition in the UART DMA driver. (BLESTACK-2229).

- Fixed a issue in the LL where the event numCompletePacket was send before the packet was actually ack by the peer. (BLESTACK-4533).

- Update the way authorization to read or write a characteristic were done to be compliant with the specification. (BLESTACK-4330).

- In the running sensor profile, fix an issue where the service is responding to a ATT write request with success while waiting for an indication confirmation. (BLESTACK-4416).

Known Issues / Limitations:

- HCI packet size of 128 bytes or more will be disregarded by the stack, and as 
  such, no HCI event will be returned.

- The configuration of the PICTL register by HalKeyConfig in Components\hal\target\CC2540USB\hal_key.c is incorrect. 
  Change the following within HalKeyConfig:
    PICTL |= 0x01;                 // P1ICONL: Falling edge ints on pins 0-3.
  to
    PICTL |= 0x02;                 // P1ICONL: Falling edge ints on pins 0-3.

Upgrade and Compatibility Information:

- For details on how to qualify your Bluetooth product, please see http://www.ti.com/ble-qualification

- All projects have been migrated from IAR Embedded Workbench for 8051 v9.10.3 to v10.30.1. In order to build all projects, be sure to upgrade to IAR v10.30.1. Use of other versions of IAR may result in compatibility issues with this SDK release.

 IAR software can be obtained from:
  
 https://www.iar.com/iar-embedded-workbench/partners/texas-instruments/ti-wireless/

For technical support please visit the Texas Instruments Bluetooth E2E Forum:
http://www.ti.com/ble-forum
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

BLE-Stack Version 1.4.2
June 7, 2016
Texas Instruments, Inc.

Notices:

- This version of the Texas Instruments BLE-Stack and software is a maintenance update to the v1.4.1 release and contains several bug fixes

- For applications running v1.4.1, no application porting is required since all changes are in protocol stack libraries.

- TI recommends using BLE-Stack v1.4.1 or later to ensure pairing compatibility with Android 6.0 (Marshmallow) devices

- The included Software Developer's Guide (SWRU271G) is compatible with this release

Bug fixes included in this release:

- Fixed an issue where Limited Discoverable advertising doesn't end if the ADV payload length is 31 bytes

- Fixed an issue where the GATT Client is not able to read the full GAP Device Name when the name length is > 19 characters

- Added check for GATT_PERMIT_ENCRYPT_WRITE in ggs_SetAttrWPermit

- Addressed Central role stability issues with multiple connections when performing concurrent operations: pairing, scan or initiating

- Fixed an issue with Channel Map Updates not properly ack'd in certain conditions when Slave Latency is applied

- Fixed a condition where Slave Latency was not temporarily disabled in degraded RF channel conditions

- Fixed a slave condition where LL_TERMINATE_IND is not ack'd if sent at the 6th interval after receiving a LL_CONNECTION_UPDATE_IND

Known Issues / Limitations:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

- HCI packet size of 128 bytes or more will be disregarded by the stack, and as 
  such, no HCI event will be returned.

Additional Resources:

For technical support please visit the Texas Instruments Bluetooth E2E Forum:

  http://www.ti.com/ble-forum

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

CC2540/41 Bluetooth low energy Software Development Kit
Release Notes

BLE-Stack Version 1.4.1
May 21, 2015

Notices:

- This version of the Texas Instruments BLE-Stack and software is a maintenance 
  update to the v1.4.0 release. It contains several bug fixes and enhancements.

- The BLE protocol stack, including both the controller and host, was 
  completely retested for v1.4.1.

- All Sample Applications in the SDK ported and verified for v1.4.1

- Default SDK installation path is C:\Texas Instruments\BLE-CC254x-1.4.1.xxxxx\
  where "xxxxx' is the SDK build revision number.

- For guidance on how to port existing v1.4.0 projects to v1.4.1, refer to the 
  "Additional Resources" section below.

Changes and minor enhancements:

- All projects have been migrated from IAR v8.20.2 to IAR 9.10.3. In order to
  build all projects, be sure to upgrade to IAR v9.10.3.
  
- Smarter handling of connection parameter updates with multiple connections 

- GAPRole_SetParameter(GAPROLE_ADVERT_DATA) changes the advertising data   

- Allows removal of Service Changed Characteristic 

- HAL components set to TRUE if not defined 

- Added HCI Vendor Specific Guide revision history 

- Several bug fixes. 
 
Bug Fixes:

- Fix for RSSI value does not change in V1.4 stack 

- Fix for Number HCI Commands parameter not updated in Command Complete Event 

- Fixed CC254x UART DMA reception discontinuity 

- Fix for SPI reliability improvement 

- Fix for updating advertisement data while simultaneously connected as peripheral and advertising 

- Fix for filtering duplicate ADV reports even when the filter is FALSE 

- Fix for possible race condition T2ISR vs T2E1 on slow wakeups 

- Fix for HAL_DMA_CLEAR_IRQ() can be interrupted causing missed ISR cause 

- Fixed HCI_LERemoveDeviceFromWhiteList Fails after Scan 

- Watchdog Kick Macro Affected by Interrupts

- Fixed HCI_EXT_ResetSystem soft reset to work as expected on CC254x 

- Fixed White List Irregularities During Scan / Connect 

- Fixed Overlap processing that causes Slave task to last too long for next event setup 

- Add BTool Support for new field 'encKeySize' added to GATT_AddService command

- Fixed CC254x UART DMA reception discontinuity

- Fixed CC254x unresponsive when resetting in initiating state 

- Fix for after successful reconnect using private non-resolvable address, rebond fails with "Key Req Rejected"

- Fix for CC254x host Bond Manager setParam configuration does not support M/S LinkKey enc exchange

- Fixed TICKSPD, CLKSPD is overwritten on X/HS-OSC change

Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

- HCI packet size of 128 bytes or more will be disregarded by the stack, and as 
  such, no HCI event will be returned.

Additional Resources:

For technical support please visit the Texas Instruments Bluetooth E2E Forum:

  http://www.ti.com/ble-forum

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.4.0
November 8, 2013

Notices:

- This version of the Texas Instruments BLE stack and software is a minor 
  update to the v1.3.2 release. It contains some minor bug fixes and a few 
  functional changes.

- The BLE protocol stack, including both the controller and host, was 
  completely retested for v1.4.0.

Changes and Enhancements:

- All projects have been migrated from IAR v8.10.4 to IAR 8.20.2. In order to
  build all projects, be sure to upgrade to IAR v8.20.2.

- Updated SPI and UART_DMA drivers for improved robustness and throughput.

- Added an overlapped processing feature to improve throughput and reduce power
  consumption in devices where peak power consumption isn't an issue.    Overlapped processing allows the stack to concurrently process while the radio 
  is active.  Since the stack is concurrently processing, it is able to insert 
  new data in the Tx buffer during the connection event, causing additional 
  packets to be sent before the end of the event.

- Added a Number of Completed Packets HCI command which offers the possibility   
  of waiting for a certain number of completed packets before reporting to the   
  host. This allows higher throughput when used with overlapped processing.

- Added an HCI Extension command HCI_EXT_DelaySleepCmd which provides the user 
  control of the system initialization sleep delay (wake time from PM3/boot 
  before going back to sleep).  The default sleep delay is based on the 
  reference design 32 kHz XOSC stabilization time.

- Added a low duty cycle directed advertising option.

- Added support for deleting a single bond with the GAP_BondSetParam command.

- Decreased CRC calculation time during OAD by using DMA. 

Bug Fixes:

- Using a short connection interval and exercising high throughput, there was   
  some loss of packets.  This was fixed by adding host to application flow   control support.

- Bonding was unstable at short connection intervals. This is now fixed.

- Fixed USB CDC Drivers to work with Windows 8.

- OAD sample project would fail if long connection interval was used. This was     fixed by not allowing parameter updates to the central device.

- Fixed linking errors in UBL project.

- Fixed minor issues in sample apps to work with PTS dongle.

- Fixed USB descriptors in HostTestRelease to display correct string.

Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

- HCI packet size of 128 bytes or more will be disregarded by the stack, and as 
  such, no HCI event will be returned.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.3.2
June 13, 2013

Notices:

- This version of the Texas Instruments BLE stack and software is a minor 
  update to the v1.3.1 release. It contains some minor bug fixes and a few 
  functional changes.

- The BLE protocol stack, including both the controller and host, was 
  completely retested for v1.3.2. The profiles Running Speed and Cadence,
  Cycling Speed and Cadence, and Glucose were fully tested and passed 
  certification. Other profiles with no code changes since 1.3.1 were sanity 
  tested only.

Changes and Enhancements:

- Added Running Speed and Cadence profile and service. An example application 
  demonstrating running speed and cadence is provided.

- Added Cycling Speed and Cadence profile and service. An example application 
  demonstrating cycling speed and cadence is provided. 

- Added delay before performing Connection Parameter changes. Implemented 
  conn_pause_peripheral) and TGAP(conn_pause_central) timers as described in 
  CSA 3 rev 2, Gap Connection Parameters Changes, Section 1.12. Updated 
  HIDAdvRemote, HIDEmuKbd, KeyFob, SensorTag, and SimpleBLEPeripheral 
  applications.

- Update Privacy Flag and Reconnection Address characteristics permissions
  (Erratum 4202)

- A new Windows USB CDC driver has been included in the installer. This new
  driver is signed and is functional on Windows 8 systems.

Bug Fixes:

- Some minor updates to glucose sensor and collector were made. 

- The gyroscope would draw continuous 6mA when enabled. The updated 
  code now performs a read and turns off the gyro after 60ms.

- The master�s host would accept invalid connection parameters requested 
  by the Slave, and would send back the Connection Parameter Update Response
  with �parameters accepted�. The host now performs validation on these 
  parameters.

- When coming out of sleep, the HCI_EXT_ExtendRfRangeCmd would override     
  HCI_EXT_SetRxGainCmd setting and set it to default gain. This has been fixed.


Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

- HCI packet size of 128 bytes or more will be disregarded by the stack, and as 
  such, no HCI event will be returned.

- The HAL SPI driver that was implemented since the v1.3 release can sometimes
  hang, particularly in cases in which power management is used and when there
  is heavy traffic on the SPI bus.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.3.1
April 18, 2013

Notices:

- This version of the Texas Instruments BLE stack and software is a minor 
  update to the v1.3 release. It contains some minor bug fixes, with no major 
  functional changes. It also contains two additional projects for the CC2541 
  Advanced Remote Control Kit.

- Since none of the profile source code was significantly changed since the
  v1.3 release, no additional re-testing of the profiles and sample
  application were done for v1.3.1. The only exception is the HID-over-GATT
  profile, which was fully re-tested for this release. The BLE protocol stack,
  including both the controller and host, was completely retested for v1.3.1.
  
Major Changes and Enhancements:

- The GAP parameter TGAP_LIM_ADV_TIMEOUT now uses units of seconds instead
  of milliseconds.

- The HidAdvRemote Project has been added. This implements a full mouse-like 
  pointing functionality using motion and gesture control. The project runs on
  the CC2541 BLE Advanced Control included as part of the CC2541DK-REMOTE kit.
  The application implements the HID-over-GATT (HOGP) profile with a report
  descriptor supporting the keyboard, mouse, and consumer control classes of
  HID devices.

- The HidAdvRemoteDongle project has been added. This application runs on the
  CC2540USB dongle, and implements partial functionality of HID-over-GATT 
  (HOGP) host with a fixed report descriptor to match that of the descriptor
  of the HidAdvRemote Project. This means that the HidAdvRemoteDongle was 
  designed only to work with the HidAdvRemote, and will not be compatible
  with any other HOGP devices. This project was created to allow users who
  are using a host device that does not have native Bluetooth Smart Ready
  support and/or does not have HOGP support to use the BLE Advanced Remote
  Control with their system.

- For GAP central role applications, the bond manager now properly handles 
  cases in which the peripheral device has erased previously stored bonding 
  information

- A new HCI extension API has been added to allow peripheral/slave devices to
  temporarily ignore any nonzero slave latency value, and explicitly wake up
  at every connection event regardless of whether it has any data to send.
  The prototype for the API function HCI_EXT_SetSlaveLatencyOverrideCmd can 
  be found in hci.h, including the description of the function.

- A new HCI extension API has been added to allow the application layer to 
  get or set a build revision number.


Bug Fixes:

- In some cases L2CAP Peripheral Connection Parameter Update requests failed
  due to a zero value in the transmitWindowOffset parameter when the
  connection was initially established. This has been fixed and updates 
  should now work successfully.

- During bonding, connection failures would occasionally occur due to the
  OSAL Simple NV driver performing a page compaction and halting the CPU for
  longer than the time required for the link layer to maintain proper
  connection timing. To prevent this from occurring, the simple NV driver now
  has any API to force a page compaction if the page is full beyond a specified
  threshold. The bond manager calls this API every time a connection is
  terminated to ensure that compaction occurs before the next connection is set
  up.

- Occasional slave connection failures would previously occur in cases in which 
  the master device sends Update Channel Map requests while a large slave 
  latency value is in use. This has been fixed.

- The SensorTag application now properly supports storage of GATT Client
  Characteristic Configuration Descriptor values with bonded devices.

- After disabling advertising, the CC254x would unnecessarily wake up for a
  short period of time 500ms later. This unecessary wake-up has been removed.

- Upon Power-On Reset or after wake-up from PM3, a 400ms delay has been 
  implemented, during which time the CC254x will not go into PM2 sleep. This 
  allows time for the 32kHz crystal to stabilize. Previously, in rare cases
  with certain hardware configurations the CC254x could have timing issues due
  to the crystal not having time to stabilize. 

- Minor bug fixes to GlucoseSensor and GlucoseCollector projects.


Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

- HCI packet size of 128 bytes or more will be disregarded by the stack, and as 
  such, no HCI event will be returned.

- The HAL SPI driver that was implemented since the v1.3 release can sometimes
  hang, particularly in cases in which power management is used and when there
  is heavy traffic on the SPI bus.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.3
Dec 12, 2012

Notices:

- This version of the Texas Instruments BLE stack and software features several
  changes, enhancements, and bug fixes from v1.2.1. Details of these can be
  found below.
  
Changes and Enhancements:

- A new sample project, SensorTag, has been added. This application runs on the
  CC2541 Sensor Tag board, which is included as part of the CC2541DK-SENSOR
  development kit. The application includes custom services for an
  accelerometer, barometer, gyro, humidity sensor, IR temperature sensor, and
  magnetometer.

- A new Boot Image Manager (BIM) is included. This allows one CC2540 or CC2541
  device to contain two separate software images (an "A" image and a "B" image)
  stored in flash. Upon power-up, the BIM selects which image to boot into.
  This can be based on criteria such as the state of a GPIO pin, or based on a
  selection from the previously running application upon reset.

- A new Over-the-air firmware download (OAD) feature is included. The feature
  allows a peer device (which could be a central BT Smart device such as a
  smartphone) to push a new firmware image onto a peripheral device and update
  the firmware. This feature uses the BIM, in which case the downloaded image
  gets stored in the opposite flash location as the currently running image.
  For example, if the "A" image is the current image and is used to perform the
  download, then the downloaded image becomes the "B" image. Upon reset, the
  "B" image with the updated firmware would be loaded. The OAD feature   
  optionally allows for the firmware image to be signed (using AES). Both the  
  SensorTag and SimpleBLEPeripheral projects include configurations for using
  the OAD feature. A central "OADManager" application is also included,
  demonstrating a central implementation for sending a new firmware image to an   OAD target device.

- The physical HCI interface used by the network processor (HostTestRelease)
  has been enhanced to work while power management is enabled on the CC254x 
  device. The UART interface, when using RTS and CTS lines, can be used by an
  external application processor to wake-up the CC254x network processor. When
  the network processor has completed all processing, it will go into deep
  sleep. In addition to UART, an SPI interface has been added as an option for
  the physical HCI interface. It also supports power management by means of 
  the MRDY and SRDY lines.

- The CC2541 configuration of the KeyFobDemo project has been modified to 
  support the new CC2541 keyfob hardware, contained in the CC2541DK-MINI kit.
  The accelerometer has been changed, and a TPS62730 DC/DC converter has been
  added.

- The structure of all projects have been changed to include a Transport Layer
  ("TL") library and network processor interface "NPI" source code. This new
  architecture allows for non-network processor applications to have slightly
  reduced code size by removing unnecessary stack components.

- An API has been provided allowing the device name and appearance 
  characteristics in the GAP service to be modified by the application layer.

- KeyFobDemo project now includes visual feedback from LED to indicate when
  device has powered up and when device is advertising.

- The HID-over-GATT Profile (HOGP) implementation has been updated to now 
  queue up HID report and send notifications upon reconnection to a HID host.
  
- A new implementation of the HID service has been included, which supports
  a combined keyboard, mouse, and consumer class device in its HID report
  descriptor.

- The API for sending L2CAP Connection Parameter Update Requests from the GAP
  Peripheral Role Profile has been updated to take both the requested minimum
  and maximum connection intervals as parameters.

- BTool has been enhanced with a new GATT explorer table, displaying discovered
  attributes, handles, and values. An XML file is included which allows the 
  user to define descriptions of characteristics based on their UUIDs.

- HCI UART interface baud rate has been changed from 57600 to 115200.

Bug Fixes:

- When power management is used with long connection intervals (>2s), the
  CC254x remains sleeping properly without unnecessary wake-ups.

- When slave latency is used, peripheral devices now properly wake-up before 
  the next connection event when a data packet is queued

- Various bug fixes on the GlucoseSensor and GlucoseCollector projects to 
  improve compliance with profile and service specifications.

- HID-over-GATT Pofile (HOGP) implementation has been updated to provide 
  better interoperability with HID hosts.

Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

- HCI packet size of 128 bytes or more will be disregarded by the stack, and as
  such, no HCI event will be returned.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.2.1
Apr 13, 2012

Notices:

- This version of the Texas Instruments BLE stack and software is a minor 
  update to the v1.2 release. It contains some minor enhancements and bug
  fixes, with no API changes or major functional changes.
  
Changes and Enhancements:

- When advertising is enabled by calling GAP_MakeDiscoverable, the first
  advertisement event will now occur within a few milliseconds, rather than 
  waiting for 10ms.

Bug Fixes:

- The HidEmuKbd project now properly implements the HID Service include of the
  Battery Service. This bug fix allows for proper interoperability between the
  CC254x HID Profile and host systems running Windows 8.
  
- The source code file hal_board_cfg.h has been updated to better support the
  serial bootloader (SBL) and Universal Bootloader (UBL).
  
- Scanning in BTool can now be cancelled at any time without hanging or 
  freezing the system.

Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.2
Feb 13, 2012

Notices:

- This version of the Texas Instruments BLE stack and software includes support
  for the CC2541, as well as some enhancements and bug fixes. Details of these
  can be found below. If you have not previously worked with the v1.1b release
  (which had limited distribution) it is recommended that you also read the notes
  detailing the changes and enhancements from v1.1a to v1.1b in addition to the
  notes for v1.2.

Changes and Enhancements:

- All projects have been migrated from IAR v7.60 to IAR v8.10.4. In order to
  build all projects, be sure to upgrade and have IAR v8.10.4. Also, be sure to
  download and install all of the latest patches from IAR for full CC2540 and
  CC2541 support.

- Multi-role and combo-role support has been enhanced. The BLE stack can now
  support simultaneously advertising and/or scanning while in a connection as
  either a master or a slave. This allows for a central device to perform
  device discovery while in a connection. All previous rules for multiple
  simultaneous connections as a central device still apply (see v1.1a release
  notes below).

- New sample projects "SimpleBLEBroadcaster" and "SimpleBLEObserver" have been
  added, as example projects for pure broadcaster and observer applications
  with very low code size. The projects make use of new GAP role profiles
  broadcaster.c and observer.c that are included.

- All projects have a modified architecture from the v1.1, v1.1a, and v1.1b
  releases. Each project contains a file "buildConfig.cfg" that can be found in
  the project directory and is included in the IAR project workspace as part of
  the "TOOLS" group. The settings in this file determine the role of the device
  in the application. Based on this configuration, different pieces of the BLE
  stack in object code are linked in, causing the code size to be larger or
  smaller depending on the roles supported. For example, HostTestRelease by
  default is now configured to support every single BLE GAP role in a single
  build, and therefore has a large code size (approx. 165kB). On the other
  hand, SimpleBLEBroadcaster is configured to only support the GAP broadcaster
  role, and therefore has a very small code size (approx. 39kB).

- The function GAPRole_SendUpdateParam in peripheral.c has been made public to
  allow a peripheral application to send an L2CAP connection parameter update
  request at any time.
  
- The names and configuration of the BLE stack libraries have changed.
  Different libraries are used depending on the GAP role (or combination of
  roles) used by the application. More information can be found in section
  3.3.5 of the BLE Software Developer's Guide.

- All library files now support power management. Power management must be
  enabled by the application by calling osal_pwrmgr_device( PWRMGR_BATTERY );.
  All sample applications that use power management make this call in the main
  function.
  
- All GATT service source code has been cleaned up to make handling of client
  characteristic configuration descriptors (CCCDs) simpler. All CCCDs are now
  processing is now handled by GATTServApp and no longer must be handled by the
  service itself. Examples of this can be found in the included example
  services such as SimpleGATTprofile, Simple Keys service, Accelerometer
  service, etc...

- The HostTestRelease network processor project now includes HCI Vendor 
  Specific commands for each GATT client sub-procedure, matching the GATT 
  client API. All GATT commands have been added to the "Adv. Commands" tab in
  BTool. The functions in the BTool GUI "Read / Write" tab now make use of the
  GATT commands as opposed to ATT commands.

- The old "EmulatedKeyboard" project has been removed and replaced with the new
  "HIDEmuKbd" project. The new project performs the same functions as the old
  one, but is now based on the "HID over GATT Profile" v1.0 specification
  (HOGP_SPEC_V10) that has been adopted by the Bluetooth SIG. The HID profile
  functionality has been implemented in a OSAL task that runs separate from the 
  application to allow for easy portability to other HID projects. More details
  on the new application can be found in the BLE Sample Application Guide 
  included as part of the release. The following additional new services / 
  profiles have been included to fully support the HOGP specification:
  
	- HID Service v1.0 (HIDS_SPEC_V10)
	
	- Scan Parameters Profile v1.0 (ScPP_SPEC_V10)
	
	- Scan Parameters Service v1.0 (ScPS_SPEC_V10)
	
	- Device Information Service v1.1 (DIS_SPEC_V11r00)
	
	- Battery Service v1.0 (BAS_SPEC_V10)
  
- The KeyFobDemo project has been updated to use the adopted battery service.
  The custom battery service that was used in previous released has been 
  removed.

- The TimeApp project has been updated to include support for the Phone Alert
  Status Profile (PASP_SPEC_V10) in the Client role.
  
- Support for "Production Test Mode" has been added, allowing a BLE application
  in a "single-chip" configuration to temporarily expose the HCI over the UART
  interface when triggered externally to do so (e.g. hold a GPIO pin low during
  power up). This allows the device to be connected to a Bluetooth tester in 
  order to run direct test mode (DTM) commands on a production line using the
  final release firmware, while leaving the UART GPIO pins available for the 
  application to use at all other times

- A Universal Boot Loader (UBL) using the USB Mass Storage Device (USB-MSD) 
  class has been added along with a Serial Boot Loader (SBL). The 
  HostTestRelease project includes configurations with examples of both boot 
  loaders. The SBL project is included with the installer. More information on 
  the UBL can be found in the following document:
  
  C:\Texas Instruments\BLE-CC254x-1.2\Documents\
  Universal Boot Loader for SOC-8051 by USB-MSD Developer's Guide.pdf

- HCI extension command HCI_EXT_MapPmIoPortCmd added to support toggling of a
  GPIO line as CC254x device goes in and out of sleep. This command can be 
  used to automatically control the bypass line of the TPS62730 DC/DC 
  converter for reducing power consumption in an optimized manner.

- A slave device will now dynamically widen it's Rx window when a previous
  connection event was missed. This improves connection stability by accounting
  for additional clock drift that may have occurred since the last successful
  connection event.
  
- The application now has the capability to change the permissions of the
  device name in the GAP service by calling GGS_SetParameter and changing
  the value of the parameter GGS_W_PERMIT_DEVICE_NAME_ATT. The application can
  also receive a callback when a client device writes a new name to the device. 
  The application registers the callback by calling GGS_RegisterAppCBs. The
  prototype for GGS_RegisterAppCBs can be found in gapgattserver.h.

Bug Fixes:

- Duplicate filtering now works with combination states.

- Various minor application / profile bug fixes.
  
Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.1b
Nov 30, 2011

Notices:

- This version of the Texas Instruments BLE stack and software includes support
  for the CC2541, as well as some minor enhancements and bug fixes. Details of 
  these can be found below. The general software architecture remains the same 
  as in the v1.1 and v1.1a releases.
  
Changes and Enhancements:

- BLE stack libraries for the CC2541 are included.

- All BLE libraries are renamed and now indicate whether they are used for 
  CC2540 or CC2541.

- For each project and configuration, new IAR projects are included for use 
  with the CC2541. The only exception is that any project/configuration that
  uses the USB interface has not been replicated for the CC2541, as it does not
  have an on-chip hardware USB interface.
  
- Link-layer processing has been optimized to provide for reduced power 
  consumption during connection events and advertising events.
  
- SimpleBLEPeripheral and SimpleBLECentral now use the HCI_EXT_ClkDivOnHaltCmd,
  which reduces the current level while the CC2540/41 radio is active.

- The bond manager has been updated to allow peripheral devices to properly
  pair, bond, and resolve the address of central devices that use the private
  resolvable address type.

- New command HCI_EXT_SetMaxDtmTxPowerCmd included, which allows the maximum
  Tx power level to be set. This is useful when using Direct Test Mode (DTM),
  in that the Tx power level will be set to the maximum value set by the
  HCI_EXT_SetMaxDtmTxPowerCmd command, which may be less than +4dBm for the 
  CC2540 and less than 0dBm for the CC2541. The function prototype can be 
  found in hci.h.
  
Bug Fixes:

- The command HCI_EXT_SetTxPowerCmd is now properly working.

Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

- Duplicate filtering does not work when scan is used in combination with a
  connection.
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.1a
Aug 10, 2011

Changes and Enhancements:
   
- The thermometer profile sample application has been updated to support 
  stored measurements. The TI_BLE_Sample_Applications_Guide has been updated
  to match these changes.

Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

- Duplicate filtering does not work when scan is used in combination with a
  connection.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.1
July 13, 2011

Notices:

- This version of the Texas Instruments BLE stack and software features several
  changes, enhancements, and bug fixes from v1.0. Details of these can be found 
  below.


Changes and Enhancements:
   
- All projects have been migrated from IAR v7.51A to IAR v.7.60. In order to
  build all projects, be sure to upgrade and have IAR v7.60. Also, be sure to
  download and install all of the latest patches from IAR for full CC2540
  support.

- The stack now supports up to 3 simultaneous connection as a central / master
  device, with a few constraints:
   	
	- All connection intervals must be a multiple of the minimum connection
	  interval (i.e. the minimum connection interval is the greatest common
	  denominator of all connection intervals).
   	 
   	- The minimum connection interval allowed is 25ms when using more than
   	  one connection.

   	- When more than one connection is active, only one data packet per
   	  connection event will be allowed in each direction.
   	  
   	- Scanning is not supported while in a connection. The consequences of
   	  this is that device discovery is not possible while in a connection.
   	  Therefore, to discover and connect to multiple devices, the device
   	  discovery must occur before the first connection is established.   	

- Several new sample projects are included, with examples of many different BLE
  applications / profiles. Full details on the sample applications can be found
  in the BLE Sample Applications Guide, which can be accessed from the Windows
  Start Menu. These sample applications implement various functions. Some are
  based on adopted Bluetooth specifications, some are based on draft
  specifications, and others are custom designed by Texas Instruments. These
  projects should serve as good examples for various other BLE applications.

- The following updates have been made to BTool (more information on these
  updates can be found in the CC2540DK-MINI User Guide which can be downloaded
  here: http://www.ti.com/lit/pdf/swru270):
	
	- Improved GUI and robustness.
	
	- All functions on the GUI been updated to handle multiple simultaneous
	  connections.
	
	- A new "Pairing / Bonding" tab has been added, allowing link
	  encryption and authentication, passkey entry, and saving / loading of
	  long-term key data (from bonding) to file.
	  
	- Ability to "Cancel" a link establishment while the dongle is
	  initiating.
   	
- The following additional new controller stack features are included in this
  release:
  
	- Support for multiple simultaneous connections as a master (details
	  above)
	
	- HCI Vendor Specific function HCI_EXT_SetSCACmd allows you to specify
	  the exact sleep clock accuracy as any value from 0 to 500 PPM, in
	  order	to support any crystal accuracy with optimal power consumption.
	  This feature is only available for slave / peripheral applications.
	
	- HCI Vendor Specific function HCI_EXT_SetMaxDtmTxPowerCmd allows you
	  to set the maximum transmit output power for Direct Test Mode. This
	  allows you to perform use the LE Transmitter Test command with power
	  levels less than +4dBm.
	  
	- A master device can now advertise while in a connection.
	
	- New production test mode (PTM) has been added allowing the CC2540 to
	  run Direct Test Mode (DTM) while connected to a tester using a
	  "single-chip" BLE library.
	  
	- The controller now uses DMA to more efficiently encrypt and decrypt
	  packets. All BLE projects must now define HAL_AES_DMA=TRUE in the
	  preprocessor settings when using the v1.1 libraries.
	  
- The following additional new host stack features are included in this
  release:

	- A new GAP central role profile for single-chip embedded central
	  applications is included, with functions similar to the GAP
	  peripheral role profile. The SimpleBLECentral project serves as an
	  example of an application making use of the central role profile.
	
	- The GAP peripheral role has been optimized to significantly improve
	  power consumption while advertising with small amounts of data by
	  no longer transmitting non-significant bytes from in the
	  advertisement and scan response data.

- The following additional new application / profile features are included in
  this release:
  
  	- The GAP peripheral bond manager has been replaced with a general GAP
	  bond manager, capable of managing bond data for both peripheral and
	  central role devices. The gap peripheral bond manager has been
	  included for legacy support; however it is recommend to switch to the
	  general GAP bond manager (gapbondmgr.c/h).
	
	- The bond manager also now manages the storage of client
	  characteristic configurations for each bond as per the Bluetooth 4.0
	  spec.
  	
  	- The simple GATT profile has a new fifth characteristic. This
	  characteristic is 5 bytes long, and has readable permissions only
	  while in an authenticated connection. It should serve as a reference
	  for development of other profiles which require an encrypted link.
  	
  	- All GATT profiles have been updated to properly handle client
  	  characteristic configurations for both single and multiple
  	  connections. Characteristic configurations now get reset to zero
  	  (notifications / indications off) after a connection is terminated,
  	  and the bond manager now stores client characteristic configurations
  	  for bonded devices so that they are remembered for next time when the 
  	  device reconnects.
  	  
  	- Added linker configuration file for support of 128kB flash versions
  	  of the CC2540. An example is included in the SimpleBLEPeripheral
  	  project.
  	  
  	- The SimpleBLEPeripheral project "CC2540 Slave" configuration has been
  	  updated to better support the SmartRF05EB + CC2540EM hardware
  	  platform, making use of the LCD display.


Bug Fixes:

 - The following bugs have been fixed in the controller stack:

	- Scanning now working for master devices with power savings enabled.
	
	- RSSI reads no longer require a data packet to update.
	
	- Improved stability when using very high slave latency setting
	
	- HCI LE direct test modes now working properly.
	
	- HCI Read Local Supported Features now returns the proper value.
	
	- Use of two advertising channels now works.
	
	- When connecting to a device on the whitelist, the correct peer device
	  address is returned to the host.  
	
 - The following bugs have been fixed in the host stack:
 
	- Pairing no longer fails when either device is using a static, private 
	  resolvable, or private non-resolvable address.

 - The following bugs have been fixed in the profiles / applications:
 
	- Reading of RSSI with peripheral role profile now working.
	
	- Peripheral role profile now allows all legal whitelist modes.
	
	- Can now connect with short connection intervals (such as 7.5ms), 
	  since bond manager now reads data from NV memory upon initialization
	  rather than immediately after a connection is established. Pairing
	  still may not be stable when using the bond manager with very short
	  connection intervals (for reason noted in "Known Issues" below)


Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

- Duplicate filtering does not work when scan is used in combination with a
  connection.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Version 1.0
October 7, 2010

Notices:

- The Texas Instruments Bluetooth� low energy (BLE) software development kit 
  includes all necessary software to get started on the development of 
  single-mode BLE applications using the CC2540 system-on-chip. It includes 
  object code with the BLE protocol stack, a sample project and applications 
  with source code, and BTool, a Windows PC application for testing BLE 
  applications. In addition to the software, the kit contains documentation, 
  including a developer�s guide and BLE API guide.

- For complete information on the BLE software development kit, please read
  the developer's guide:
  
	BLE Software Developer's Guide:
	<Install Directory>\Documents\TI_BLE_Software_Developer's_Guide.pdf
	(Also can be accessed through the Windows Start Menu)
 
- The following additional documentation is included:
 	 	
 	BLE API Guide:
 	<Install Directory>\Documents\BLE_API_Guide_main.htm
 	
 	Vendor Specific HCI Guide:
 	<Install Directory>\Documents\TI_BLE_Vendor_Specific_HCI_Guide.pdf
 	
 	HAL Drive API Guide:
 	<Install Directory>\Documents\hal\HAL Driver API.pdf
 	
 	OSAL API Guide:
 	<Install Directory>\Documents\osal\OSAL API.pdf
 	
- The following software projects are included, all built using IAR Embedded
  Workbench v7.51A:
   
   	SimpleBLEPeripheral:
   	<Install Directory>\Projects\ble\SimpleBLEPeripheral\CC2540DB        \SimpleBLEPeripheral.eww

	HostTestRelease:
	<Install Directory>\Projects\ble\HostTestApp\CC2540\HostTestRelease.eww

- The following Windows PC application is included:
  
  	BTool:
  	<Install Directory>\Projects\BTool\BTool.exe
  	(Also can be accessed through the Windows Start Menu)
 
Changes:
 
- Initial Release

Bug Fixes:
 
- Initial Release

Known Issues:

- Use of the NV memory (to save application data or BLE Host bonding
  information) during a BLE connection may cause an unexpected disconnect.
  The likelihood of this happening increases with frequent usage, especially
  when using short connection intervals. The cause is related to the NV wear
  algorithm which at some point may cause an NV page erase which can disrupt
  system real-time processing. It is therefore recommended that the NV memory
  be used sparingly, or only when a connection is not active.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
© Copyright 2010-2019, Texas Instruments Incorporated. All rights reserved.