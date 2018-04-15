//	Copyright (C) 2015 Michael McMaster <michael@codesrc.com>
//
//	This file is part of SCSI2SD.
//
//	SCSI2SD is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	SCSI2SD is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with SCSI2SD.  If not, see <http://www.gnu.org/licenses/>.

#include "device.h"
#include "scsi.h"
#include "config.h"
#include "mo.h"


// Handle magneto-optical scsi device commands
int scsiMOCommand()
{
	int commandHandled = 0;

	uint8 command = scsiDev.cdb[0];
	if ((command == 0x2C) || // ERASE(10)
		(command == 0xAC)) // ERASE(12)
	{
		// TODO consider sending an erase command to the SD card.

		commandHandled = 1;
	}

	return commandHandled;
}

