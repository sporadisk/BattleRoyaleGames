#include "HG_ShopMacros.h"
/*
    Author - HoverGuy
	Description - Called when selection in xListbox has changed
	© All Fucks Reserved
*/
params["_ctrl","_index"];
private["_shopType","_shopItems","_spawnPoints","_itemName","_ind"];

disableSerialization;

_shopType = _ctrl lbData _index;
_shopType = _shopType splitString "/";
_shopItems = getArray(missionConfigFile >> "CfgClientShop" >> "HG_VehiclesShopCfg" >> (_shopType select 0) >> (_shopType select 1) >> "vehicles");
_spawnPoints = getArray(missionConfigFile >> "CfgClientShop" >> "HG_VehiclesShopCfg" >> (_shopType select 0) >> (_shopType select 1) >> "spawnPoints");

{
    deleteVehicle _x;
} forEach HG_VEHICLE_PREVIEW;

lbClear HG_VEHICLES_LIST;
lbClear HG_VEHICLES_SP;

{
    _itemName = getText(configFile >> "CfgVehicles" >> (_x select 0) >> "displayName");
    _ind = HG_VEHICLES_LIST lbAdd _itemName;
    HG_VEHICLES_LIST lbSetData[_ind,(_x select 0)];
    HG_VEHICLES_LIST lbSetValue[_ind,(_x select 1)];
	HG_VEHICLES_LIST lbSetTooltip[_ind,_itemName];
} forEach _shopItems;

{
    _ind = HG_VEHICLES_SP lbAdd (_x select 0);
	HG_VEHICLES_SP lbSetData[_ind,(_x select 1)];
} forEach _spawnPoints;
	
HG_VEHICLES_LIST lbSetCurSel 0;
HG_VEHICLES_SP lbSetCurSel 0;
