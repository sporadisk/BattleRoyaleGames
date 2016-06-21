#include "HG_ShopMacros.h"
/*
    Author - HoverGuy
	Description - Called when you click "Buy" button in dialog
	© All Fucks Reserved
*/
private "_price";

disableSerialization;

_price = HG_VEHICLES_LIST lbValue (lbCurSel HG_VEHICLES_LIST);

if((player getVariable "HG_myCash") >= _price) then
{
    private["_spawnPoint","_spawnBusy"];
    _spawnPoint = HG_VEHICLES_SP lbData (lbCurSel HG_VEHICLES_SP);
	_spawnBusy = nearestObjects [(getMarkerPos _spawnPoint),["Car","Air","Tank"],3];
	_spawnBusy = _spawnBusy - [HG_VEHICLE_PREVIEW];
	if((count _spawnBusy) > 0) then
	{
	    titleText [(localize "STR_HG_SPAWN_BUSY"),"PLAIN DOWN",1];
	} else {
	    private["_vehicle","_displayName"];
		_vehicle = HG_VEHICLES_LIST lbData (lbCurSel HG_VEHICLES_LIST);
	    _displayName = getText(configFile >> "CfgVehicles" >> _vehicle >> "displayName");
	    _vehicle = _vehicle createVehicle (getMarkerPos _spawnPoint);
		_vehicle setDir (markerDir _spawnPoint);
		[_price,1] call HG_fnc_addOrSubCash;
		closeDialog 0;
		hint format[(localize "STR_HG_VEHICLE_BOUGHT"),_displayName,[_price] call BIS_fnc_numberText];
	};
} else {
    titleText [format[(localize "STR_HG_NOT_ENOUGH_MONEY"),[_price] call BIS_fnc_numberText,[(player getVariable "HG_myCash")] call BIS_fnc_numberText],"PLAIN DOWN",1];
};
