#include "HG_ShopMacros.h"
/*
    Author - HoverGuy
	Description - Called by the player when the dialog is closed (with the dialog close button or by pressing escape)
	© All Fucks Reserved
*/

if(!HG_CLOTHING_BOUGHT) then
{
    [] call HG_fnc_reset;
};

deleteVehicle HG_PLAYER_PREVIEW;

{
    if(_x != player) then 
	{
	    _x hideObject false;
	};
} forEach playableUnits;

HG_CAMERA_PREVIEW cameraEffect ["TERMINATE","BACK"];
camDestroy HG_CAMERA_PREVIEW;

HG_PLAYER_PREVIEW = nil;
HG_GEAR_SAVED = nil;
HG_CAMERA_PREVIEW = nil;
HG_GEAR_PREVIEW = nil;
HG_CLOTHING_BOUGHT = nil;
