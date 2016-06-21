#include "HG_ShopMacros.h"
/*
    Author - HoverGuy
	Description - Called when selection in listbox has changed
	© All Fucks Reserved
*/
params["_ctrl","_index"];
private["_item","_price","_itemClass","_itemPicture","_itemDescription"];

disableSerialization;

_item = _ctrl lbData _index;
_price = _ctrl lbValue _index;
_itemClass = [_item] call HG_fnc_getConfig;
_itemPicture = getText(configFile >> _itemClass >> _item >> "Picture");
_itemDescription = getText(configFile >> _itemClass >> _item >> "descriptionShort");
	
HG_WEAPONS_ITEM_PICTURE ctrlSetText _itemPicture;
HG_WEAPONS_ITEM_PRICE ctrlSetText format[(localize "STR_HG_DLG_PRICE_TAG_W"),[_price] call BIS_fnc_numberText];
HG_WEAPONS_ITEM_TEXT ctrlSetStructuredText parseText format
[
	"
		<t align='center' size='1'><br />%1</t>
	"
	,_itemDescription
];
