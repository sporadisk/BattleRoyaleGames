#include "HG_ShopMacros.h"
/*
    Author - HoverGuy
	Description - Called by the player to open and feed the dialog with data
	© All Fucks Reserved
*/
params["_target","_caller","_id","_whatShop"];
if((typeName _whatShop) != "STRING") exitWith {hint (localize "STR_HG_ERR_ON_LOAD_1");};
if(_whatShop isEqualTo "") exitWith {hint (localize "STR_HG_ERR_ON_LOAD_2");};

disableSerialization;

createDialog "HG_VehiclesShopDialog";

private["_shopList","_ind"];

_shopList = "true" configClasses (missionConfigFile >> "CfgClientShop" >> "HG_VehiclesShopCfg" >> _whatShop);
	
lbClear HG_VEHICLES_SWITCH;

{
	_ind = HG_VEHICLES_SWITCH lbAdd (getText(_x >> "displayName"));
	HG_VEHICLES_SWITCH lbSetData [_ind,format["%1/%2",_whatShop,(configName _x)]];
} forEach _shopList;
	
HG_VEHICLE_PREVIEW = [];
HG_VEHICLES_SWITCH lbSetCurSel 0;

{
    if(_x != player) then 
	{
	    _x hideObject true;
	};
} forEach playableUnits;
