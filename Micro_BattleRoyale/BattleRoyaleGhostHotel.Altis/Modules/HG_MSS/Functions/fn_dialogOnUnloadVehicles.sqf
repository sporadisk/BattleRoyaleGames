#include "HG_ShopMacros.h"
/*
    Author - HoverGuy
	Description - Called by the player when the dialog is closed (with the dialog close button or by pressing escape)
	© All Fucks Reserved
*/

{
    deleteVehicle _x;
} forEach HG_VEHICLE_PREVIEW;

{
    if(_x != player) then 
	{
	    _x hideObject false;
	};
} forEach playableUnits;

HG_CAMERA_PREVIEW cameraEffect ["TERMINATE","BACK"];
camDestroy HG_CAMERA_PREVIEW;

HG_VEHICLE_PREVIEW = nil;
HG_CAMERA_PREVIEW = nil;
