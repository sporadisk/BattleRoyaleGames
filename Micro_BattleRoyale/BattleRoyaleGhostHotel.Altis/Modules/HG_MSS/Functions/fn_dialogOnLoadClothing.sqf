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

createDialog "HG_ClothingShopDialog";

private["_shopList","_ind"];

_shopList = "true" configClasses (missionConfigFile >> "CfgClientShop" >> "HG_ClothingShopCfg" >> _whatShop);
	
lbClear HG_CLOTHING_SWITCH;

{
	_ind = HG_CLOTHING_SWITCH lbAdd (getText(_x >> "displayName"));
	HG_CLOTHING_SWITCH lbSetData [_ind,format["%1/%2/%3",_whatShop,(configName _x),(getNumber(_x >> "type"))]];
} forEach _shopList;

HG_CLOTHING_SWITCH lbSetCurSel 0;

if(isNil "HG_PLAYER_BOX") then
{
    HG_PLAYER_BOX = "Box_NATO_Wps_F" createVehicleLocal getPos player;
    HG_PLAYER_BOX addAction ["<img image='HG_MSS\UI\crate.paa' size='1.5'/><t color='#FF0000'>Delete Crate</t>",{deleteVehicle (_this select 0); HG_PLAYER_BOX = nil},"",0,false,false,"",'(alive player) && !dialog && player distance _target < 2'];
	HG_PLAYER_BOX addAction ["<img image='HG_MSS\UI\crate.paa' size='1.5'/><t color='#FF0000'>Empty Crate</t>",{clearItemCargo HG_PLAYER_BOX; clearMagazineCargo HG_PLAYER_BOX; clearWeaponCargo HG_PLAYER_BOX; clearBackpackCargo HG_PLAYER_BOX;},"",0,false,false,"",'(alive player) && !dialog && player distance _target < 2'];
};

HG_PLAYER_BOX setPos [(getPos player select 0)+1,(getPos player select 1),(getPos player select 2)];
HG_PLAYER_BOX setDir (getDir player)+90;
clearItemCargo HG_PLAYER_BOX;
clearMagazineCargo HG_PLAYER_BOX;
clearWeaponCargo HG_PLAYER_BOX;
clearBackpackCargo HG_PLAYER_BOX;

HG_PLAYER_PREVIEW = "#lightpoint" createVehicleLocal getPos player;
HG_PLAYER_PREVIEW setlightbrightness 0.5;
HG_PLAYER_PREVIEW setlightcolor [1,1,1];
HG_PLAYER_PREVIEW setlightambient [1,1,1];
HG_PLAYER_PREVIEW lightAttachObject [player,[0,0,2]];

player setBehaviour "SAFE";
player switchMove "AmovPercMstpSnonWnonDnon";

HG_CAMERA_PREVIEW = "CAMERA" camCreate getPos player;
showCinemaBorder false;
HG_CAMERA_PREVIEW cameraEffect ["Internal","Back"];
HG_CAMERA_PREVIEW camSetTarget (player modelToWorld [0,0,1]);
HG_CAMERA_PREVIEW camSetPos (player modelToWorld [1,4,2]);
HG_CAMERA_PREVIEW camSetFOV .33;
HG_CAMERA_PREVIEW camSetFocus [50,0];
HG_CAMERA_PREVIEW camCommit 0;

HG_GEAR_PREVIEW = [[],[],[],[],[]];
HG_GEAR_SAVED = [(goggles player),(headgear player),(vest player),(vestItems player),(uniform player),(uniformItems player),(backpack player),(backpackItems player)];
HG_CLOTHING_BOUGHT = false;

{
    if(_x != player) then 
	{
	    _x hideObject true;
	};
} forEach playableUnits;
