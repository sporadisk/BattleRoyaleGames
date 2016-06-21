#include "HG_ShopMacros.h"
/*
    Author - HoverGuy
	Description - Called when selection in xListbox has changed
	© All Fucks Reserved
*/
params["_ctrl","_index"];
private["_shopType","_shopItems","_itemClass","_itemName","_ind"];

disableSerialization;
	
_shopType = _ctrl lbData _index;
_shopType = _shopType splitString "/";
_shopItems = getArray(missionConfigFile >> "CfgClientShop" >> "HG_ClothingShopCfg" >> (_shopType select 0) >> (_shopType select 1) >> "content");

lbClear HG_CLOTHING_LIST;

{
    _itemClass = [(_x select 0)] call HG_fnc_getConfig;
    _itemName = getText(configFile >> _itemClass >> (_x select 0) >> "displayName");
    _ind = HG_CLOTHING_LIST lbAdd _itemName;
    HG_CLOTHING_LIST lbSetData[_ind,(_x select 0)];
    HG_CLOTHING_LIST lbSetValue[_ind,(_x select 1)];
	HG_CLOTHING_LIST lbSetTooltip[_ind,_itemName];
} forEach _shopItems;

[parseNumber(_shopType select 2)] call HG_fnc_setCamPos;
	
HG_CLOTHING_LIST lbSetCurSel -1;
